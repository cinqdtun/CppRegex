/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AstNode.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:32:29 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 15:07:59 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AstNode.hpp"

AstNode::AstNode() : _left(NULL), _right(NULL), _min(1), _max(1) {}

AstNode::AstNode(const AstNode& obj) : _left(obj._left), _right(obj._right), 
	_min(obj._min), _max(obj._max) {}

AstNode::~AstNode() {}

AstNode& AstNode::operator=(const AstNode& obj) 
{
	if (this != &obj)
	{
		this->_left = obj._left;
		this->_right = obj._right;
		this->_min = obj._min;
		this->_max = obj._max;
	}
	return (*this);
}
