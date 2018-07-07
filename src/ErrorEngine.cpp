/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:52:10 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 14:42:22 by amatshiy         ###   ########.fr       */
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

ErrorEngine::ErrorEngine(std::string line, int words)
{
    this->_line = line;
    this->_exit = false;
    this->_words = words;

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
    ErrorDetails e;
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
        e.setErrorMsg("\033[1;31mError\033[0m: Multiple instructions in one line");
        throw e;
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
    ErrorDetails e;

    if (instruction.size())
    {
        FileEngine f_engine;
        std::string opCodes[11] = {"pop", "dump", "add", "sub", "mul", "div", "mod", 
                                    "print", "exit", "push", "assert"};

        std::string dataTypes[10] = {"int8", "int16", "int32", "float", "double", 
                                    "Int8", "Int16", "Int32", "Float", "Double"};

        if (!f_engine.in_array(instruction.at(0), opCodes, 11))
        {
            e.setErrorMsg("\033[1;31mError\033[0m: Invalid Opcode: " + instruction.at(0));
            throw e;
        }
        else if (instruction.size() == 3)
        {
            if (!f_engine.in_array(instruction.at(1), dataTypes, 10))
            {
                e.setErrorMsg("\033[1;31mError\033[0m: Invalid data type: " + instruction.at(1));
                throw e;
            }
            else
            {
                std::string dataType = instruction.at(1);
                std::string value = instruction.at(2);

                if (value.length())
                {
                    if (isConvertable(value, dataType))
                    {
                        if (dataType == "int8")
                        {
                            int8_t intValue = convertToINT8(value);
                            std::cout << "Int8: " << sizeof(intValue) << std::endl;
                        }
                        else if (dataType == "int16")
                        {
                            int16_t intValue = convertToINT16(value);
                            std::cout << "Int16: " << sizeof(intValue) << std::endl;
                        }
                        else if (dataType == "int32")
                        {
                            int32_t intValue = convertToINT32(value);
                            std::cout << "Int32: " << sizeof(intValue) << std::endl;
                        }
                        else if (dataType == "float")
                        {
                            float   floatValue = convertToFLOAT(value);
                            std::cout << "Float: " << sizeof(floatValue) << std::endl;
                        }
                        else if (dataType == "double")
                        {
                            double  doubleValue = convertToDOUBLE(value);
                            std::cout << "Double: " << sizeof(doubleValue) << std::endl;
                        }
                        else
                        {
                            ErrorDetails e_details("Error: Unknown Data type (" + dataType + ")");
                            throw e_details;
                        }
                    }
                    else
                    {
                        //std::cout << "We found the bug" << std::endl;
                        ErrorDetails e_details("Error: Unable to convert value.");
                        throw e_details;
                    }
                    //StackEngine() will be called here
                    StackEngine s_engine(dataType, value);
                }
                else
                {
                    ErrorDetails e_details("Error: No value found");
                    throw e_details;
                }
            }
        }
    }
}

//checking if value is convertable 

