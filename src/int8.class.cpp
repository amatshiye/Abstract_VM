/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:49:57 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/14 18:14:35 by amatshiy         ###   ########.fr       */
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

int Int8_Class::getPrecision() const { return Int8; }

eOperandType    Int8_Class::getType(void) const { return Int8; }

IOperand const *Int8_Class::operator+(IOperand const &rhs) const
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

IOperand const *Int8_Class::operator-(IOperand const &rhs) const
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

IOperand const *Int8_Class::operator*(IOperand const &rhs) const 
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

IOperand const *Int8_Class::operator/(IOperand const &rhs) const
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

IOperand const *Int8_Class::operator%(IOperand const &rhs) const
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

const std::string   &Int8_Class::toString(void) const { return this->_value; }