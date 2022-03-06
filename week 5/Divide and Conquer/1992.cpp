/*
쿼드 트리 1992 
https://www.acmicpc.net/problem/1992
*/

// 문자열 사용해야함

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// (1) 주어진 인덱스가 모두 0이나 1로만 되어있는지 판단함.
// y와 x는 좌표를 가리킨다. (인덱스)
// n은 격자 한변의 길이.

bool Is_Same(vector<vector<int>> &list, int y, int x, int n){

    int tmp = list[y][x];
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(tmp != list[i][j]) return false;
        }
    }

    return true;


}

void quad(vector<vector<int>> &list, int y, int x, int n){

    if(Is_Same(list, y, x, n)){
        cout << list[y][x];
        return;
        // 출력하게끔.
        // 괄호는 어떻게 처리할 것인가. 
        // 임시 변수를 두는게 어떨까? cnt 같은걸로 해서 괄호 몇번 처리해야할지

    }
    
    // 이 for문이 정확하게 1 ,2, 3, 4 순서로 출력함.
    cout << "(";
    for(int i = y; i < y + n; i += int(n/2)){
        for(int j = x; j < x+n; j += int(n/2)){
            quad(list, i, j, int(n/2));
        }
    }
    cout << ")";
  
    
    /*
    8 x 8 격자면
    (0,0) (4,0)
    (0,4) (4,4)
    */
} 

int main(){

    int n;
    cin >> n;
    
    vector <vector <int>> arr(n, vector<int>(n,0));

    for(int i = 0 ; i< n ; i++){

        string str;
        cin >> str;


        for(int j = 0; j < n; j++){
            
            arr[i][j] = str[j] - '0';
        }
    }
 
    quad(arr, 0, 0, n);
 

}