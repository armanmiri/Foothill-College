//student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <math.h>

#ifndef Hash_Table_LP_h
#define Hash_Table_LP_h

using namespace std;

template <typename T> size_t Hash(const T& item);

template <typename T>
class Hash_Table_LP
{

protected:

    struct Entry
    {
        T _data;
    
        enum STATE { ACTIVE, VACANT, DELETED } _state;
      
        Entry(const T& d = T(), STATE st = VACANT) : _data(d), _state(st) {}
   };

    static const size_t DEFAULT_INIT_CAPACITY = 3;
   
    vector<Entry> _elems;
   
    size_t _size;
   
    size_t _num_non_vacant_cells;
   
    float _max_load_factor;
   
    virtual size_t _get_hash_modulus(const T& item) const
    {
        return Hash<T>(item) % _elems.size();
    }
    
    virtual void _rehash()
    {
        vector<Entry> inprg;
        
        size_t n = 0;
        
        while (n < _elems.size())
        {
            if (Entry::ACTIVE == _elems[n]._state)
            {
                inprg.push_back(Entry(_elems[n]));
                
                 _elems[n]._state = Entry::VACANT;
            }
            
            n++;
        }
        
        _grow_capacity();

        _num_non_vacant_cells = 0;

        _size = 0;
        
        size_t p = 0;
        
        while (p < inprg.size())
        {
            if (Entry::ACTIVE == inprg[p]._state)
            {
                insert(inprg[p]._data);
            }
            
            p++;
        }
        
    }
    
    virtual bool set_max_load_factor(float x)
    {
        if (x > 0 && x <= _get_biggest_allowed_max_load_factor())
        {
            _max_load_factor = x;
            
            return true;
        }
    
        return false;
    }
    
    virtual float _get_biggest_allowed_max_load_factor() const
    {
        return 0.75;
    }
    
    virtual size_t _find_pos(const T& item) const
    {
        if (_num_non_vacant_cells >= _elems.size())
        {
            return string::npos;
        }
        else if (_elems.size() <= 0)
        {
            return string::npos;
        }

        size_t c = _get_hash_modulus(item);
        
        size_t s = _elems.size();
        
        while (Entry::VACANT != _elems[c % s]._state)
        {
            if (item == _elems[c % s]._data)
            {
                break;
            }
            
            c++;
        }

        return (c % s);
    }
    
    virtual void _grow_capacity()
    {
        if (!(0 >= _elems.size()))
        {
            size_t newsize = _elems.size() * 2;
            
            size_t orignal = _elems.size();
            
            size_t n = orignal;
            
            while (n < newsize)
            {
                _elems.push_back(Entry());
                
                n++;
            }
        }
        else
        {
            return;
        }
    }
    
public:
    
    Hash_Table_LP(size_t n = DEFAULT_INIT_CAPACITY)
    {
        if (0 < n)
        {
           _elems.resize(n);
        }
        else
        {
           _elems.resize(DEFAULT_INIT_CAPACITY);
        }
         
         _num_non_vacant_cells = 0;
         
         _size = 0;
         
         _max_load_factor = _get_biggest_allowed_max_load_factor();
         
     }
    
    size_t get_size() const
    {
        return _size;
    }

    bool is_empty() const
    {
        return _size == 0;
    }
    
    bool contains(const T& item) const
    {
        try
        {
            size_t p = _find_pos(item);
                        
            if (_elems[p]._state == Entry::VACANT)
            {
                throw Not_found_exception();
            }
            if (p == string::npos)
            {
                throw Table_full_exception();
            }
            else
            {
                return true;
            }
        }
        
        catch (Not_found_exception othecptin)
        {
           cout << othecptin.to_string() << endl;
            
           return false;
        }
        
        catch (Table_full_exception ecptin)
        {
           cout << ecptin.to_string() << endl;
            
           return false;
        }
    }
    
    T& find(const T& item)
    {
        size_t p = _find_pos(item);
        
        if (_elems[p]._state == Entry::VACANT)
        {
          throw Not_found_exception();
        }
        else if (p == string::npos)
        {
           throw Table_full_exception();
        }
        else
        {
            return _elems[p]._data;
        }
    }
         

    
    bool clear()
    {
        size_t n = 0;
        
        while (n < _elems.size())
        {
           _elems[n]._state = Entry::VACANT;
        }
         
        return true;
         
    }
    
    bool insert(const T& item)
    {
        size_t p = _find_pos(item);
        
        if (Entry::DELETED == _elems[p]._state)
        {
            _elems[p]._state = Entry::ACTIVE;
            
            _size++;
        }
        else if (Entry::ACTIVE == _elems[p]._state)
        {
            return false;
        }
        else if (p == string::npos)
        {
            return false;
        }
        else if (_elems[p]._state == Entry::VACANT)
        {
           _elems[p]._data = item;
           
           _elems[p]._state = Entry::ACTIVE;
          
           _num_non_vacant_cells++;
         
           _size++;

       }

       if (_num_non_vacant_cells > (_elems.size() * _max_load_factor))
       {
           _rehash();
       }
       
       return true;
    }
    
    bool remove(const T& item)
    {
        size_t p = _find_pos(item);
        
        if (Entry::DELETED == _elems[p]._state)
        {
            return false;
        }
        else if (Entry::ACTIVE == _elems[p]._state)
        {
            _elems[p]._state = Entry::DELETED;
             
            _size--;
        }
        else if (p == string::npos)
        {
            return false;
        }
        else if (_elems[p]._state == Entry::VACANT)
        {
            return false;

       }
        
       return true;
    }
    
    class Table_full_exception : public exception
    {
       public:
        
        const string to_string() const throw()
        {
            return string("Table full exception");
        }
    };
    
    class Not_found_exception :public exception
    {
       public:
        
        const string to_string() const throw()
        {
            return string("Not found exception");
        }
    };

    friend class Tests;
 };

 #endif

