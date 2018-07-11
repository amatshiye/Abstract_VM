/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:49:57 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/10 17:37:55 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/int8.class.hpp"

Int8_Class::Int8_Class(void) 
{
    this->int_8_value = 0;
}

Int8_Class::Int8_Class(const Int8_Class &src)
{
    *this = src;
}

Int8_Class::Int8_Class(std::string value)
{
    this->_value = value;
    createInt8(value);
}

IOperand const * Int8_Class::createInt8( std::string const & value ) const
{
    Int8_Class *op_obj = new Int8_Class();

    int8_t val = static_cast<int8_t>(std::stoi(value));
    op_obj->int_8_value = val;

    return op_obj;
}

Int8_Class::~Int8_Class(void) 
{
    std::cout << "Class destroyed" << std::endl;
}

int Int8_Class::getPrecision() const
{
    return 0;
}

eOperandType    Int8_Class::getType(void) const
{
    //this is for precision shit
    return Int8;
}

void    Int8_Class::setValue(std::string value)
{
    Int8_Class *op_obj = new Int8_Class();
    op_obj->_value = value;
}

IOperand const *Int8_Class::operator+(IOperand const &rhs) const
{
    int8_t val_1 = static_cast<int8_t>(std::stoi(this->_value));
    int8_t val_2 = static_cast<int8_t>(std::stoi(rhs.toString()));
    setValue(std::to_string(val_1 + val_2));

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
    return this->_value;
}