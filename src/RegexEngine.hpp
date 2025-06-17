/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RegexEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:10:48 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/17 22:36:49 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEXENGINE_HPP
# define REGEXENGINE_HPP

#include <iostream>
#include <vector>
#include <list>
#include "./helpers/Token.hpp"
#include "./helpers/RangeToken.hpp"
#include "./helpers/LiteralToken.hpp"

class RegexEngine
{
    public:
        class InvalidPatternException : public std::exception {
			public:
				const char * what () const throw();
		};
        std::vector<Token> tokenize(const std::string& pattern);
    private:
        RegexEngine();
        RegexEngine(const RegexEngine& obj);
        ~RegexEngine();
        RegexEngine&    operator=(const RegexEngine& obj);

        Token           translateEscaped(char c);
};

#endif