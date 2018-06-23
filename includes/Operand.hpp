/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 08:33:12 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/23 19:58:12 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"

//subclass of IOperand

class Operand : public IOperand
{
    private:

    public:
        Operand();
        ~Operand();
        
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
        //data types
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;

        //from the IOpernad class
        int getPrecision(void) const;
        eOperandType getType(void) const;

        //Operators from the IOperand class
        IOperand const *operator+(IOperand const &rhs) const;
        IOperand const *operator-(IOperand const &rhs) const;
        IOperand const *operator*(IOperand const &rhs) const;
        IOperand const *operator/(IOperand const &rhs) const;
        IOperand const *operator%(IOperand const &rhs) const;

        //String representation of the instance ::IOPerand class
        std::string const &toString(void) const;

};

#endif