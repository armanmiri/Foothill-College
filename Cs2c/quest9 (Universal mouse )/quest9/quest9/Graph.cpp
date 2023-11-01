//student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <math.h>
#include "Graph.h"
#include <climits>
#include <cfloat>

using namespace std;

Graph& Graph::add_edge(int src, int tgt, float wt, bool replace)
{
    if (src < 0)
    {
        return *this;
    }
    else if (tgt < 0)
    {
        return *this;
    }
    //else if (src == tgt)
    //{
      //  return *this;
    //}
    
    int maxint = max(src, tgt);
    
    maxint++;
    
    if (signed(_nodes.size()) < maxint)
    {
        _nodes.resize(maxint);
    }
    
    if (src == tgt)
    {
      return *this;
    }
    
    bool found = false;
    
    for (int n = 0; n < (signed)_nodes[src].size(); n++)
    {
        if (_nodes[src][n].dst == tgt)
        {
            found = true;
            
            if (replace)
            {
                _nodes[src][n].wt = wt;
            }
            else
            {
                _nodes[src][n].wt += wt;
            }
            
            break;
        }
    }
    
    if (!found)
    {
        _nodes[src].push_back(Edge(tgt, wt));
    }
    
    return *this;
}

float Graph::find_edge_weight(int src, int tgt) const
{
    if (src >= (signed)get_num_nodes())
    {
        return Graph::FLOOR;
    }
    else if (src < 0)
    {
        return Graph::FLOOR;
    }
    else if (tgt < 0)
    {
        return Graph::FLOOR;
    }
    else if (tgt >= (signed)get_num_nodes())
    {
        return Graph::FLOOR;
    }
        
    for (int n = 0; n < (signed)_nodes[src].size(); n++)
    {
        if (_nodes[src][n].dst == tgt)
        {
            return _nodes[src][n].wt;
        }
    }
    
    return Graph::FLOOR;
}

string Graph::to_string() const
{
    string output = "# Graph - ";
    
    output += std::to_string(_nodes.size()) + " nodes.\n";
    
    output += "# Edge lists:\n";
        
       for (int n = 0; n < (signed)get_num_nodes(); n++)
       {
          if (_nodes[n].empty())
          {
             continue;
          }
           
          output += std::to_string(n) + " : ";
           
          for (int q = 0; q < (signed)_nodes[n].size(); q++)
          {
             stringstream strg;
              
             strg << _nodes[n][q].wt;
             
             output += "(" + std::to_string(_nodes[n][q].dst) + "," + strg.str() + ") ";
          }
           
           output += "\n";
       }
        
    output += "# End of Graph\n";
   
    return output;
}
