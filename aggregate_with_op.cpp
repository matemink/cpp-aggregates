#include <vector>
#include <functional>  
#include <iostream>


int add(int a, int b) {
    return a + b;  
}

int mul(int a, int b) {
    return a * b;  
}


template<typename T>
T aggregate(const std::vector<T>& xs, std::function<T(T, T)> op) {
    if (xs.empty()) return T();  

    T result = xs[0];  
    for (size_t i = 1; i < xs.size(); ++i) {
        result = op(result, xs[i]);  
    }
    return result;
}

int main() {
    std::vector<int> xs = {1, 2, 3, 4};
    std::cout << aggregate(xs, add) << std::endl; // 10
    std::cout << aggregate(xs, mul) << std::endl; // 24
}
