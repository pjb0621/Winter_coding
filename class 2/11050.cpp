/*
combination
*/

#include <iostream>
using namespace std;


int binominal(int n, int k){

    if(k==0) return 1;
    if(k==1) return n;
    
    if(n==k) return 1;
    return binominal(n-1, k) + binominal(n-1,k-1);
}
int main(){

    int n, k;
    cin >> n >> k;
    cout << binominal(n,k) << endl;
}