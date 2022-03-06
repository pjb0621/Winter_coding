/*
박스채우기 1493
https://www.acmicpc.net/problem/1493
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 



int length, width, height;

// n은 인덱스
// a,b,c는 각각 가로 세로 높이.
// vector는 call by reference접근 해야함.
// 개수를 사용할때마다 감소 시킬것. 
void fill_cube(int n, int a, int b, int c, vector<vector <int>> &cube, int &tmp_cnt){

    // base case
    
    // 가로, 세로, 높이 중 하나가 0 이하면 종료.
    if(a == 0 || b==0 || c==0 || tmp_cnt == -1) return ;
    bool flag = false; 


    // 아직 이해를 못한 부분임.
    // 이미 재귀를 하는데  재귀 한상태에서도
    // 박스의 종류 n-1  ~  1까지 다시 돌아서 공간을 분할 하는 이유를 모르겠음..
    // 생각해보니까 그공간도 새롭게 개수 남아있다면 하고 개수가 부족한 큐브라면 다음 큐브를 사용해야함.



    // for문의 목적은 큐브의 모든 종류를 체크하면서
    // 이 박스가 들어갈 수 있는지 판단하고자 하는 것임
    // 그래서 for문에서 if문으로 안들어가고 끝나면
    // 결국 미완성 이거나 하나도 안들어갔다는 의미이므로,
    // flag == false인 상태에서
    // count == -1 이 되게하는 것. 
    for(int i = n-1; i>=0 ; i--){
        int cube_len = pow(2, cube[i][0]);
        if(cube[i][1]){
            // 입력받은 가로, 세로, 높이가 박스보다 작으면 
            if(cube_len <= a && cube_len <= b && cube_len <= c){
                flag = true;
                // 큐브의 개수를 줄이고, 사용 횟수 증가.
                // 박스를 한번 사용하면 공간이 3개로 분할되므로 3번 부른다. 
                cube[i][1] -= 1;
                tmp_cnt += 1;   
                fill_cube(i+1,a-cube_len, b, c, cube, tmp_cnt);
                fill_cube(i+1, cube_len, b-cube_len, c, cube, tmp_cnt);
                fill_cube(i+1, cube_len, cube_len, c-cube_len, cube, tmp_cnt);
                break;
            } 
        }

    }

    if(!flag){
        tmp_cnt = -1;

    }

    
    // 예외를 처리하는 것이 필요해보임.
    // 박스로 못채우는 경우 어떻게 예외 처리를 하는가. 
}

int main(){

    int n;
    int cnt = 0;
    int &tmp_cnt = cnt;  
    
    cin >> length >> width >> height;
    cin >> n;

    vector <vector <int>> cube(n, vector<int>(2,0));

    for(int i =0; i < n; i++){
       
            int x, y ;
            cin >> x >> y;
            cube[i][0] = x;
            cube[i][1] = y;
    }
    

    fill_cube(n,length, width, height, cube, tmp_cnt);
    cout << cnt << endl;
    return 0;

}









/*
처음에 풀어서 실패한 풀이
동전 0 처럼 풀어서 부피만 고려하다보니,
실제 정육면체의 모양에 부합하지 않는 경우가 존재한다.


int main(){
    // 전체 박스의 크기
    int len, wid, height;

    cin >> len >> wid >> height;
    // 큐브 종류의 개수 n
    int n;

    cin >> n;
    // [N][0] : 큐브의 종류 (A_i)
    // [N][1] : 큐브의 개수 (B_i)
    // 큐브 한변의 길이는 2^N 이다. 
    vector <vector <int>> cube(n,(vector <int> (2,0))); 
    
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        cube[i][0] = x;
        cube[i][1] = y;
    }

    int cnt = 0 , Vol = len * wid * height;
    int index = n-1; 
    // 박스의 부피가 0 이되면 종료
    while(Vol != 0 ){

        if(index == -1) break; 
        int cube_vol = pow(2, 3*cube[index][0]);
        // 큐브의 부피가 박스 크기보다 작으면 
        if(cube_vol <= Vol){
            // 몫이 큐브의 개수보다 작거나 같으면
            if( cube[index][1] >= Vol/cube_vol){

                // 사용 개수에 추가하기. 
                // 박스의 부피 갱신.
                cnt += Vol / cube_vol;
                Vol = Vol % cube_vol;
            }
            // 몫이 큐브의 개수보다 크면 
            else{

                // 큐브 개수만큼 전부다 써서 
                // 박스를 채운다
                cnt += cube[index][1];
                Vol = Vol - cube[index][1] * cube_vol;
                cube[index][1] = 0;

            }
        }

        index -= 1;
         
    }
    if(index == -1 && cnt == 0) cout << -1 << endl;
    else cout << cnt << endl ;

    return 0 ;
}


*/