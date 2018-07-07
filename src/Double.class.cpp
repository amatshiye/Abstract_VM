/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:02:49 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 12:20:21 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Double.class.hpp"

Double_Class::Double_Class(void) 
{
    std::cout << "Double Class called" << std::endl;
}

Double_Class::Double_Class(const Double_Class &src)
{
    *this = src;
}

Double_Class::~Double_Class(void) {}

int Double_Class::getPrecision() const
{
    return 0;
}

eOperandType    Double_Class::getType(void) const
{
    return Double;
}

IOperand const *Double_Class::operator+(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Double_Class::operator-(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Double_Class::operator*(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Double_Class::operator/(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Double_Class::operator%(IOperand const &rhs) const
{
    return &rhs;
}

const std::string   &Double_Class::toString(void) const
{
    const std::string *what = nullptr;
    return *what;
}