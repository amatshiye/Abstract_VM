/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:52:10 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/15 17:32:22 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ErrorEngine.hpp"
#include "../includes/FileEngine.hpp"

ErrorEngine::ErrorEngine(void)
{
    this->_error_message = "";
    this->_line = "";
    this->_exit = false;
    this->_words = 0;
}

ErrorEngine::ErrorEngine(std::string line, int words, int l_num)
{
    this->_line = line;
    this->_exit = false;
    this->_words = words;
    this->_l_num = l_num - 1;

    this->ISplit(this->_line, this->_words);
    this->exception_core();
}

ErrorEngine::ErrorEngine(const ErrorEngine &src)
{
    *this = src;
}

ErrorEngine::~ErrorEngine(void)
{
}

void    ErrorEngine::exception_core() throw()
{
    //call other error handling functions
    if (this->_exit)
        std::cout << this->getErrorMessage() << std::endl;
}

void   ErrorEngine::check_exit()
{
    if (this->_line == "exit")
    {
        this->_exit = true;
    }
}

//deal with the fucken spaces man
bool    ErrorEngine::check_stack()
{
    //check if stack is not greater than 2;
    return false;
}

bool    ErrorEngine::is_stack_empty()
{
    //check if stack is empty
    return false;
}

std::string ErrorEngine::getErrorMessage()
{
    return this->_error_message;
}

//Function to split the instruction per line
void    ErrorEngine::ISplit(std::string line, int words)
{
    //vector size
    std::vector<std::string> tokens;
    std::vector<std::string> instruction;

    FileEngine f_engine;
    std::string opCode;
    std::string dataType;
    std::string value;

    if (words == 1)
    {
        opCode = f_engine.removeSpace(line);
        instruction.push_back(opCode);
    }
    else if (words == 2)
    {
        //getting opcode
        tokens = f_engine.ft_strplit(line, " ");
        std::string temp = tokens.at(1);
        opCode = f_engine.removeSpace(tokens.at(0));
        instruction.push_back(opCode);

        //getting data type
        //reason why the vector is funcking up ;)
        tokens = f_engine.ft_strplit(tokens.at(1), "(");
        dataType = f_engine.removeSpace(tokens.at(0));
        instruction.push_back(dataType);

        //getting value
        temp = temp.substr(dataType.length() + 1, temp.length());
        tokens = f_engine.ft_strplit(temp, ")");
        value = tokens.at(0);
        instruction.push_back(value);
    }
    else if (words > 2)
    {
        // throw an exception if shit went down
        throw ErrorDetails::MultipleInstructions();
    }

    if (instruction.size() > 0)
    {
        this->parseInstruction(instruction);
    }
    //return instruction;
}

void    ErrorEngine::parseInstruction(std::vector<std::string> instruction)
{
    // //check if opcode is valid
    if (instruction.size())
    {
        FileEngine f_engine;
        std::string opCodes[11] = {"pop", "dump", "add", "sub", "mul", "div", "mod", 
                                    "print", "exit", "push", "assert"};

        std::string dataTypes[5] = {"int8", "int16", "int32", "float", "double"};

        if (!f_engine.in_array(instruction.at(0), opCodes, 11))
        {
            throw ErrorDetails::InvalidInstruction();
        }
        else if (instruction.size() == 3)
        {
            if (!f_engine.in_array(instruction.at(1), dataTypes, 10))
            {
                throw ErrorDetails::InvalidInstruction();
            }
            else
            {
                std::string opCode = instruction.at(0);
                std::string dataType = instruction.at(1);
                std::string value = instruction.at(2);

                if (value.length())
                {
                    if (isConvertable(value, dataType))
                    {
                        if (dataType == "int8")
                        {
                            convertToINT8(value);
                        }
                        else if (dataType == "int16")
                        {
                            convertToINT16(value);
                        }
                        else if (dataType == "int32")
                        {
                            convertToINT32(value);
                        }
                        else if (dataType == "float")
                        {
                            convertToFLOAT(value);
                        }
                        else if (dataType == "double")
                        {
                            convertToDOUBLE(value);
                        }
                        else
                        {
                            throw ErrorDetails::InvalidInstruction();
                        }
                    }
                    else
                    {
                        //std::cout << "We found the bug" << std::endl;
                        throw ErrorDetails::UnableToConvert();
                    }
                    //store var will be called here
                    if (instruction.size() == 3)
                    {
                        this->_store.push_back(opCode);
                        this->_store.push_back(dataType);
                        this->_store.push_back(value);
                    }
                }
                else
                {
                    throw ErrorDetails::ValueNotFound();
                }
            }
        }
        //add the opcode here
        if (instruction.size() == 1)
        {
            this->_store.push_back(instruction.at(0));
        }
    }
}

