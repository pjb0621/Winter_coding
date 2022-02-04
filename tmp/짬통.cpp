#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
    stack<int> c;
    vector<int> a;
    
    for(int i = 0; i<5; i++) {
        a.push_back(i);
    }
    cout << binary_search_index(a, 0, 4, 5) << endl;
    cout << max(1, 2);
}

