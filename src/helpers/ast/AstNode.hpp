/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AstNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:32:54 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 20:17:37 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTNODE_HPP
# define ASTNODE_HPP

#include <iostream>
#include "./../Token.hpp"

class AstNode
{
	public:
		enum Type
		{
			LITTERAL,
			CLASS,
			SPECIAL,
		};
		
		AstNode();
		AstNode(const Token& token);
		AstNode(const AstNode& obj);
		~AstNode();
		AstNode&	operator=(const AstNode& obj);
		void		setMin(size_t min);
		void		setMax(size_t max);
		void		print() const;
	private:
		AstNode*	_left;
		AstNode*	_right;
		size_t		_min;
		size_t		_max;
		Token*		_token;
};

# endif