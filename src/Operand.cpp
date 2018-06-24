/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:19:26 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/24 11:40:23 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Operand.hpp"

template <typename T>
Operand<T>::Operand() {}

template <typename T>
Operand<T>::~Operand()
{
    std::cout << "Operand class destoryed" << std::endl;
}

template <typename T>
//create operand function
IOperand const *Operand<T>::createOperand(eOperandType type, std::string const & value ) const
{

}

//data types
template <typename T>
IOperand const *Operand<T>::createInt8( std::string const & value ) const
{
    
}

template <typename T>
IOperand const *Operand<T>::createInt16( std::string const & value ) const
{

}

template <typename T>
IOperand const *Operand<T>::createInt32( std::string const & value ) const
{

}

template <typename T>
IOperand const *Operand<T>::createFloat( std::string const & value ) const
{
    
}

template <typename T>
IOperand const *Operand<T>::createDouble( std::string const & value ) const
{
    
}