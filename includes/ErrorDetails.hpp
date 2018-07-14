/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorDetails.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:11:36 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/04 10:29:19 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_EXCEPTION
#define ERROR_EXCEPTION

#include <exception>
#include <iostream>

class ErrorDetails : std::exception
{
    private:
        std::string _errorMsg;

    public:
        ErrorDetails(void);
        ErrorDetails(std::string errorMsg);
        ErrorDetails(ErrorDetails const &src);
        ~ErrorDetails(void) throw();

        ErrorDetails & operator=(ErrorDetails const &rhs);
        virtual const char * what() const throw();

        std::string getErrorMsg() const;
        void    setErrorMsg(std::string errorMsg);
};

#endif