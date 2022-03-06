/*
3053 택시기하학
https://www.acmicpc.net/problem/3053
*/
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>


using namespace std;
int main(){

    double R;
    cin >> R;
    
    double pie = M_PI;



    cout << fixed;
    cout.precision(6);
    cout << pie * R * R << '\n';
    cout << 2 * R * R << '\n';

    return 0;



}

