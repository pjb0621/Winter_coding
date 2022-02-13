#include <iostream>
#include <algorithm>
#include <string.h>

int arr[1000];
int memoziation[1000][1001];

int makemax(int n, int i, int min){
    if(i == n - 1){
        if(arr[i] > min){
            return arr[i];
        }
        else{
            return 0;
        }
    }
    if(memoziation[i][min] != -1){
        return memoziation[i][min];
    }
    int ans = 0;
    if(arr[i] > min){
        ans = makemax(n, i + 1, arr[i]) + arr[i];
    }
    ans = std::max(ans, makemax(n, i + 1, min));

    memoziation[i][min] = ans;
    return ans;

}

int main(){
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    memset(memoziation, -1, sizeof(memoziation));
    std::cout << makemax(n, 0, 0) << std::endl;
}