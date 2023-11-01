//student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <math.h>

#ifndef Hash_Table_QP_h
#define Hash_Table_QP_h

#include "Hash_Table_LP.h"

using namespace std;

template <typename T> size_t Hash(const T& item);

template <typename T>

class Hash_Table_QP : public Hash_Table_LP<T>
{
public:

    Hash_Table_QP(size_t n = Hash_Table_LP<T>::DEFAULT_INIT_CAPACITY) : Hash_Table_LP<T>(n)
    {
      this->_max_load_factor = _get_biggest_allowed_max_load_factor();
    }

protected:
   
    virtual float _get_biggest_allowed_max_load_factor() const
    {
      return 0.49;
    }

    virtual size_t _find_pos(const T& item) const
    {
        size_t testing = 1;
       
        return testing;
    }

    virtual void _grow_capacity()
    {
       return;
    }

   
    static size_t _next_prime(size_t n)
    {
        bool test = true;
        
        if (n < 2)
        {
            return 2;
        }
        
        if (n < 0)
        {
            return string::npos;
        }
            
        n++;
        
        while (test)
        {
            if (n <= 5)
            {
                if (n % 5 == 0)
                {
                    return n;
                }
                if (n % 3 == 0)
                {
                    return n;
                }
            }
            
            if(n % 2 == 0)
            {
                n++;
            
                continue;
            }
            if (n % 3 == 0)
            {
                n++;
                
                continue;
            }
                double sqrtfunc = sqrt(n);
                
                if (sqrtfunc - floor(sqrtfunc) == 0)
                {
                    n++;
                
                    continue;
                }
                
                size_t ceiling = ceil(sqrtfunc);
                
                size_t sqrtsix = ceiling / 6;
                
                bool prime = true;
                
                size_t r = 1;
                
                while(r <= sqrtsix)
                {
                    if (n % (6 * r - 1) == 0)
                    {
                        n++;
                        
                        prime = false;
                        
                        break;
                    }
                    
                    if (n % (6 * r + 1) == 0)
                    {
                        n++;
                        
                        prime = false;
                        
                        break;
                        
                    }
                    
                    r++;
                }
                
                if (prime)
                {
                    break;
                }
            }
        
        return n;
    }

   friend class Tests;
};

#endif
