/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:22:44 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 10:54:05 by fdehan           ###   ########.fr       */
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
            ANYTHING,
            DIGIT,
            WORD,
            CHAR_CLASS_START,
            CHAR_CLASS_END,
            RANGE,
            LITERAL,
            ZERO_OR_MORE,
            ONE_OR_MORE,
        };

        Token();
        Token(Type type);
        Token(const Token& obj);
        virtual         ~Token();
        Token&          operator=(const Token& obj);

        Type            getType() const;
        virtual void    printToken() const;
        bool            isQuantitativeToken();
    protected:
        Type    _type;
};

# endif