/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LiteralToken.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:40:00 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 09:52:29 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERALTOKEN_HPP
# define LITERALTOKEN_HPP

#include "./Token.hpp"

class LiteralToken : public Token
{
    public:
        LiteralToken(char literal);
        LiteralToken(const LiteralToken& obj);
        ~LiteralToken();
        LiteralToken&   operator=(const LiteralToken& obj);

        char            getLiteral() const;
        void            printToken() const;
    private:
        char    _literal;
};

# endif