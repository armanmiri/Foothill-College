//student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <queue>
#include <iterator>
#include <algorithm>
#include <math.h>
#include "Graph_Algorithms.h"
#include "Graph.h"
#include <climits>
#include <cfloat>

using namespace std;


float Gx::_get_capacity_of_this_path(const Graph& g, const std::vector<int>& path)
{
    return 0;
}

float Gx::_get_max_capacity_path(const Graph& g, int src, int dst, std::vector<int>& path)
{
    return 0;
}

bool Gx::_is_cyclic(const Graph& g, size_t node, std::vector<bool> seen, std::vector<bool>& cycle_free)
{
    if (cycle_free[node])
    {
        return false;
    }
    else if (seen[node])
    {
        return true;
    }
    
     for (size_t n = 0; n < g._nodes[node].size(); n++)
     {
         seen[node] = true;
     
         if (_is_cyclic(g, g._nodes[node][n].dst, seen, cycle_free))
         {
             return true;
         }
     }

     return false;
}

bool Gx::is_cyclic(const Graph& g)
{
    int cycles = g.get_num_nodes();
    
    vector<bool> cycle_free(cycles, false);
   
    for (int n = 0; n < cycles; n++)
    {
        vector<bool> seen(cycles, false);
        
        if (_is_cyclic(g, n, seen, cycle_free))
        {
            return true;
        }
        
        cycle_free[n] = true;
   }

    return false;
}

bool Gx::prune_unreachables(Graph& g, int src)
{
    int cycles = g._nodes.size();
       
    if (src >= cycles)
    {
        g.clear();
        
        return false;
    }
    else if (src < 0)
    {
        g.clear();
        
        return false;
    }
    
    vector <bool> reachcheckvar (cycles, false);
    
    reachcheck(g, src, reachcheckvar);
    
    int n = 0;
    
    while (n < cycles)
    {
        if (!(reachcheckvar[n]))
        {
            //_nodes[n].clear();
            // wont work need a helper since I need ot clear certian line and void clear wont do it
            // need to accese _nodes
            
            g.clearspecific(n);
        }
        
        n++;
    }
    
    return true;
}

size_t Gx::get_shortest_unweighted_path(const Graph& g, int src, int dst, std::vector<int>& path)
{
    int cycles = g.get_num_nodes();
    
    path.clear();
    
    if (src == dst)
    {
        path.resize(1);
        
        path[0] = src;
        
        return path.size();
    }
    
    if (src >= cycles)
    {
        return string::npos;
    }
    else if (dst >= cycles)
    {
        return string::npos;
    }
    else if (src < 0)
    {
        return string::npos;
    }
    else if (dst < 0)
    {
        return string::npos;
    }
    
    queue<int> inprg;
    
    vector<bool> check(cycles, false);
    
    vector<int> length(cycles);
    
    vector<int> root(cycles);
    
    inprg.push(src);
    
    check[src] = true;
    
    root[src] = -1;
    
    while (!(inprg.empty()))
    {
        int step = inprg.front();
        
        inprg.pop();
        
        for (Graph::Edge item : g._nodes[step])
        {
            if (!(check[item.dst]))
            {
                check[item.dst] = true;
                
                inprg.push(item.dst);
                
                length[item.dst] = length[item.dst] + 1;
                
                root[item.dst] = step;
                
                if (item.dst == dst)
                {
                    break;
                }
            }
        }
    }
    
    if (!(check[dst]))
    // will not let while loop run if before then function doesnt work placemnet is important
    {
        return string::npos;
    }
    
    for (int n = dst; n != -1; n = root[n])
    {
        path.insert(path.begin(), n);
    }
    
    return path.size();
}

size_t Gx::get_shortest_weighted_path(const Graph& g, int src, int dst, std::vector<int>& path)
{
    int cycles = g.get_num_nodes();
    
    path.clear();
    
    if (src == dst)
    {
        path.resize(1);
        
        path[0] = src;
        
        return path.size();
    }
    
    if (src >= cycles)
    {
        return string::npos;
    }
    else if (dst >= cycles)
    {
        return string::npos;
    }
    else if (src < 0)
    {
        return string::npos;
    }
    else if (dst < 0)
    {
        return string::npos;
    }
    
   // path.clear();
    
    vector<NW> vertex;
    
    //int n = 0;
    
   // while(n < cycles)
    for (int n = 0; n < cycles; n++)
    {
        vertex.push_back(NW(n, -1, 999999999999.f));
        
        //n++;
    }
    
    priority_queue<NW, vector<NW> > nextside;
    
    nextside.push(NW(src, src, 0));

    while (!(nextside.empty()))
    {
        NW nextnode = nextside.top();
        
        nextside.pop();

        if (vertex[nextnode.node].weight < nextnode.weight)
        {
            continue;
        }

        for (Graph::Edge currentside : g._nodes[nextnode.node])
        {
            if (vertex[currentside.dst].weight > (nextnode.weight + currentside.wt))
            {
                //vertex[currentside.dst].pred = nextnode.node;
                
                vertex[currentside.dst].weight = nextnode.weight + currentside.wt;
                
                vertex[currentside.dst].pred = nextnode.node;
                
                nextside.push(NW(currentside.dst, nextnode.node, nextnode.weight + currentside.wt));
                
            }
        }
    }
    
    if (vertex[dst].pred == -1)
    // will not let while loop run if before then function doesnt work placemnet is important
    {
        return string::npos;
    }

    for (int n = dst; n != src; n = vertex[n].pred)
    {
        path.insert(path.begin(), n);
    }
    
    path.insert(path.begin(), src);
    
    return path.size();
}

float Gx::get_max_flow(const Graph& g, int src, int dst)
{
    return 0;
}

void Gx::reachcheck(const Graph& g, int src, vector<bool>& reachcheckvar)
// used to check if the item is reachable for the unreachable function to run using recusriosnm couldn't figure
// out how to do it wihtout this
{
    reachcheckvar[src] = true;

   for (size_t n = 0; n < g._nodes[src].size(); n++)
   {
      if (!reachcheckvar[g._nodes[src][n].dst])
      {
          reachcheck(g, g._nodes[src][n].dst, reachcheckvar);
      }
   }
}
