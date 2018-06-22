#include <iostream>
#include <random>
#include <functional>
using std::cout;
using std::endl;

int main() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1);
    auto sideGenerator = std::bind(distribution,generator);
    for(int i = 0;i<1000;i++)
        cout << sideGenerator() << " ";
    return 0;
}
