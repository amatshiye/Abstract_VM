/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:52:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/13 16:07:39 by amatshiy         ###   ########.fr       */
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

int Float_Class::getPrecision() const { return Float; }

eOperandType    Float_Class::getType(void) const { return Float; }

IOperand const *Float_Class::operator+(IOperand const &rhs) const
{
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    float val_3 = static_cast<float>(std::stof(this->_value));
    float val_4 = static_cast<float>(std::stof(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() > 3) ?
        core_engine.createOperand(this->getType(), std::to_string(val_3 + val_4)) : 
            core_engine.createOperand(this->getType(), std::to_string((val_1 + val_2)));

    core_engine.ft_push(operand_obj);
    return operand_obj;
}

IOperand const *Float_Class::operator-(IOperand const &rhs) const
{
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    float val_3 = static_cast<float>(std::stof(this->_value));
    float val_4 = static_cast<float>(std::stof(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() > 3) ?
        core_engine.createOperand(this->getType(), std::to_string(val_3 - val_4)) : 
            core_engine.createOperand(this->getType(), std::to_string((val_1 - val_2)));

    core_engine.ft_push(operand_obj);
    return operand_obj;
}


IOperand const *Float_Class::operator/(IOperand const &rhs) const
{
    double val_1 = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if ((val_1 == static_cast<double>(0)) || (val_2 == static_cast<double>(0)))
    {
        ErrorDetails e("\033[1;31mError\033[0m: You can't divide by zero");
        throw e;
    }

    CoreEngine core_engine;
    float val_3 = static_cast<float>(std::stof(this->_value));
    float val_4 = static_cast<float>(std::stof(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() > 3) ?
        core_engine.createOperand(this->getType(), std::to_string(val_3 / val_4)) : 
            core_engine.createOperand(this->getType(), std::to_string((val_1 / val_2)));

    core_engine.ft_push(operand_obj);
    return operand_obj;
}

IOperand const *Float_Class::operator*(IOperand const &rhs) const
{
    CoreEngine core_engine;
    double  val_1 = static_cast<double>(std::stod(this->_value));
    double  val_2 = static_cast<double>(std::stod(rhs.toString()));

    float val_3 = static_cast<float>(std::stof(this->_value));
    float val_4 = static_cast<float>(std::stof(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() > 3) ?
        core_engine.createOperand(this->getType(), std::to_string(val_3 * val_4)) : 
            core_engine.createOperand(this->getType(), std::to_string((val_1 * val_2)));

    core_engine.ft_push(operand_obj);
    return operand_obj;
}

IOperand const *Float_Class::operator%(IOperand const &rhs) const
{
    double val_1 = static_cast<double>(std::stod(rhs.toString()));
    double val_2 = static_cast<double>(std::stod(this->_value));
    
    if ((val_1 == static_cast<double>(0)) || (val_2 == static_cast<double>(0)))
    {
        ErrorDetails e("\033[1;31mError\033[0m: You can't divide by zero");
        throw e;
    }

    CoreEngine core_engine;
    float val_3 = static_cast<float>(std::stof(this->_value));
    float val_4 = static_cast<float>(std::stof(rhs.toString()));

    IOperand const * operand_obj = (rhs.getPrecision() > 3) ?
        core_engine.createOperand(this->getType(), std::to_string(fmod(val_3, val_4))) : 
            core_engine.createOperand(this->getType(), std::to_string(fmod(val_1, val_2)));

    core_engine.ft_push(operand_obj);
    return operand_obj;
}

const std::string   &Float_Class::toString(void) const { return this->_value; }