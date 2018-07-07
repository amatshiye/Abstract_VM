/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int16.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:51:36 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 12:19:29 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/int16.class.hpp"

Int16_Class::Int16_Class(void) 
{
    std::cout << "Int16 Class called" << std::endl;
}

Int16_Class::Int16_Class(const Int16_Class &src)
{
    *this = src;
}

Int16_Class::~Int16_Class(void) {}

int Int16_Class::getPrecision() const
{
    return 0;
}

eOperandType    Int16_Class::getType(void) const
{
    return Int16;
}

IOperand const *Int16_Class::operator+(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int16_Class::operator-(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int16_Class::operator*(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int16_Class::operator/(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int16_Class::operator%(IOperand const &rhs) const
{
    return &rhs;
}

const std::string   &Int16_Class::toString(void) const
{
    const std::string *what = nullptr;
    return *what;
}