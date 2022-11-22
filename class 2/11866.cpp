//
// Created by pjb on 2022-11-15.
/*
틀렸던 이유가 cnt =1를 초기호 ㅏ안해두니까 오류가 뜨더라.
주의할점.
iterator 순회를 할때
[1, 2, 3, 4, 5]
 에서 it= 3일때
 erase(it)를 하면 it는 4를 가리키게된다.
 이점을 이용해서 순회할때
 erase할때는 it를 건드리지 않았고,
 그 외의 경우에는 ++it로 증가시키는 방향으로 순회를 하였음.
*/
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


int main(){
    int n,k, cnt = 1;
    cin >> n >> k;

    vector<int> circle;
    vector<int> Josephus;
    for(int i = 0 ; i < n; i++){
        circle.push_back(i+1);
    }

    while(!circle.empty()){

        for(auto it = circle.begin(); it != circle.end(); ){

            if(cnt == k){
                Josephus.push_back(*it);
                circle.erase(it);
                cnt = 1;
            }
            else{
                cnt++;
                ++it;
            }
        }
    }

    cout << "<";
    for(int i = 0; i < n; i++){
        if(i == n-1) cout << Josephus[i] << ">";
        else cout << Josephus[i] << ", ";
    }


}
