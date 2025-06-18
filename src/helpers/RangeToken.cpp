/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RangeToken.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:32:02 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 09:35:32 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RangeToken.hpp"

RangeToken::RangeToken(char start, char end) : Token(RANGE), _start(start), 
    _end(end) {}

RangeToken::RangeToken(const RangeToken& obj) : Token(RANGE), 
    _start(obj._start), _end(obj._end) {}

RangeToken::~RangeToken() {}

RangeToken& RangeToken::operator=(const RangeToken& obj) 
{
    if (this != &obj)
    {
        Token::operator=(obj);
        this->_start = obj._start;
        this->_end = obj._end;
    }
    return (*this);
}

char RangeToken::getStart() const
{
    return (this->_start);
}

char RangeToken::getEnd() const
{
    return (this->_end);
}

void RangeToken::printToken() const
{
    std::cout << "Type: RANGE between " 
        << this->_start << " (" << (int)this->_start << ") and " 
        << this->_end << " (" << (int)this->_end << ")" << std::endl;
}
