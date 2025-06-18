/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:22:44 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 10:05:52 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <iostream>

class Token
{
    public:
        enum Type
        {
            DEFAULT,
            CHAR_CLASS_START,
            CHAR_CLASS_END,
            RANGE,
            LITERAL,
            ONE_OR_MORE,
            ZERO_OR_MORE,
            ANYTHING,
            DIGIT,
            WORD,
        };

        Token();
        Token(Type type);
        Token(const Token& obj);
        virtual         ~Token();
        Token&          operator=(const Token& obj);

        Type            getType() const;
        virtual void    printToken() const;
    protected:
        Type    _type;
};

# endif