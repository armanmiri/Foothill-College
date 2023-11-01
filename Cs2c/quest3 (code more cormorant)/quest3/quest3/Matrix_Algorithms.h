// student id: 20481838

#ifndef Matrix_Algorithms_h
#define Matrix_Algorithms_h

#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include "Matrix.h"
#include "Sparse_Matrix.h"

using namespace std;

class Mx {
   
public:
    
    template <typename T> static bool can_multiply(const Matrix<T> &a, const Matrix<T> &b)
    {
        if(b.get_num_rows() == a.get_num_cols())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    template <typename T> static bool multiply(const Matrix<T> &a, const Matrix<T> &b, Matrix<T> &res)
    {
        if(can_multiply(a, b))
        {
            res.resize(a.get_num_rows(), b.get_num_cols());
            
            size_t n = 0;
            
            while(a.get_num_rows() > n)
            {
                size_t r = 0;
                
                while (b.get_num_cols() > r)
                {
                    T total = 0;
                    
                    size_t z = 0;
                    
                    while(b.get_num_rows() > z)
                    {
                        total = total + a.at2(n, z) * b.at2(z, r);
                        
                        z++;
                    }
                    
                    res.at(n, r) = total;
                    
                    r++;
                
                }
                
                n++;
            }
            
            return true;
            
        }
        
        return false;
    }
    
    template <typename T> static bool can_multiply(const Sparse_Matrix<T> &a, const Sparse_Matrix<T> &b)
    {
        /*
        if(b.get_num_rows() == 0)
        {
            return false;
        }
        if(a.get_num_cols() == 0)
        {
            return false;
        }
        */
        if(b.get_num_rows() == a.get_num_cols())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    template <typename T> static bool add_to_cell(Sparse_Matrix<T> &spmat, size_t r, size_t c, const T &val)
    {
        if(spmat.is_valid(r, c))
        {
            if(spmat.is_valid(r, c))
            {
                T addition = spmat.get(r, c) + val;
                
                return spmat.set(r, c, addition);
            
            }
            else
            {
                return false;
            }
            
            return true;
        }
        
        return false;
    }
            

    template <typename T> static bool multiply(const Sparse_Matrix<T> &a, const Sparse_Matrix<T> &b, Sparse_Matrix<T> &res)
    {
        
        size_t arow = a.get_num_rows();
        
        size_t acol = a.get_num_cols();
        
        //size_t brow = b.get_num_rows();
        
      //  size_t bcol = b.get_num_cols();
        
        Matrix<T> newmtrx(arow, acol);
         
        size_t f = 0;
         
        while(arow > f)
        {
            if (!(a.rowcheck(f).empty()))
            {
                for (auto &testing : a.rowcheck(f))
                {
                    newmtrx.at(f, testing.get_col()) = testing.get_val();
                }
            }
            f++;
        }
        
   
        if(can_multiply(a, b))
        {
            // res = Sparse_Matrix<T>(a.get_num_rows(), b.get_num_cols());
            
            res.setup(a.get_num_rows(), b.get_num_cols());
            
            
            
        
            for(size_t n = 0; a.get_num_rows() > n; n++)
                // trying for instead of while loop since it is meant to be faster
            {
                if(!(a.rowcheck(n).empty()))
                {
                 //   cout << "row empty \n";
             
                
                    for(size_t r = 0; b.get_num_cols() > r; r++)
                        // trying for instead of while loop since it is meant to be faster
                {
                 //   cout << "row empty2 \n";
                    T total = 0;
                    
                    //size_t z = 0;
                    
                    
                   // while(brow > z)
                    // trying for instead of while loop since it is meant to be faster
                    for (size_t z = 0; z < b.get_num_rows(); z++)
                    {
                     //   cout << "row empty3 \n";
                        if (newmtrx.rrows(n, z) == 0)
                        {
                           continue;
                        }
                        //if(!(b.rowcheck(z).empty()))
                        else
                        {
                      
                            total += newmtrx.rrows(n, z) * b.get(z, r);
                        
                        }
                        
                            //z++;
                     
                    }
                    
                    //r++;
                    
                    if (total != a.default_value())
                    {
                        if (total != b.default_value())
                        {
                            res.set(n , r , total);
                        }
                    }
                
                
                
                }
                }
                
               // n++;
            }
            
            
            return true;
            
        }
        
        return false;

    }
    
    
    template <typename T> static bool is_default(const double &val)
    {
        if((Sparse_Matrix<T>::Floor) > (val - Sparse_Matrix<T>::_default_val))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    
    friend class Tests;
    
};

#endif


