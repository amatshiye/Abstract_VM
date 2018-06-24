/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:49:41 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/24 10:45:53 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_ENGINE
#define FILE_ENGINE

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class FileEngine
{
    private:
        std::string _fileName;
        std::vector<std::string>    _fileData;
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
        std::vector<std::string> getFileData();
};

#endif