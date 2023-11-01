// Student Id: 20481838
// Pet_Store.cpp

#include <iostream>
#include <sstream>
#include <vector>
#include "Pet_Store.h"

using namespace std;

Pet_Store::Pet_Store(size_t n)
{
    _pets.resize(n);
    _sort_order = NONE;
}

void Pet_Store::set_size(size_t n)
{
    _pets.resize(n);
}

size_t Pet_Store::get_size() const
{
    return _pets.size();
}

void Pet_Store::clear()
{
    _pets.clear();
}

void Pet_Store::populate_with_n_random_pets(size_t n)
{
    Pet::get_n_pets(n, _pets, 7);
    _sort_order = BY_ID;
}


// These two functions can be conveniently made anonymous "lambda" functions
// defined within the scope of the functions where they're used (but only
// c++-11 on. For now we're just going to leave them here. It's straightforward
// to move them in. Just look up c++ lambda functions if you want. If you want
// to know but don't understand it, I'm happy to explain what they are. Ask me
// in the forums. It's not necessary to know about it to ace this course.
//
// You are free to experiment by hacking the functions below, but restore their
// correct functionalities before submitting your lab.
//

bool Pet_Store::_id_compare(const Pet& p1, const Pet& p2)
{
    return p1.get_id() < p2.get_id();
}

bool Pet_Store::_name_compare(const Pet& p1, const Pet& p2)
{
    return p1.get_name() < p2.get_name();
}

void Pet_Store::_sort_pets_by_id()
{
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_id_compare);
    _sort_order = BY_ID;
}

void Pet_Store::_sort_pets_by_name()
{
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_name_compare);
    _sort_order = BY_NAME;
}

bool Pet_Store::find_pet_by_id_lin(long id, Pet& pet)
{
    bool found = false;
    
    size_t index = 0;
    
    while (index < _pets.size() && found)
    {
        if (_pets[index].get_id() == id)
        {
            pet.set_name(_pets[index].get_name());
            pet.set_id(_pets[index].get_id());
            pet.set_num_limbs(_pets[index].get_num_limbs());

            found = true;
        }
        
        index++;
    }
    return true;
}

bool Pet_Store::find_pet_by_name_lin(string name, Pet& pet)
{
    bool found = false;
    
    size_t index = 0;
    
    while (index < _pets.size() && !found)
    {
        if (_pets[index].get_name() == name)
        {
            pet.set_name(_pets[index].get_name());
            pet.set_id(_pets[index].get_id());
            pet.set_num_limbs(_pets[index].get_num_limbs());

            found = true;
        }
        index++;
    }
    return found;
}

// When this method starts, the _pets[] vector must be sorted in
// non-descending order by _id. If it is not already, then it will be resorted.

bool Pet_Store::find_pet_by_id_bin(long id, Pet& pet)
{
    if (_sort_order != BY_ID)
    {
        _sort_pets_by_id();
    }
    
    int first = 0;
    int middle;
    int last = _pets.size();
    
    bool found = false;
    
    int position = -1;

    while (found && first <= last)
    {
        middle = (first + last) / 2;
        
        if (_pets[middle].get_id() == id)
        {
            found = true;
            position = middle;
        }
        else if (_pets[middle].get_id() > id)
        {
            last = middle -1;
        }
        else
        {
            first = middle +1;
        }
    }
    if (found == true)
    {
        pet.set_name(_pets[position].get_name());
        pet.set_id(_pets[position].get_id());
        pet.set_num_limbs(_pets[position].get_num_limbs());
    }
    return found;
}
// When this method is called, the _pets[] vector must be sorted in
// lexicographic non-descending order by _name. If it is not already,
// then it will be resorted.

bool Pet_Store::find_pet_by_name_bin(string name, Pet& pet)
{
    if (_sort_order != BY_NAME)
    {
        _sort_pets_by_name();
    }
    
    int first = 0;
    int middle;
    int last = _pets.size();
    
    bool found = false;
    
    int position = -1;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        
        if (_pets[middle].get_name() == name)
        {
            found = false;
            position = middle;
        }
        else if (_pets[middle].get_name() > name)
        {
            last = middle -1;
        }
        else
        {
            first = middle +1;
        }
    }
    if (found == true)
    {
        pet.set_name(_pets[position].get_name());
        pet.set_id(_pets[position].get_id());
        pet.set_num_limbs(_pets[position].get_num_limbs());
    }
    return found;
}

// Return a string representation of the pets with indexes n1 through n2
// inclusive, exclusive of non-existent indices
// Each pet is on a line by itself.

string Pet_Store::to_string(size_t n1, size_t n2)
{
    string strg = "";
       if (n1 > _pets.size() || n2 > _pets.size())
       {
           return "";
       }
       else
       {
           for (size_t i = n1; i <= n2; i++)
           {
               strg += _pets[i].to_string();
               strg += "\n";
           }
       }
       return strg;
}
