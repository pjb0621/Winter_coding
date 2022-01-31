#include <iostream>

int main(){
    int n;
    int i = 2;
    std::cin >> n;
    while(n != 1){
        if(n % i == 0){
            std::cout << i << '\n';
            n = n / i;
        }
        else{
            i++;
        }
    }
}