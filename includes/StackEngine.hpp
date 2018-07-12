/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:33:29 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/12 08:48:56 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ENGINE_HPP
#define STACK_ENGINE_HPP
#include <map>
#include "FileEngine.hpp"
#include "int8.class.hpp"
#include "int16.class.hpp"
#include "int32.class.hpp"
#include "Float.class.hpp"
#include "Double.class.hpp"

class StackEngine
{
    private:
        std::vector<const IOperand*>   _Stack;
        std::vector<std::vector<std::string> > _line;
        std::string opCode;
        std::string _dataType;
        std::string _value;
        size_t _line_size;
        eOperandType _type;

        IOperand const * createInt8( std::string const & value ) const;

    public:
        StackEngine(void);
        StackEngine(std::vector<std::vector<std::string> > line);
        StackEngine(StackEngine const &src);
        StackEngine &operator=(StackEngine const &rhs);
        ~StackEngine(void);

        void    Stack_Brain(std::vector<std::vector<std::string> > line);

        //Stack commands 
        void    ft_assert(std::string value);
        void    ft_push(IOperand const *operand);
        void    ft_pop();
        void    ft_dump();
        void    ft_print();
        void    ft_add();
        void    ft_sub();
        std::map<eOperandType, IOperand const *(StackEngine::*)(std::string const & value) const> create;
        std::map<eOperandType, std::string> r_value;
        std::map<std::string, eOperandType> enum_value;

        std::string getDataType(eOperandType type);
        size_t  getLineSize();
        eOperandType createEnumValue(std::string dataType);
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

#endif