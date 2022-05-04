/**
 * CS-102 Project 08: Requires the user to input an encryption matrix to decrypt a file.
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
   std::cout << "Enter your key to decrypt: " << std::endl; // Prompts the user to input a key.
   eMatrix m; // Calls the generic constructor which promts the user for dimensions and to insert a key.
   std::cout << std::endl << "File to decrypt: "; // Prompts the user for a filepath of the file to encrypt.
   std::string filepath; // Stores the filepath.
   std::cin >> filepath; // Reads in the filepath.
   std::string text = readFile(filepath); // Reads in the text in the file at filepath.
   std::cout << "Decrypting file..." << std::endl; // Informs the user that the file is being decrypted.
   std::string decryptedText = m.decrypt(text); // Decrypts the text from the file.
   clearFile(filepath); // Empties the file.
   writeFile(filepath, decryptedText); // Writes the decrypted text into the file.
   std::cout << "Successful!" << std::endl; // Informs the user the code ran successfully.

}
