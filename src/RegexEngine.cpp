/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RegexEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:11:19 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/19 11:09:26 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RegexEngine.hpp"

std::list<Token*> RegexEngine::tokenize(const std::string& pattern)
{
    std::list<Token*> tokens;
    std::string::const_iterator it = pattern.begin();
    bool inClass = false;
    ClassToken* cToken = NULL;
    std::list<Token*>* cTokenList = NULL;
    while (it != pattern.end())
    {
        if (!cToken)
        {
            switch (*it)
            {
                case '[':
                    cToken = new ClassToken();
                    cTokenList = &cToken->getTokens();
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
                    if (cTokenList->size() == 0)
                        throw InvalidPatternException();
                    tokens.push_back(cToken);
                    cToken = NULL;
                    break;
                case '\\':
                    ++it;
                    if (it == pattern.end())
                        throw InvalidPatternException();
                    cTokenList->push_back(translateEscaped(*it));
                    break;
                case '-':
                    if (cTokenList->size() && 
                        (*cTokenList->rbegin())->getType() == Token::LITERAL)
                    {
                        ++it;
                        if (it == pattern.end())
                            throw InvalidPatternException();
                        char start = dynamic_cast<LiteralToken*>(
                                *cTokenList->rbegin())->getLiteral();
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
                                delete *cTokenList->rbegin();
                                cTokenList->pop_back();
                                cTokenList->push_back(start == end ? 
                                    (Token*)new LiteralToken(start) : 
                                    (Token*)new RangeToken(start, end));
                                delete tok;
                            }
                            else
                            {
                                cTokenList->push_back(new LiteralToken('-'));
                                cTokenList->push_back(tok);
                            }
                        }
                        else if (*it != ']')
                        {
                            end = *it;
                            cTokenList->pop_back();
                            cTokenList->push_back(start == end ? 
                                    (Token*)new LiteralToken(start) : 
                                    (Token*)new RangeToken(start, end));
                        }
                        else
                        {
                            cTokenList->push_back(new LiteralToken('-'));
                            tokens.push_back(cToken);
                            cToken = NULL;
                        }
                    }
                    else
                       cTokenList->push_back(new LiteralToken('-'));
                    break;
                default:
                    cTokenList->push_back(new LiteralToken(*it));
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
		if (!(*it)->isQuantitativeToken())
            ast.push_back(*(*it));
        else
        {
            switch ((*it)->getType())
            {
                case Token::ZERO_OR_MORE:
                    (*ast.rbegin()).setMin(0);
                    (*ast.rbegin()).setMax(__INT_MAX__);
                    break;
                case Token::ONE_OR_MORE:
                    (*ast.rbegin()).setMin(1);
                    (*ast.rbegin()).setMax(__INT_MAX__);
                    break;
                default:
                    break;
            }
        }
	}

    return (ast);
}

std::list<NFAState> RegexEngine::compileAst(const std::list<AstNode>& ast)
{
	std::list<NFAState> states;

	std::list<AstNode>::const_iterator it;
	size_t state = 0;
	NFAState nState;
	for (it = ast.begin(); it != ast.end(); ++it)
	{
		nState.clearTransition();
		nState.setState(state);
		nState.setIsAccepting(false);
		
		nState.addTransition()
		states.push_back(nState);
		++state;
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

void RegexEngine::printAst(const std::list<AstNode>& ast)
{
    std::list<AstNode>::const_iterator it;

    for (it = ast.begin(); it != ast.end(); ++it)
    {
        if (it != ast.begin())
            std::cout << "|" << std::endl;
        it->print();
    }
}

bool RegexEngine::isSyntaxValid(const std::list<Token*>& tokens)
{
    std::list<Token*>::const_iterator it;
    bool quantFound = true;
    
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