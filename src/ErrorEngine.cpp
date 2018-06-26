/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiye@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:52:10 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/26 16:31:09 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ErrorEngine.hpp"

ErrorEngine::ErrorEngine(void)
{
    this->_error_message = nullptr;
}

ErrorEngine::ErrorEngine(std::vector<std::string> fileData)
{
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
    if (!check_exit())
        throw what();
}

bool   ErrorEngine::check_exit()
{
    std::vector<std::string>::iterator x;

    for (x = this->_fileData.begin(); x != this->_fileData.end(); x++)
    {
        if (*x == "exit")
            return true;
    }
    return false;
}

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

const char *ErrorEngine::what() const throw()
{
    return "Error: No exit found";
}