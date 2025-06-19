/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassToken.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:09:01 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 20:24:43 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSTOKEN_HPP
# define CLASSTOKEN_HPP

#include <list>
#include "./Token.hpp"


class ClassToken : public Token
{
	public:
		ClassToken();
        ClassToken(const ClassToken& obj);
        ~ClassToken();
        ClassToken& 				operator=(const ClassToken& obj);
		std::list<Token*>& 			getTokens();
		const std::list<Token*>&	getTokens() const;
		void            			printToken() const;
		ClassToken*					clone() const;
	private:
		std::list<Token*> _tokens;
};

# endif