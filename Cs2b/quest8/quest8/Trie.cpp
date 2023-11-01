// student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#include "Trie.h"
using namespace std;

size_t Trie::Node::get_completions(vector<string>& completions, size_t limit) const
    {
    struct Continuation
    {
        const Trie::Node *node;
        
        string partial;
        
        Continuation(const Node *p, string s): node(p), partial(s) {}
    };
    
    queue<Continuation> unprocessed_nodes;
    
    completions.clear();
    
    unprocessed_nodes.push(Continuation(this, ""));

    while(!unprocessed_nodes.empty() && completions.size() < limit)
    {
        Continuation cont = unprocessed_nodes.front();
    
        unprocessed_nodes.pop();
        
        if (cont.node == nullptr)
        {
            continue;
        }
        
        if (cont.node -> next[0] != nullptr)
        {
            completions.push_back(cont.partial);
        }
        
        for (size_t n = 1; n < cont.node -> next.size(); n++)
        {
            if (cont.node -> next[n] != nullptr)
            {
                unprocessed_nodes.push(Continuation(cont.node->next[n], cont.partial + (char) n));
            }
        }

    }
    
    return completions.size();
}

size_t Trie::trie_sort(vector<string>& vec) const
{
    vec.clear();
   
    get_completions("", vec, 100000);
    
    return vec.size();
}
