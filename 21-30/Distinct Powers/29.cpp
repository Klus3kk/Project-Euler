#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <set>

int main() {
    using namespace boost::multiprecision;
    std::set<cpp_int> distinctPowers;

    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            cpp_int power = 1;
            for (int i = 0; i < b; ++i) {
                power *= a;
            }
            distinctPowers.insert(power);
        }
    }

    std::cout << "Total distinct terms are: " << distinctPowers.size() << std::endl;

    return 0;
}
