

#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include "Matrix.h"
#include "Sparse_Matrix.h"
#include "Matrix_Algorithms.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    
    
    


    //tests for regular matrix

//    Matrix<int> test1(1, 3);
//
//    Matrix<int> test2(3, 2);
//
//
//    test1.at(0, 0) = 3;
//
//    test1.at(0, 1) = 1;
//
//    test1.at(0, 2) = 4;
//
//
//    test2.at(0, 0) = 4;
//
//    test2.at(0, 1) = 3;
//
//    test2.at(1, 0) = 2;
//
//    test2.at(1, 1) = 5;
//
//    test2.at(2, 0) = 6;
//
//    test2.at(2, 1) = 8;
    
    Sparse_Matrix<int> testing(4,6,0);
    
    Sparse_Matrix<int> testing2(6,4,0);
    
    Sparse_Matrix<int> testing3;
    
    
    testing.set(1, 0, 1);
    
    testing.set(1, 1, 2);
    
    testing.set(1, 2, 3);
    
    testing.set(2, 0, 4);
    
    testing.set(2, 1, 5);
    
    testing.set(2, 2, 6);
    
    
    //testing.set(1, 2, 4);
    
    
    testing2.set(1, 0, 7);
    
    testing2.set(1, 1, 10);
    
    testing2.set(2, 0, 8);
    
    testing2.set(2, 1, 11);
    
    testing2.set(3, 0, 9);
    
    testing2.set(3, 1, 12);
    
    
    
    
    
//    testing2.set(1, 0, 2);
//    testing2.set(1, 1, 5);
//    testing2.set(2, 0, 6);
//    testing2.set(2, 1, 8);
    
    Mx::multiply(testing, testing2, testing3);
    
    cout << testing.get_slice(0, 0, testing.get_num_rows(), testing.get_num_cols()).to_string() << endl;
    
    cout << testing2.get_slice(0, 0, testing2.get_num_rows(), testing2.get_num_cols()).to_string() << endl;
    
  //  cout << "testing row" << endl;
    
    //cout << testing.is_row_empty(0) << endl;
    
    //cout << "testing col" << endl;
    
    //cout << testing2.is_col_empty(0) << endl;
    
//    cout << "testing is default" << endl;
//
//    cout << testing2.is_default(testing2.get(2, 2)) << endl;
    
    cout << testing3.get_slice(0, 0, testing3.get_num_rows(), testing3.get_num_cols()).to_string() << endl;
    
    
    
    

    
    
    
    
    
    
//    testing.set(1, 1, 1);
//    testing.set(1, 2, 2);
//    testing.set(1, 3, 3);
//    testing.set(2, 1, 4);
//    testing.set(2, 2, 5);
//    testing.set(2, 3, 6);
//    testing.set(3, 1, 7);
//    testing.set(3, 2, 8);
//    testing.set(3, 3, 9);
    
    
//    cout << "first matrix" << endl;
//
//    cout << test1.to_string() << endl;
//
//    cout << "second matrix" << endl;
//
//    cout << test2.to_string() << endl;
//
//    cout << "multiplied matrix" << endl;
//
//    Matrix<int> test3;
    
//    Mx::multiply(test1, test2, test3);
//
//    cout << endl << test3.to_string() << endl;
//
//    cout << Mx::can_multiply(testing, testing2) << endl;
//
//    cout << "multiply with defaults" << endl;
    //start
    
//    cout << testing.set(3, 1, -0.777983) << endl;
//
//    cout << "testing remove" << endl;
//
//    cout << "initial value" << endl;
//
//    cout << testing.get(3, 1) << endl;
//
//    cout << "removing" << endl;
//
//    cout << testing.add_and_set(3, 1, 0.777983) << endl;
//
//    cout << "after remove" << endl;
//
//    cout << testing.get(3, 1) << endl;
//
//    cout << "initial value" << endl;
//
//    cout << testing.get(2, 1) << endl;
//
//    cout << "testing set" << endl;
//
//    cout << testing.set(2, 1, 2) << endl;
//
//    cout << "val after set" << endl;
//
//    cout << testing.get(2, 1) << endl;
//
//    cout << "testing valid" << endl;
//
//    cout << testing.is_valid(2, 1) << endl;
//
//    cout << "adding cell" << endl;
//
//    cout << Mx::add_to_cell(testing, 2, 1, 8) << endl;
//
//    //Mx::add_to_cell(testing, 2, 1, 1);
//
//    cout << "value after add" << endl;
//
//    cout << testing.get(2, 1) << endl;

    
    
 //   cout << testing3.get_slice(0, 0, 4, 4);
    
    
    
    
    
    
    
    
    

    
//
//    cout << (test1 == test2) << endl;
//
//    cout << "testing at" << endl;
//
//    cout << test1.at(1, 1) << endl;
//
//    cout << "print before resize" << endl;
//
//    cout << test1.to_string() << endl;
//
//    test1.resize(2, 2);
//
//    cout << "print after resize" << endl;
//
//    cout << test1.to_string() << endl;
//
//    cout << "are they the same" << endl;
//
//    cout << (test1 == test2) << endl;
//
////
//
//
//    // Tests for sparse

//    Sparse_Matrix<int> testing(4,4,0);
//
//    testing.set(1, 1, 1);
//    testing.set(1, 2, 2);
//    testing.set(1, 3, 3);
//    testing.set(2, 1, 4);
//    testing.set(2, 2, 5);
//    testing.set(2, 3, 6);
//    testing.set(3, 1, 7);
//    testing.set(3, 2, 8);
//    testing.set(3, 3, 9);
//
//
//    //cout << testing.set(1, 1, 5);
//    cout << testing.get_slice(1, 1, 3, 3).to_string() << endl;
//    //testing.get(1, 1);
//
//
    
    //keep
    return 0;
}
