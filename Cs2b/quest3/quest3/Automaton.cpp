// student id: 20481838

#include "Automaton.h"

#include <string>
#include <vector>

using namespace std;

Automaton::Automaton(size_t num_parents, size_t rule)
{
    if (num_parents > MAX_PARENTS)
    {
        _is_valid = false;
        _num_parents = 0;
    }
    else
    {
        _num_parents = num_parents;
        set_rule(rule);
    }

    _extreme_bit = 0;
}

bool Automaton::set_rule(size_t rule)
{
    bool output = false;

    _rules.clear();
    _rules.resize(pow_2(_num_parents));

    if (_num_parents > MAX_PARENTS || rule >= pow_2(pow_2(_num_parents)))
    {
        _is_valid = false;
    }
    else
    {
        for (int i = 0; rule > 0; i++)
        {
            _rules[i] = rule % 2;
            rule /= 2;
        }

        _is_valid = true;
        
        output = true;
    }

    return output;
}

bool Automaton::equals(const Automaton& that)
{
    bool output = false;

    if (this -> _is_valid == false && that._is_valid == false)
    {
        output = true;
    }
    
    if (this -> _is_valid == true && that._is_valid == true && this -> _num_parents == that._num_parents && this -> _rules == that._rules && this -> _extreme_bit == that._extreme_bit)
    {
        output = true;
    }
        
    return output;
}

bool Automaton::make_next_gen(const vector<int>& current_gen, vector<int>& next_gen)
{
    bool output = false;

    if (_is_valid && ((current_gen.size() % 2) || !current_gen.size()))
    {
        if (!current_gen.size())
        {
            next_gen = { 1 };
            _extreme_bit = 0;
        }
        
        else
        {
            vector<int> inprg(current_gen);

            for (size_t n = 0; n < _num_parents - 1; n++)
            {
                inprg.insert(inprg.begin(), _extreme_bit);
                inprg.push_back(_extreme_bit);
            }

            next_gen.resize(current_gen.size() + _num_parents - 1);

            for (size_t n = 0; n < next_gen.size(); n++)
            {
                next_gen[n] = _rules[translate_n_bits_starting_at(inprg, n, _num_parents)];
            }

            if (_extreme_bit)
            {
                _extreme_bit = _rules.back();
            }
            else
            {
                _extreme_bit = _rules.front();
            }
        }

        output = true;
    }

    return output;
}

string Automaton::get_first_n_generations(size_t n, size_t width)
{
    string output;

    if (_is_valid && width % 2)
    {
        vector<int> inprg;

        while (n--)
        {
            make_next_gen(inprg, inprg);
            
            output += generation_to_string(inprg, width) + "\n";
        }
    }

    return output;
}

string Automaton::generation_to_string(const vector<int>& gen, size_t width)
{
    string strg = "";
    
    if (width % 2 == 0)
    {
        return strg;
    }
    
    if (gen.size() % 2 == 0)
    {
        return strg;
    }
    
    for (size_t n = 0; n < gen.size(); n++)
    {
        if (gen[n] == 1)
        {
            strg += "*";
        }
        else
        {
            strg += " ";
        }
    }
    
    if (gen.size() < width)
    {
        for (size_t n = 0; n < (width-gen.size())/2; n++)
        {
            string xstrg = " ";
            
            if (_extreme_bit == 1)
            {
                xstrg = "*";
            }
            
            strg.insert(0, xstrg);
            
            strg.insert(strg.size(), xstrg);
        }
    }
    
    if (gen.size() > width)
    {
        strg.erase(strg.begin(), strg.begin() + (gen.size()-width) / 2);
        
        strg.erase(strg.end() - (gen.size()-width) / 2, strg.end());
    }
    
    return strg;
}

size_t Automaton::translate_n_bits_starting_at(const vector<int>& bits, size_t pos, size_t n)
{
    size_t output = 0;

    if (pos + n <= bits.size())
    {
        for (size_t i = pos; i < pos + n; i++)
        {
            output *= 2;
            
            output += bits[i];
        }
    }

    return output;
}
