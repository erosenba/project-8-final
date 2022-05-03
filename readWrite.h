#ifndef READWRITE_H
#define READWRITE_H

#include <cstdlib>
#include <string>

std::string readFile(const std::string& filepath);
void clearFile(const std::string& filepath);
void writeFile(const std::string& filepath, const std::string& text);

#endif
