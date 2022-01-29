/*
    택시 기하학
    https://www.acmicpc.net/problem/3053
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int R;
    cin >> R;
    double pi=3.14159265358979;
    double uarea=R*R*pi;
    double tarea=R*R*2;
    cout << fixed;
    cout.precision(7);
    cout << uarea << "\n";
    cout << tarea << "\n";
    return 0;
}