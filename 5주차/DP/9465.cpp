#include <iostream>
#include <algorithm>
const int MAX = 100000;

int value[2][MAX];

int sticker(int c, int status,int n,int **memory){
    if(c == n){
        return 0;
    }
    if(memory[c][status] != -1){
        return memory[c][status];
    } // 미리 계산되어있으면 다시 계산하지 않음//
    int ans = sticker(c + 1, 0, n, memory);  // status == 0 , 이전 열에서 스티커를 떼지 않음 //
    if(status != 2){
        ans = std::max(ans, sticker(c+1, 2, n, memory) + value[1][c]);
    }
    if(status != 1){
        ans = std::max(ans, sticker(c+1, 1, n, memory) + value[0][c]);
    }

    memory[c][status] = ans; // memoization //

    return ans;
    

}


int main(){
    int T,n;
    int **memory;
    std::cin >> T;
    for (int i = 0; i < T; i++){
        int sum = 0;
        std::cin >> n;
        memory = new int*[n];
        for(int index = 0; index < n; index++){
            memory[index] = new int[3];
            memory[index][0] = -1;
            memory[index][1] = -1;
            memory[index][2] = -1;
        }
        for(int k = 0; k < 2; k++){
            for (int j = 0; j < n; j++){
                std::cin >> value[k][j];
            }
        }
        std::cout << sticker(0,0,n,memory) << std::endl;
        
    }
}