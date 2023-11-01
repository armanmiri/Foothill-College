// student id: 20481838

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#include "Graph.h"
using namespace std;

void Graph::make_silly_snake()
{
    _nodes.clear();

    add_edge(0, 1, "i-see");
    add_edge(1, 2, "the-silly-snake");
    add_edge(2, 3, "i-be");
    add_edge(3, 4, "you-saw-me");
    add_edge(4, 5, "once-like");
    add_edge(5, 0, "kekule");
};

void Graph::make_mr_sticky()
{
    _nodes.clear();
    
    add_edge(0, 1, ".");
    add_edge(1, 2, ".");
    add_edge(1, 3, ".");
    add_edge(1, 4, ".");
    add_edge(4, 5, ".");
    add_edge(4, 6, ".");
};

void Graph::make_driftin_dragonfly()
{
    _nodes.clear();

    add_edge(0, 1, "dis-be-me-head");
    add_edge(1, 2, "me");
    add_edge(1, 5, "dis-be-me");
    add_edge(1, 9, "dis-be-me");
    add_edge(2, 3, "long-tail");
    add_edge(3, 4, "be-dis");
    add_edge(5, 6, "front-right");
    add_edge(6, 7, "me-right");
    add_edge(7, 8, "back");
    add_edge(8, 2, "be-dis");
    add_edge(9, 10, "front-left");
    add_edge(10, 11, "and-left");
    add_edge(11, 12, "back");
    add_edge(12, 2, "be-dis");
};

void Graph::make_slinky_star()
{
    _nodes.clear();
    add_edge(0, 1, "-");
    add_edge(0, 3, "-");
    add_edge(0, 5, "-");
    add_edge(0, 7, "-");
    add_edge(0, 9, "-");
    add_edge(0, 11, "-");
    add_edge(0, 13, "-");
    add_edge(1, 2, "-");
    add_edge(3, 4, "-");
    add_edge(5, 6, "-");
    add_edge(7, 8, "-");
    add_edge(9, 10, "-");
    add_edge(11, 12, "-");
    add_edge(13, 14, "-");
};

void Graph::make_kathy_da_grate()
{
    _nodes.clear();
    
    add_edge(0, 1, "-");
    add_edge(0, 5, "-");
    add_edge(1, 2, "-");
    add_edge(1, 7, "-");
    add_edge(2, 3, "-");
    add_edge(2, 9, "-");
    add_edge(3, 4, "-");
    add_edge(3, 11, "-");
    add_edge(4, 0, "-");
    add_edge(4, 13, "-");
    add_edge(5, 6, "-");
    add_edge(7, 8, "-");
    add_edge(9, 10, "-");
    add_edge(11, 12, "-");
    add_edge(13, 14, "-");
};
void Graph::make_dodos_in_space()
{
    _nodes.clear();
    
    for (size_t n = 0; n < 50; n += 2)
    {
        string strg;
        
        strg = "Yippee-Dodo-#";
        
        strg += std::to_string(n);
        
        add_edge(n, n + 1, strg);
    }
};



void Graph::make_purty_pitcher()
{
    _nodes.clear();

    add_edge(2, 3, ".");
    add_edge(3, 7, ".");
    add_edge(4, 9, ".");
    add_edge(5, 4, ".");
    add_edge(7, 4, ".");
    add_edge(8, 6, ".");
    add_edge(9, 2, ".");
    add_edge(10, 8, ".");
    add_edge(11, 13, ".");
    add_edge(12, 18, ".");
    add_edge(13, 15, ".");
    add_edge(14, 13, ".");
    add_edge(15, 15, ".");
    add_edge(16, 13, ".");
    add_edge(17, 19, ".");
    add_edge(18, 12, ".");
    add_edge(19, 24, ".");
    add_edge(20, 2, ".");
    add_edge(21, 20, ".");
};
