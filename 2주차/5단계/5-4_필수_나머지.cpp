//나머지 https://www.acmicpc.net/problem/3052

#include <iostream>
using namespace std;

int main(){
    int num, result=0;
    int arr[42];
    
    for(int i=0; i<42; i++){
        arr[i]=0;
    }
    for(int i=0; i<10; i++){
        cin>>num;
        arr[num%42]=1;
    }
    for(int i=0; i<42; i++){
        result+=arr[i];
    }
    cout<<result;
}
