#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <numeric>
#include <functional>
#include <iterator>

template<typename TCollection, typename Op, typename TInit>
auto aggregate(const TCollection& xs, Op op, TInit init) {
    auto end = std::end(xs);

    auto impl = [&op, end](auto self, auto current, auto acc) -> TInit {
        if (current == end) {
            return acc;
        }
        return self(self, std::next(current), op(acc, *current));
    };
    return impl(impl, std::begin(xs), init);
}

int main() {
    std::vector<int> xs = {1, 2, 3, 4, 5};
    std::list<int> xs_list = {1, 2, 3, 4, 5};
    int xs_array[] = {1, 2, 3, 4, 5};

    // Vector
    int sum_vec = aggregate(xs, [](int a, int b) { return a + b; }, 0);
    std::cout << "Vector Sum: " << sum_vec << '\n';

    long long product_vec = aggregate(xs, [](long long a, int b) { return a * b; }, 1LL);
    std::cout << "Vector Product: " << product_vec << '\n';

    std::string concat_vec = aggregate(xs, [](std::string a, int b) { return a + std::to_string(b) + " "; }, std::string("Vector Elements: "));
    std::cout << "Vector Concatenation: " << concat_vec << '\n';

    // List
    int sum_list = aggregate(xs_list, [](int a, int b) { return a + b; }, 0);
    std::cout << "List Sum: " << sum_list << '\n';

    long long product_list = aggregate(xs_list, [](long long a, int b) { return a * b; }, 1LL);
    std::cout << "List Product: " << product_list << '\n';

    std::string concat_list = aggregate(xs_list, [](std::string a, int b) { return a + std::to_string(b) + " "; }, std::string("List Elements: "));
    std::cout << "List Concatenation: " << concat_list << '\n';

    // Plain Array
    int sum_array = aggregate(xs_array, [](int a, int b) { return a + b; }, 0);
    std::cout << "Plain Array Sum: " << sum_array << '\n';

    long long product_array = aggregate(xs_array, [](long long a, int b) { return a * b; }, 1LL);
    std::cout << "Plain Array Product: " << product_array << '\n';

    std::string concat_array = aggregate(xs_array, [](std::string a, int b) { return a + std::to_string(b) + " "; }, std::string("Array Elements: "));
    std::cout << "Plain Array Concatenation: " << concat_array << '\n';
}
