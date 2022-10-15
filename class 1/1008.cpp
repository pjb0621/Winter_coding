/*
https://www.acmicpc.net/problem/1008
*/

#include <iostream>
using namespace std;

int main(){

    long double a;
    long double b;
    cin >> a>> b;
    cout << fixed;
    cout.precision(12);
    long double c = (long double) a / (long double)b;
    cout << c << endl;
}