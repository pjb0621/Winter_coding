#include <iostream>
#include <algorithm>

void makeone(int n, int *arr){
    int i = 4;
    while(i != n + 1){
        int min[3] = {i, i, i};
        min[0] = arr[i-1] + 1;
        if(i % 2 == 0){
            min[1] = arr[i / 2] + 1;
        }
        if(i % 3 == 0){
            min[2] = arr[i / 3] + 1;
        }
        std::sort(min, min + 3);
        arr[i] = min[0];
        i++;
    }
    return;
}   
int main(){
    int n, count = 0;
    int num = 1;
    std::cin >> n;
    int *arr;
    arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++){
        arr[i] = 0;
    }
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    if(n < 4){
        std::cout << arr[n];
        return 0;
    }
    makeone(n, arr);

    std::cout << arr[n] << std::endl;
    return 0;
}