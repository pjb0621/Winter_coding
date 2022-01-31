#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int sum = 0;
    int num = 1;
    while( (n - 1) / 6.0 > sum){
        sum += num;
        num++;
    }

    std::cout << num;

    return 0;
}