/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:33:50 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/30 22:38:06 by amatshiy         ###   ########.fr       */
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
       int x = 1;
       while (!file.eof())
       {
           getline(file, line);
           line = removeComment(line);
           line = removeSpace(line);
           checkInstruction(line);
           if (charParser(line))
           {
               std::cout << "Line: " << x << " :Syntax error" << std::endl;
           }
           if (line != "")
                this->_fileData.push_back(line);
            x++;
            ErrorEngine(line, this->getNumWords(line));
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
        {

            return "";
        }
    }
    return line;
}

std::string FileEngine::removeSpace(std::string line)
{
    //function to remove space at the beg and end.

    //removing spaces at the beg
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

        //removing spaces at the end
        unsigned long end_x = line.length();
        while (end_x > 0)
        {
            if (isspace(line[end_x]))
                end_x--;
            else
                break;
        }
        line = line.substr(0, end_x);
    }
    return line;
}

int    FileEngine::getNumWords(std::string line)
{
    //this is to get the number of words in a line
    bool space_found = false;
    int words_ = 1;

    unsigned long x = 0;
    while (line.length() > x)
    {
        if (isspace(line[x]))
            space_found = true;
        if (space_found)
        {
            space_found = false;
            for (unsigned long i = x; line.length() > i; i++)
            {
                if (!isspace(line[i]))
                {
                    words_++;
                    x = i;
                    break;
                }
            }
        }
        x++;
    }
    return (words_);
}

//checking instructions 
void    FileEngine::checkInstruction(std::string line)
{
    //validating instructions
    //get the line
    //check how many words the line has
    //split it if it has two
    std::string opCodes_single[9] = {"pop", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"};
    std::string opCode_multi[2] = {"push", "assert"};
    std::string temp;

    if (line.c_str())
    {
        if (this->getNumWords(line) == 1)
        {
            temp = removeSpace(line);
            if (temp.length() > 1)
            {
                if (in_array(line, opCodes_single, 9))
                    std::cout << line << ": " << "Opcode is valid" << std::endl;
                else
                    std::cout << line << ": " << "Invalid Opcode" << std::endl;
            }
        }
        else if (this->getNumWords(line) == 2)
        {
            temp = removeSpace(line);
            std::vector<std::string> tokens = this->ft_strplit(line, " ");

            if (in_array(tokens.at(0), opCode_multi, 2))
                std::cout << line << ": " << "Opcode is valid" << std::endl;
            else
                std::cout << line << ": " << "Invalid Opcode" << std::endl;
        }
        else
        {
            std::cout << "Error line: " << line  << std::endl;
        }
    }
}

//in_array function
bool    FileEngine::in_array(std::string value, std::string *array, int length)
{
    for (int x = 0; x < length; x++)
    {
        if (value.compare(array[x]) == 0)
            return true;
    }
    return false;
}

//string split in c++
std::vector<std::string> FileEngine::ft_strplit(std::string str, std::string delimiter)
{
    size_t pos;
    std::vector<std::string> tokens;

    str = str.append(" ");
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        tokens.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }
    return tokens;
}

//searches for unwanted chars in the instructions
bool    FileEngine::charParser(std::string line)
{
    if (line.c_str())
    {
        for (size_t x = 0; x < line.length(); x++)
        {
            if (line[x] == '.')
                continue;
            if (line[x] >= '!' && line[x] <= static_cast<char>(39))
                return true;
            else if (line[x] >= '*' && line[x] <= '/')
                return true;
            else if (line[x] >= ':' && line[x] <= '@')
                return true;
            else if (line[x] >= '[' && line[x] <= '`')
                return true;
            else if (line[x] >= '{' && line[x] <= '~')
                return true;
        }
    }
    return false;
}

//getting file data
std::vector<std::string> FileEngine::getFileData()
{
    this->getData();
    if (!this->_exit_found)
    {
        this->_error_msg = "Error: Missing an exit";
    }
    return  this->_fileData;
}