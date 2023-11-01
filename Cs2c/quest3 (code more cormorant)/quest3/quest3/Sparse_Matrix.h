//student id: 20481838

#ifndef Sparse_Matrix_h
#define Sparse_Matrix_h

#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <list>

using namespace std;

template <typename T>

class Sparse_Matrix {

private:
    static double constexpr FLOOR = 1e-10;
    
    struct Node {
        size_t _col;
        T _val;
        
        Node(size_t c, const T &v) : _col(c), _val(v) {}
        
        size_t get_col() const
        {
            return _col;
        };
        
        const T get_val() const
        {
            return _val;
        };
        
        void set_val(const T &val)
        {
            _val = val;
        }
        
        virtual const T &operator=(const T& val)
        {
            return _val = val;
        }
        
        friend ostream& operator<<(ostream& os, const Node &node)
        {
            return os << "{ C: " << node.col << ", V: " << node.value << " }";
        }
    };
    
    
    vector<list<Node>> _rows;
    
    size_t _num_rows, _num_cols;
    
    T _default_val;
    
public:
    
    Sparse_Matrix(size_t nr = 0, size_t nc = 0, const T &default_val = T()) :
    _num_rows(nr), _num_cols(nc), _default_val(default_val)
    {
        _rows.resize(nr);
    }
    
    size_t get_num_rows() const
    {
        return _num_rows;
    };
    
    size_t get_num_cols() const
    {
        return _num_cols;
    }
    
    bool is_valid(size_t r, size_t c) const
    {
        if(c >= get_num_cols())
        {
            return false;
        }
        if(r >= get_num_rows())
        {
            return false;
        }
            return true;
        }
        
    
    void clear()
    {
        size_t n = 0;
        
        while (n < get_num_rows())
        {
            _rows[n].clear();
            
            n++;
        }
    }
    
    const T get(size_t r, size_t c) const
    {
        if(is_valid(r,c))
        {
            for(const auto &elem : _rows[r])
            {
                if(elem.get_col() > c)
                {
                    break;
                }
                
                else if(c == elem.get_col())
                {
                    return elem.get_val();
                }
            }
            
            if (_rows[r].empty())
            {
                return _default_val;
            }
        }
            return _default_val;
    }
    
    bool defaultval(const double &val) const
    // needed in order to fulter out the defualt case in my code using _default_val = val didnt do it
    {
        if(Sparse_Matrix<T>::FLOOR > (val - Sparse_Matrix<T>::_default_val))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    bool set(size_t row, size_t col, const T &val)
     
    {
        if(is_valid(row, col))
        {
            for(auto &elem : _rows[row])
            {
                if (col == elem.get_col() && defaultval(val))
                {
                    _rows[row].remove(elem);
                    
                    return true;
                }
                else if (col == elem.get_col())
                {
                    elem.set_val(val);
                    
                    return true;
                }
                
                if (col < elem.get_col() && defaultval(val))
                {
                    return true;
                }
                else if (col < elem.get_col())
                {
                    Node inprgnde(col, val);
                    
                    elem.set_val(val);
                    
                    return true;
                }
                
            }
            
            Node finalnde(col, val);
            
            _rows[row].push_back(finalnde);
            
            return true;
        }
        
        return false;
    }
    
    Matrix<T> get_slice(size_t r1, size_t c1, size_t r2, size_t c2) const
    {
        Matrix<T> output((r2 - r1 + 1), c2 - c1 + 1);
        
        size_t n = r1;
        
        while(r2 >= n)
        {
            size_t b = c1;
            
            while (c2 >= b)
            {
                if(is_valid(n, b))
                {
                    output.at(n - r1, b - c1) = this -> get(n, b);
                }
                
                b++;
            }
            n++;
        }
        
        return output;
    }

    
    friend bool operator==(const Node n1, const Node n2)
    // when I ran I needed this becasue teh site said there was no operator == so I made my own.
    {
        
        if(n2.get_col() == n1.get_col())
        {
            return true;
        }
            return false;
    }
    
    void setup(size_t nr, size_t nc)
    {
        _rows.resize(nr);
        
        _num_cols = nc;
        
        _num_rows = nr;
        
    }
    
    T default_value() const
    // needed to access _default_val in Matrix_Algorithims
    {
        return _default_val;
    }
    
    
    list<Node> rowcheck(size_t row) const
    //used to check if the row is empty
    {
        return _rows[row];
    }
    
    list<Node> get_value(size_t val) const
    {
        return val;
    }
    
    friend class Tests;

};

#endif /* Sparse_Matrix_h */

    
