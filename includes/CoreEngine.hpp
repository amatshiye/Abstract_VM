/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:02:18 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 11:14:42 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_HPP
#define CORE_ENGINE_HPP

#include <map>
#include <regex>
#include "FileEngine.hpp"
#include "int8.class.hpp"
#include "int16.class.hpp"
#include "int32.class.hpp"
#include "Float.class.hpp"
#include "Double.class.hpp"
#include "StackEngine.hpp"
#include <cmath>

class CoreEngine
{
    private:
        std::string _opCode;
        std::string _dataType;
        std::string _value;
        std::vector<const IOperand*>   _Stack;
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;

    public:
        CoreEngine(void);
        CoreEngine(std::vector<const IOperand*> &_Stack);
        CoreEngine(CoreEngine const & src);
        ~CoreEngine(void);

        void    setValues(std::vector<std::string> line);
        CoreEngine const & operator=(CoreEngine const &rhs);
        std::string getDataType(eOperandType type);
        //Stack commands
        void    ft_push(IOperand const *operand);
        void    ft_assert(std::string value);
        void    ft_pop();
        void    ft_dump();
        void    ft_print();
        void    ft_add();
        void    ft_sub();
        void    ft_div();
        void    ft_mul();
        void    ft_mod();

        //maps .
        std::map<eOperandType, IOperand const *(CoreEngine::*)(std::string const & value) const> create;
        std::map<eOperandType, std::string> r_value;

        //factory method
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

#endif