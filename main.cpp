#include <iostream>
using std::cout;
using std::endl;

void printNum(const int&& num){
    cout << num << endl;
}

int main() {
    printNum(5);
    const int& num = 10;
    printNum(num);
    return 0;
}
