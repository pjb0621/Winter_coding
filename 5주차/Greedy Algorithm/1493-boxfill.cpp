#include <iostream>
#include <cmath>

void filling(int **cube, int l, int w, int h, int n, int &count){
    if(!l || !w || !h || count == -1){
        return;
    } // ���� �� ������ �ϳ��� 0 �� �ִٴ� ���� ������ ���ٴ� ���̰� count = -1 �̶�� ���� �̹� �����Ͽ��ٴ� ���̹Ƿ� return//
    bool check = false;//ť�긦 �־����� üũ//
    for (int i = n -1; i >= 0; i--){
        int len = pow(2, cube[i][0]);
        if(len <= l && len <= w && len <= h && cube[i][1]){// ť�갡 �� �� �ְ� ť���� ������ 0�� �ƴ�//
            check = true;
            ++count;
            --cube[i][1];

            filling(cube, l - len, w, h, i + 1, count);
            filling(cube, len, w- len, h, i + 1, count);
            filling(cube, len, len, h - len, i + 1,count);
            break;
        }
    }
    if(!check){//ť�긦 �ϳ��� ���־����Ƿ� ����!//
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
        std::cin >> cube[i][0] >> cube[i][1]; //0���� ���̸�  1���� ť�� ������ ����//
    }
    filling(cube, l, w, h, n, acount);
    std::cout << count;
}