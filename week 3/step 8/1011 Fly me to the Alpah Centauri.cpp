/*
1011 Fly me to the Alpha Centauri
https://www.acmicpc.net/problem/1011
*/

#include <iostream>
#include <cmath>
using namespace std;


long int min_cnt(int x, int y){


    long int distance = y - x;
    long int n  = 1;
    while(1){
        // n^2 <= distance <  n+1 ^ 2 에서 찾기
        if(distance >= pow(n,2) && distance < pow((n+1),2)){
            
             if (distance == pow(n,2)) return 2*n -1;
             if (distance > pow(n,2) && distance <= pow(n,2)+n) return 2*n;
             if (distance > pow(n,2) + n && distance <= pow((n+1),2)) return 2*n + 1;             
        }
        
        n += 1;

    }


}
int main(){

    int T;
    cin >> T;

    for(int i = 0;  i <T ;i++){

        int x, y;
        cin >> x >> y;
        cout << min_cnt(x,y) << '\n';

    
    }
    return 0;
}