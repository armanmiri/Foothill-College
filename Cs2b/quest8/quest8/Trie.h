// student id: 20481838

#ifndef Trie_h
#define Trie_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie
{
    private:
        struct Node
        {
            vector<Trie::Node *> next;

            ~Node()
            {
                for (size_t n = 0; n < next.size(); n++)
                {
                    delete next[n];
                    
                    next[n] = nullptr;
                }
            };

            void insert(string s)
            {
                Trie::Node *current = this;
                
                for (const char *strg = s.c_str(); *strg; strg++)
                {
                    char c = *strg;
                    
                    if ((size_t) c >= current -> next.size())
                    {
                        current -> next.resize(c+1);
                    }
                 
                    if (current -> next[c] != nullptr)
                    {
                        current = current -> next[c];
                    }
                  
                    else
                    {
                        current = current -> next[c] = new Trie::Node();
                        
                    }
                }
                
                if (current -> next.size() == 0)
                {
                    current -> next.resize(1);
                }
                
                if (current -> next[0] == nullptr)
                {
                    current -> next[0] = new Trie::Node();
                }
                
            };
            
            const Node *traverse(string s) const
            {
                const Trie::Node *current = this;
                
                for (const char *strg = s.c_str(); *strg; strg++)
                {
                    char c = *strg;
                   
                    if ((size_t) c >= current ->next.size())
                    {
                        return nullptr;
        
                    }
                    
                    if (current -> next[c] != nullptr)
                    {
                        current = current -> next[c];
                        
                    }
                    
                    else
                    {
                        return nullptr;
                    }
                }
                
                return current;
            };
            
            bool lookup(string s)
            {
                const Trie::Node *output = this->traverse(s);
                
                if (output == nullptr)
                {
                    return false;
                }
                
                if (output -> next[0] != nullptr)
                {
                    return true;
                }
                
                else
                {
                    return false;
                }
    
            };
            
          size_t get_completions(vector<string>& completions, size_t limit) const;
        
        } *_root;

    
        const Node *traverse(string &s) {return _root -> traverse(s);};
           
            public:
        
            Trie()
            {
                _root = new Node();
            };
        
            ~Trie()
            {
                delete _root;
                
                _root = nullptr;
            };

            void insert(string s) const
            {
                _root -> insert(s);
            };
        
            bool lookup(string s) const
            {
                return _root -> lookup(s);
            };
        
            size_t get_completions(string s, vector<string>& completions, size_t limit) const
            {
                return _root -> traverse(s) -> get_completions(completions, limit);
            };
        
            size_t trie_sort(vector<string>& vec) const;

            string to_string(size_t limit) const
            {
                string strg;
                
                vector<string> completions;
                
                get_completions("", completions, limit+1);
                
                strg = "# Trie contents\n";
                
                if (limit >= completions.size())
                {
                    for (size_t n = 0; n < completions.size(); n++)
                    {
                        strg += completions[n] + "\n";
                    }
                }
                else
                {
                    for (size_t n = 0; n < limit; n++)
                    {
                        strg += completions[n] + "\n";
                    }
                        
                        strg += "...\n";
                }
                
                return strg;
                
                
            };
        
            ostream& operator<<(ostream os)
            {
                return os << to_string(100);
            };

            friend class Tests;
};


#endif /* Trie_h */
