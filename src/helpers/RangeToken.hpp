/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RangeToken.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:29:40 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 09:32:09 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANGETOKEN_HPP
# define RANGETOKEN_HPP

#include "./Token.hpp"

class RangeToken : public Token
{
    public:
        RangeToken(char start, char end);
        RangeToken(const RangeToken& obj);
        ~RangeToken();
        RangeToken& operator=(const RangeToken& obj);
        
        char        getStart() const;
        char        getEnd() const;
        void        printToken() const;
    private:
        char    _start;
        char    _end;
};

#endif