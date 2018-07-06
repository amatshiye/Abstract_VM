/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:33:29 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/06 12:54:54 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ENGINE_HPP
#define STACK_ENGINE_HPP

#include "FileEngine.hpp"

class StackEngine
{
    private:
        std::vector<std::string>    _Stack;
        std::string _dataType;
        std::string _value;

    public:
        StackEngine(void);
        StackEngine(std::string dataType, std::string value);
        ~StackEngine(void);
};

#endif