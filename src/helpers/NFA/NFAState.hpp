/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NFAState.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:33:23 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/19 10:01:23 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NFASTATE_HPP
#define NFASTATE_HPP

#include <iostream>
#include <set>
#include <map>

class NFAState
{
    public:
        enum OPCodes
        {
            ONCE,
            REAPEAT,
        };
        
        NFAState(size_t state);
        NFAState(const NFAState& obj);
        ~NFAState();
        NFAState& operator=(const NFAState& obj);
    private:
        size_t                                              _state;
        
        std::map<std::string, std::set<size_t>> _transitions;
        bool                                                _isAccepting;
};

#endif