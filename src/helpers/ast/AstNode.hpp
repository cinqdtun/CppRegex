/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AstNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:32:54 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 15:06:58 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTNODE_HPP
# define ASTNODE_HPP

#include <iostream>

class AstNode
{
	public:
		enum Type
		{
			LITTERAL,

		};
		
		AstNode();
		AstNode(const AstNode& obj);
		~AstNode();
		AstNode& operator=(const AstNode& obj);
	private:
		AstNode*	_left;
		AstNode*	_right;
		size_t		_min;
		size_t		_max;
};

# endif