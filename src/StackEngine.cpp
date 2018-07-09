/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:34:21 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/09 08:23:11 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/StackEngine.hpp"

StackEngine::StackEngine(void)
{
    this->_dataType = "";
    this->_value = "";
    this->counter = 0;
    this->head = NULL;
    this->tail = NULL;
}

StackEngine::StackEngine(std::vector<std::vector<std::string> > line)
{
    this->_line = line;
    this->_line_size = line.size();
    this->counter = 0;
    this->head = NULL;
    this->tail = NULL;

    Stack_Brain(line);
}

void    StackEngine::Stack_Brain(std::vector<std::vector<std::string> > line)
{
    IOperand const *operand;

    for (size_t x = 0; x < this->_line_size; x++)
    {
        std::cout << "Times: " << this->counter << std::endl;
        this->counter++;
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
        
        std::cout << "****OPCODE BEFORE STACK**** :" << this->opCode << std::endl;        
        if (this->opCode == "push")
        {
            std::cout << "****OPCODE TO STACK*****: " << this->opCode << std::endl;
            operand = createOperand(this->_type, this->_value);
            this->push_back(operand);
            this->opCode = "";
        }
        else if (this->opCode == "dump")
        {
            this->dump();
        }
    }
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
    IOperand * operand = NULL;

    if (this->opCode == "push")
    {
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
    }
    return operand;
}

void    StackEngine::push_back(IOperand const *operand)
{
    //inserting data at the back
    Stack   *temp = new Stack;

    temp->data = operand;
    temp->next = NULL;

    if (this->head == NULL)
    {
        this->head = temp;
        this->tail = temp;
        temp = NULL;
    }
    else
    {
        this->tail->next = temp;
        this->tail = temp;
    }
}

void    StackEngine::dump()
{
    std::cout << "========dump=======" << std::endl;
    //dumping the data in the stack
    Stack   *temp = new Stack;

    temp = this->head;
    while (temp != NULL)
    {
        std::cout << "DUMPED VALUE: " << temp->data->toString() << std::endl;
        temp = temp->next; 
    }
    std::cout << "========dump end=======" << std::endl;
}