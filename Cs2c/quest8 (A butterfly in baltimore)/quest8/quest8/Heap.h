//student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <math.h>

#ifndef Heap_h
#define Heap_h

using namespace std;

template <typename T> T get_sentinel();

template <typename T>
class Heap
{
protected:
    
    vector<T> _elems;
    size_t _size;
    static const int INIT_HEAP_CAPACITY = 128;

public:
    
    bool _percolate_down(size_t pos)
    {
        if (pos <= 0 || _size < pos)
        {
            return false;
        }
            
        size_t min = pos;
        
        size_t leftmin = 2 * pos;
        
        size_t rightmin = 2 * pos + 1;
        
        if (_elems[leftmin] < _elems[min])
        {
            if (leftmin <= _size)
            {
                min = leftmin;
            }
        }
        
        if (_elems[rightmin] < _elems[min])
        {
            if (rightmin <= _size)
            {
                min = rightmin;
            }
        }
        
        if (pos != min)
        {
            T inprg = _elems[pos];
            
            _elems[pos] = _elems[min];
            
            _elems[min] = inprg;
            
            _percolate_down(min);
        }
        
        return true;
    //     }
       // return false;
    }
    
    bool _heapify()
    {
        if (!is_empty())
        {
            size_t n = (_size / 2 + 1);
            
            while (n > 0)
            {
                _percolate_down(n);
                
                n--;
            }
        
            return true;
        }
            return false;
    }
    
public:
   
    Heap()
    {
        _elems.resize(INIT_HEAP_CAPACITY);
        
        _elems[0] = get_sentinel<T>();
        
        _size = 0;
    }
    
    Heap(const vector<T>& vec)
    {
        _size = vec.size();
        
        _elems.resize(_size + 1);
        
        _elems[0] = get_sentinel<T>();
        
        size_t n = 1;
        
        while(n <= vec.size())
        {
            _elems[n] = vec[n - 1];
            
            n++;
        }
          
        this -> _heapify();
    }
    
    virtual bool is_empty() const
    {
        return _size == 0;
    }
    
    virtual bool insert(const T& elem)
    {
        if (!(elem < _elems[0]))
        {
            _size++;

            if (_elems.size() <= _size)
            {
               _elems.resize(_elems.size() * 2);
            }
            
            size_t size = _size;
            
            size_t mstrsize = size / 2;

            while (elem < _elems[mstrsize])
            {
                _elems[size] = _elems[mstrsize];
               
                size = mstrsize;
              
                mstrsize = size / 2;
            }
           
            _elems[size] = elem;
            
            return true;
        }
       
        return false;
    }
    
    virtual bool delete_min()
    {
        if (!(is_empty()))
        {
            _elems[1] = _elems[_size];
            
            _size--;
            
            _percolate_down(1);
            
            return true;
        }
   
        return false;
    }
    
    virtual const T& peek_min() const
    {
        if (!(is_empty()))
        {
            return _elems[1];
        }
        else
        {
            return _elems[0];
        }
    }
    
    virtual string to_string() const
    {
      
        stringstream cur, lft, rgt;
        
        cur << _elems[1];
        
        string result = "# Heap with min = " + cur.str() + "\n";
          
        result += "# Size = " + std::to_string(_size) + "\n";

       // size_t n = 1;
        
          //while (n <= _size)
          for (size_t n = 1; n <= _size; n++)
          {
             size_t lftndx = 2 * n;
             size_t rghtndx = 2 * n + 1;
             string lftchld = "-";
             string rgtchld = "-";

             if (lftndx > _size)
             {
                 if (rghtndx > _size)
                 {
                     continue;
                 }
             }
             
              if (lftndx <= _size)
             {
                 lft.str(std::string());
              
                 lft << _elems[lftndx];
                
                 lftchld = lft.str();
             }
              
             if (rghtndx <= _size)
             {
                 rgt.str(std::string());
                
                 rgt << _elems[rghtndx];
               
                 rgtchld = rgt.str();
             }
              
              cur.str(std::string());
           
              cur << _elems[n];
            
              result += cur.str() + " : " + lftchld + " " + rgtchld + "\n";
              
              //n++;
          }
        
        result += "# End of heap\n";
          
        return result;
         
         
        
         // return "empty";

    }

    friend class Tests;
 };

#endif 
