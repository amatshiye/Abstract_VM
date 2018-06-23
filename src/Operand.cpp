/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:19:26 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/23 14:10:41 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Operand.hpp"

Operand::Operand() {}

Operand::~Operand()
{
    std::cout << "Operand class destoryed" << std::endl;
}

//create operand function
IOperand const *Operand::createOperand(eOperandType type, std::string const & value ) const
{

}

//data types

IOperand const *Operand::createInt8( std::string const & value ) const
{
    
}

IOperand const *Operand::createInt16( std::string const & value ) const
{

}

IOperand const *Operand::createInt32( std::string const & value ) const
{

}

IOperand const *Operand::createFloat( std::string const & value ) const
{
    
}

IOperand const *Operand::createDouble( std::string const & value ) const
{
    
}