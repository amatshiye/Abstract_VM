/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiye@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:43:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/26 14:53:44 by amatshiy         ###   ########.fr       */
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
        std::string _exit_found;
        std::vector<std::string> _fileData;

    public:
        ErrorEngine(void);
        ErrorEngine(std::vector<std::string> fileData);
        ErrorEngine(ErrorEngine const &src);
        ~ErrorEngine() throw();

        //Error check functions
        void    check_exit();
        void    check_stack();
        void    is_stack_empty();
        
};

#endif