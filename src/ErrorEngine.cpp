/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiye@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:52:10 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/26 14:34:07 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ErrorEngine.hpp"

ErrorEngine::ErrorEngine(void)
{
    this->_exit_found = false;
    this->_error_message = nullptr;
}

ErrorEngine::ErrorEngine(std::vector<std::string> fileData)
{
    this->_fileData = fileData;
    this->_exit_found = false;

    std::vector<std::string>::iterator x;
}

ErrorEngine::ErrorEngine(const ErrorEngine &src)
{
    *this = src;
}

ErrorEngine::~ErrorEngine(void) throw()
{
    std::cout << "ErrorEngine destructor called" << std::endl;
}

void ErrorEngine::check_exit()
{
    std::vector<std::string>::iterator x;

    for (x = this->_fileData.begin(); x != this->_fileData.end(); x++)
    {
        if (*x == "exit")
            this->_exit_found = true;
        else
            continue;
    }
}

void ErrorEngine::check_stack()
{
    //check if stack is not greater than 2;
}

void ErrorEngine::is_stack_empty()
{
    //check if stack is empty
}