/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorDetails.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:11:36 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/15 18:05:09 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_EXCEPTION
#define ERROR_EXCEPTION

#include <exception>

struct  ErrorDetails
{
    struct  StackEmpty : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  DivideByZero : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  InvalidInstruction : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  OverFlow : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  UnderFlow : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  AssertIsFalse : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  NotAnInt8Type : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  MissingExit : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  UnkownSyntax : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  FileNotFound : public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  MultipleInstructions: public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  UnableToConvert: public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  ValueNotFound: public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  UnableToDisplay: public std::exception { char const * what(void) const _NOEXCEPT; };
    struct  ZeroInstructions: public std::exception { char const * what(void) const _NOEXCEPT; };
};

#endif