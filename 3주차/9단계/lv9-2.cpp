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
    int M,N;
    int sum = 0;
    int min = 0;
    std::cin >> M >> N;
    for (int i = M; i < N + 1; i++){
        if (yesorno(i)){
            sum += i;
            if(min == 0){
                min = i;
            }
        }
    }
    if(sum == 0){
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << sum << '\n' << min << std::endl;

    return 0;
}