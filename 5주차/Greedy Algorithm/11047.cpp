#include <iostream>

int main(){
    int n,k;
    std::cin >> n >> k;
    int arr[n];
    int count = 0;
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    int i = n - 1;
    while(k){
        while(k / arr[i]){
            count += k / arr[i];
            k = k % arr[i];
        }
        i--;
    }

    std::cout << count << std::endl;

    return 0;
}