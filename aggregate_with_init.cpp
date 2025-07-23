#include <vector>
#include <functional>
#include <iostream>
#include <string>


template<typename T>
T aggregate(const std::vector<T>& xs, std::function<T(T, T)> op, T init = T()) {
    T result = init;  
    for (const T& x : xs) {
        result = op(result, x);  
    }
    return result;
}


std::string concat(const std::string& a, const std::string& b) {
    return a + b;
}

int main() {
    std::vector<int> xs = {1, 2, 3, 4};
    std::cout << aggregate(xs, [](int a, int b) { return a + b; }, 0) << std::endl;      
    std::cout << aggregate(xs, [](int a, int b) { return a * b; }, 10) << std::endl;     

    std::vector<std::string> ys = {"1", "2", "3", "4"};
    std::cout << aggregate(ys, concat, "0") << std::endl;                                
}
