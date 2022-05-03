#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <ctime>
#include <string>
#include <exception>

#include "eMatrix.h"

eMatrix::eMatrix()
{
   std::cout << "Insert size: ";
   int xSize;
   std::cin >> xSize;
   int ySize;
   std::cin >> ySize;
   int value;
   for (int yIndex = 0; yIndex < ySize; yIndex++)
   {
      std::vector<int> newVector;
      std::cout << "Insert row " << yIndex << ": ";
      for (int xIndex = 0; xIndex < xSize; xIndex++)
      {
         std::cin >> value;
         newVector.push_back(value);
      }
      addRow(newVector);
   }
}

eMatrix::eMatrix(const int& seed, const int& xSize, const int& ySize)
{
   srand(seed);
   for (int yIndex = 0; yIndex < ySize; yIndex++)
   {
      std::vector<int> newVector;
      for (int xIndex = 0; xIndex < xSize; xIndex++)
      {
         newVector.push_back(rand() % getMod());
      }
      addRow(newVector);
   }
}

eMatrix::eMatrix(const int& xSize, const int& ySize)
{
   srand(time(0));
   for (int yIndex = 0; yIndex < ySize; yIndex++)
   {
      std::vector<int> newVector;
      for (int xIndex = 0; xIndex < xSize; xIndex++)
      {
         newVector.push_back(rand() % getMod());
      }
      addRow(newVector);
   }
}

const std::string keyString = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+[]{}|;:<>\?,./\n";

const std::string eMatrix::encrypt(std::string text)
{
   std::vector<std::vector<int>> asciiVectors;
   std::vector<int> holder;
   for (auto &character : text)
   {
      if (holder.size() == ySize())
      {
         asciiVectors.push_back(holder);
         std::vector<int> newVector;
         holder = newVector;
      }
      holder.push_back(keyString.find(character));
   }
   while (holder.size() != ySize())
   {
      holder.push_back(0);
   }
   asciiVectors.push_back(holder);

   std::vector<int> result;
   std::string encrypted;

   for (size_t vectorIndex = 0; vectorIndex < asciiVectors.size(); vectorIndex++)
   {
      holder = asciiVectors.at(vectorIndex);
      result = multiply(holder);
      for (size_t intIndex = 0; intIndex < result.size(); intIndex++)
      {
         int keyIndex = result.at(intIndex);
         encrypted += keyString.at(keyIndex);
      }
   }

   return encrypted;
}

const std::map<std::vector<int>, std::vector<int>> eMatrix::constuctHashTable()
{
   std::cout << "Constructing Hash Table\nThis may take a minute\n";
   int mod = getMod();
   size_t size = ySize();
   std::map<std::vector<int>, std::vector<int>> hashTable;
   int remaining;
   long long int limit = std::pow(mod, size);
   for (long long int value = 0; value < limit; value++)
   {
      std::vector<int> newVector;
      remaining = value;
      while (remaining != 0)
      {
         newVector.insert(newVector.begin(), remaining % mod);
         remaining = remaining / mod;
      }
      while (newVector.size() != size)
      {
         newVector.insert(newVector.begin(), 0);
      }
      // for (size_t index = 0; index < newVector.size(); index++)
      // {
      //    std::cout << newVector.at(index) << " ";
      // }
      // std::cout << std::endl;
      std::vector<int> result = multiply(newVector);
      hashTable[result] = newVector;
   }
   return hashTable;
}

const std::string eMatrix::decrypt(std::string text)
{
   std::map<std::vector<int>, std::vector<int>> hashTable = constuctHashTable();
   std::vector<std::vector<int>> asciiVectors;
   std::vector<int> holder;
   for (auto &character : text)
   {
      if (holder.size() == xSize())
      {
         asciiVectors.push_back(holder);
         std::vector<int> newVector;
         holder = newVector;
      }
      holder.push_back(keyString.find(character));
   }
   while (holder.size() != xSize())
   {
      holder.push_back(0);
   }
   asciiVectors.push_back(holder);

   std::vector<int> result;
   std::string decrypted;

   for (size_t vectorIndex = 0; vectorIndex < asciiVectors.size(); vectorIndex++)
   {
      holder = asciiVectors.at(vectorIndex);
      result = hashTable[holder];
      for (size_t intIndex = 0; intIndex < result.size(); intIndex++)
      {
         int keyIndex = result.at(intIndex);
         decrypted += keyString.at(keyIndex);
      }
   }

   return decrypted;
}
