/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:33:50 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/23 12:51:50 by amatshiy         ###   ########.fr       */
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

void FileEngine::removeComments()
{
    
}

std::vector<std::string> FileEngine::getFileData()
{
    return  this->_fileData;
}