// 부녀회장이 될테야 https://www.acmicpc.net/problem/2775

#include <iostream>
#include <vector>
using namespace std;

int resident_number(int k, int n){
    if(k==0) return n;
    else if(n==1) return 1;
    return resident_number(k, n-1)+resident_number(k-1, n);
}

int main(){
    int T, k, n;
    cin>>T;
    vector<int> v(T);

    for(int i=0; i<T; i++){
        cin>>k>>n;
        v[i]=resident_number(k, n);
    }
    for(int i=0; i<T; i++){
        cout<<v[i]<<"\n";
    }
}