/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:34:21 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/12 17:59:45 by amatshiy         ###   ########.fr       */
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

    //for getting enum value
    this->enum_value["Int8"] = Int8;
    this->enum_value["Int16"] = Int16;
    this->enum_value["Int32"] = Int32;
    this->enum_value["Float"] = Float;
    this->enum_value["Double"] = Double;

    Stack_Brain(line);
}

void    StackEngine::Stack_Brain(std::vector<std::vector<std::string> > line)
{
    IOperand const *operand;
    CoreEngine core_engine(this->_Stack);

    for (size_t x = 0; x < this->_line_size; x++)
    {
        if (line[x].size() == 3)
        {
            this->_value = line[x].at(2);
            this->_dataType = line[x].at(1);
            this->opCode = line[x].at(0);
            
            core_engine.setValues(line[x]);
            //generating type
            this->_type = this->createEnumValue(this->_dataType);
            core_engine.createOperand(this->_type, this->_value);
        }
        else if (line[x].size() == 1)
        {   
            this->opCode = line[x].at(0);
            core_engine.setValues(line[x]);
        }
        
               
        if (this->opCode == "push")
        {
            operand = core_engine.createOperand(this->_type, this->_value);
            core_engine.ft_push(operand);
        }
        if (this->opCode == "dump")
            core_engine.ft_dump();
        if (this->opCode == "pop")
            core_engine.ft_pop();
        else if (this->opCode == "assert")
            core_engine.ft_assert(this->_value);
        else if (this->opCode == "print")
            core_engine.ft_print();
        else if (this->opCode == "add")
            core_engine.ft_add();
        else if (this->opCode == "sub")
            core_engine.ft_sub();
        else if (this->opCode == "div")
            core_engine.ft_div();
    }
    delete operand;
}

StackEngine::~StackEngine() {}

eOperandType    StackEngine::createEnumValue(std::string dataType)
{
    //returns enum value Int8, Int16, Int32, Float or Double
    this->_type = this->enum_value[dataType];
    return this->_type;
}