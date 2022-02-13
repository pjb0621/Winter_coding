#include <iostream>
#include <cmath>

void filling(int **cube, int l, int w, int h, int n, int &count){
    if(!l || !w || !h || count == -1){
        return;
    } // 길이 폭 높이중 하나라도 0 이 있다는 말은 공간이 없다는 말이고 count = -1 이라는 얘기는 이미 실패하였다는 말이므로 return//
    bool check = false;//큐브를 넣었는지 체크//
    for (int i = n -1; i >= 0; i--){
        int len = pow(2, cube[i][0]);
        if(len <= l && len <= w && len <= h && cube[i][1]){// 큐브가 들어갈 수 있고 큐브의 개수가 0이 아님//
            check = true;
            ++count;
            --cube[i][1];

            filling(cube, l - len, w, h, i + 1, count);
            filling(cube, len, w- len, h, i + 1, count);
            filling(cube, len, len, h - len, i + 1,count);
            break;
        }
    }
    if(!check){//큐브를 하나도 못넣었으므로 실패!//
        count = -1;
        return;
    }

    return;
}

int main(){
    int l,w,h,n;
    std::cin >> l >> w >> h;
    std::cin >> n;
    int **cube;
    int count = 0;
    int &acount = count;
    cube = new int*[n];
    for (int i = 0; i < n; i++){
        cube[i] = new int[2];
    }
    for (int i = 0; i < n; i++){
        std::cin >> cube[i][0] >> cube[i][1]; //0에는 길이를  1에는 큐브 개수를 넣음//
    }
    filling(cube, l, w, h, n, acount);
    std::cout << count;
}