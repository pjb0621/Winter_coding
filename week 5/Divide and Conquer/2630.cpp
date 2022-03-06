/*
2630 색종이 만들기
https://www.acmicpc.net/problem/2630
*/

#include <iostream>
#include <vector>
int white = 0;
int blue = 0;

using namespace std;

// (1) 종이내의 모든 칸이 같은 색인지 확인함.
// y와 x는 인덱스를 가리키는 좌표, n은 격자 한변의 길이
bool Is_Same(vector <vector<int>> &list, int y, int x, int n){

    int tmp = list[y][x];
    for(int i = y; i < y + n; i++){
        for(int j = x; j< x+n; j++){

            if(tmp != list[i][j]) return false;
            
        }
    }

    return true;

}

void func(vector <vector<int>> &list, int y, int x, int n){

    if(Is_Same(list, y, x, n)){
        if(list[y][x] == 0) white++;
        if(list[y][x] == 1) blue++;
        return ;
    }

    for(int i = y; i < y + n; i += int(n/2)){
        for(int j = x; j < x + n; j += int(n/2)){
            func(list, i, j, int(n/2));
        }
    }


}

int main(){

    int n;
    cin>> n;

    vector <vector <int>> arr(n, vector<int> (n,0));

    for(int i = 0; i <n; i++){
        for(int j = 0 ; j < n; j++){
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    func(arr, 0, 0, n);
    cout << white << endl;
    cout << blue << endl;

}