/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiye@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 07:32:09 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/26 16:33:48 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/IOperand.hpp"
#include "includes/FileEngine.hpp"

int main(int ac, char **av)
{
    std::cout << "=============================================" << std::endl;
    std::cout << "                 Abstract VM" << std::endl;
    std::cout << "=============================================" << std::endl;

    if (ac != 1)
    {
        if (av[1])
        {
            try
            {
                // throw ErrorEngine::what();
                FileEngine * data = new FileEngine(av[1]);
                
                data->getFileData();
                // std::vector<std::string> vector_data = data->getFileData();
                // std::vector<std::string>::iterator i;

                // std::cout << "Main print out: " << std::endl;
                // for (i = vector_data.begin(); i != vector_data.end(); i++)
                //     std::cout << "Line: " << *i << std::endl;
            }
            catch (ErrorDetails e)
            {
                std::cout << e.what() << std::endl;
            }
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