/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:52:10 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/27 23:14:53 by amatshiy         ###   ########.fr       */
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

    std::vector<std::string> tokens;
    FileEngine f_engine;

    std::string opCode;
    std::string dataType;
    std::string value;

    if (words == 1)
    {
        std::cout << "One word found" << std::endl;
    }
    else if (words == 2)
    {
        tokens = f_engine.ft_strplit(line, " ");
        //
        for (size_t i = 0; tokens.size() > i; i++)
        {
            std::cout << "Token " << i << ": " << tokens.at(i) << std::endl; 
        }
    }
    return tokens;
}