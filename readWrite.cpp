/**
 * CS-102 Project 08: Implementation for basic input output tools.
 * @file eMatrix.h
 * @author: Teddy Rosenbaum
 * @collaborators: None
 * @date: 5/3/2022
 */

#include <fstream>

#include "readWrite.h"

std::string readFile(const std::string& filepath)
/**
Description
--------
Reads in the text from the file at filepath.

Input
----
const std::string& filepath -- The filepath of the intended file.

Output
----
std::string -- The text in the intended file.

*/
{
   std::fstream file(filepath); // Creates a fstream with the file at filepath.
   return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); // Turns the text into a string and returns it.
}

void clearFile(const std::string& filepath)
/**
Description
--------
Clears the file at filepath.

Input
----
const std::string& filepath -- The filepath of the file being cleared.

Output
----
None

*/
{
   std::fstream file; // Creates a generic fstream.
   file.open(filepath, std::ofstream::out | std::ofstream::trunc); // Opens the file and empties it.
   file.close(); // Closes the file.
}

void writeFile(const std::string& filepath, const std::string& text)
/**
Description
--------
Adds text to the file at filepath.

Input
----
const std::string& filepath -- The filepath of the file text is being put into.
const std::string& text -- The text being put into the file.

Output
----
None

*/
{
   std::fstream file(filepath); // Creates an fstream with the file at filepath.
   file << text; // Pushes text into the fstream.
   file.close(); // Closes the file.
}
