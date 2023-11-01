// student id: 20481838

#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <utility>
using namespace std;


template <typename T>

class Matrix {

protected:
    
   vector<vector<T>> _rows;
   
public:
    Matrix(size_t nr = 0, size_t nc = 0)
    {
        _rows.resize(nr);
        
        T num = T();
        
        for (size_t n = 0; n < nr; n++)
        {
            vector<T> inprgvctr(nc, num);
            
            _rows[n] = inprgvctr;
        }
    }
    
    size_t get_num_rows() const
    {
        return _rows.size();
    };
    
    size_t get_num_cols() const
    {
        return (_rows.size()>0? _rows[0].size() : 0);
    }
    
    void clear()
    {
        _rows.clear();
    };
    
    void resize(size_t nr, size_t nc)
    {
        _rows.resize(nr);
        
        size_t n = 0;
        
        while (n < get_num_rows())
        {
            _rows[n].resize(nc);
            
            n++;
        }
    }
    
    T &at(size_t r, size_t c)
    {
        if(c >= get_num_cols())
        {
            OOB_exception at_err;
            
            throw at_err;
        }
        
        if(r >= get_num_rows())
        {
            OOB_exception at_err;
            
            throw at_err;
        }
        
        return _rows[r][c];
    }
    
    T at2(size_t r, size_t c) const
    {
        if(c >= get_num_cols())
        {
            OOB_exception at_err;
            
            throw at_err;
        }
        
        if(r >= get_num_rows())
        {
            OOB_exception at_err;
            
            throw at_err;
        }
        
        return _rows[r][c];
    }
    
    string to_string() const
    {
        stringstream output;
        
        output << "# Matrix\n";
        
        size_t n = 0;
        
        while(n < get_num_rows())
        {
            size_t b = 0;
            
            while(b < get_num_cols())
            {
                if(b != 0)
                {
                    output << " ";
                }
                
                output << setw(6) << _rows[n][b];
                    
                b++;
            }
            
            output << "\n";
            
            n++;
        
        }
        
        return output.str();
    }
    
    class OOB_exception : public exception
    {
        
        public: string what() {return "Out of bounds access";};
        
    };
    
    friend ostream &operator<<(ostream& os, const Matrix<T> &mat)
    {
        return os << mat.to_string();
    }
    
    friend bool operator==(const Matrix<T> &m1, const Matrix<T> &m2)
    {
        if(m1.get_num_rows() != m2.get_num_rows()) return false;
        if(m1.get_num_cols() != m2.get_num_cols()) return false;
        
        size_t f = 0;
        
        while (f < m1.get_num_rows())
        {
            size_t g = 0;
            
            while (g < m1.get_num_cols())
            {
                if (m2._rows[f][g] != m1._rows[f][g])
                {
                    return false;
                }
                
                g++;
            }
            
            f++;
        }
        
        return true;
        
    }

    friend bool operator!=(const Matrix<T> &m1, const Matrix<T> &m2)
    {
        return !(m1 == m2);
    }
    
    T rrows(size_t r, size_t c) const
    {
      //  if(get_num_rows() <= r)
        //{
          //  OOB_exception at_err;
                
            //throw at_err;
        //}
        //else if (get_num_cols() <=  c)
        //{
          //  OOB_exception at_err;
                
            //throw at_err;
        //}
        //else
        //{
            return _rows[r][c];
        //}

        }
    
    friend class Tests;
    
};

#endif /* Matrix_h */
