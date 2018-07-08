/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:34:21 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/08 18:12:21 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/StackEngine.hpp"

StackEngine::StackEngine(void)
{
    std::cout << "Stack Engine default constructor called" << std::endl;
    this->_dataType = "";
    this->_value = "";
    this->counter = 0;
}

StackEngine::StackEngine(std::vector<std::vector<std::string> > line)
{
    std::cout << "Stack Engine custom constructor called bro" << std::endl;
    this->_line = line;
    this->_line_size = line.size();
    this->counter = 0;

    Stack_Brain(line);
}

void    StackEngine::Stack_Brain(std::vector<std::vector<std::string> > line)
{
    this->counter++;

    std::cout << "Is it opcode: " << line.at(3).size() << std::endl;
    std::cout << "Times: " << this->counter << std::endl;


    std::cout << "Line opcode: " << line[2].at(0) << std::endl;
    for (size_t x = 0; x < this->_line_size; x++)
    {
        std::cout << "Line size: " + std::to_string(this->_line_size) << std::endl;
        if (line[x].size() == 3)
        {
            // std::cout << "Line size: " << line[x].size() << std::endl;
            // std::cout << "Stack_Brain datatype: " << line[x].at(0) + " " + line[x].at(1) + " " + line[x].at(2) << std::endl;
            // std::cout << line[x].at(0) << std::endl;

            this->_value = line[x].at(2);
            this->_dataType = line[x].at(1);
            this->opCode = line[x].at(0);
        }
        else if (line[x].size() == 1)
        {
            // std::cout << "Line size: " << line[x].size() << std::endl;
            // std::cout << "Stack_Brain opcode: " << line[x].at(0) << std::endl;
            // std::cout << line[x].at(0) << std::endl;
            
            this->opCode = line[x].at(0);
        }
        
        //generating type
        this->_type = this->createEnumValue(this->_dataType);
        createOperand(this->_type, this->_value);
        
        IOperand const *operand;
        
        operand = createOperand(this->_type, this->_value);
        Stack_Data data;
        if (this->opCode == "push")
        {
            data.push_back(operand);
        }
        else if (this->opCode == "dump")
        {
            data.dump();
        }
    }
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
    std::cout << "CreateOperand() called" << std::endl;
    IOperand * operand = NULL;

    if (value.length())
    {
        switch (type)
        {
            case Int8:
                operand = new Int8_Class(value);
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

//stack core/brain
StackEngine::Stack_Data::Stack_Data()
{
    std::cout << "Stack_Data() called" << std::endl;
    head = NULL;
    tail = NULL;
}

StackEngine::Stack_Data::Stack_Data(StackEngine::Stack_Data const &src)
{
    *this = src;
}

StackEngine::Stack_Data::~Stack_Data(void)
{
    std::cout << "Stack_Data destroyed" << std::endl;
}

void    StackEngine::Stack_Data::push_back(IOperand const *operand)
{
    //inserting data at the back
    std::cout << "Push back() function called" << std::endl;
    StackEngine s_engine;
    s_engine._stack = new Stack();

    s_engine._stack->data = operand;
    s_engine._stack->next = NULL;
    if (this->head == NULL)
    {
        this->head = s_engine._stack;
        this->tail = s_engine._stack;
        s_engine._stack = NULL;
    }
    else
    {
        s_engine._stack->next = s_engine._stack;
        this->tail = s_engine._stack;
    }
}

void    StackEngine::Stack_Data::dump()
{
    //dumping the data in the stack
    std::cout << "dump() function called" << std::endl;
    StackEngine s_engine;
    s_engine._stack = new Stack();

    s_engine._stack = this->head;
    std::cout << "===========================" << std::endl;
    while (s_engine._stack != NULL)
    {
        std::cout << "==========Loop of despair=================" << std::endl;

        std::cout << "Line Size: " << s_engine.getLineSize() << std::endl;
        std::cout << s_engine._stack->data->toString() << std::endl;
        s_engine._stack = s_engine._stack->next;
    }
}