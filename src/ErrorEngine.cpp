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
    std::cout << "Error Engine called" << std::endl;
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
    std::cout << "ErrorEngine destructor called" << std::endl;
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

//Exception details class
/*
ErrorEngine::ErrorDetails::ErrorDetails()
{
    
    this->_errorMsg = "";
}*/

//Function to split the instruction per line
std::vector<std::string> ErrorEngine::ISplit(std::string line, int words)
{
    //get the line
    //get the number of words in a line
    //words should be 1 or 2 per line
    //if words = 2 use strsplit
    //if 1 put it in the vector
    //vector size
    std::cout << "==================================" << std::endl;
    std::cout << "Line Value: " << line << std::endl;
    std::cout << "==================================" << std::endl;
    std::vector<std::string> tokens;
    std::vector<std::string> instruction;

    FileEngine f_engine;
    std::string opCode;
    std::string dataType;
    std::string value;

    if (words == 1 && line.length() != 0)
    {
        std::cout << "===========One word found==============" << std::endl;
        std::cout << "Line Word 1 Test: " << line << std::endl;
        opCode = f_engine.removeSpace(line);
        instruction.push_back(opCode);
        std::cout << "opCode: " << opCode << std::endl;
        std::cout << "================END====================" << std::endl;
    }
    else if (words == 2)
    {

        //getting opcode
        std::cout << "================1st Code====================" << std::endl;
        tokens = f_engine.ft_strplit(line, " ");
        std::string temp = tokens.at(1);
        opCode = f_engine.removeSpace(tokens.at(0));
        instruction.push_back(opCode);
        std::cout << "Opcode: " << opCode << std::endl;

        std::cout << "================2nd Code====================" << std::endl;
        //getting data type
        tokens = f_engine.ft_strplit(tokens.at(1), "(");
        dataType = f_engine.removeSpace(tokens.at(0));
        instruction.push_back(dataType);
        std::cout << "Token dataType: " << dataType << std::endl;

        //use find to get the position of the bracket
        //use substr

        std::cout << "================3rd Code====================" << std::endl;
        //getting value
        temp = temp.substr(dataType.length() + 1, temp.length());
        tokens = f_engine.ft_strplit(temp, ")");
        value = tokens.at(0);
        std::cout << "Value: " << value << std::endl;
    }
    return instruction;
}