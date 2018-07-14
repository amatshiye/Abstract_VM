/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckFlow.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:15:27 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/14 17:59:06 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_FLOW_HPP
#define CHECK_FLOW_HPP

#include "IOperand.hpp"

// class IOperand;

class CheckFlow
{
    public:
        CheckFlow(void);
        CheckFlow(IOperand const * operand);
        CheckFlow(CheckFlow const &src);
        ~CheckFlow(void);

        CheckFlow & operator=(CheckFlow const &rhs);
        void    isFlow(std::string value, eOperandType type);
};

#endif