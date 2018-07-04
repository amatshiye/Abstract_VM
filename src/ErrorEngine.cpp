/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:52:10 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/30 23:02:15 by amatshiy         ###   ########.fr       */
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
        std::string opCodes[11] = {"pop", "dump", "add", "sub", "mul", "div", "mod", "print", "exit", "push", "assert"};
        std::string dataTypes[5] = {"int8", "int16", "int32", "float", "double"};

        if (!f_engine.in_array(instruction.at(0), opCodes, 11))
        {
            e.setErrorMsg("\033[1;31mError\033[0m: Invalid Opcode: " + instruction.at(0));
            throw e;
        }
        else if (instruction.size() == 3)
        {
            if (!f_engine.in_array(instruction.at(1), dataTypes, 5))
            {
                e.setErrorMsg("\033[1;31mError\033[0m: Invalid data type: " + instruction.at(1));
                throw e;
            }
        }
    }
}