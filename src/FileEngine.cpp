/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:33:50 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/24 10:49:28 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileEngine.hpp"

FileEngine::FileEngine () {}

FileEngine::FileEngine (std::string fileName)
{
    this->_fileName = fileName;
    this->_exit_found = false;
}

FileEngine::~FileEngine()
{
}

std::string FileEngine::getFileName()
{
    return this->_fileName;
}

//copy constructor
FileEngine::FileEngine(const FileEngine &src)
{
    *this = src;
}

FileEngine &FileEngine::operator=(const FileEngine &rhs)
{
    this->_fileData = rhs._fileData;
    this->_fileName = rhs._fileName;
    return *this;
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
       exit(1);
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
    this->getData();
    if (!this->_exit_found)
    {
        this->_error_msg = "Error: Missing an exit";
    }
    return  this->_fileData;
}