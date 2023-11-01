//student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <math.h>

#ifndef Pivoting_h
#define Pivoting_h

using namespace std;


template <typename T>
class Pivoting {
private:
   
    static size_t _partition(vector<T>& elems, size_t lo, size_t hi)
    {
        T inprg;
        
        size_t pivot = lo + (hi - lo) / 2;
        
        T val = elems[pivot];
    
        while (lo < hi)
        {
            if (elems[lo] < val)
            {
                lo++;
                
                if (val < elems[hi])
                {
                    hi--;
                }
            }
            else if (val < elems[hi])
            {
                hi--;
                
                if (elems[lo] < val)
                {
                    lo++;
                }
            }
            else
            {
                inprg = elems[lo];
                
                elems[lo] = elems[hi];
                
                elems[hi] = inprg;
                
                hi--;
                
                lo++;
                
            }
        }
        
        if (val < elems[hi])
        {
           return hi - 1;
        }
        
        return hi;
    }

    static void _do_qsort(vector<T>& elems, size_t lo, size_t hi)
    {
        if (!(hi <= lo))
        {
          size_t pivot = _partition(elems, lo, hi);

          _do_qsort(elems, lo, pivot);
            
          _do_qsort(elems, pivot + 1, hi);
        }
        else
        {
            return;
        }
    }

    static T _find_kth_least_elem(vector<T>& elems, size_t lo, size_t hi, size_t k)
    {
       if (hi == lo)
       {
           return elems[lo];
       }

       size_t point = _partition(elems, lo, hi);
       
       if (point < k)
       {
           return _find_kth_least_elem(elems, point + 1, hi, k);
       }
       else if (point >= k)
       {
           return _find_kth_least_elem(elems, lo, point, k);
       }
   
        return elems[k];
    }

public:
   static T find_median(vector<T>& elems)
    {
       size_t size = elems.size();
       
       size_t median = size / 2;
     
       return _find_kth_least_elem(elems, 0, size - 1, median);
    }

    static T find_kth_least_elem(vector<T>& elems, size_t k)
    {
        if (k >= 0)
        {
            if (k < elems.size())
            {
                return _find_kth_least_elem(elems, 0, elems.size() - 1, k);
            }
        }
    
        return T();
        
    }

    static void do_qsort(vector<T>& elems)
    {
        _do_qsort(elems, 0, elems.size() - 1);;
    }

    friend class Tests;
};

#endif
