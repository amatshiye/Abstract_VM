/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:33:50 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/11 08:04:21 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileEngine.hpp"

FileEngine::FileEngine () {}

FileEngine::FileEngine (std::string fileName)
{
    this->_fileName = fileName;
    this->_exit_found = false;
}

FileEngine::~FileEngine() throw()
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
   ErrorDetails e;
   std::vector<std::vector<std::string> > data;
   std::string dataType;
   std::string value;

   if (file.is_open())
   {
       int x = 1;
       while (!file.eof())
       {
           getline(file, line);
           if (line == "")
                continue;
           line = removeComment(line);
           line = removeSpace(line);
           line = patchSpace(line);
           checkInstruction(line, x);
           if (charParser(line))
           {
               e.setErrorMsg("Line " + std::to_string(x) + " :Syntax error:\033[1;31m " + line + "\033[0m");
               throw e;
           }
            if (line != "")
                this->_fileData.push_back(line);
            if (line.find("exit") != std::string::npos)
                this->_exit_found = true;
            x++;
            try
            {
                ErrorEngine e_engine(line, this->getNumWords(line));
                data.push_back(e_engine.getIns());
            }
            catch(ErrorDetails e)
            {
                throw e;
            }
       }

       try
       {
            StackEngine s(data);
       }
       catch(std::exception e)
       {
           e.what();
       }
       if (!this->_exit_found)
       {
           e.setErrorMsg("Error: Missing an\033[1;31m exit\033[0m");
           throw e;
       }
       file.close();
   }
   else
   {
       //better error imp. needed.
       e.setErrorMsg("\033[1;31mError\033[0m: Unable to open file.");
       throw e;
   }
}

std::string FileEngine::removeComment(std::string line)
{
    //remove everything from the index of (;)

    if (line.length())
    {
        const unsigned long pos = line.find(';'); //searches for the ; char
        
        if (pos != std::string::npos)
        {

            if (pos != 0)
            {
                line = line.substr(0, pos);
                size_t op_b = line.find("(");
                size_t cl_b = line.find(")");

                if (op_b == std::string::npos || cl_b == std::string::npos)
                {
                    ErrorDetails e_details("Error: Unable to process instruction ::" + line);
                    throw e_details;
                }
                return line;
            }
            else
            {
                return "";
            }
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
        while (line.length() != beg_x)
        {
            if (isspace(line[beg_x]))
                beg_x++;
            else
                break;
        }
        line = line.substr(beg_x, line.length());

        //removing spaces at the end
        while (line[line.length() - 1] == ' ')
            line.erase(line.length() - 1, 1);
    }
    return line;
}

int    FileEngine::getNumWords(std::string line)
{
    //this is to get the number of words in a line

    size_t  x;
    size_t  words_ = 0;

    for (x = 0; line.length() > x ; x++)
    {
        if (line[x] != ' ')
            words_++;
        while (line[x] != ' ' && line[x + 1] != '\0')
            x++;
    }

    if (line.length() > 0 && words_ == 0)
        words_ = 1;
    return (words_);
}

//checking instructions 
void    FileEngine::checkInstruction(std::string line, int l_num)
{
    //validating instructions
    //get the line
    //check how many words the line has
    //split it if it has two
    std::string opCodes_single[9] = {"pop", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"};
    std::string opCode_multi[2] = {"push", "assert"};
    std::string temp;
    ErrorDetails e;

    if (line.c_str())
    {
        if (this->getNumWords(line) == 1)
        {
            temp = removeSpace(line);
            if (temp.length() > 0)
            {
                if (!in_array(temp, opCodes_single, 9))
                {
                    e.setErrorMsg("Line " + std::to_string(l_num) + ": " + line + ": " + "\033[1;31mInvalid Instruction\033[0m");
                    throw e;
                }
            }
        }
        else if (this->getNumWords(line) == 2)
        {
            temp = removeSpace(line);
            std::vector<std::string> tokens = this->ft_strplit(line, " ");

            if (tokens.size() > 0)
            {
                if (!in_array(tokens.at(0), opCode_multi, 2))
                {
                    //throw an error and destroy the program
                    e.setErrorMsg("Line " + std::to_string(l_num) + ": " + line + ":\033[1;31mInvalid Instruction\033[0m");
                    throw e;
                }
            }
        }
        else
        {
            if (line.length())
            {
                e.setErrorMsg("Error line:\033[1;31m " + line + "\033[0m");
                throw e;
            }
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
    try
    {
        if (line.length())
        {
            for (size_t x = 0; x < line.length(); x++)
            {
                size_t pos;
                if ((pos = line.find("(")) != std::string::npos)
                {
                    if ((line[pos + 1] != 0) && (line[pos + 1] == '+' || line[pos + 1] == '-'))
                        continue;

                    size_t _c_bracket = line.find(")");
                    size_t _dot = line.find(".");

                    if (_dot > pos && _dot < _c_bracket)
                        continue;                        
                }
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
    }
    catch (std::exception e)
    {
        e.what();
        ErrorDetails e_details("Error: Unable to process instruction");
        throw e_details;
    }
    return false;
}

//getting file data
std::vector<std::string> FileEngine::getFileData()
{
    this->getData();
    return  this->_fileData;
}

std::string FileEngine::patchSpace(std::string line)
{
    size_t pos;

    line = std::regex_replace(line, std::regex(" +"), " ");
    if ((pos = line.find("(")) != std::string::npos)
    {
        if (line[pos - 1] == ' ')
        {
            size_t space = pos;
            line.replace(space - 1, 1, "");
        }
    }

    return line;
}