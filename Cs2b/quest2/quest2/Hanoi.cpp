// Student ID: 20481838

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Hanoi.h"

using namespace std;

std::string Hanoi::lookup_moves(int num_discs, int src, int dst)
{
    string strg;
    
    if(_cache.size() > unsigned(num_discs))
    {
            
        if(_cache[num_discs].size() > unsigned(src))
        {
            
            if(_cache[num_discs][src].size() > unsigned(dst))
            {
                strg = _cache[num_discs][src][dst];
            }
        }
    }
    
    return strg;

}

std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp)
{
    string strg = lookup_moves(num_discs, src, dst);

    if (_cache.size() < unsigned(num_discs) + 1)
    {
        _cache.resize(num_discs + 1);
    }

    if (_cache[num_discs].size() < unsigned(src) + 1)
    {
        _cache[num_discs].resize(src + 1);
    }

    if (_cache[num_discs][src].size() < unsigned(dst) + 1)
    {
        _cache[num_discs][src].resize(dst + 1);
    }

    if (strg.length() == 0)
    {
        if (num_discs == 1)
        {
            strg = to_string(src) + "->" + to_string(dst) + "\n";
        }
        else if (num_discs > 1)
        {
            strg += get_moves(num_discs - 1, src, tmp, dst);
           
            strg += get_moves(1, src, dst, tmp);
            
            strg += get_moves(num_discs - 1, tmp, dst, src);

            if (_cache[num_discs - 1].size() > 0)
            {
                _cache[num_discs - 1].clear();
            }
        }

        _cache[num_discs][src][dst] = strg;
    }

    return strg;
}

std::string Hanoi::solve(int num_discs, int src, int dst, int temp)
{
    return "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n" + get_moves(num_discs, src, dst, temp);
}
