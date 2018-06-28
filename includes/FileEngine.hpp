/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:49:41 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/27 23:54:59 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_ENGINE
#define FILE_ENGINE

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include "ErrorEngine.hpp"

class FileEngine
{
    private:
        std::string     _error_msg;
        std::string     _fileName;
        std::vector<std::string>    _fileData;
        bool        _exit_found;
        //create a vector array globally

    public:
        FileEngine();
        FileEngine(std::string fileName);
        FileEngine(FileEngine const &src);
        ~FileEngine();

        FileEngine &operator=(FileEngine const &rhs);
        std::string getFileName();
        void getData();
        std::string removeComment(std::string line);
        std::string removeSpace(std::string line);
        void    getNumWords(std::string line);
        std::vector<std::string> getFileData();
};

#endif