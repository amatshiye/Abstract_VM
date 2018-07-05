/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:43:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/04 10:10:36 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_ENGINE_HPP
#define ERROR_ENGINE_HPP

#include <vector>
#include <exception>
#include <stdint.h>
#include "IOperand.hpp"
#include "../includes/ErrorDetails.hpp"

class ErrorEngine
{
    private:
        std::string _error_message;
        std::string _line;
        bool    _exit;
        int     _words;

    public:
        ErrorEngine(void);
        ErrorEngine(std::string line, int words);
        ErrorEngine(ErrorEngine const &src);
        ~ErrorEngine();

        //Error check functions
        void    exception_core() throw();
        void    check_exit();
        bool    check_stack();
        bool    is_stack_empty();
        void    ISplit(std::string line, int words);
        void    parseInstruction(std::vector<std::string> instruction);

        //convertions to check underflow and overflow
        bool    isConvertable(std::string value, std::string dataType);
        int8_t  convertToINT8(std::string value);
        int16_t convertToINT16(std::string value);
        int32_t convertToINT32(std::string value);
        float   convertToFLOAT(std::string value);
        double  convertToDOUBLE(std::string value);

        //exception details
        std::string getErrorMessage();
};
#endif