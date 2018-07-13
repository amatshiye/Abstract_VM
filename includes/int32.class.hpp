/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int32.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:10:50 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/13 09:55:33 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_CLASS_HPP
#define INT32_CLASS_HPP

#include "IOperand.hpp"
#include "CoreEngine.hpp"

class Int32_Class : public IOperand
{
    private:
        std::string _value;
        int32_t  int_32_value;
        IOperand const * createInt32( std::string const & value ) const;

    public:
        Int32_Class(void);
        Int32_Class(std::string value);
        Int32_Class(const Int32_Class &src);
        ~Int32_Class(void);

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