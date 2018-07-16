/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int16.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:13:21 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 11:19:40 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_CLASS_HPP
#define INT16_CLASS_HPP

#include "IOperand.hpp"
#include "CoreEngine.hpp"

class Int16_Class : public IOperand
{
    private:
        std::string _value;
        int16_t  int_16_value;
        IOperand const * createInt16( std::string const & value ) const;

    public:
        Int16_Class(void);
        Int16_Class(std::string value);
        Int16_Class(const Int16_Class &src);
        ~Int16_Class(void);

        Int16_Class const &operator=(Int16_Class const & rhs);
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