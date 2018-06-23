/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:49:41 by amatshiy          #+#    #+#             */
/*   Updated: 2018/06/23 12:49:49 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_ENGINE
#define FILE_ENGINE

#include <iostream>
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
        ~FileEngine();

        std::string getFileName();
        void getData();
        void removeComments();
        std::vector<std::string> getFileData();
};

#endif