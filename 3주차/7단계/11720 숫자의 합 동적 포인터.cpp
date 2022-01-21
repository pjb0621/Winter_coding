/* https://www.acmicpc.net/problem/11720
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.

출력
입력으로 주어진 숫자 N개의 합을 출력한다. */

#include <iostream>

using namespace std;

int main(void)
{
    int size;
    char *nums;
    int sum = 0;
    cin >> size;
    nums = new char[size];
    cin >> nums;
    for(int i = 0; i<size; i++) {
        sum += nums[i] - '0';
    }
    cout << sum;
}

