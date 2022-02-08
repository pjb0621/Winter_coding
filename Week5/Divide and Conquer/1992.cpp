/*
    쿼드트리
    https://www.acmicpc.net/problem/1992
*/

#include <iostream>
#include <string>


using namespace std;

void quad_tree(string data[], int N);

int main() {
    int N;
    cin >> N;
    string data[N];
    for(int i=0;i<N;i++){
        cin >> data[i];
    }
    quad_tree(data, N);
    return 0;
}

void quad_tree(string data[], int N){
    char first=data[0][0];
    int flag=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(data[i][j]!=first) flag=1;
        }
    }
    if(flag==0) cout << first;
    else{
        cout << '(';
        string newarr[N/2];
        for(int i=0;i<N/2;i++){
            newarr[i]=data[i].substr(0, N/2);
        }
        quad_tree(newarr, N/2);
        for(int i=0;i<N/2;i++){
            newarr[i]=data[i].substr(N/2, N/2);
        }
        quad_tree(newarr, N/2);
        for(int i=0;i<N/2;i++){
            newarr[i]=data[i+N/2].substr(0, N/2);
        }
        quad_tree(newarr, N/2);
        for(int i=0;i<N/2;i++){
            newarr[i]=data[i+N/2].substr(N/2, N/2);
        }
        quad_tree(newarr, N/2);
        cout << ')';
    }
}