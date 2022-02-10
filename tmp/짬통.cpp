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
    int a = -3;
    int b = 2;
    cout << a/b;
}
