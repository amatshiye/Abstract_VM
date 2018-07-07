/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:49:57 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 14:05:51 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/int8.class.hpp"

Int8_Class::Int8_Class(void) 
{
    this->_value = "";
    std::cout << "Int8 Class called" << std::endl;
}

Int8_Class::Int8_Class(const Int8_Class &src)
{
    *this = src;
}

Int8_Class::~Int8_Class(void) {}

int Int8_Class::getPrecision() const
{
    return 0;
}

eOperandType    Int8_Class::getType(void) const
{
    return Int8;
}

IOperand const *Int8_Class::operator+(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int8_Class::operator-(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int8_Class::operator*(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int8_Class::operator/(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int8_Class::operator%(IOperand const &rhs) const
{
    return &rhs;
}

const std::string   &Int8_Class::toString(void) const
{
    const std::string *what = nullptr;
    return *what;
}