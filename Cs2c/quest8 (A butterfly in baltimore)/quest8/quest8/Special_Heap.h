//student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <climits>
#include "Heap.h"

#ifndef Special_Heap_h
#define Special_Heap_h

template <typename T>
class Special_Heap : public Heap<T> {
public:
  
    Special_Heap() : Heap<T>() {};
    Special_Heap(const vector<T>& vec) : Heap<T>(vec) {}

    const vector<T>& get_least_k(size_t k)
    {
        
        if (!(k > this->_size))
        {
            size_t n = 0;
            
            while (n < k)
            {
                T set = this -> _elems[1];
              
                this -> delete_min();
               
                this -> _elems[this -> _size + 1] = set;
                
                n++;
            }
            
            this -> _size = 0;
            
            return this -> _elems;
        }
       
         return this -> _elems;
         
       
        
    //attempting rewrtite for effeicney and cleaning up
     
        /*
        if (k > this->_size)
        {
            return this->_elems;
        }

        for (size_t n = 0; n < k; n++)
        {
            T set = this -> _elems[1];
          
            this -> delete_min();
          
            this -> _elems[this -> _size + 1] = set;
        }
        
        this -> _size = 0;
        
        return this -> _elems;
        */
       
       //return this -> _elems;
    }

    friend class Tests;
};

#endif 
