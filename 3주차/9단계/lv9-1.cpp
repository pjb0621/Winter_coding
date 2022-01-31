#include <iostream>

int yesorno(int n){
    if(n == 1){
        return 0;
    }
    else if(n == 2){
        return 1;
    }
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    int count = 0;
    int N,n;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> n;
        if(yesorno(n)){
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}