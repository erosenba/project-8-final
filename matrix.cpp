/**
 * CS-102 Project 08: Implementation for a general matrix class.
 * @file matrix.cpp
 * @author: Teddy Rosenbaum
 * @collaborators: None
 * @date: 5/3/2022
 */

#include <vector>
#include <iostream>
#include <exception>

#include "matrix.h"

const int matrix::at(const size_t& x, const size_t& y)
{
   return data.at(y).at(x); // Returns the data at the specified coordinates.
}

const int matrix::getMod()
{
   return modulo; // Returns the mod (kinda the base) of the matrix.
}

const size_t matrix::xSize()
{
   return data.at(0).size(); // Returns the x size of the matrix.
}

const size_t matrix::ySize()
{
   return data.size(); // Returns the y size of the matrix.
}

const void matrix::print() // Prints the matrix.
{
   for (size_t yIndex = 0; yIndex < ySize(); yIndex++) // Loops through the rows of the matrix.
   {
      for (size_t xIndex = 0; xIndex < xSize(); xIndex++) // Loops through every item in each row.
      {
         std::cout << at(xIndex, yIndex) << " "; // Prints the item.
      }
      std::cout << std::endl; // Starts a new row.
   }
}

void matrix::addRow(std::vector<int> newRow)
{
   data.push_back(newRow); // Adds a new row to the matrix.
}

const std::vector<int> matrix::multiply(const std::vector<int>& input) // Computes vector matrix multiplication (ie: input * this).
{
   if (input.size() != ySize()) // If the input vector is not of the appropiate size.
   {
      throw std::invalid_argument(" invalid input vector."); // Throws an error informing the user.
   }
   std::vector<int> result; // Stores the output of the multiplication.
   int tot; // Holds the sum that will go into result.
   for (size_t xIndex = 0; xIndex < xSize(); xIndex++) // Loops through every column.
   {
      tot = 0; // Resets tot.
      for (size_t yIndex = 0; yIndex < ySize(); yIndex++) // Loops through every value in that column.
      {
         tot += (input.at(yIndex) * at(xIndex, yIndex)); // Essentialy just finds a linear combination of the column.
      }
      result.push_back(tot % getMod()); // Adds the tot % modulo (a value x st 0 leq x < 89) to the result vector.
   }
   return result; // Returns the computed vector.
}
