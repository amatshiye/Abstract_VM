/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:15:01 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 07:38:50 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_CLASS_HPP
#define INT8_CLASS_HPP

#include "IOperand.hpp"

class Int8_Class : public IOperand
{
    private:
        IOperand const * createInt8( std::string const & value ) const;

    public:
        Int8_Class(void);
        Int8_Class(const Int8_Class &src);
        ~Int8_Class(void);

        int getPrecision(void) const;                         // Precision of the type of the instance
        eOperandType getType(void) const;
        
        IOperand const *operator+(IOperand const &rhs) const; // Sum
        IOperand const *operator-(IOperand const &rhs) const; // Difference
        IOperand const *operator*(IOperand const &rhs) const; // Product
        IOperand const *operator/(IOperand const &rhs) const; // Quotient
        IOperand const *operator%(IOperand const &rhs) const; // Modulo

        std::string const &toString(void) const;    // String representation of the instance
};

#endif