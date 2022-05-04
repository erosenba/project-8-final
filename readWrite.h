/**
 * CS-102 Project 08: Header file for basic file input output tools.
 * @file eMatrix.h
 * @author: Teddy Rosenbaum
 * @collaborators: None
 * @date: 5/3/2022
 */

#ifndef READWRITE_H
#define READWRITE_H

#include <cstdlib>
#include <string>

std::string readFile(const std::string& filepath);
void clearFile(const std::string& filepath);
void writeFile(const std::string& filepath, const std::string& text);

#endif
