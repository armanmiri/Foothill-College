// student id: 20481838

#ifndef fish_h
#define fish_h

#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

template <typename T>

class Set {

private:
    
    vector<T> *_master_ptr;
    
    vector<size_t> _elems;
    
    size_t _sum;
        
public:
    
    Set(vector<T> *mast_ptr = nullptr) : _master_ptr(mast_ptr), _sum(0) {};
    
    const size_t size() const
    {
        return _elems.size();
    }
    
    const vector<T> *get_master_ptr() const
    {
        return _master_ptr;
    }
    
    const size_t get_sum() const
    {
        return _sum;
    }
    
    bool add_elem(size_t n)
    {
        if (!(_master_ptr == nullptr))
        {
            if (n < _master_ptr -> size())
            {
            
            _elems.push_back(n);
            
            _sum = _sum + (*_master_ptr)[n];
            
            return true;
            
            }
        }
        
        return false;
        
    }

    bool add_all_elems()
    {
        bool fulllist = true;
        
        for (size_t n = 0; n < this -> _master_ptr -> size(); n++)
        {
            fulllist = this -> add_elem(n);
        }
        
        return fulllist;
    }
    
    
    Set<T> find_biggest_subset_le(size_t target)
    {
        bool finalsolution = false;
        
        size_t bestsolution = 0;
        
        size_t numsolutions = 1;
        
        vector <Set> choices;
        
        Set <T> blank;
        
        choices.push_back(blank);
        
        size_t i = 0;
        
        while (i < _master_ptr -> size())
        {
            size_t r = 0;
            
            while (r < numsolutions)
            {
                if (choices[r].get_sum() + (*_master_ptr)[i] <= target)
                {
                    Set addition (_master_ptr);
                    
                    size_t q = 0;
                    
                    while ( q < choices[r]._elems.size())
                    {
                        addition.add_elem(choices[r]._elems[q]);
                        
                        q++;
                        
                    }
                           
                    addition.add_elem(i);
                    
                    choices.push_back(addition);
                    
                    }
                
                if (choices[r].get_sum() + (*_master_ptr)[i] == target)
                {
                    choices[r].add_elem(i);
                    
                    finalsolution = true;
                    
                    return choices[r];
                    
                }
                    r++;
            }
            
            numsolutions = choices.size();
            
            i++;
        }
        
        if (!(finalsolution))
        {
            size_t t = 0;
            
            while (t < choices.size())
            {
                
                if (choices[bestsolution].get_sum() < choices[t].get_sum())
                {
                    bestsolution = t;
                }
            
                t++;
                
            }
    
        }
        
        return choices[bestsolution];
    }
    
    friend ostream &operator<<(ostream& os, const Set<T> &set)
    {
        const vector<T> *mast_ptr = set.get_master_ptr();
        
        os << "{\n";
        
        for (size_t index : set._elems)
        {
            os << " " << mast_ptr->at(index) << "\n";
        }
        
        return os << "}";
    }
    
    friend class Tests;
    
};
        
#endif /* fish_h */
