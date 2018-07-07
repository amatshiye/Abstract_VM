/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:09:28 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 07:32:47 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_CLASS_HPP
#define FLOAT_CLASS_HPP

#include "IOperand.hpp"

class Float_Class : public IOperand
{
    private:
        IOperand const * createFloat( std::string const & value ) const;

    public:
        Float_Class(void);
        Float_Class(const Float_Class &src);
        ~Float_Class(void);

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