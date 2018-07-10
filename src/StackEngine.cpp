/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:34:21 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/10 09:27:21 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/StackEngine.hpp"

StackEngine::StackEngine(void)
{
    this->_dataType = "";
    this->_value = "";
}

StackEngine::StackEngine(std::vector<std::vector<std::string> > line)
{
    this->_line = line;
    this->_line_size = line.size();
    this->create[Int8] = &StackEngine::createInt8;

    Stack_Brain(line);
}

void    StackEngine::Stack_Brain(std::vector<std::vector<std::string> > line)
{
    IOperand const *operand;

    for (size_t x = 0; x < this->_line_size; x++)
    {
        if (line[x].size() == 3)
        {
            this->_value = line[x].at(2);
            this->_dataType = line[x].at(1);
            this->opCode = line[x].at(0);
        }
        else if (line[x].size() == 1)
        {   
            this->opCode = line[x].at(0);
        }
        
        //generating type
        this->_type = this->createEnumValue(this->_dataType);
        createOperand(this->_type, this->_value);
               
        if (this->opCode == "push")
        {
            operand = createOperand(this->_type, this->_value);
            this->push(operand);
        }
        else if (this->opCode == "dump")
        {
            this->dump();
        }
        else if (this->opCode == "pop")
        {
            this->pop();
        }
        else if (this->opCode == "assert")
        {
            this->assert(this->_value);
        }
        else if (this->opCode == "print")
        {
            this->print();
        }
    }
    delete operand;
    std::cout << "********************" << std::endl;
    std::cout << "STACK BRAIN COMPLETE" << std::endl;
    std::cout << "********************" << std::endl;
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

size_t  StackEngine::getLineSize()
{
    return this->_line_size;
}

IOperand const * StackEngine::createOperand(eOperandType type, std::string const & value) const
{
    //Implement the factory here
    IOperand const * (StackEngine::*f)(std::string const & value) const;
    f = create.at(type);
    
    return ((*this.*f)(value));
}

IOperand const * StackEngine::createInt8(std::string const & value) const
{
    return (new Int8_Class(value));
}

std::string StackEngine::getDataType(eOperandType type)
{
    std::string r_value;

    switch (type)
    {
        case Int8:
            r_value = "Int8";
            break;
        case Int16:
            r_value = "Int16";
            break;
        case Int32:
            r_value = "Int32";
            break;
        case Float:
            r_value = "Float";
            break;
        case Double:
            r_value = "Double";
            break;
    }
    return r_value;
}

void    StackEngine::assert(std::string value)
{
    std::string type;

    if (this->_Stack.size() > 0)
    {
        //getting top value data type
        type = getDataType(this->_Stack[0]->getType());
        //asserting top value
        if (!(type == this->_dataType) && !(value == this->_Stack[0]->toString()))
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

void    StackEngine::push(IOperand const *operand)
{
    //inserting data at the back
    std::vector<const IOperand*>::iterator data;
    data = this->_Stack.begin();

    this->_Stack.insert(data, operand);
}

void    StackEngine::pop()
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

void    StackEngine::dump()
{
    //dumping the data in the stack
    std::cout << "=========dump=========" << std::endl;

    for (size_t x = 0; x != this->_Stack.size(); x++)
    {
        if (this->_Stack[x]->toString() != "")
            std::cout << "DUMP: " << this->_Stack[x]->toString() << std::endl;
    }
    std::cout << "========dumpEnd=======" << std::endl;
}

void    StackEngine::print()
{
    if (this->_Stack.size() > 0)
    {
        if (this->_Stack[0]->getType() == 0)
        {
            int8_t v = static_cast<int8_t>(std::stoi(this->_Stack[0]->toString()));
            if (isprint(v))
                std::cout << "Print: " << v << std::endl;
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
}