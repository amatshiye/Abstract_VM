/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:34:21 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/09 12:13:42 by amatshiy         ###   ########.fr       */
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

    Stack_Brain(line);
}

void    StackEngine::Stack_Brain(std::vector<std::vector<std::string> > line)
{
    IOperand const *operand;

    std::cout << "=========push=========" << std::endl;
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
            std::cout << "PUSH: " << operand->toString() << std::endl;
            this->push_back(operand);
        }
        else if (this->opCode == "dump")
        {
            this->dump();
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
    this->_Stack.insert(this->_Stack.begin(), operand);
}

void    StackEngine::dump()
{
    //dumping the data in the stack
    std::cout << "=========dump=========" << std::endl;
    std::vector<IOperand>::iterator x;

    for (size_t x = 0; this->_Stack.size(); x++)
    {
        if (this->_Stack.at(x)->toString() != "")
            std::cout << "DUMP: " << this->_Stack.at(x)->toString() << std::endl;
    }
    std::cout << "========dumpEnd=======" << std::endl;
}