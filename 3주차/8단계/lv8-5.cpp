#include <iostream>

int main (){
    int H,W,N,T;
    int por,rest;
    std::cin >> T;
    for (int i = 0; i < T; i++){
        std::cin >> H >> W >> N;
        if ( N % H == 0){
            por = N / H;
            rest = H;
        }
        else{
            por = N / H + 1;
            rest = N % H;
        }

        std::cout << rest;
        if (por < 10){
            std::cout << 0 << por << std::endl;
        }
        else{
            std::cout << por << std::endl;
        }
    }
}