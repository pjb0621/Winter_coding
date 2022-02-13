#include <iostream>

int arr[1001] ={0, };

int hogu(int n, int *card){
    if(arr[n] != 0 ){
        return arr[n];      
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int temp = card[i] + hogu(n - i, card);
        if(temp > ans){
            ans = temp;
        }
    }
    arr[n] = ans;
    return ans;
}

int main(){
    int n;
    std::cin >> n;
    int *card = new int[n + 1];
    card[0] = 0;
    for (int i = 1; i < n + 1; i++){
        std::cin >> card[i];
    }
    arr[1] = card[1];
    std::cout << hogu(n, card) << std::endl;

    return 0;
}