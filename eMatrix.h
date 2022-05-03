#ifndef EMATRIX_H
#define EMATRIX_H

#include <cstdlib>
#include <string>
#include <map>

#include "matrix.h"

class eMatrix : public matrix
{

public:
   eMatrix();
   eMatrix(const int& seed, const int& xSize, const int& ySize);
   eMatrix(const int& xSize, const int& ySize);
   const std::string encrypt(std::string text);
   const std::map<std::vector<int>, std::vector<int>> constuctHashTable();
   const std::string decrypt(std::string text);

};

#endif
