#include <iostream>

int arr[100001] = {0, };

int squarenum(int n){
    if(arr[n] != 0){
        return arr[n];
    }
    if(n == 0){
        return 0;
    }
    int ans = 1000000;
    for (int i = 1; i * i <= n; i++){
        int temp = 1 + squarenum(n - i * i);
        if(temp < ans){
            ans = temp;
        }
    }
    arr[n] = ans;

    return ans;
}

int main(){
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 1;
    int n;
    std::cin >> n;
    std::cout << squarenum(n) << std::endl;

    return 0;
}