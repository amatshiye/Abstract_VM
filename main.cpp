/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 07:32:09 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 09:37:26 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/IOperand.hpp"
#include "includes/FileEngine.hpp"

int main(int ac, char **av)
{
    std::cout << "=============================================" << std::endl;
    std::cout << "                 Abstract VM" << std::endl;
    std::cout << "=============================================" << std::endl;

    try
    {
        if (ac != 1)
        {
            if (av[1])
            {
                // throw ErrorEngine::what();
                FileEngine * data = new FileEngine(av[1]);
                data->getFileData();
                delete data;
            }
        }
        else
        {
            bool    isEmpty = false;
            std::string line;
            std::vector<std::string> lines;
            std::vector<std::string> temp;
            std::cout << "Enter Instructions: " << std::endl;
            FileEngine f_engine;
            while (true)
            {
                //implement a way to get data from stdin
                getline(std::cin, line);
                if (line == "")
                    continue;
                if (line.find(";;") != std::string::npos)
                {
                    if (lines.empty())
                    {
                        isEmpty = true;
                    }
                    temp = f_engine.ft_strplit(line, ";;");
                    if (temp.size() > 0)
                    {
                        // 
                        lines.push_back(temp[0]);
                    }
                    break;
                }
                else
                    lines.push_back(line);
            }
            if (isEmpty)
                std::cout << "\033[1;31mError\033[0m: No instructions found/Multiple/Invalid instruction were passed. Please input instructions" << std::endl;
            else
            {
                f_engine.getData(lines);
                std::cout << "============================================="<< std::endl;
            }
        }
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
