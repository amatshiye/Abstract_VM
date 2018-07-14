/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:21:44 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/14 17:50:10 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CoreEngine.hpp"

CoreEngine::CoreEngine() 
{
    this->create[Int8] = &CoreEngine::createInt8;
    this->create[Int16] = &CoreEngine::createInt16;
    this->create[Int32] = &CoreEngine::createInt32;
    this->create[Float] = &CoreEngine::createFloat;
    this->create[Double] = &CoreEngine::createDouble;

    //for getting data type
    this->r_value[Int8] = "int8";
    this->r_value[Int16] = "int16";
    this->r_value[Int32] = "int32";
    this->r_value[Float] = "float";
    this->r_value[Double] = "double";
}

CoreEngine::CoreEngine(std::vector<const IOperand *> &_Stack)
{
    //the values;
    this->_Stack = _Stack;

    //for the factory method
    this->create[Int8] = &CoreEngine::createInt8;
    this->create[Int16] = &CoreEngine::createInt16;
    this->create[Int32] = &CoreEngine::createInt32;
    this->create[Float] = &CoreEngine::createFloat;
    this->create[Double] = &CoreEngine::createDouble;

    //for getting data type
    this->r_value[Int8] = "int8";
    this->r_value[Int16] = "int16";
    this->r_value[Int32] = "int32";
    this->r_value[Float] = "float";
    this->r_value[Double] = "double";
}

CoreEngine::~CoreEngine(void) {}

CoreEngine::CoreEngine(CoreEngine const &src)
{
    *this = src;
}

CoreEngine  & CoreEngine::operator=(CoreEngine const & rhs)
{
    (void)rhs;
    return *this;
}

void    CoreEngine::setValues(std::vector<std::string> line)
{
    if (line.size() == 3)
    {
        this->_value = line.at(2);
        this->_dataType = line.at(1);
        this->_opCode = line.at(0);
    }
    else if (line.size() == 1)
    {
        this->_opCode = line.at(0);
    }
}

IOperand const * CoreEngine::createInt8(std::string const & value) const { return (new Int8_Class(value)); }

IOperand const * CoreEngine::createInt16(std::string const & value) const { return (new Int16_Class(value)); }

IOperand const * CoreEngine::createInt32(std::string const & value) const { return (new Int32_Class(value)); }

IOperand const * CoreEngine::createFloat(std::string const & value) const { return (new Float_Class(value)); }

IOperand const * CoreEngine::createDouble(std::string const & value) const { return (new Double_Class(value)); }

std::string CoreEngine::getDataType(eOperandType type)
{
    return this->r_value[type];
}

IOperand const *CoreEngine::createOperand(eOperandType type, std::string const & value) const
{
    //Implement the factory here
    IOperand const * (CoreEngine::*f)(std::string const & value) const;
    f = create.at(type);
    return ((*this.*f)(value));
}

void    CoreEngine::ft_push(IOperand const *operand)
{
    std::vector<const IOperand*>::iterator data;
    data = this->_Stack.begin();

    this->_Stack.insert(data, operand);
}

void    CoreEngine::ft_assert(std::string value)
{
    std::string type;

    if (this->_Stack.size() > 0)
    {
        //getting top value data type
        type = getDataType(this->_Stack[0]->getType());

        //asserting top value
        if (!(type == this->_dataType) || !(value == this->_Stack[0]->toString()))
        {
            ErrorDetails e("\033[1;31mError\033[0m: values are not the same");
            throw e;
        }
    }
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Stack is empty");
        throw e;
    }
}

void    CoreEngine::ft_pop()
{
    std::vector<const IOperand*>::iterator pos;
    pos = this->_Stack.begin();

    if (this->_Stack.size() > 0)
        this->_Stack.erase(pos);
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Unable to pop. Stack is empty");
        throw e;
    }
}

void    CoreEngine::ft_dump()
{
    //dumping the data in the stack
    for (size_t x = 0; x != this->_Stack.size(); x++)
    {
        if (this->_Stack[x]->toString() != "")
            std::cout << this->_Stack[x]->toString() << std::endl;
    }
}

void    CoreEngine::ft_print()
{
    if (!this->_Stack.empty())
    {
        if (!this->_Stack.empty() && this->_Stack[0]->getType() == 0)
        {
            int8_t v = static_cast<int8_t>(std::stoi(this->_Stack[0]->toString()));
            if (isprint(v))
                std::cout << v << std::endl;
            else
            {
                ErrorDetails e("\033[1;31mError\033[0m: Unable to print value");
                throw e;
            }
        }
        else
        {
            ErrorDetails e("\033[1;31mError\033[0m: Value is not an int8");
            throw e;
        }
    }
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Unable to print. Stack is empty");
        throw e;
    }
}

void    CoreEngine::ft_add()
{
    if (this->_Stack.size() >= 2)
    {
        IOperand const *operand_1 = this->_Stack[0];
        IOperand const *operand_2 = this->_Stack[1];

        //removing the firts two values from the stack
        this->ft_pop();
        this->ft_pop();

        IOperand const *operand_sum = *operand_1 + *operand_2;

        //add new operand to the stack
        this->ft_push(createOperand(operand_sum->getType(), operand_sum->toString()));
    }
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Unable to add. Stack has less than 2 values");
        throw e;
    }
}

void    CoreEngine::ft_sub()
{
    if (this->_Stack.size() >= 2)
    {
        IOperand const *operand_1 = this->_Stack[0];
        IOperand const *operand_2 = this->_Stack[1];

        IOperand const *operand_sum = *operand_1 - *operand_2;

        //removing the firts two values from the stack
        this->ft_pop();
        this->ft_pop();

        //add new operand to the stack
        this->ft_push(createOperand(operand_sum->getType(), operand_sum->toString()));
    }
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Unable to subtract. Stack has less than 2 values");
        throw e;
    }
}

void    CoreEngine::ft_div()
{
    if (this->_Stack.size() >= 2)
    {
        IOperand const *operand_1 = this->_Stack[0];
        IOperand const *operand_2 = this->_Stack[1];

        IOperand const *operand_sum = *operand_1 / *operand_2;

        //removing the firts two values from the stack
        this->ft_pop();
        this->ft_pop();

        //add new operand to the stack
        this->ft_push(createOperand(operand_sum->getType(), operand_sum->toString()));
    }
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Unable to divide. Stack has less than 2 values");
        throw e;
    }
}

void    CoreEngine::ft_mul()
{
    if (this->_Stack.size() >= 2)
    {
        IOperand const *operand_1 = this->_Stack[0];
        IOperand const *operand_2 = this->_Stack[1];

        IOperand const *operand_sum = *operand_1 * *operand_2;

        //removing the firts two values from the stack
        this->ft_pop();
        this->ft_pop();

        //add new operand to the stack
        this->ft_push(createOperand(operand_sum->getType(), operand_sum->toString()));
    }
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Unable to multiply. Stack has less than 2 values");
        throw e;
    }
}

void    CoreEngine::ft_mod()
{
    if (this->_Stack.size() >= 2)
    {
        IOperand const *operand_1 = this->_Stack[0];
        IOperand const *operand_2 = this->_Stack[1];

        IOperand const *operand_sum = *operand_1 % *operand_2;

        //removing the firts two values from the stack
        this->ft_pop();
        this->ft_pop();

        //add new operand to the stack
        this->ft_push(createOperand(operand_sum->getType(), operand_sum->toString()));
    }
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Unable to mod. Stack has less than 2 values");
        throw e;
    }
}