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

ErrorEngine::ErrorEngine(void)
{
    this->_error_message = nullptr;
}

ErrorEngine::ErrorEngine(std::vector<std::string> fileData)
{
    std::cout << "Error Engine called" << std::endl;
    this->_fileData = fileData;
    exception_core();
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
    if (check_exit() == false)
        std::cout << this->getErrorMessage() << std::endl;
    std::cout << check_exit() << std::endl;
}

bool   ErrorEngine::check_exit()
{
    std::vector<std::string>::iterator x;

    for (x = this->_fileData.begin(); x != this->_fileData.end(); x++)
    {
        if (*x == "exit")
        {
            return true;
        }
    }
    this->_error_message = "Error_: Missing exit command.";
    return false;
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