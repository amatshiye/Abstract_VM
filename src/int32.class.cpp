/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int32.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:52:03 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/15 07:21:14 by amatshiy         ###   ########.fr       */
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

int Int32_Class::getPrecision() const { return Int32; }

eOperandType    Int32_Class::getType(void) const { return Int32; }

IOperand const *Int32_Class::operator+(IOperand const &rhs) const
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

IOperand const *Int32_Class::operator-(IOperand const &rhs) const
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

IOperand const *Int32_Class::operator*(IOperand const &rhs) const
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

IOperand const *Int32_Class::operator/(IOperand const &rhs) const
{
    double val_1 = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if (val_1 == static_cast<double>(0))
    {
        ErrorDetails e("\033[1;31mError\033[0m: You can't divide by zero");
        throw e;
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

IOperand const *Int32_Class::operator%(IOperand const &rhs) const
{
    double val_1 = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if (val_1 == static_cast<double>(0))
    {
        ErrorDetails e("\033[1;31mError\033[0m: You can't divide by zero");
        throw e;
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

const std::string   &Int32_Class::toString(void) const { return this->_value; }