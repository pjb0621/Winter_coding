#include <iostream>
#include <algorithm>
#include <string.h>//memset 함수 사용//

int item[100][2] = {0, }; // 1열은 무게 2열은 가치//
int memoziation[100][100001]; // i번째 물건부터 사용하고 무게 한계가 k 일때 best 경우//

int backpacking(int n, int i, int k){
    if(i == n - 1){
        if(item[i][0] <= k){
            return item[i][1];
        }
        else{
            return 0;
        }
    }
    if(memoziation[i][k] != -1){
        return memoziation[i][k];
    }
    int ans = 0;
    if(item[i][0] <= k){
        ans = backpacking(n, i + 1, (k - item[i][0])) + item[i][1];
    }
    ans = std::max(ans, backpacking(n, i + 1, k));

    memoziation[i][k] = ans;
    return ans;
}

int main(){
    int n,k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++){
        std::cin >> item[i][0] >> item[i][1];
    }
    memset(memoziation, -1, sizeof(memoziation));
    std::cout << backpacking(n, 0, k) << std::endl;
}