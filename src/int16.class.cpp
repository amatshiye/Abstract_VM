/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int16.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:51:36 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/12 14:17:35 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/int16.class.hpp"

Int16_Class::Int16_Class(void) { this->int_16_value = 0; }

Int16_Class::Int16_Class(const Int16_Class &src) { *this = src; }

Int16_Class::Int16_Class(std::string value)
{
    this->_value = value;
    createInt16(value);
}

IOperand const * Int16_Class::createInt16( std::string const & value ) const
{
    Int16_Class *op_obj = new Int16_Class();

    int16_t val = static_cast<int16_t>(std::stoi(value));
    op_obj->int_16_value = val;

    return op_obj;
}

Int16_Class::~Int16_Class(void) {}

int Int16_Class::getPrecision() const { return 0; }

eOperandType    Int16_Class::getType(void) const { return Int16; }

IOperand const *Int16_Class::operator+(IOperand const &rhs) const
{
    Int16_Class * int16_obj = new Int16_Class();
    int16_t val_1 = static_cast<int16_t>(std::stoi(this->_value));
    int16_t val_2 = static_cast<int16_t>(std::stoi(rhs.toString()));
    int16_obj->_value = std::to_string(val_1 + val_2);

    return int16_obj;
}

IOperand const *Int16_Class::operator-(IOperand const &rhs) const
{
    Int16_Class * int16_obj = new Int16_Class();
    int16_t val_1 = static_cast<int16_t>(std::stoi(this->_value));
    int16_t val_2 = static_cast<int16_t>(std::stoi(rhs.toString()));
    int16_obj->_value = std::to_string(val_1 - val_2);

    return int16_obj;
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

const std::string   &Int16_Class::toString(void) const { return this->_value; }