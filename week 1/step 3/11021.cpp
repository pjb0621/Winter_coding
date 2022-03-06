/*
11021 A+B-7
https://www.acmicpc.net/problem/11021
*/

#include <iostream>
using namespace std;

int main(){
    int T;
    cin.tie(NULL);

    cin >> T;
    for(int i=0; i< T; i++){
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a+b << '\n'; 
    }
    return 0;
}
