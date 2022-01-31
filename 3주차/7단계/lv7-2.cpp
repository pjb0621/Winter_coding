#include <iostream>

int main(){
    char *arr;
    int n;
    int sum = 0;
    std::cin >> n;
    arr = new char[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        sum += arr[i] - 48;
    }

    std::cout << sum << std::endl;

    return 0;
}