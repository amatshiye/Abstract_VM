/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckFlow.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:21:22 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/15 17:31:14 by amatshiy         ###   ########.fr       */
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
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::OverFlow();
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
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::UnderFlow();
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
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::OverFlow();
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
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::OverFlow();
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
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::OverFlow();
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
}