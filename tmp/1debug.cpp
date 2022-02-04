/* https://www.acmicpc.net/problem/1780
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다. 우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

출력
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int resultcount[3] = {0,0,0};

void paperCount(int **Board, int N, int a, int b) {
    int count[3] = {0,0,0};
    int Nsquare = N*N;

    for(int i=a; i<a+N; i++) {
        for(int j=b;j<b+N;j++) {
            count[ Board[i][j] + 1 ]++;
        }
    }

    if(count[0]==Nsquare || count[1]==Nsquare || count[2] == Nsquare) {
        resultcount[0] += count[0]/Nsquare;
        resultcount[1] += count[1]/Nsquare;
        resultcount[2] += count[2]/Nsquare;
        return;
    }
    else
    {
        for (int i = 0; i < N; i = i + N / 3)
        {
            for (int j = 0; j < N; j = j + N / 3)
            {
                paperCount(Board, N / 3, i, j);
            }
        }
    }
}


int main(void)
{
    int N, tmp;
    cin >> N;
    int **Board;
    Board = new int*[N];
    for(int j = 0; j < N; j++) {
        Board[j] = new int[N];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> tmp;
            Board[i][j] = tmp;
        }
    }
    paperCount(Board,N,0,0);
    cout << resultcount[0] << endl << resultcount[1] << endl << resultcount[2] << endl;
    return 0;
}
