#include <iostream>

int creator(int n){
    int sum = n;
    while(n){
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

int main(){
    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++){
        if(n == creator(i)){
            std::cout << i << std::endl;
            return 0;
        }
    }

    std::cout << 0 << std::endl;

    return 0;
}