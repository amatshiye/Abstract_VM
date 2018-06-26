/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiye@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:43:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/26 16:27:17 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_ENGINE_HPP
#define ERROR_ENGINE_HPP

#include "IOperand.hpp"
#include <vector>
#include <exception>

class ErrorEngine : public std::exception
{
    private:
        std::string _error_message;
        std::vector<std::string> _fileData;

    public:
        ErrorEngine(void);
        ErrorEngine(std::vector<std::string> fileData);
        ErrorEngine(ErrorEngine const &src);
        ~ErrorEngine();

        //Error check functions
        void    exception_core() throw();
        bool    check_exit();
        bool    check_stack();
        bool    is_stack_empty();

        //exception details
        virtual const char * what() const throw();
        
};

#endif