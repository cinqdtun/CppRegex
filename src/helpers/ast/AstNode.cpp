/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AstNode.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:32:29 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 20:34:10 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AstNode.hpp"

AstNode::AstNode() : _left(NULL), _right(NULL), _min(1), _max(1), _token(NULL) 
	{}

AstNode::AstNode(const Token& token) : _left(NULL), _right(NULL), 
	_min(1), _max(1), _token(NULL) 
{
	this->_token = token.clone();
}

AstNode::AstNode(const AstNode& obj) : _left(obj._left), _right(obj._right), 
	_min(obj._min), _max(obj._max), _token(obj._token->clone()) {}

AstNode::~AstNode() 
{
	delete this->_token;
}

AstNode& AstNode::operator=(const AstNode& obj) 
{
	if (this != &obj)
	{
		this->_left = obj._left;
		this->_right = obj._right;
		this->_min = obj._min;
		this->_max = obj._max;
		this->_token = obj._token;
	}
	return (*this);
}

void AstNode::setMin(size_t min)
{
	this->_min = min;
}

void AstNode::setMax(size_t max)
{
	this->_max = max;
}

void AstNode::print() const
{
	std::cout << "[Node] Repetition min : " << this->_min << " max : " 
			  << this->_max << std::endl;
	this->_token->printToken();
}
