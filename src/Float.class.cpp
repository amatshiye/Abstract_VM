/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:52:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/12 17:55:32 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Float.class.hpp"

Float_Class::Float_Class(void) { this->float_value = 0; }

Float_Class::Float_Class(const Float_Class &src) { *this = src; }

Float_Class::Float_Class(std::string value)
{
    this->_value = value;
    createFloat(value);
}

IOperand const * Float_Class::createFloat( std::string const & value ) const
{
    Float_Class *op_obj = new Float_Class();

    float val = static_cast<float>(std::stof(value));
    op_obj->float_value = val;

    return op_obj;
}

Float_Class::~Float_Class(void) {}

int Float_Class::getPrecision() const { return 7; }

eOperandType    Float_Class::getType(void) const { return Float; }

IOperand const *Float_Class::operator+(IOperand const &rhs) const
{
    Float_Class * float_obj = new Float_Class();
    float val_1 = static_cast<float>(std::stof(this->_value));
    float val_2 = static_cast<float>(std::stof(rhs.toString()));
    float_obj->_value = std::to_string(val_1 + val_2);

    return float_obj;
}

IOperand const *Float_Class::operator-(IOperand const &rhs) const
{
    Float_Class * float_obj = new Float_Class();
    float val_1 = static_cast<float>(std::stoi(this->_value));
    float val_2 = static_cast<float>(std::stoi(rhs.toString()));
    float_obj->_value = std::to_string(val_1 - val_2);

    return float_obj;
}

IOperand const *Float_Class::operator*(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Float_Class::operator/(IOperand const &rhs) const
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

IOperand const *Float_Class::operator%(IOperand const &rhs) const
{
    return &rhs;
}

const std::string   &Float_Class::toString(void) const { return this->_value; }