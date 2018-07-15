/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorDetails.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:17:25 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/15 18:06:05 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ErrorDetails.hpp"

char const * ErrorDetails::StackEmpty::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Stack is empty or has less than 2 values."; }
char const * ErrorDetails::DivideByZero::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Can't divide by zero (0)"; }
char const * ErrorDetails::InvalidInstruction::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Instruction is Unknown"; }
char const * ErrorDetails::OverFlow::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Number is too big."; }
char const * ErrorDetails::UnderFlow::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Number is too small"; }
char const * ErrorDetails::AssertIsFalse::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Assert is false"; }
char const * ErrorDetails::NotAnInt8Type::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: The number is not an int8 data type"; }
char const * ErrorDetails::MissingExit::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Exit was not found"; }
char const * ErrorDetails::UnkownSyntax::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Syntax is invalid"; }
char const * ErrorDetails::FileNotFound::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Unable to find file"; }
char const * ErrorDetails::MultipleInstructions::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Multiple instructions found"; }
char const * ErrorDetails::UnableToConvert::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Value is not convertable"; }
char const * ErrorDetails::ValueNotFound::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: No value found"; }
char const * ErrorDetails::UnableToDisplay::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: No a displayable character"; }
char const * ErrorDetails::ZeroInstructions::what(void) const _NOEXCEPT { return "\033[1;31mError\033[0m: Only exit was found in the instruction list."; }