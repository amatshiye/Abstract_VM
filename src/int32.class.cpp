/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int32.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:52:03 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 12:20:51 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/int32.class.hpp"

Int32_Class::Int32_Class(void) 
{
    std::cout << "Int32 Class called" << std::endl;
}

Int32_Class::Int32_Class(const Int32_Class &src)
{
    *this = src;
}

Int32_Class::~Int32_Class(void) {}

int Int32_Class::getPrecision() const
{
    return 0;
}

eOperandType    Int32_Class::getType(void) const
{
    return Int32;
}

IOperand const *Int32_Class::operator+(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int32_Class::operator-(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int32_Class::operator*(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int32_Class::operator/(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int32_Class::operator%(IOperand const &rhs) const
{
    return &rhs;
}

const std::string   &Int32_Class::toString(void) const
{
    const std::string *what = nullptr;
    return *what;
}