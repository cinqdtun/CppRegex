/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:22:37 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/17 22:41:07 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Token.hpp"

Token::Token()
{
    
}

Token::Token(Type type) : _type(type) {}

Token::Token(const Token& obj) : _type(obj._type) {}

Token::~Token() {}

Token& Token::operator=(const Token& obj) 
{
    if (this != &obj)
    {
        this->_type = obj._type;
    }
    return (*this);
}

Token::Type Token::getType() const
{
    return (this->_type);
}