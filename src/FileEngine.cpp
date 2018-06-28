/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:33:50 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/28 02:40:09 by amatshiy         ###   ########.fr       */
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
           line = removeSpace(line);
           if (line != "")
                this->_fileData.push_back(line);
            
       }
       ErrorEngine(this->_fileData);
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

std::string FileEngine::removeSpace(std::string line)
{
    //function to remove space at the beg and end.
    unsigned long beg_x = 0;

    if (line.length())
    {
        while (line.length() > beg_x)
        {
            if (isspace(line[beg_x]))
                beg_x++;
            else
                break;
        }
        line = line.substr(beg_x, line.length());

        unsigned long end_x = line.length();
        while (end_x > 0)
        {
            if (isspace(line[end_x]))
                end_x--;
            else
                break;
        }
        line = line.substr(0, end_x);

        //check spaces in the middle
        unsigned long x = 0;
        while (line.length() > x)
        {
            if (!isspace(line[x]))
                x++;
            else
            {
                while ((line[x + 1] != 0) && isspace(line[x + 1]))
                {
                    line.erase(x, 1);
                    x++;
                }
                break;
            }
        }
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