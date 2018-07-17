/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int16.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:51:36 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 11:19:47 by amatshiy         ###   ########.fr       */
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

Int16_Class const & Int16_Class::operator=(Int16_Class const & rhs)
{
    (void)rhs;
    return *this;
}

Int16_Class::~Int16_Class(void) {}

int Int16_Class::getPrecision() const { return Int16; }

eOperandType    Int16_Class::getType(void) const { return Int16; }

IOperand const *Int16_Class::operator+(IOperand const &rhs) const
{
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    int val_3 = static_cast<int>(std::stoi(this->_value));
    int val_4 = static_cast<int>(std::stoi(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() < 3) ?
        core_engine.createOperand(this->getType(), std::to_string(val_3 + val_4)) : 
            core_engine.createOperand(this->getType(), std::to_string((val_1 + val_2)));

    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

IOperand const *Int16_Class::operator-(IOperand const &rhs) const
{
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    int val_3 = static_cast<int>(std::stoi(this->_value));
    int val_4 = static_cast<int>(std::stoi(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() < 3) ?
        core_engine.createOperand(this->getType(), std::to_string(val_3 - val_4)) : 
            core_engine.createOperand(this->getType(), std::to_string((val_1 - val_2)));

    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

IOperand const *Int16_Class::operator*(IOperand const &rhs) const
{
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    int val_3 = static_cast<int>(std::stoi(this->_value));
    int val_4 = static_cast<int>(std::stoi(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() < 3) ?
        core_engine.createOperand(this->getType(), std::to_string(val_3 * val_4)) : 
            core_engine.createOperand(this->getType(), std::to_string((val_1 * val_2)));

    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

IOperand const *Int16_Class::operator/(IOperand const &rhs) const
{
    double val_1 = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if (val_1 == static_cast<double>(0))
    {
        throw ErrorDetails::DivideByZero();
    }

    CoreEngine core_engine;
    int val_3 = static_cast<int>(std::stoi(this->_value));
    int val_4 = static_cast<int>(std::stoi(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() < 3) ?
        core_engine.createOperand(this->getType(), std::to_string(val_3 / val_4)) : 
            core_engine.createOperand(this->getType(), std::to_string((val_1 / val_2)));

    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

IOperand const *Int16_Class::operator%(IOperand const &rhs) const
{
    double val_1 = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if (val_1 == static_cast<double>(0))
    {
        throw ErrorDetails::DivideByZero();
    }

    CoreEngine core_engine;
    int val_3 = static_cast<int>(std::stoi(this->_value));
    int val_4 = static_cast<int>(std::stoi(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() < 3) ?
        core_engine.createOperand(this->getType(), std::to_string(fmod(val_3, val_4))) : 
            core_engine.createOperand(this->getType(), std::to_string(fmod(val_1, val_2)));

    CheckFlow *c_flow = new CheckFlow(operand_obj);
    core_engine.ft_push(operand_obj);
    delete c_flow;
    return operand_obj;
}

const std::string   &Int16_Class::toString(void) const { return this->_value; }