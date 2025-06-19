/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:22:09 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/19 11:07:13 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

#include <iostream>

class Instruction
{    
    public:
        enum OPCode
        {
            EPSILON,
            ONCE,
            REAPEAT,
        };
		Instruction(OPCode op, std::string rule = "", size_t min = 1, 
			size_t max = 1);
        Instruction(const Instruction& obj);
        ~Instruction();
        Instruction& operator=(const Instruction& obj);
    private:
        OPCode      _op;
        std::string _rule;
		size_t		_min;
		size_t		_max;
};

# endif