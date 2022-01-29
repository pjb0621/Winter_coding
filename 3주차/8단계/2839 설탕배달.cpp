/*
    설탕배달
    https://www.acmicpc.net/problem/2839
*/

#include <iostream>

using namespace std;

int main(){
    int N, count=0;
    int imp=0;
    cin >> N;
    while(N>12 || N%3!=0){
        if(N<5){
            cout << "-1" << endl;
            imp=1;
            break;
        }
        else{
            N=N-5;
            count++;
        }
    }
    count=count+N/3;
    if(imp!=1) cout << count << endl;
    return 0;
}