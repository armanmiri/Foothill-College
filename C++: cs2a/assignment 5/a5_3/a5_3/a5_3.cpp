/*
 
Arman Miri
CS F002A
10/18/21
Harden
a5_3
Assignment 5 Part 3
 
This program reads the number of words in text files, words being defined as any sequence of
non-whitespace characters. The program asks the user for the name of the file then writes the number
of words it counts. The user can quit the code by entering quit whenever they are prompted to input
a file name.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  int wordcount;
  // integer for wordcount
    
  string words;
  string filename;
  // strings for files inputs
    
  ifstream infile;
  // declaring stream variable

  cout << "Enter the name of a file including its extension for which you want the word count (or \"quit\"): ";
  // asks the user to enter the name of the file for which they want the word count
    
  cin >> filename;
  // stores user input for filname under stream variable

  while (filename != "quit")
  // while loop to run the program as long as user input isn't quit
  {
      wordcount = 0;
      // sets the wordcount to 0
      
      infile.open(filename);
      // opens the file that the user entered
      
      while (infile >> words)
      // finds the words from the input file
      {
          wordcount++;
          // adds 1 to word count
      }
      
  infile.close();
  // closes the file
  
  cout << "This file has " << wordcount << " words. \n \n";
  // writes the number of words the file has
      
  cout << "Enter the name of a file including its extension for which you want the word count (or \"quit\"): ";
  // asks the user to enter the name of the file for which they want the word count
      
  cin >> filename;
  // stores the user input for filname under stream variable
      
  }
    
  cout << "\n";
  // creates space in result
    
  return 0;
    
}


    
/*
 
 Enter the name of a file including its extension for which you want the word count (or "quit"): file1.txt
 This file has 7 words.
  
 Enter the name of a file including its extension for which you want the word count (or "quit"): file2.txt
 This file has 10 words.
  
 Enter the name of a file including its extension for which you want the word count (or "quit"): file3.txt
 This file has 21 words.
  
 Enter the name of a file including its extension for which you want the word count (or "quit"): file4.txt
 This file has 19 words.
  
 Enter the name of a file including its extension for which you want the word count (or "quit"): file5.txt
 This file has 22 words.
  
 Enter the name of a file including its extension for which you want the word count (or "quit"): quit

 Program ended with exit code: 0
 
*/
    
