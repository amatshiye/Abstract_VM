/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorDetails.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:17:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/04 10:36:30 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ErrorDetails.hpp"

ErrorDetails::ErrorDetails()
{
    this->_errorMsg = "";
}

ErrorDetails::ErrorDetails(std::string errorMsg)
{
    this->_errorMsg = errorMsg;
}

ErrorDetails::ErrorDetails(ErrorDetails const &src)
{
    *this = src;
}

ErrorDetails::~ErrorDetails(void) throw()
{
    std::cout << "ErrorDetails object destroyed." << std::endl;
}

ErrorDetails & ErrorDetails::operator=(const ErrorDetails &rhs)
{
    this->_errorMsg = rhs._errorMsg;
    return *this;
}

const char  *ErrorDetails::what() const throw()
{
    const char * msg = this->getErrorMsg().c_str();
    return msg;
}

std::string ErrorDetails::getErrorMsg() const
{
    return this->_errorMsg;
}

void    ErrorDetails::setErrorMsg(std::string errorMsg)
{
    this->_errorMsg = errorMsg;
}