std::vector<std::string>    ErrorEngine::getIns()
{
    return this->_store;
}

//checking if value is convertable 

bool    ErrorEngine::isConvertable(std::string value, std::string &dataType)
{
    if ((dataType == "int8") || (dataType == "int16") 
        || (dataType == "int32"))
    {
        try
        {
            int x = std::stod(value);
            if (x == 0)
                x++;
            if (x)
                return true;
        }
        catch(std::exception e)
        {
            return false;
        }
    }
    else if (dataType == "float")
    {
        try
        {
            int x = std::stof(value);
            if (x == 0)
                x++;
            if (x)
                return true;
        }
        catch(std::exception e)
        {
            return false;
        }
    }
    else if (dataType == "double")
    {
        try
        {
            int x = std::stod(value);
            if (x == 0)
                x++;
            if (x)
                return true;
        }
        catch(std::exception e)
        {
            return false;
        }
    }
    return false;
}

//converting to int8

void    ErrorEngine::convertToINT8(std::string value)
{
    int c_value;

    try
    {
        c_value = std::stoi(value);
    }
    catch(std::exception e)
    {
        e.what();
        (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
            ErrorDetails::OverFlow();
    }


    if (c_value > std::numeric_limits<int8_t>::max())
    {
       throw ErrorDetails::OverFlow();
    }
    else if (c_value < std::numeric_limits<int8_t>::min())
    {
        throw ErrorDetails::UnderFlow();
    }
}

//converting to int16

void    ErrorEngine::convertToINT16(std::string value)
{
    int c_value;

    try
    {
        c_value = std::stoi(value);
    }
    catch(std::exception e)
    {
        e.what();
        (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
            ErrorDetails::OverFlow();
    }

    if (c_value > std::numeric_limits<int16_t>::max())
    {
        throw ErrorDetails::OverFlow();
    }
    else if (c_value < std::numeric_limits<int16_t>::min())
    {
        throw ErrorDetails::UnderFlow();
    }
}

//converting to int32

void    ErrorEngine::convertToINT32(std::string value)
{
    int32_t c_value;

    try
    {
        c_value = std::stoi(value);
    }
    catch(std::exception e)
    {
        e.what();
        (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
            ErrorDetails::OverFlow();
    }


    if (c_value > std::numeric_limits<int32_t>::max())
    {
        throw ErrorDetails::OverFlow();
    }
    else if (c_value < std::numeric_limits<int32_t>::min())
    {
        throw ErrorDetails::UnderFlow();
    }
}

//converting to float

void    ErrorEngine::convertToFLOAT(std::string value)
{
    float r_value;

    try
    {
        r_value = std::stof(value);
    }
    catch(std::exception e)
    {
        e.what();
        (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
            ErrorDetails::OverFlow();
    }

    if (r_value > std::numeric_limits<float>::max())
    {
        throw ErrorDetails::OverFlow();
    }
    else if (r_value < std::numeric_limits<float>::min())
    {
        throw ErrorDetails::UnderFlow();
    }
}

//converting to double

void    ErrorEngine::convertToDOUBLE(std::string value)
{
    double  r_value;

    try
    {
        r_value = std::stof(value);
    }
    catch(std::exception e)
    {
        e.what();
        (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
            ErrorDetails::OverFlow();
    }

    if (r_value > std::numeric_limits<double>::max())
    {
        throw ErrorDetails::OverFlow();
    }
    else if (r_value < std::numeric_limits<double>::min())
    {
        throw ErrorDetails::UnderFlow();
    }
}