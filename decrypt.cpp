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
   std::cout << "Enter your key to decrypt: " << std::endl;
   eMatrix m;
   std::cout << std::endl << "File to decrypt: ";
   std::string filepath;
   std::cin >> filepath;
   std::string text = readFile(filepath);
   std::cout << "Decrypting file..." << std::endl;
   std::string decryptedText = m.decrypt(text);
   clearFile(filepath);
   writeFile(filepath, decryptedText);
   std::cout << "Successful!" << std::endl;

}
