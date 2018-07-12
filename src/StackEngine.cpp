/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:34:21 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/12 08:45:58 by amatshiy         ###   ########.fr       */
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

    //for getting data type
    this->r_value[Int8] = "Int8";
    this->r_value[Int16] = "Int16";
    this->r_value[Int32] = "Int32";
    this->r_value[Float] = "Float";
    this->r_value[Double] = "Double";

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

    for (size_t x = 0; x < this->_line_size; x++)
    {
        if (line[x].size() == 3)
        {
            this->_value = line[x].at(2);
            this->_dataType = line[x].at(1);
            this->opCode = line[x].at(0);
            
            //generating type
            this->_type = this->createEnumValue(this->_dataType);
            createOperand(this->_type, this->_value);
        }
        else if (line[x].size() == 1)
        {   
            this->opCode = line[x].at(0);
        }
        
               
        if (this->opCode == "push")
        {
            operand = createOperand(this->_type, this->_value);
            this->ft_push(operand);
        }
        if (this->opCode == "dump")
        {
            this->ft_dump();
        }
        if (this->opCode == "pop")
        {
            this->ft_pop();
        }
        else if (this->opCode == "assert")
        {
            this->ft_assert(this->_value);
        }
        else if (this->opCode == "print")
        {
            this->ft_print();
        }
        else if (this->opCode == "add")
        {
            this->ft_add();
        }
    }
    delete operand;
}

StackEngine::~StackEngine()
{
    std::cout << "StackEngine destroyed" << std::endl;
}

eOperandType    StackEngine::createEnumValue(std::string dataType)
{
    //returns enum value Int8, Int16, Int32, Float or Double
    this->_type = this->enum_value[dataType];
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
    return this->r_value[type];
}

void    StackEngine::ft_assert(std::string value)
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

void    StackEngine::ft_push(IOperand const *operand)
{
    //inserting data at the back
    std::vector<const IOperand*>::iterator data;
    data = this->_Stack.begin();

    this->_Stack.insert(data, operand);
}

void    StackEngine::ft_pop()
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

void    StackEngine::ft_dump()
{
    //dumping the data in the stack
    for (size_t x = 0; x != this->_Stack.size(); x++)
    {
        if (this->_Stack[x]->toString() != "")
            std::cout << "DUMP: " << this->_Stack[x]->toString() << std::endl;
    }
}

void    StackEngine::ft_print()
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

void    StackEngine::ft_add()
{
    if (this->_Stack.size() >= 2)
    {
        IOperand const *operand_1 = this->_Stack[0];
        IOperand const *operand_2 = this->_Stack[1];

        IOperand const *operand_sum = *operand_1 + *operand_2;

        //removing the firts two values from the stack
        this->ft_pop();
        this->ft_pop();

        //add new operand to the stack
        this->ft_push(createOperand(operand_sum->getType(), operand_sum->toString()));
    }
    else
    {
        ErrorDetails e("\033[1;31mError\033[0m: Unable to add. Stack has less than 2 values");
        throw e;
    }
}