/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 07:26:31 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 09:43:30 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <iostream>


enum eOperandType {Int8, Int16, Int32, Float, Double};

class IOperand
{
    public:
        virtual int getPrecision(void) const = 0;                         // Precision of the type of the instance
        virtual eOperandType getType(void) const = 0;                     // Type of the instance

        virtual IOperand const *operator+(IOperand const &rhs) const = 0; // Sum
        virtual IOperand const *operator-(IOperand const &rhs) const = 0; // Difference
        virtual IOperand const *operator*(IOperand const &rhs) const = 0; // Product
        virtual IOperand const *operator/(IOperand const &rhs) const = 0; // Quotient
        virtual IOperand const *operator%(IOperand const &rhs) const = 0; // Modulo
        
        virtual std::string const &toString(void) const = 0;              // String representation of the instance
        virtual ~IOperand(void) {}
};

#endif