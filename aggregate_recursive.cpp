#include <iostream>
#include <vector>
#include <functional>


template<typename T>
T aggregateRecursive(const std::vector<T>& xs, std::function<T(T, T)> op, T init, size_t index = 0) {
    if (index == xs.size()) {
        return init;  
    }
    return aggregateRecursive(xs, op, op(init, xs[index]), index + 1);  
}


template<typename T, size_t N>
T aggregateRecursive(const T (&xs)[N], std::function<T(T, T)> op, T init, size_t index = 0) {
    if (index == N) {
        return init;  
    }
    return aggregateRecursive(xs, op, op(init, xs[index]), index + 1);
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    int arr[] = {1, 2, 3, 4};

    auto add = [](int a, int b) { return a + b; };
    auto mul = [](int a, int b) { return a * b; };

    std::cout << aggregateRecursive(vec, add, 0) << std::endl;   
    std::cout << aggregateRecursive(vec, mul, 1) << std::endl;   

    std::cout << aggregateRecursive(arr, add, 0) << std::endl;   
    std::cout << aggregateRecursive(arr, mul, 1) << std::endl;   
}
