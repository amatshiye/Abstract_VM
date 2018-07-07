/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:33:29 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/07 09:43:27 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ENGINE_HPP
#define STACK_ENGINE_HPP

#include "FileEngine.hpp"
#include "int8.class.hpp"
#include "int16.class.hpp"
#include "int32.class.hpp"
#include "Float.class.hpp"
#include "Double.class.hpp"

class StackEngine
{
    private:
        std::vector<std::string>    _Stack;
        std::string _dataType;
        std::string _value;
        eOperandType _type;

    public:
        StackEngine(void);
        StackEngine(std::string dataType, std::string value);
        StackEngine(StackEngine const &src);
        StackEngine &operator=(StackEngine const &rhs);
        ~StackEngine(void);

        eOperandType createEnumValue(std::string dataType);
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

#endif