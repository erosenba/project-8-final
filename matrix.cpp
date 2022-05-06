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
/**
Description
--------
Returns the data at the specified coordinates.

Input
----
const size_t& x -- The x coordinate.
const size_t& y -- The y coordinate.

Output
----
int -- The value at x,y.

*/
{
   return data.at(y).at(x); // Returns the data at x,y.
}

const int matrix::getMod()
/**
Description
--------
Returns the modulo value of the matrix. This value determines the maximum value that can be in the matrix.

Input
----
None

Output
----
int -- The modulo of the matrix.

*/
{
   return modulo; // Returns the mod (kinda the base) of the matrix.
}

const size_t matrix::xSize()
/**
Description
--------
Returns the number of columns in the matrix.

Input
----
None

Output
----
size_t -- The number of columns in the matrix.

*/
{
   return data.at(0).size(); // Returns the x size of the matrix.
}

const size_t matrix::ySize()
/**
Description
--------
Returns the number of rows in the matrix.

Input
----
None

Output
----
size_t -- The number of rows in the matrix.

*/
{
   return data.size(); // Returns the y size of the matrix.
}

const void matrix::print() // Prints the matrix.
/**
Description
--------
Prints the matrix formated nicely.

Input
----
None

Output
----
None

*/
{
   int value; // Used to store the current value.
   for (size_t yIndex = 0; yIndex < ySize(); yIndex++) // Loops through the rows of the matrix.
   {
      for (size_t xIndex = 0; xIndex < xSize(); xIndex++) // Loops through every item in each row.
      {
         value = at(xIndex, yIndex); // Stores the current value
         if (value < 10) // Prints an extra space if value is single digit.
         {
            std::cout << " " << value << " ";
         }
         else // Prints normaly otherwise.
         {
            std::cout << value << " ";
         }
      }
      std::cout << std::endl; // Starts a new row.
   }
}

void matrix::addRow(std::vector<int> newRow)
/**
Description
--------
Adds a new row to the matrix.

Input
----
std::vector<int> newRow -- The row being added.

Output
----
None

*/
{
   data.push_back(newRow); // Adds the new row to the matrix.
}

const std::vector<int> matrix::multiply(const std::vector<int>& input)
/**
Description
--------
Computes vector matrix multiplication (ie: input * this).

Input
----
const std::vector<int>& input -- The vector being multiplied by this matrix.

Output
----
std::vector<int> -- The resultant vector.

*/
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
