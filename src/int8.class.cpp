/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:49:57 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 17:42:29 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/int8.class.hpp"

Int8_Class::Int8_Class(void) 
{
    std::cout << "Int8 Class called" << std::endl;
    this->_value = "";
    this->int_8_value = 0;
}

Int8_Class::Int8_Class(const Int8_Class &src)
{
    *this = src;
}

Int8_Class::Int8_Class(std::string value)
{
    std::cout << "Int8 value: " << value << std::endl;
    this->_value = value;
    createInt8(value);
}

IOperand const * Int8_Class::createInt8( std::string const & value ) const
{
    Int8_Class *op_obj = new Int8_Class();

    std::cout << "CreateInt8() called" << std::endl;
    int8_t val = static_cast<int8_t>(std::stoi(value));
    op_obj->int_8_value = val;

    std::cout << "CreateInt8() complete" << std::endl;
    return op_obj;
}

Int8_Class::~Int8_Class(void) {}

int Int8_Class::getPrecision() const
{
    return 0;
}

eOperandType    Int8_Class::getType(void) const
{
    //this is for precision shit
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

int8_t  Int8_Class::getValue()
{
    return this->int_8_value;
}

const std::string   &Int8_Class::toString(void) const
{
    std::cout << "I have been called" << std::endl;
    return this->_value;
}