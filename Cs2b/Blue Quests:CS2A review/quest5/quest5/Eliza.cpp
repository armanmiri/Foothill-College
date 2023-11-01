// Student ID: 20481838
// TODO - Replace the number above with your actual Student ID
// Eliza.cpp
// 2a.Lab-05-Eliza
//
//


#include <iostream>
#include <sstream>

#include <string>

using namespace std;

// Return a new string in which the letters (lowercase) a, e, i, o, and u
// have been replaced by the next vowel in the sequence aeiou. Replace u by a.
//
// Note that the string is passed in by reference. So the caller may not
// rely on the result being returned.

string rotate_vowels(string& s){
    
    char toLookFor;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    
    string fs = s;
    
    for (int count = 0; count < 5; count++)
    {
        toLookFor = vowels[count];
        
        if (count < 4)
        {
            for (size_t i=0; i < s.size(); i++)
            {
                if (s[i] == toLookFor)
                {
                    fs[i] = vowels[count+1];
                }
            }
        }
        else
        {
            for (size_t i=0; i<s.size(); i++)
            {
                if (s[i] == toLookFor)
                {
                    fs[i] = 'a';
                }
            }
        }
     }
    s = fs;
    return s;
}


// Return a string in which all occurrences of s have been replaced by th
string lispify(string s)
{
  string strg;
  for (size_t i = 0; i < s.size(); i++)
  {
    if (s[i] == 's')
        {
            strg.push_back('t');
            strg.push_back('h');
        }
    else if (s[i] == 'S')
    {
        strg.push_back('T');
        strg.push_back('h');
        
    }
    else
    {
        strg.push_back(s[i]);
    }
  }
  return strg;
}

// Enter the user-interaction loop as described earlier
void enter()
{

    bool stop = false;
    
    string line = "";
    
    int excount = 0;
    int strgcount = 0;
    
    while (stop == false)
    {
        getline(cin, line);
        if(line.size() == 0)
        {
            enter();
            
        }
        else
        {
          cout << "    " << line << endl << endl;
         for(size_t i=0; i<line.size(); i++)
            {
            if (line[i] == '!')
                {
                    excount++;
                    
                }
             }
          for(size_t i=0; i<line.size(); i++)
          {
            if (line[i] == 's')
            {
                strgcount++;
                
            }
          }
          if (excount > 0)
          {
              cout << "OMG! You don't say!! " << line << "!!!!!" << endl;
              enter();
          }
          else if (!line.find("why") || !line.find("what"))
          {
              cout << "I'm sorry, I don't like questions that contain what or why.";
              enter();
          }
          else if (strgcount > 0)
          {
              cout << "Interethting. When did you thtop thtopping your thibilanth?" << endl << lispify(line) << "! Sheesh! Now what?";
              enter();
          }
          else if (!line.find("bye") || !line.find("Bye") || !line.find("quit") || !line.find("Quit"))
          {
              cout << "Ok Bye. Nice being a force of change in your life." << endl;
              stop = false;
          }
          else
          {
            if (rand() % 10 == 8 || rand() % 10 == 9)
            {
              cout << "Huh? Why do you say: " << line << "?" << endl;
            }
            else
            {
                cout << rotate_vowels(line) << "?" << endl;
                
            }
          }
        }
      }
    }
