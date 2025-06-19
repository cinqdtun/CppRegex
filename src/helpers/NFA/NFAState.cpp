/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NFAState.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:28:34 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/19 11:00:32 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./NFAState.hpp"

NFAState::NFAState() : _state(0), _isAccepting(false) {}

NFAState::NFAState(size_t state, bool isAccepting) : _state(state), 
    _isAccepting(isAccepting) {}

NFAState::NFAState(const NFAState& obj) : _state(obj._state), 
	_transitions(obj._transitions), _isAccepting(obj._isAccepting) {}

NFAState::~NFAState() {}

NFAState& NFAState::operator=(const NFAState& obj) 
{
    if (this != &obj)
    {
        this->_state = obj._state;
        this->_transitions = obj._transitions;
        this->_state = obj._state;
    }
    return (*this);
}

void NFAState::addTransition(const Instruction& in, const std::set<size_t>& transition)
{
    this->_transitions.push_back(std::pair(in, transition));
}

void NFAState::clearTransition()
{
	this->_transitions.clear();
}

void NFAState::setState(size_t state) 
{
	this->_state = state;
}

void NFAState::setIsAccepting(bool isAccepting) 
{
	this->_isAccepting = isAccepting;
}
