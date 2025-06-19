/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:21:45 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/19 11:08:19 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Instruction.hpp"

Instruction::Instruction(OPCode op, std::string rule, size_t min, size_t max) : 
	_op(op), _rule(rule), _min(min), _max(max) {}

Instruction::Instruction(const Instruction& obj) : _op(obj._op),
    _rule(obj._rule), _min(obj._min), _max(obj._max) {}

Instruction::~Instruction() {}

Instruction& Instruction::operator=(const Instruction& obj) 
{
    if (this != &obj)
    {
        this->_op = obj._op;
        this->_rule = obj._rule;
		this->_min = obj._min;
		this->_max = obj._max;
    }
    return (*this);
}
