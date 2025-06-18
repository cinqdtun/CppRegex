/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LiteralToken.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:39:47 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 09:52:46 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LiteralToken.hpp"

LiteralToken::LiteralToken(char literal) : Token(LITERAL), _literal(literal) {}

LiteralToken::LiteralToken(const LiteralToken& obj) : Token(LITERAL), 
    _literal(obj._literal) {}

LiteralToken::~LiteralToken() {}

LiteralToken& LiteralToken::operator=(const LiteralToken& obj) 
{
    if (this != &obj)
    {
        Token::operator=(obj);
        this->_literal = obj._literal;
    }
    return (*this);
}

char LiteralToken::getLiteral() const
{
    return (this->_literal);
}

void LiteralToken::printToken() const
{
    std::cout << "Type: LITERAL equal to " 
        << this->_literal << " (" << (int)this->_literal << ")" << std::endl;
}
