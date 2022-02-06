#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int binary_search_index(vector<int> &a, int left, int right, int target)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (a[mid] == target)
    {
        return mid;
    }

    else if (a[mid] < target)
    {
        return binary_search_index(a, mid + 1, right, target);
    }

    else
    {
        return binary_search_index(a, left, mid - 1, target);
    }
}

int main(void)
{
    queue<pair<int, int>> nums; // value, 원래순서
    vector<int> values;
    int T, N, M, i, j, tmp;
    cin >> N >> M;
    int count = 0;
    for (int j = 0; j < N; j++)
    {
        cin >> tmp;
        values.push_back(tmp);
        nums.push(make_pair(tmp, j));
    }
    cout << nums.front().first;
    nums.push(nums.front());
    nums.pop();
    cout << nums.front().first;
}
