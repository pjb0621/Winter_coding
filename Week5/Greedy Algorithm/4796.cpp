/*
    캠핑
    https://www.acmicpc.net/problem/4796
*/

#include <iostream>

using namespace std;

int main() {
    int L=1, P=1, V=1;
    int count=1;
    while(1){
        cin >> L >> P >> V;
        if(L*P*V==0) break;
        cout << "Case " << count << ": ";
        if(V%P>L) cout << (V/P)*L+L << '\n';
        else cout << (V/P)*L+(V%P) << '\n';
        count++;
    }
    return 0;
}