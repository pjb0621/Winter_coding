#include <iostream>

long long arr[91] = {0, };

long long pinarynum(int n){
    if(n == 1 || n == 2){
        return arr[n];
    }
    for (int i = 3; i <= n; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];

}

int main(){
    int n;
    std::cin >> n;
    arr[1] = 1;
    arr[2] = 1;
    std::cout << pinarynum(n) %  << std::endl;

    return 0;
}