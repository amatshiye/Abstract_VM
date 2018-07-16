/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:33:50 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/16 06:05:38 by amatshiy         ###   ########.fr       */
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

void FileEngine::getData(std::vector<std::string> stdin_data)
{
   std::string line;
   std::vector<std::vector<std::string> > data;
   std::string dataType;
   std::string value;
   
   if (stdin_data.size() > 0)
   {
       int x = 1;
       std::vector<std::string>::iterator stdin_line;
       for (stdin_line = stdin_data.begin(); stdin_line != stdin_data.end(); stdin_line++)
       {
           line = *stdin_line;
           if (line == "")
            {
                continue;
            }
            else if (!(stdin_data.size() > 2))
            {
                if (stdin_data[0].find("exit") != std::string::npos)
                {
                    throw ErrorDetails::ZeroInstructions();
                }
            }
            line = removeComment(line);
            line = removeSpace(line);
            line = patchSpace(line);
            checkInstruction(line);
           if (charParser(line))
           {
               throw ErrorDetails::UnkownSyntax();
           }
            if (line != "")
                this->_fileData.push_back(line);
            if (line.find("exit") != std::string::npos)
                this->_exit_found = true;
            x++;
            this->_line = x;
            try
            {
                try
                {
                    ErrorEngine e_engine(line, this->getNumWords(line), x);
                    data.push_back(e_engine.getIns());
                }
                catch(std::out_of_range oor)
                {
                    throw ErrorDetails::InvalidInstruction();
                }
            }
            catch(std::exception e)
            {
                e.what();
                throw ErrorDetails::InvalidInstruction();
            }
       }
       if (!this->_exit_found)
       {
           throw ErrorDetails::MissingExit();
       }
       try
       {
            StackEngine s(data);
       }
       catch(std::exception e)
       {
           e.what();
       }
   }
   else
   {
       //better error imp. needed.
       throw ErrorDetails::FileNotFound();
   }
}

void FileEngine::getData()
{
   std::ifstream file(this->getFileName());
   std::string  line;
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
            checkInstruction(line);
           if (charParser(line))
           {
               throw ErrorDetails::UnkownSyntax();
           }
            if (line != "")
                this->_fileData.push_back(line);
            if (line.find("exit") != std::string::npos)
                this->_exit_found = true;
            x++;
            this->_line = x;
            try
            {
                try
                {
                    ErrorEngine e_engine(line, this->getNumWords(line), x);
                    data.push_back(e_engine.getIns());
                }
                catch(std::out_of_range oor)
                {
                    throw ErrorDetails::InvalidInstruction();
                }
            }
            catch(std::exception e)
            {
                e.what();
                throw ErrorDetails::InvalidInstruction();
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
           throw ErrorDetails::MissingExit();
       }
       file.close();
   }
   else
   {
       //better error imp. needed.
       throw ErrorDetails::FileNotFound();
   }
}

std::string FileEngine::removeComment(std::string line)
{
    //remove everything from the index of (;)
    if (line.length())
    {
        size_t  pos = line.find(';'); //searches for the ; char
        if (pos != std::string::npos)
        {
            //splitting the string using ;
            line = line.substr(0, line.find(";", 0));
        }
        else
        {
            return line;
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
            if (temp.length() > 0)
            {
                if (!in_array(temp, opCodes_single, 9))
                {
                    throw ErrorDetails::InvalidInstruction();
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
                    throw ErrorDetails::InvalidInstruction();
                }
            }
        }
        else
        {
            if (line.length())
            {
                throw ErrorDetails::InvalidInstruction();
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
        throw ErrorDetails::InvalidInstruction();
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
        if (line[pos + 1] == ' ')
        {
            size_t space = pos;
            line.replace(space + 1, 1, "");
        }
        if (line[pos - 1] == ' ')
        {
            size_t space = pos;
            line.replace(space - 1, 1, "");
        }
    }

    return line;
}