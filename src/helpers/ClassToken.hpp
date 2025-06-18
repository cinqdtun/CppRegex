/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassToken.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:09:01 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 15:11:46 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSTOKEN_HPP
# define CLASSTOKEN_HPP

#include <list>
#include "./Token.hpp"


class ClassToken : public Token
{
	public:
		ClassToken(char literal);
        ClassToken(const ClassToken& obj);
        ~ClassToken();
        ClassToken&   operator=(const ClassToken& obj);
	private:
		std::list<Token*> tokens;
};

# endif