#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M, tmp;
    int index;
    int tmpindex;
    cin >> N;
    queue<int> nums1;
    for(int i = 1; i <= N; i++) {
        nums1.push(i);
    }
    while(nums1.size()>1) {
        nums1.pop();
        nums1.push(nums1.front());
        nums1.pop();
    }
    cout<<nums1.front();
}