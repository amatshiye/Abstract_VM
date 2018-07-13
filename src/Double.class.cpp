/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:02:49 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/13 07:43:26 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Double.class.hpp"

Double_Class::Double_Class(void) { this->double_value = 0; }

Double_Class::Double_Class(const Double_Class &src) { *this = src; }

Double_Class::Double_Class(std::string value)
{
    this->_value = value;
    createDouble(value);
}

IOperand const * Double_Class::createDouble( std::string const & value ) const
{
    Double_Class *op_obj = new Double_Class();

    double val = static_cast<double>(std::stod(value));
    op_obj->double_value = val;

    return op_obj;
}

Double_Class::~Double_Class(void) {}

int Double_Class::getPrecision() const { return Double; }

eOperandType    Double_Class::getType(void) const
{
    return Double;
}

IOperand const *Double_Class::operator+(IOperand const &rhs) const
{
    Double_Class * double_obj = new Double_Class();
    double val_1 = static_cast<double>(std::stod(this->_value));
    double val_2 = static_cast<double>(std::stod(rhs.toString()));
    double_obj->_value = std::to_string(val_1 + val_2);

    return double_obj;
}

IOperand const *Double_Class::operator-(IOperand const &rhs) const
{
    Double_Class * double_obj = new Double_Class();
    double val_1 = static_cast<double>(std::stod(this->_value));
    double val_2 = static_cast<double>(std::stod(rhs.toString()));
    double_obj->_value = std::to_string(val_1 - val_2);

    return double_obj;
}

IOperand const *Double_Class::operator*(IOperand const &rhs) const
{
    return &rhs;
}

IOperand const *Double_Class::operator/(IOperand const &rhs) const
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

IOperand const *Double_Class::operator%(IOperand const &rhs) const
{
    return &rhs;
}

const std::string   &Double_Class::toString(void) const
{
    const std::string *what = nullptr;
    return *what;
}