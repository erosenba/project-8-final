/**
 * CS-102 Project 08: Header file for a general matrix class.
 * @file matrix.h
 * @author: Teddy Rosenbaum
 * @collaborators: None
 * @date: 5/3/2022
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include <vector>

class matrix
{
private:
   std::vector<std::vector<int>> data;
   int modulo = 89; // must be prime to guarentee the row space is a vector space

public:
   const int at(const size_t& x, const size_t& y);
   const int getMod();
   const size_t xSize();
   const size_t ySize();
   const void print();
   void addRow(std::vector<int> newRow);
   const std::vector<int> multiply(const std::vector<int>& input);
};

#endif
