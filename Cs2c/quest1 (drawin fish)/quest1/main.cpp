
#include "Set.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

int main(int argc, const char * argv[]) {
    
    vector<int> master;
    size_t master_total = 0;
    for (size_t i = 0; i < 10; i++) {
        int val = rand() % 300;
        master_total += val;
        master.push_back(val);
    }
    
    size_t target = master_total / 2;
    
    //size_t target = 50;
    
    Set<int> master_set(&master);
    Set<int> best_subset = master_set.find_biggest_subset_le(target);
    
    cout << master[1] << endl;
    cout << "target: " << target << endl;
    cout << "Best sum: " << best_subset.get_sum() << endl;
    cout << best_subset << endl;
    
}
