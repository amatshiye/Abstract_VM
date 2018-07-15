/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckFlow.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:21:22 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/15 09:12:00 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CheckFlow.hpp"

CheckFlow::CheckFlow() {}

CheckFlow::CheckFlow(IOperand const * operand) 
{ 
    isFlow(operand->toString(), operand->getType());
}

CheckFlow::~CheckFlow() {}

CheckFlow::CheckFlow(CheckFlow const &rhs) { *this = rhs; }

CheckFlow & CheckFlow::operator=(CheckFlow const &rhs)
{
    (void)rhs; 
    return *this; 
}

void    CheckFlow::isFlow(std::string value, eOperandType type)
{
    //checking value overflow and underflow
    if (type == Int8)
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
            (value[0] == '-') ? e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than INT8_MIN") :
                e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than INT8_MAX");
            throw e_;
        }

        ErrorDetails e;
        if (c_value > std::numeric_limits<int8_t>::max())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than INT8_MAX");
            throw e;
        }
        else if (c_value < std::numeric_limits<int8_t>::min())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than INT8_MIN");
            throw e;
        }
    }
    else if (type == Int16)
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
            (value[0] == '-') ? e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than INT16_MIN") :
                e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than INT16_MAX");
            throw e_;
        }

        ErrorDetails e;
        if (c_value > std::numeric_limits<int16_t>::max())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than INT16_MAX");
            throw e;
        }
        else if (c_value < std::numeric_limits<int16_t>::min())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than INT16_MIN");
            throw e;
        }
    }
    else if (type == Int32)
    {
        int32_t c_value;

        try
        {
            c_value = std::stoi(value);
        }
        catch(std::exception e)
        {
            e.what();
            ErrorDetails e_;
            (value[0] == '-') ? e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than INT32_MIN") :
                e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than INT32_MAX");
            throw e_;
        }

        ErrorDetails e;

        if (c_value > std::numeric_limits<int32_t>::max())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than INT32_MAX");
            throw e;
        }
        else if (c_value < std::numeric_limits<int32_t>::min())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than INT32_MIN");
            throw e;
        }
    }
    else if (type == Float)
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
            (value[0] == '-') ? e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than FLOAT_MIN") :
                e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than FLOAT_MAX");
            throw e_;
        }

        ErrorDetails e;

        if (r_value > std::numeric_limits<float>::max())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than FLOAT_MAX");
            throw e;
        }
        else if (r_value < std::numeric_limits<float>::min())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than FLOAT_MIN");
            throw e;
        }
    }
    else if (type == Double)
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
            (value[0] == '-') ? e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than DOUBLE_MIN") :
                e_.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than DOUBLE_MAX");
            throw e_;
        }

        ErrorDetails e;

        if (r_value > std::numeric_limits<double>::max())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is greather than DOUBLE_MAX");
            throw e;
        }
        else if (r_value < std::numeric_limits<double>::min())
        {
            e.setErrorMsg("\033[1;31mError\033[0m: (" + value + ") is less than DOUBLE_MIN");
            throw e;
        }
    }
}