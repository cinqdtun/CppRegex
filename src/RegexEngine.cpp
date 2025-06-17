/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RegexEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:11:19 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/17 23:15:26 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RegexEngine.hpp"

std::vector<Token> RegexEngine::tokenize(const std::string& pattern)
{
    std::list<Token> tokens;
    std::string::const_iterator it = pattern.begin();
    bool inClass = false;

    while (it != pattern.end())
    {
        if (!inClass)
        {
            switch (*it)
            {
                case '[':
                    tokens.push_back(Token::CHAR_CLASS_START);
                    inClass = true;
                    break;
                case ']':
                    tokens.push_back(Token::CHAR_CLASS_END);
                    inClass = false;
                    break;
                case '+':
                    tokens.push_back(Token::ONE_OR_MORE);
                    break;
                case '*':
                    tokens.push_back(Token::ZERO_OR_MORE);
                    break;
                case '.':
                    tokens.push_back(Token::ANYTHING);
                    break;
                case '\\':
                    ++it;
                    if (it == pattern.end())
                        throw InvalidPatternException();
                    tokens.push_back(translateEscaped(*it));
                    break;
                default:
                    tokens.push_back(Token::LITERAL);
                    break;
            }
        }
        else
        {
            switch (*it)
            {
                case '\\':
                    ++it;
                    if (it == pattern.end())
                        throw InvalidPatternException();
                    tokens.push_back(translateEscaped(*it));
                    break;
                case '-':
                    if ((*tokens.rbegin()).getType() == Token::LITERAL)
                    {
                        ++it;
                        if (it == pattern.end())
                            throw InvalidPatternException();
                        if (*it == '\\')
                        {
                            ++it;
                            if (it == pattern.end())
                                throw InvalidPatternException();
                            
                        }
                    }
                default:
                   
                    break; tokens.push_back(LiteralToken(*it));
            }
        }
        ++it;
    }
    
    if (inClass)
        throw InvalidPatternException();
}

Token RegexEngine::translateEscaped(char c)
{
    switch (c)
    {
        case 'd': return Token(Token::DIGIT);
        case 'w': return Token(Token::WORD);
        case 's': return LiteralToken(' ');
        case 'n': return LiteralToken('\n');
        case 't': return LiteralToken('\t');
        default: return LiteralToken(c);
    }
}

// Exceptions

const char *RegexEngine::InvalidPatternException::what() const throw()
{
	return ("Invalid pattern exception");
}