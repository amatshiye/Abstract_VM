/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckFlow.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:21:22 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 10:05:00 by amatshiy         ###   ########.fr       */
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

void    CheckFlow::isFlow(std::string value, eOperandType type, int line_no)
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
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::UnderFlow();
        }

        if (c_value > std::numeric_limits<int8_t>::max())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            throw ErrorDetails::OverFlow();
        }
        else if (c_value < std::numeric_limits<int8_t>::min())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
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
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::OverFlow();
        }

        if (c_value > std::numeric_limits<int16_t>::max())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            throw ErrorDetails::OverFlow();
        }
        else if (c_value < std::numeric_limits<int16_t>::min())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
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
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::OverFlow();
        }

        if (c_value > std::numeric_limits<int32_t>::max())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            throw ErrorDetails::OverFlow();
        }
        else if (c_value < std::numeric_limits<int32_t>::min())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
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
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::OverFlow();
        }

        if (r_value > std::numeric_limits<float>::max())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            throw ErrorDetails::OverFlow();
        }
        else if (r_value < std::numeric_limits<float>::min())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
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
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            (value[0] == '-') ? throw ErrorDetails::UnderFlow() :
                throw ErrorDetails::OverFlow();
        }

        if (r_value > std::numeric_limits<double>::max())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            throw ErrorDetails::OverFlow();
        }
        else if (r_value < std::numeric_limits<double>::min())
        {
            std::cout << "Line: (" << line_no <<  "): " << "\033[1;31m(" << value << ")\033[0m" <<  std::endl;
            throw ErrorDetails::UnderFlow();
        }
    }
}