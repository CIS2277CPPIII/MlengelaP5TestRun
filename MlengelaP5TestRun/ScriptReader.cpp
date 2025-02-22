/*********************************************************************
* Program: Linked List
* Programmer: Daudi Mlengela(dmlengela@cnm.edu)
* Date: March 14th 2023
* Purpose: Program 5 linked list
**********************************************************************/

#include "ScriptReader.h"
#include "PersonGen.h"
#include "ListMgr.h"

ScriptReader::ScriptReader(string file)
{
   in.open(file);
   if (!in) {
       std::cout << "Could not open file: " << file << "\n";
   }
}

ScriptReader::~ScriptReader()
{
    // close the file
   in.close();
   // delete anything that needs deleting
}

int ScriptReader::GetNextInt()
{
   // Skip lines beginning with '#' and empty lines

   string temp;
   while(in.peek() == '#' || in.peek() == ' ' || in.peek() == '\n')
   {
         getline(in, temp);
   }
   int choice{ 0 };
   in >> choice;
   in.ignore();
   return choice;
}

string ScriptReader::GetNextString()
{
    // Skip lines beginning with '#' and empty lines
    // do pretty much the same, reading lines that start with '#' or ' '

   string temp;
   int choice;
   do
   {
      int choice = in.peek();

      if (choice == '#' || choice == '\n' || choice == ' ') {
          getline(in, temp);
      }
      else {
          break;
      }
   } while (true); 
   // into a junk variable until the next line is a string
    // read the next line as a string using a getline.
   getline(in, temp);
   return(temp);
}

