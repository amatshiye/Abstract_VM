/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:34:21 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 12:04:53 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/StackEngine.hpp"

StackEngine::StackEngine(void)
{
    std::cout << "Stack Engine default constructor called" << std::endl;
    this->_dataType = "";
    this->_value = "";
}

StackEngine::StackEngine(std::string dataType, std::string value)
{
    std::cout << "Stack Engine custom constructor called" << std::endl;
    this->_dataType = dataType;
    this->_value = value;

    //generating type
    this->_type = this->createEnumValue(dataType);
    createOperand(this->_type, this->_value);

    /*IOperand const *operand = */createOperand(this->_type, this->_value);
}

StackEngine::~StackEngine()
{
    std::cout << "StackEngine destroyed" << std::endl;
}

eOperandType    StackEngine::createEnumValue(std::string dataType)
{
    if (dataType.length())
    {
        if (dataType == "int8")
            return Int8;
        else if (dataType == "int16")
            return Int16;
        else if (dataType == "int32")
            return Int32;
        else if (dataType == "float")
            return Float;
        else if (dataType == "double")
            return Double;
    }
    return this->_type;
}

IOperand const * StackEngine::createOperand(eOperandType type, std::string const & value) const
{
    //Implement the factory here
    IOperand * operand = NULL;

    if (value.length())
    {
        switch (type)
        {
            case Int8:
                operand = new Int8_Class();
                break;
            case Int16:
                operand = new Int16_Class();
                break;
            case Int32:
                operand = new Int32_Class();
                break;
            case Float:
                operand = new Float_Class();
                break;
            case Double:
                operand = new Double_Class();
                break;
            default:
                ErrorDetails e_details("Error: Program died");
                throw e_details;
        }
    }
    return operand;
}