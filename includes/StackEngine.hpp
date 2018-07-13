/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:33:29 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/13 15:09:14 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ENGINE_HPP
#define STACK_ENGINE_HPP
#include <map>
#include "FileEngine.hpp"
#include "CoreEngine.hpp"
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


    public:
        StackEngine(void);
        StackEngine(std::vector<std::vector<std::string> > line);
        StackEngine(StackEngine const &src);
        StackEngine &operator=(StackEngine const &rhs);
        ~StackEngine(void);

        void    Stack_Brain(std::vector<std::vector<std::string> > line);

        eOperandType createEnumValue(std::string dataType);
};

#endif