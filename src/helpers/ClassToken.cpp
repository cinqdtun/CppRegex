/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassToken.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:08:41 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 20:45:20 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClassToken.hpp"

ClassToken::ClassToken() : Token(CLASS) {}

ClassToken::ClassToken(const ClassToken& obj) : Token(CLASS)
{
    std::list<Token*>::const_iterator it;

    for (it = obj._tokens.begin(); it != obj._tokens.end(); ++it)
    {
        this->_tokens.push_back((*it)->clone());
    }
}

ClassToken::~ClassToken() 
{
    std::list<Token*>::const_iterator it;

    for (it = this->_tokens.begin(); it != this->_tokens.end(); ++it)
    {
        delete *it;
    }
}

ClassToken& ClassToken::operator=(const ClassToken& obj) 
{
    if (this != &obj)
    {
        Token::operator=(obj);
        std::list<Token*>::const_iterator it;
        
        for (it = obj._tokens.begin(); it != obj._tokens.end(); ++it)
        {
            this->_tokens.push_back((*it)->clone());
        }
    }
    return (*this);
}

std::list<Token*>& ClassToken::getTokens() 
{
    return (this->_tokens);
}

const std::list<Token*>& ClassToken::getTokens() const 
{
    return (this->_tokens);
}

void ClassToken::printToken() const
{
    std::list<Token*>::const_iterator it;
    std::cout << "[CLASS]\n"
              << "Type: CLASS containing : " << std::endl;

    for (it = this->_tokens.begin(); it != this->_tokens.end(); ++it)
    {
        (*it)->printToken();
    }
    std::cout << "[CLASS]" << std::endl;
}

ClassToken* ClassToken::clone() const
{
    return (new ClassToken(*this));
}
