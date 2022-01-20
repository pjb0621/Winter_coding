// 큰 수 A+B https://www.acmicpc.net/problem/10757

#include <iostream>
#include <string>
using namespace std;

int main(){
    int size, n, sum, temp=0;
    string A, B, res="";
    cin>>A>>B;

    if(A.size()>B.size()){
        size = A.size();
        B = string (A.size()-B.size(), '0')+B;
    }
    else{
        size = B.size();
        A = string (B.size()-A.size(), '0')+A;
    }

    for(int i=size-1; i>=0; i--){
        sum = (int)A[i]+(int)B[i]+temp-96;
        temp = sum/10;
        n = sum%10;
        res = to_string(n)+res;
    }
    if(temp>0) res = to_string(temp)+res;
    cout<<res;
}
