#include <vector>
#include <iostream>
#include <exception>

#include "matrix.h"

const int matrix::at(const size_t& x, const size_t& y)
{
   return data.at(y).at(x);
}

const int matrix::getMod()
{
   return modulo;
}

const size_t matrix::xSize()
{
   return data.at(0).size();
}

const size_t matrix::ySize()
{
   return data.size();
}

const void matrix::print()
{
   for (size_t yIndex = 0; yIndex < ySize(); yIndex++)
   {
      for (size_t xIndex = 0; xIndex < xSize(); xIndex++)
      {
         std::cout << at(xIndex, yIndex) << " ";
      }
      std::cout << std::endl;
   }
}

void matrix::addRow(std::vector<int> newRow)
{
   data.push_back(newRow);
}

const std::vector<int> matrix::multiply(const std::vector<int>& input)
{
   if (input.size() != ySize())
   {
      throw std::invalid_argument(" invalid input vector.");
   }
   std::vector<int> result;
   int tot;
   for (size_t xIndex = 0; xIndex < xSize(); xIndex++)
   {
      tot = 0;
      for (size_t yIndex = 0; yIndex < ySize(); yIndex++)
      {
         tot += (input.at(yIndex) * at(xIndex, yIndex));
      }
      result.push_back(tot % getMod());
   }
   return result;
}
