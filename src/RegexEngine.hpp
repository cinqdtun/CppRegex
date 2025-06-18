/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RegexEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:10:48 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 14:51:56 by fdehan           ###   ########.fr       */
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
#include "./helpers/ast/AstNode.hpp"

class RegexEngine
{
    public:
        class InvalidPatternException : public std::exception {
			public:
				const char * what () const throw();
		};
        static std::list<Token*>	tokenize(const std::string& pattern);
		static std::list<AstNode>	transformToAst(const std::list<Token*>& tokens);
        static void					printTokensList(const std::list<Token*>& tokens);
    private:
        RegexEngine();
        RegexEngine(const RegexEngine& obj);
        ~RegexEngine();
        RegexEngine&    operator=(const RegexEngine& obj);

        static bool     isSyntaxValid(const std::list<Token*>& tokens);
        static void     optimize(std::list<Token*>& tokens);
        static Token*   translateEscaped(char c);
};

#endif