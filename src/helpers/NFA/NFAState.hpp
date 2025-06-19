/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NFAState.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:33:23 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/19 10:58:53 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NFASTATE_HPP
#define NFASTATE_HPP

#include <iostream>
#include <set>
#include <list>
#include "./Instruction.hpp"

class NFAState
{
    public:
		NFAState();
        NFAState(size_t state, bool isAccepting);
        NFAState(const NFAState& obj);
        ~NFAState();
        NFAState&   operator=(const NFAState& obj);
        void        addTransition(const Instruction& in, 
                const std::set<size_t>& transition);
		void		clearTransition();
		void		setState(size_t state);
		void		setIsAccepting(bool isAccepting);
    private:
        size_t                                              _state;
        
        std::list<std::pair<Instruction, std::set<size_t>>> _transitions;
        bool                                                _isAccepting;
};

#endif