/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:33:50 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/23 14:04:43 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileEngine.hpp"

FileEngine::FileEngine () {}

FileEngine::FileEngine (std::string fileName)
{
    this->_fileName = fileName;
}

FileEngine::~FileEngine() {}

std::string FileEngine::getFileName()
{
    return this->_fileName;
}

void FileEngine::getData()
{
   std::ifstream file(this->getFileName());
   std::string  line;
   if (file.is_open())
   {
       while (!file.eof())
       {
           getline(file, line);
           line = removeComment(line);
           if (line != "")
                this->_fileData.push_back(line);
       }
       file.close();
   }
   else
   {
       //better error imp. needed.
       std::cout << "Error: Unable to open file." << std::endl;
   }
}

std::string FileEngine::removeComment(std::string line)
{
    //remove everything from the index of (;)
    const unsigned long pos = line.find(';'); //searches for the ; char
    
    if (pos != std::string::npos)
    {
        if (pos != 0)
        {
            line = line.substr(0, pos);
            return line;
        }
        else
            return "";
    }
        return line;
}

std::vector<std::string> FileEngine::getFileData()
{
    return  this->_fileData;
}