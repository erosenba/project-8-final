/**
 * CS-102 Project 08: Implementation for a encryption matrix class that extends the matrix class.
 * @file eMatrix.h
 * @author: Teddy Rosenbaum
 * @collaborators: None
 * @date: 5/3/2022
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <ctime>
#include <string>
#include <exception>

#include "eMatrix.h"

eMatrix::eMatrix()
/**
Description
--------
The generic constructer for an eMatrix. Creates an eMatrix and prompts the user for in

Input
----
None

Output
----
None

*/
{
   std::cout << "Insert the x size: "; // Prompts the user for the x dimension of the matrix.
   int xSize; // Stores the x size.
   std::cin >> xSize; // Reads in the x size.
   std::cout << "Insert the y size: "; // Prompts the user for the y dimension of the matrix.
   int ySize; // Stores the y size.
   std::cin >> ySize; // Reads in the y size.
   int value; // Holds the values that will be read in and go into the matrix.
   for (int yIndex = 0; yIndex < ySize; yIndex++) // Loops throught the number of rows.
   { // Constructs a row.
      std::vector<int> newVector; // Stores the new row.
      std::cout << "Insert row " << yIndex << ": "; // Prompts the user to insert the yIndex row.
      for (int xIndex = 0; xIndex < xSize; xIndex++) // Reads in xSize values that will go into the row.
      {
         std::cin >> value; // Reads in the value.
         newVector.push_back(value); // Adds the value to the new row.
      }
      addRow(newVector); // Adds the row to the matrix.
   }
}

eMatrix::eMatrix(const int& seed, const int& xSize, const int& ySize)
/**
Description
--------
Allows the user to generate a matrix of specified size from a specified seed.

Input
----
const int& seed -- The seed value used to generate random numbers.
const int& xSize -- The number of columns in the matrix.
const int& ySize -- The number of rows in the matrix.

Output
----
None

*/
{
   srand(seed); // Seeds the random number generator with seed.
   for (int yIndex = 0; yIndex < ySize; yIndex++) // Loops through the number of rows.
   { // Constructs a row.
      std::vector<int> newVector; // Stores the new row.
      for (int xIndex = 0; xIndex < xSize; xIndex++) // Loops through the number of columns.
      {
         newVector.push_back(rand() % getMod()); // Adds a random value to the new row.
      }
      addRow(newVector); // Adds the new row to the matrix.
   }
}

eMatrix::eMatrix(const int& xSize, const int& ySize)
/**
Description
--------
Allows the user to generate a matrix of specified size and uses the time as the seed value.

Input
----
const int& xSize -- The number of columns in the matrix.
const int& ySize -- The number of rows in the matrix.

Output
----
None

*/
{
   srand(time(0)); // Seeds the random number generator with size.
   for (int yIndex = 0; yIndex < ySize; yIndex++) // Loops through the number of rows.
   { // Constructs a row.
      std::vector<int> newVector; // Stores the new row.
      for (int xIndex = 0; xIndex < xSize; xIndex++) // Loops through the number of columns.
      {
         newVector.push_back(rand() % getMod()); // Adds a random value to the new row.
      }
      addRow(newVector); // Adds the new row to the matrix.
   }
}

const std::string keyString = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+[]{}|;:<>\?,./\n";
// Used to turn chars into ints and ints into chars.

const std::string eMatrix::encrypt(std::string text)
/**
Description
--------
Encrypts a string and returns the encrypted text.

Input
----
std::string text -- The text that is being encrypted.

Output
----
std::string -- The encrypted text.

*/
{
   std::vector<std::vector<int>> asciiVectors; // Stores a list of vectors of length ySize that corispond to chars in the text.
   std::vector<int> holder; // Holds a new vector that will go into asciiVectors.
   for (auto &character : text) // Loops through every character in the string.
   {
      if (holder.size() == ySize()) // If the vector is full.
      {
         asciiVectors.push_back(holder); // Adds the vector to the list of vectors.
         std::vector<int> newVector; // Creates a new empty vector.
         holder = newVector; // Assigns that new vector to be holder.
      }
      holder.push_back(keyString.find(character)); // Inserts the int that corisponds to character into the vector.
   }
   while (holder.size() != ySize()) // Ensures that the last vector is not too short.
   {
      holder.push_back(0); // Adds 0s to fill the vector.
   }
   asciiVectors.push_back(holder); // Pushes the final vector into asciiVectors.

   std::vector<int> result; // Holds the result of the vector multiplication.
   std::string encrypted; // A string that will hold the encrypted text.

   for (size_t vectorIndex = 0; vectorIndex < asciiVectors.size(); vectorIndex++) // Loops through every vector in asciiVectors.
   {
      holder = asciiVectors.at(vectorIndex); // Sets holder to be the current vector.
      result = multiply(holder); // Multiplies that vector with the eMatrix.
      for (size_t intIndex = 0; intIndex < result.size(); intIndex++) // Loops through the result of the multiplication.
      {
         int keyIndex = result.at(intIndex); // Stores the current value in the result vector.
         encrypted += keyString.at(keyIndex); // Adds the char at that index to the encrypted text string.
      }
   }

   return encrypted; // Returns the encrypted text.
}

