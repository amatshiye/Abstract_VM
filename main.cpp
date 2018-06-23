/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 07:32:09 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/23 21:38:15 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/IOperand.hpp"
#include "includes/FileEngine.hpp"

int main(int ac, char **av)
{
    if (ac != 1)
    {
        if (av[1])
        {
            FileEngine * data = new FileEngine(av[1]);
            
            std::vector<std::string> vector_data = data->getFileData();
            std::vector<std::string>::iterator i;

            for (i = vector_data.begin(); i != vector_data.end(); i++)
                std::cout << "Line: " << *i << std::endl;
        }
        else
        {
            std::cout << "Another Bug!!!" << std::endl;
        }
    }
    else
    {
        std::cout << "Enter Instruction: " << std::endl;
        while (true)
        {
            //implement a way to get data from stdin
        }
    }

    return (0);
}