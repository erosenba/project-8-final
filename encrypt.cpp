/**
 * CS-102 Project 08: Generates an encryption matrix and encrypts a file.
 * @file eMatrix.h
 * @author: Teddy Rosenbaum
 * @collaborators: None
 * @date: 5/3/2022
 */

#include <string>
#include <iostream>

#include "matrix.h"
#include "eMatrix.h"
#include "readWrite.h"

int main()
{
   std::cout << "Insert the x size: "; // Prompts the user for the x dimension of the matrix.
   int xSize; // Stores the x size of the matrix.
   std::cin >> xSize; // Reads in the x size of the matrix.
   std::cout << "Insert the y size: "; // Prompts the user for the y dimension of the matrix.
   int ySize; // Stores the y size of the matrix.
   std::cin >> ySize; // Reads in the y size of the matrix.
   eMatrix m(xSize, ySize); // Generates a random encryption matrix of the specified size.
   std::cout << "your encryption key is:" << std::endl; // Informs the user that it is printing the encryption matrix.
   m.print(); // Prints the encryption matrix.
   std::cout << std::endl << "File to encrypt: "; // Prompts the user for a filepath.
   std::string filepath; // Stores the filepath.
   std::cin >> filepath; // Reads in the filepath.
   std::string text = readFile(filepath); // Reads in the text from the file.
   std::cout << "Encrypting file..." << std::endl; // Informs the user that it is encrypting the file.
   std::string encryptedText = m.encrypt(text); // Encrypts the text from the file.
   clearFile(filepath); // Clears the file.
   writeFile(filepath, encryptedText); // Writes the encrypted text into the file.
   std::cout << "Successful!" << std::endl; // Informs the user that the code ran successfully.
}
