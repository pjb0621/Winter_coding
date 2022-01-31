#include <iostream>

int main(){
    int a,b,c;
    std::cin >> a >> b >> c;
    if (b >= c){
        std::cout << -1 <<std::endl;

        return 0;
    }
    int n = a/(c-b);

    std::cout << n + 1 << std::endl;

    return 0;
}