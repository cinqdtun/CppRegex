/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:22:37 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 10:55:09 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Token.hpp"

Token::Token() : _type(DEFAULT) {}

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

void Token::printToken() const
{
    std::string arr[] = {"DEFAULT",
			"ANYTHING",
            "DIGIT",
            "WORD",
            "CHAR_CLASS_START",
            "CHAR_CLASS_END",
            "RANGE",
            "LITERAL",
			"ZERO_OR_MORE",
            "ONE_OR_MORE",
	};
    std::cout << "Type: " << arr[this->_type] << std::endl;
}

bool Token::isQuantitativeToken()
{
    return (this->_type >= ONE_OR_MORE);
}
