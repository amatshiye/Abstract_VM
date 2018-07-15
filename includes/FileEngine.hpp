/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:49:41 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/15 17:39:09 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_ENGINE
#define FILE_ENGINE

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <regex>
#include <stdexcept>
#include "ErrorEngine.hpp"
#include "StackEngine.hpp"

class FileEngine
{
    private:
        std::string                 _fileName;
        std::vector<std::string>    _fileData;
        bool        _exit_found;
        int         _line;
        //create a vector array globally

    public:
        FileEngine();
        FileEngine(std::string fileName);
        FileEngine(FileEngine const &src);
        ~FileEngine() throw();

        FileEngine &operator=(FileEngine const &rhs);
        std::string getFileName();
        std::string removeComment(std::string line);
        std::string removeSpace(std::string line);
        std::string patchSpace(std::string line);
        std::vector<std::string> getFileData();
        void getData();
        void getData(std::vector<std::string> stdin_data);
        void    checkInstruction(std::string line);
        static  int    getNumWords(std::string line);
        static std::vector<std::string> ft_strplit(std::string str, std::string delimiter);
        bool    in_array(std::string value, std::string *array, int length);
        bool    charParser(std::string line);
};

#endif