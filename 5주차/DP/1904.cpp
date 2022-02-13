#include <iostream>

int arr[1000001] = {0, };

int pibonaci(int n){
    if(arr[n] != 0){
        return arr[n];
    }
    arr[n] = (pibonaci(n - 1) + pibonaci(n - 2)) % 15746; // 이렇게 안하면 피보나치 수열의 100만째항까지 구해야해서 불가능, 나머지의 성질을 이용하여 계산//
    // if c = a + b : c % k = a % k + b % k //

    return arr[n];
}

int main(){
    int n;
    std::cin >> n;
    arr[1] = 1;
    arr[2] = 2;

    std::cout << pibonaci(n) % 15746 << std::endl;

    return 0;

}