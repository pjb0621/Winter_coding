#include <iostream>
#define Pi 3.14159265358979323846264338327

int main(){
    int n;
    long double area1,area2;
    std::cin >> n;
    area1 = n * n * Pi;
    area2 = n * n * 2;
    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << area1 << '\n' << area2;

    return 0;

}