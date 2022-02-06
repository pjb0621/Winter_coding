/* https://www.acmicpc.net/problem/2981
트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다. 경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 
검문하는데 엄청나게 오랜 시간이 걸린다.

상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.

먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 
M을 모두 찾으려고 한다. M은 1보다 커야 한다.

N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.

입력
첫째 줄에 종이에 적은 수의 개수 N이 주어진다. (2 ≤ N ≤ 100)

다음 줄부터 N개 줄에는 종이에 적은 수가 하나씩 주어진다. 이 수는 모두 1보다 크거나 같고, 1,000,000,000보다 
작거나 같은 자연수이다. 같은 수가 두 번 이상 주어지지 않는다.

항상 M이 하나 이상 존재하는 경우만 입력으로 주어진다.

출력
첫째 줄에 가능한 M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다. 
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void) 
{
    int N, tmp, i,j;
    int n = 1;
    cin >> N;
    vector<int> nums;
    vector<pair<int,int>> answers;
    int remainder[200]; // 나머지는 N개의 요소를 갖는 배열 (N개의 각 숫자를 나눈 나머지가 들어감.)
    for(int j = 0; j < N; j++) {  
        cin >> tmp;
        nums.push_back(tmp);
    }




    // nums를 정렬한 뒤 2부터 시작해서 nums의 가장 작은 수까지 시도
    // 가장 작은 수보다 큰걸로 나눌 때, 그러면 나머지 값들 중 하나는 해당 수로 고정이고
    // 만약 그 다음 작은 수보다 더 큰걸로 나눈다면? 그때는 진짜 같을 수가 없다.
    // 따라서 2~nums[1]까지만 나눠보면 됨. 
    sort(nums.begin(),nums.end());
    for(int i = 2; i<=nums[1]; i++) {
        bool isAble = true;
        if(nums[0] % i == nums[1] % i) {
            answers.push_back(make_pair(i, nums[0] % i));
        }
    } // answers에 후보들이 딱 들어가있는 상황
    for(int i = 0; i<answers.size(); i++) {
        for(int j = 1; j<N; j++) {
            if(nums[j] % answers[i].first != answers[i].second) {
                answers[i].first = 0;
                break;
            }
        }
    }
    for(int i = 0;i<answers.size();i++) {
        if(answers[i].first!=0)
        cout << answers[i].first << " ";
    }
}




