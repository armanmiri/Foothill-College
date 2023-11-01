// Student ID: 20481838
// TODO - Replace the number above with your actual student ID
//
#ifndef Stacks_h
#define Stacks_h
#include <vector>
#include <sstream>
class Stack_Int 
{
private:
    std::vector<int> _data;

public:
// No explicit constructor or destructor
    size_t size() const
    {
        return _data.size();
    }
    
    bool is_empty() const
    {
        return _data.empty();
    }
    
    void push(int val)
    {
        _data.push_back(val);
    }
    
    int top(bool& success) const
    {
        if (_data.empty())
        {
            success = false; return 0;
        }
        else
        {
            success = true;
            return _data[_data.size()-1];
        }
    }
    
    bool pop()
    {
        if (_data.empty())
        {
            return false;
        }
        else
        {
            _data.pop_back();
            return true;
        }
    }
    
    bool pop(int& val)
    {
        if (_data.empty())
        {
            return false;
        }
        else
        {
            val = _data[_data.size()-1]; _data.pop_back(); return true;
        }
    }
    
std::string to_string() const
       {
           std::string strg = "";
           std::string stackSize = std::to_string(_data.size());
           strg = "Stack (" + stackSize + " elements):\n";
           if (_data.size() <= 10)
           {
               for (size_t i = _data.size(); i > 0; i--)
               {
                   strg += std::to_string(_data[i]) + "\n";
               }
           }
           else
           {
               for (size_t j = _data.size()-1; j > _data.size()-11; j--)
               {
                   strg += std::to_string(_data[j]) + "\n";
               }
               strg += "...\n";
           }
           strg += "Elements, if listed above, are in increasing order of age.";
           return strg;
       }
    
       // Don't remove the following line
       friend class Tests;
};
class Stack_String
{
    private:
       std::vector<std::string> _data;

    public:
       // No explicit constructor or destructor
        
        size_t size() const
        {
           return _data.size();
        }
       
        bool is_empty() const
        {
           return _data.empty();
        }
       
        void push(std::string val)
        {
           _data.push_back(val);
        }
       
        std::string top(bool &success) const
        {
           if (_data.empty())
            {
                success = false;
                return 0;
            }
           else
           {
               success = true;
               return _data[_data.size()];
           }
        }
    
        bool pop()
        {
           if (_data.empty())
           {
               return false;
           }
           else
           {
               _data.pop_back();
               return true;
           }
        }
    
        bool pop(std::string &val)
        {
           if (_data.empty()) {return false;}
           else {val = _data[_data.size()]; _data.pop_back(); return true;}
        }
        std::string to_string() const
        {
           std::string strg = "";
           std::string stackSize = std::to_string(_data.size());
            
           strg = strg + "Stack (" + stackSize + " elements):\n";
            
           if (_data.size() <=10)
           {
               for (size_t i = 0; i < _data.size(); i++)
               {
                   strg += _data[i] + "\n";
               }
           }
           else
           {
               for (size_t j = _data.size()-10; j < _data.size(); j++)
               {
                   strg += _data[j] + "\n";
               }
               strg += "...";
           }
           
            strg += "Elements, if listed above, are in increasing order of age.";
           
            return strg;
       }
    
       // Don't remove the following line
       friend class Tests;
};
#endif /* Stacks_h */
