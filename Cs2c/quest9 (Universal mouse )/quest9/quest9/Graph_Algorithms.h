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

#ifndef Graph_Algorithms_h
#define Graph_Algorithms_h

class Gx {
private:
    struct NW {
        int node, pred;
          float weight;
          NW(int n, int m, float wt) : node(n), pred(m), weight(wt) {}
          bool operator<(const NW& that) const { return this->weight > that.weight; }
          bool operator>(const NW& that) const { return this->weight < that.weight; }
    };
   
      static float _get_capacity_of_this_path(const Graph& g, const std::vector<int>& path);
      static float _get_max_capacity_path(const Graph& g, int src, int dst, std::vector<int>& path);
      static bool _is_cyclic(const Graph& g, size_t node, std::vector<bool> seen, std::vector<bool>& cycle_free);
   
public:
      static bool is_cyclic(const Graph& g);
      static bool prune_unreachables(Graph& g, int src);
      static size_t get_shortest_unweighted_path(const Graph& g, int src, int dst, std::vector<int>& path);
      static size_t get_shortest_weighted_path(const Graph& g, int src, int dst, std::vector<int>& path);

      static float get_max_flow(const Graph& g, int src, int dst);
      
      // my reach check to use recursion for the prune unreachables couldn't figire out how to do wihtout helper
      static void reachcheck(const Graph& g, int src, vector<bool>& reachcheckvar);
   
      friend class Tests;
 };

#endif
