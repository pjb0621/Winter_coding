#include <iostream>
#include <algorithm>
#include <string.h>//memset �Լ� ���//

int item[100][2] = {0, }; // 1���� ���� 2���� ��ġ//
int memoziation[100][100001]; // i��° ���Ǻ��� ����ϰ� ���� �Ѱ谡 k �϶� best ���//

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