
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include "Matrix.h"
#include "Sparse_Matrix.h"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    //tests for regular matrix
    
    Matrix<int> test1(2, 3);

    Matrix<int> test2(2, 3);
    
    cout << "are they the same" << endl;
    
    cout << (test1 == test2) << endl;
    
    cout << "testing at" << endl;
    
    cout << test1.at(1, 1) << endl;
    
    cout << "print before resize" << endl;
    
    cout << test1.to_string() << endl;
    
    test1.resize(2, 2);
    
    cout << "print after resize" << endl;
    
    cout << test1.to_string() << endl;
    
    cout << "are they the same" << endl;

    cout << (test1 == test2) << endl;

    
    
    
    // Tests for sparse
    
    Sparse_Matrix<int> testing(4,4,0);
    
    testing.set(1, 1, 1);
    testing.set(1, 2, 2);
    testing.set(1, 3, 3);
    testing.set(2, 1, 4);
    testing.set(2, 2, 5);
    testing.set(2, 3, 6);
    testing.set(3, 1, 7);
    testing.set(3, 2, 8);
    testing.set(3, 3, 9);
    
    
//    //cout << testing.set(1, 1, 5);
//    cout << testing.get_slice(1, 1, 3, 3).to_string() << endl;
//    //testing.get(1, 1);
    
    
    
    //keep
    return 0;
}

