#include <iostream>

int arr[1001][10] = {0, };

int upstairnum(int n, int i){
    if( arr[n][i] != 0){
        return arr[n][i];
    }
    for (int j = 0; j <= i; j++){
        arr[n][i] += upstairnum(n - 1, j) % 10007;
    }
    arr[n][i] %= 10007;

    return arr[n][i];
}

int main(){
    int n;
    std::cin >> n;
    for (int i = 0; i < 10; i++){
        arr[1][i] = 1;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++){
        sum += upstairnum(n, i);
    }

    std::cout << sum % 10007<< std::endl;

    return 0;
}