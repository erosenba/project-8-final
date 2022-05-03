#include <string>
#include <iostream>

#include "matrix.h"
#include "eMatrix.h"
#include "readWrite.h"

int main()
{
   std::cout << "Insert encryption key dimensions: ";
   int xSize;
   int ySize;
   std::cin >> xSize;
   std::cin >> ySize;
   eMatrix m(xSize, ySize);
   std::cout << std::endl << "your encryption key is:" << std::endl;
   m.print();
   std::cout << std::endl << "File to encrypt: ";
   std::string filepath;
   std::cin >> filepath;
   std::string text = readFile(filepath);
   std::string encryptedText = m.encrypt(text);
   std::cout << "Encrypting file..." << std::endl;
   clearFile(filepath);
   writeFile(filepath, encryptedText);
   std::cout << "Successful!" << std::endl;
}
