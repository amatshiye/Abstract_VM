/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:06:43 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/13 09:55:44 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_CLASS_HPP
#define DOUBLE_CLASS_HPP

#include "IOperand.hpp"
#include "CoreEngine.hpp"

class Double_Class : public IOperand
{
    private:
        std::string _value;
        double  double_value;
        IOperand const * createDouble( std::string const & value ) const;

    public:
        Double_Class(void);
        Double_Class(std::string value);
        Double_Class(const Double_Class &src);
        ~Double_Class(void);

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