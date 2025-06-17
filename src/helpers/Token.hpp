/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:22:44 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/17 22:40:34 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

class Token
{
    public:
        enum Type
        {
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
        ~Token();
        Token&  operator=(const Token& obj);

        Type    getType() const;
    protected:
        Type    _type;
};

# endif