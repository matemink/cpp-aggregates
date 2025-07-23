#include <vector>  
#include <iostream>

int vectorSum(const std::vector<int>& xs) {
    int sum = 0;                 
    for (int x : xs) {           
        sum += x;                
    }
    return sum;                  
}

int main() {
    std::vector<int> xs = {1, 2, 3, 4};
    std::cout << vectorSum(xs) << std::endl;  
}