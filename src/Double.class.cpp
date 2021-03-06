/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:02:49 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 11:17:24 by amatshiy         ###   ########.fr       */
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

Double_Class const & Double_Class::operator=(Double_Class const & rhs)
{
    (void)rhs; 
    return *this;
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
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    IOperand const * operand_obj = core_engine.createOperand(this->getType(), std::to_string((val_1 + val_2)));

    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

IOperand const *Double_Class::operator-(IOperand const &rhs) const
{
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    IOperand const * operand_obj = core_engine.createOperand(this->getType(), std::to_string((val_1 - val_2)));

    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

IOperand const *Double_Class::operator*(IOperand const &rhs) const
{
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    IOperand const * operand_obj = core_engine.createOperand(this->getType(), std::to_string((val_1 * val_2)));

    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

IOperand const *Double_Class::operator/(IOperand const &rhs) const
{
    double val_1 = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if (val_1 == static_cast<double>(0))
    {
        throw ErrorDetails::DivideByZero();
    }

    CoreEngine core_engine;
    IOperand const * operand_obj = core_engine.createOperand(this->getType(), std::to_string((val_1 / val_2)));
    core_engine.ft_push(operand_obj);
    return operand_obj;
}

IOperand const *Double_Class::operator%(IOperand const &rhs) const
{
    double val_1 = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if (val_1 == static_cast<double>(0))
    {
        throw ErrorDetails::DivideByZero();
    }
    CoreEngine core_engine;

    IOperand const * operand_obj = core_engine.createOperand(this->getType(), std::to_string(fmod(val_1, val_2)));
    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

const std::string   &Double_Class::toString(void) const
{
    return this->_value;
}