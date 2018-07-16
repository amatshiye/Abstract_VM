/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:43:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 11:15:07 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_ENGINE_HPP
#define ERROR_ENGINE_HPP

#include <vector>
#include <exception>
#include <stdint.h>
#include <limits>
#include "IOperand.hpp"
#include "../includes/ErrorDetails.hpp"

class ErrorEngine
{
    private:
        std::string _error_message;
        std::string _line;
        bool    _exit;
        int     _words;
        int     _l_num;
        std::vector<std::string> _store;

    public:
        ErrorEngine(void);
        ErrorEngine(std::string line, int words, int l_num);
        ErrorEngine(ErrorEngine const &src);
        ~ErrorEngine();

        //Error check functions
        ErrorEngine const & operator=(ErrorEngine const &rhs);
        void    exception_core() throw();
        void    check_exit();
        bool    check_stack();
        bool    is_stack_empty();
        void    ISplit(std::string line, int words);
        void    parseInstruction(std::vector<std::string> instruction);
        std::vector<std::string>    getIns();

        //convertions to check underflow and overflow
        bool    isConvertable(std::string value, std::string &dataType);
        //exception details
        std::string getErrorMessage();
};
#endif