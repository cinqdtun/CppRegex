/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RegexEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:11:19 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 14:55:47 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RegexEngine.hpp"

std::list<Token*> RegexEngine::tokenize(const std::string& pattern)
{
    std::list<Token*> tokens;
    std::string::const_iterator it = pattern.begin();
    bool inClass = false;

    while (it != pattern.end())
    {
        if (!inClass)
        {
            switch (*it)
            {
                case '[':
                    tokens.push_back(new Token(Token::CHAR_CLASS_START));
                    inClass = true;
                    break;
                case ']':
                    if ((*tokens.rbegin())->getType() == Token::CHAR_CLASS_START)
                        throw InvalidPatternException();
                    tokens.push_back(new Token(Token::CHAR_CLASS_END));
                    inClass = false;
                    break;
                case '+':
                    tokens.push_back(new Token(Token::ONE_OR_MORE));
                    break;
                case '*':
                    tokens.push_back(new Token(Token::ZERO_OR_MORE));
                    break;
                case '.':
                    tokens.push_back(new Token(Token::ANYTHING));
                    break;
                case '\\':
                    ++it;
                    if (it == pattern.end())
                        throw InvalidPatternException();
                    tokens.push_back(translateEscaped(*it));
                    break;
                default:
                    tokens.push_back(new LiteralToken(*it));
                    break;
            }
        }
        else
        {
            switch (*it)
            {
                case ']':
                    if ((*tokens.rbegin())->getType() == Token::CHAR_CLASS_START)
                        throw InvalidPatternException();
                    tokens.push_back(new Token(Token::CHAR_CLASS_END));
                    inClass = false;
                    break;
                case '\\':
                    ++it;
                    if (it == pattern.end())
                        throw InvalidPatternException();
                    tokens.push_back(translateEscaped(*it));
                    break;
                case '-':
                    if ((*tokens.rbegin())->getType() == Token::LITERAL)
                    {
                        ++it;
                        if (it == pattern.end())
                            throw InvalidPatternException();
                        char start = dynamic_cast<LiteralToken*>(
                                *tokens.rbegin())->getLiteral();
                        char end;
                        if (*it == '\\')
                        {
                            ++it;
                            if (it == pattern.end())
                                throw InvalidPatternException();
                            Token* tok = translateEscaped(*it);
                            if (tok->getType() == Token::LITERAL)
                            {
                                end = dynamic_cast<LiteralToken*>(
                                    tok)->getLiteral();
                                delete *tokens.rbegin();
                                tokens.pop_back();
                                tokens.push_back(start == end ? 
                                    (Token*)new LiteralToken(start) : 
                                    (Token*)new RangeToken(start, end));
                                delete tok;
                            }
                            else
                            {
                                tokens.push_back(new LiteralToken('-'));
                                tokens.push_back(tok);
                            }
                        }
                        else
                        {
                            end = *it;
                            tokens.pop_back();
                            tokens.push_back(start == end ? 
                                    (Token*)new LiteralToken(start) : 
                                    (Token*)new RangeToken(start, end));
                        }
                    }
                    else
                    {
                        tokens.push_back(new LiteralToken('-'));
                    }
                    break;
                default:
                    tokens.push_back(new LiteralToken(*it));
                    break; 
            }
        }
        ++it;
    }
    if (inClass || !isSyntaxValid(tokens))
        throw InvalidPatternException();
    
    optimize(tokens);
    return (tokens);
}

std::list<AstNode> RegexEngine::transformToAst(const std::list<Token*>& tokens)
{
	std::list<AstNode> ast;
	std::list<Token*>::const_iterator it;

	for (it = tokens.begin(); it != tokens.end(); ++it)
	{
		
	}
}

void RegexEngine::printTokensList(const std::list<Token*>& tokens)
{
    std::list<Token*>::const_iterator it;

    for (it = tokens.begin(); it != tokens.end(); ++it)
    {
        if (it != tokens.begin())
            std::cout << "|" << std::endl;
        (*it)->printToken();
    }
}

bool RegexEngine::isSyntaxValid(const std::list<Token*>& tokens)
{
    std::list<Token*>::const_iterator it;
    bool quantFound = false;
    
    for (it = tokens.begin(); it != tokens.end(); ++it)
    {
        bool isQuant = (*it)->isQuantitativeToken();
        
        if (quantFound && isQuant)
            return (false);
        
        quantFound = isQuant;
    }
    return (true);
}

void RegexEngine::optimize(std::list<Token*>& tokens)
{
	(void)tokens;
    // Can optimize to reduce complexity
}

Token* RegexEngine::translateEscaped(char c)
{
    switch (c)
    {
        case 'd': return new Token(Token::DIGIT);
        case 'w': return new Token(Token::WORD);
        case 's': return new LiteralToken(' ');
        case 'n': return new LiteralToken('\n');
        case 't': return new LiteralToken('\t');
        default: return new LiteralToken(c);
    }
}

// Exceptions

const char *RegexEngine::InvalidPatternException::what() const throw()
{
	return ("Invalid pattern exception");
}