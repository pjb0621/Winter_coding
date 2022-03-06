/*
1780 종이의 개수
https://www.acmicpc.net/problem/1780
*/


/* 
NXN 크기의 행렬로 표현되는 종이에 -1 , 0 , 1가 저장되어 있음.(각 칸에)

첫번쨰로 입력을 받으면 됨 VECTOR나 배열에

그다음 두 가지 규칙에 따라 종이를 자른다음에 
-1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 종이의 개수


즉 칸 하나 or 구역으로 최대한 쪼개내야함. 

만약 종이가 모두 같은 수로 되어있다면 이종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 9개로 자르고, 각각의 잘린 종이에 대해(1)의 과정을 반복함.
종이크기는 3의 제곱꼴이라,

만약 모든 인덱스가 같은 숫자면 그냥 pass 하는거고,
그게 아니라면 9개의 그리드로 자르면 된다.

마찬가지로 반복한다. 이 9개 칸으로 이루어진 그리드가 같은 수면 그대로 사용
그게 아니면 9개도 각각 1개씩으로 쪼갠다.

그래서 총 단계수는 몇번이 있는가 하면.. Log 3 N 정도이다. 

나누어지는 개수는 9가지  (a=9)
크기는 N/9 으로 된다.
한번 정복하는데 들어가는 횟수는 그냥 O(N) 
그래서 복잡도는 O(NlogN)이다.

배열로 접근하자. 근데 배열 을 함수 인자로 받게끔 해야하니까..
Vector가 나을것으로 보임.

0 <= < 3 / 3<=  <6  / 6 <=  <9
모든 블록의 인덱스를 정리해보자
(0,3) + (0,3) / (0,3) + (3,6) /  (0,3) + (6,9)

(3,6) + (0,3) / (3,6) + (3,6)  / (3,6) + (6,9)

(6,9) + (0,3) / (6,9) + (3,6)  / (6,9) + (6,9)

9번 부르는데, 수식화만 하면 된다.

함수는 2개 만들기.

배열  9개 블록으로 나눌때도 굉장히 어려움 .

규칙성을 찾아야함. 
*/
#include <iostream>
#include <vector>

using namespace std;
int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;

// (1) 종이가 모두 같은 수로 되어 있는지를 확인한다.
// y는 행, x는 열을 나타내는 좌표.(인덱스)
bool Is_Same(vector<vector<int>> &list, int y, int x, int n){

    int tmp = list[y][x];
    for(int i = y; i < y + n; i++){
        for(int j = x;  j < x + n ; j++){

            if(tmp != list[i][j]) return false;

        }
    }

    return true; 

}

// (2) 같은 수가 아닌 경우, 종이를 9개로 자른다. 
// (2) 같은 수면 cnt += 1;
void func(vector <vector <int>> &list, int y, int x, int n){

    // 같은 수인 경우 종이의 개수 증가.
    if(Is_Same(list, y, x, n)){

        if(list[y][x] == -1) cnt1 += 1 ;
        if(list[y][x] == 0) cnt2 += 1;
        if(list[y][x] == 1) cnt3 += 1;
        return ;
    }
    

    // 같은 수가 아닌 경우 종이를 9개로 자름.
    for(int i = y; i < y + n ; i+=n/3){
        for(int j = x; j < x + n; j+=n/3){
            func(list, i, j, int(n/3));
        }
    }
     
    /*
    is_same 에서 y ~ y + n / x ~ x + n 인덱스를 순회함.
    그러므로 n/3으로 넣어주고. 
    시작 좌표를 건드려주면 됨
    n = 9일때,
    (0,0) (0,3) (0,6)   일반화 하면 시작점을 다
    (3,0) (3,3) (3,6)
    (6,0) (6,3) (6,6)
    */

}


int main(){

    int n;

    cin >> n;

    vector <vector <int>> list(n, vector<int> (n,0));

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            list[i][j] = x;
        }
    }

    func(list, 0, 0, n);
    cout << cnt1 << endl;
    cout << cnt2 << endl;
    cout << cnt3 << endl;

    

}