const std::map<std::vector<int>, std::vector<int>> eMatrix::constuctHashTable()
/**
Description
--------
Creates a map that returns the input for every given output of matrix multiplication with the eMatrix.

Input
----
None

Output
----
std::map<std::vector<int>, std::vector<int>> -- A map for all possible output values.

*/
{
   std::cout << "Constructing Hash Table\nThis may take a minute\n"; // Informs the user that this process may take some time.
   int mod = getMod(); // Storest the mod of the matrix.
   size_t size = ySize(); // Stores the y size of the matrix.
   std::map<std::vector<int>, std::vector<int>> hashTable; // Creates an empty map.
   long long int remaining; // Used to turn an int into a possible input vector.
   long long int limit = std::pow(mod, size); // Finds the number of possible input vectors.
   for (long long int value = 0; value < limit; value++) // Loops through the number of possible input vectors.
   {
      std::vector<int> newVector; // Creates a empty vector that will be constructed from value.
      remaining = value; // Stores value as a different variable that can be modified as needed.
      while (remaining != 0) // Loops until value == 0.
      { // Converts value to a base mod number
         newVector.insert(newVector.begin(), remaining % mod); // Finds the next value and adds it to the newVector.
         remaining = remaining / mod; // Accounts for the value now in newVector.
      }
      while (newVector.size() != size) // Ensures that the newVector is of proper size.
      {
         newVector.insert(newVector.begin(), 0); // Adds zeros until it is the right size.
      }
      std::vector<int> result = multiply(newVector); // Finds and stores the output of doing vector matrix multiplication with newVector.
      hashTable[result] = newVector; // Adds newVector to the map with the result vector as the key
   } // This will be very useful for decoding encrypted text.
   return hashTable; // Returns the map.
}

const std::string eMatrix::decrypt(std::string text)
/**
Description
--------
Decodes text that was encoded with this eMatrix.

Input
----
std::string text -- The text that is being decrypted.

Output
----
std::string -- The decrypted text.

*/
{
   std::map<std::vector<int>, std::vector<int>> hashTable = constuctHashTable(); // Constructs a map that will give us the input vectors based on the output vectors used when encoding the text.
   std::vector<std::vector<int>> asciiVectors; // Will store the text converted to a list of int vectors.
   std::vector<int> holder; // Holds the current vector that will eventualy be added to asciiVectors.
   for (auto &character : text) // Loops through the characters in the encrypted text.
   {
      if (holder.size() == xSize()) // If the vector is full.
      {
         asciiVectors.push_back(holder); // Adds the vector to asciiVectors.
         std::vector<int> newVector; // Creates a new vector.
         holder = newVector; // Assigns holder to the new vector.
      }
      holder.push_back(keyString.find(character)); // Adds the index of character in keyString to the holder vector.
   }
   while (holder.size() != xSize()) // Ensures that the last vector is of proper size.
   {
      holder.push_back(0); // Fills any empty spaces with 0s.
   }
   asciiVectors.push_back(holder); // Adds the last vector to asciiVectors.

   std::vector<int> result; // Stores the input vecotrs.
   std::string decrypted; // Stores the decrypted text.

   for (size_t vectorIndex = 0; vectorIndex < asciiVectors.size(); vectorIndex++) // Loops through all of the vectors in asciiVectors.
   {
      holder = asciiVectors.at(vectorIndex); // Stores the current vector.
      result = hashTable[holder]; // Finds the input vector that resulted in holder.
      for (size_t intIndex = 0; intIndex < result.size(); intIndex++) // Loops through this input vector.
      {
         int keyIndex = result.at(intIndex); // Stores the current value.
         decrypted += keyString.at(keyIndex); // Finds the character that corisponds to that value and adds it to decrypted.
      }
   }

   return decrypted; // Returns the decrypted text.
}
