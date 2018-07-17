/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckFlow.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:15:27 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 10:55:53 by amatshiy         ###   ########.fr       */
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

        CheckFlow const & operator=(CheckFlow const &rhs);
        void    isFlow(std::string value, eOperandType type, int line_no = 0);
};

#endif