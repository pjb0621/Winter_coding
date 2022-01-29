/*
    숫자의 합
    https://www.acmicpc.net/problem/11720
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, sum=0;
    string nums;
    cin >> N;
    cin >> nums;
    for(int i=0;i<N;i++){
        int x = nums[i]-'0';
        sum=sum+x;
    }
    cout << sum << endl;
    return 0;
}