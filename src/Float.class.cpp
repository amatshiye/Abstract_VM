/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:52:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 12:18:53 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Float.class.hpp"

Float_Class::Float_Class(void) 
{
    std::cout << "Float Class called" << std::endl;
}

Float_Class::Float_Class(const Float_Class &src)
{
    *this = src;
}

Float_Class::~Float_Class(void) {}

int Float_Class::getPrecision() const
{
    return 0;
}

eOperandType    Float_Class::getType(void) const
{
    return Float;
}

IOperand const *Float_Class::operator+(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Float_Class::operator-(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Float_Class::operator*(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Float_Class::operator/(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Float_Class::operator%(IOperand const &rhs) const
{
    return &rhs;
}

const std::string   &Float_Class::toString(void) const
{
    const std::string *what = nullptr;
    return *what;
}