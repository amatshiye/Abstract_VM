/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:49:57 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/12 14:46:41 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/int8.class.hpp"

Int8_Class::Int8_Class(void) { this->int_8_value = 0; }

Int8_Class::Int8_Class(const Int8_Class &src) { *this = src;}

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

Int8_Class::~Int8_Class(void) {}

int Int8_Class::getPrecision() const { return 0; }

eOperandType    Int8_Class::getType(void) const { return Int8; }

IOperand const *Int8_Class::operator+(IOperand const &rhs) const
{
    Int8_Class * int8_obj = new Int8_Class();
    int8_t val_1 = static_cast<int8_t>(std::stoi(this->_value));
    int8_t val_2 = static_cast<int8_t>(std::stoi(rhs.toString()));
    int8_obj->_value = std::to_string(val_1 + val_2);

    return int8_obj;
}

IOperand const *Int8_Class::operator-(IOperand const &rhs) const
{
    Int8_Class * int8_obj = new Int8_Class();
    int8_t val_1 = static_cast<int8_t>(std::stoi(this->_value));
    int8_t val_2 = static_cast<int8_t>(std::stoi(rhs.toString()));
    int8_obj->_value = std::to_string(val_1 - val_2);

    return int8_obj;
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

const std::string   &Int8_Class::toString(void) const { return this->_value; }