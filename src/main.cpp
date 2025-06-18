/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:04:08 by fdehan            #+#    #+#             */
/*   Updated: 2025/06/18 10:39:21 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Regex.hpp"
#include "./RegexEngine.hpp"

int main()
{
    std::list<Token*> tokens = RegexEngine::tokenize("[e-u\\d]++");
    RegexEngine::printTokensList(tokens);
    //Regex re("test");
    return (0);
}