bool    ErrorEngine::isConvertable(std::string value, std::string &dataType)
{
    if (dataType == "int8" || dataType == "int16" || dataType == "int32")
    {
        try
        {
            int x = std::stoi(value);
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
            if (x)
                return true;
        }
        catch(std::exception e)
        {
            std::cout << "skidfgksdgf" << std::endl;
            return false;
        }
    }
    else if (dataType == "double")
    {
        try
        {
            int x = std::stod(value);
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

int8_t  ErrorEngine::convertToINT8(std::string value)
{
    int c_value;

    try
    {
        c_value = std::stoi(value);
    }
    catch(std::exception e)
    {
        e.what();
        ErrorDetails e_;
        if (value[0] == '-')
            e_.setErrorMsg("Error: (" + value + ") is less than INT8_MIN");
        else
            e_.setErrorMsg("Error: (" + value + ") is greather than INT8_MAX");
        throw e_;
    }


    int8_t r_value = static_cast<int8_t>(c_value);
    ErrorDetails e;

    if (c_value > std::numeric_limits<int8_t>::max())
    {
        e.setErrorMsg("Error: (" + value + ") is greather than INT8_MAX");
        throw e;
    }
    else if (c_value < std::numeric_limits<float>::min())
    {
        e.setErrorMsg("Error: (" + value + ") is less than INT8_MIN");
        throw e;
    }

    return r_value;
}

//converting to int16

int16_t ErrorEngine::convertToINT16(std::string value)
{
    int c_value;

    try
    {
        c_value = std::stoi(value);
    }
    catch(std::exception e)
    {
        e.what();
        ErrorDetails e_;
        if (value[0] == '-')
            e_.setErrorMsg("Error: (" + value + ") is less than INT16_MIN");
        else
            e_.setErrorMsg("Error: (" + value + ") is greather than INT16_MAX");
        throw e_;
    }

    int16_t r_value = static_cast<int16_t>(c_value);
    ErrorDetails e;

    if (c_value > std::numeric_limits<int16_t>::max())
    {
        e.setErrorMsg("Error: (" + value + ") is greather than INT16_MAX");
        throw e;
    }
    else if (c_value < std::numeric_limits<int16_t>::min())
    {
        e.setErrorMsg("Error: (" + value + ") is less than INT16_MIN");
        throw e;
    }

    return r_value;
}

//converting to int32

int32_t ErrorEngine::convertToINT32(std::string value)
{
    int c_value;

    try
    {
        c_value = std::stoi(value);
    }
    catch(std::exception e)
    {
        e.what();
        ErrorDetails e_;
        if (value[0] == '-')
            e_.setErrorMsg("Error: (" + value + ") is less than INT32_MIN");
        else
            e_.setErrorMsg("Error: (" + value + ") is greather than INT32_MAX");
        throw e_;
    }


    int r_value = static_cast<int32_t>(c_value);
    ErrorDetails e;

    if (c_value > std::numeric_limits<int32_t>::max())
    {
        e.setErrorMsg("Error: (" + value + ") is greather than INT32_MAX");
        throw e;
    }
    else if (c_value < std::numeric_limits<int32_t>::min())
    {
        e.setErrorMsg("Error: (" + value + ") is less than INT32_MIN");
        throw e;
    }

    return r_value;
}

//converting to float

float   ErrorEngine::convertToFLOAT(std::string value)
{
    float r_value;

    try
    {
        r_value = std::stof(value);
    }
    catch(std::exception e)
    {
        e.what();
        ErrorDetails e_;
        if (value[0] == '-')
            e_.setErrorMsg("Error: (" + value + ") is less than FLOAT_MIN");
        else
            e_.setErrorMsg("Error: (" + value + ") is greather than FLOAT_MAX");
        throw e_;
    }

    ErrorDetails e;

    if (r_value > std::numeric_limits<float>::max())
    {
        e.setErrorMsg("Error: (" + value + ") is greather than FLOAT_MAX");
        throw e;
    }
    else if (r_value < std::numeric_limits<float>::min())
    {
        e.setErrorMsg("Error: (" + value + ") is less than FLOAT_MIN");
        throw e;
    }

    return r_value;
}

//converting to double

double  ErrorEngine::convertToDOUBLE(std::string value)
{
    double  r_value;

    try
    {
        r_value = std::stof(value);
    }
    catch(std::exception e)
    {
        e.what();
        ErrorDetails e_;
        if (value[0] == '-')
            e_.setErrorMsg("Error: (" + value + ") is less than DOUBLE_MIN");
        else
            e_.setErrorMsg("Error: (" + value + ") is greather than DOUBLE_MAX");
        throw e_;
    }

    ErrorDetails e;

    if (r_value > std::numeric_limits<double>::max())
    {
        e.setErrorMsg("Error: (" + value + ") is greather than DOUBLE_MAX");
        throw e;
    }
    else if (r_value < std::numeric_limits<double>::min())
    {
        e.setErrorMsg("Error: (" + value + ") is less than DOUBLE_MIN");
        throw e;
    }

    return r_value;
}