/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int32.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:52:03 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/12 17:56:39 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/int32.class.hpp"

Int32_Class::Int32_Class(void) { this->int_32_value = 0; }

Int32_Class::Int32_Class(const Int32_Class &src) { *this = src; }

Int32_Class::Int32_Class(std::string value)
{
    this->_value = value;
    createInt32(value);
}

IOperand const * Int32_Class::createInt32( std::string const & value ) const
{
    Int32_Class *op_obj = new Int32_Class();

    int32_t val = static_cast<int32_t>(std::stoi(value));
    op_obj->int_32_value = val;

    return op_obj;
}

Int32_Class::~Int32_Class(void) {}

int Int32_Class::getPrecision() const { return 0; }

eOperandType    Int32_Class::getType(void) const { return Int32; }

IOperand const *Int32_Class::operator+(IOperand const &rhs) const
{
    Int32_Class * int32_obj = new Int32_Class();
    int32_t val_1 = static_cast<int32_t>(std::stoi(this->_value));
    int32_t val_2 = static_cast<int32_t>(std::stoi(rhs.toString()));
    int32_obj->_value = std::to_string(val_1 + val_2);

    return int32_obj;
}

IOperand const *Int32_Class::operator-(IOperand const &rhs) const
{
    Int32_Class * int32_obj = new Int32_Class();
    int32_t val_1 = static_cast<int32_t>(std::stoi(this->_value));
    int32_t val_2 = static_cast<int32_t>(std::stoi(rhs.toString()));
    int32_obj->_value = std::to_string(val_1 - val_2);

    return int32_obj;
}

IOperand const *Int32_Class::operator*(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Int32_Class::operator/(IOperand const &rhs) const
{
    double val = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if ((val == static_cast<double>(0)) || (val_2 == static_cast<double>(0)))
    {
        ErrorDetails e("\033[1;31mError\033[0m: You can't divide by zero");
        throw e;
    }

    return &rhs;
}

IOperand const *Int32_Class::operator%(IOperand const &rhs) const
{
    return &rhs;
}

const std::string   &Int32_Class::toString(void) const { return this->_value; }