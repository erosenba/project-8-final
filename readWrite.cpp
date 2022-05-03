#include <fstream>

#include "readWrite.h"

std::string readFile(const std::string& filepath)
{
   std::fstream file(filepath);
   return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void clearFile(const std::string& filepath)
{
   std::fstream file;
   file.open(filepath, std::ofstream::out | std::ofstream::trunc);
   file.close();
}

void writeFile(const std::string& filepath, const std::string& text)
{
   std::fstream file(filepath);
   file << text;
   file.close();
}
