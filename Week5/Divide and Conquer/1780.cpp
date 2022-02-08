/*
    종이의 개수
    https://www.acmicpc.net/problem/1780
*/

#include <iostream>

using namespace std;

int count[3]={0,};
void cut(int paper[][2187], int N);

int main() {
    int N;
    cin >> N;
    int paper[N][2187];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> paper[i][j];
        }
    }
    cut(paper, N);
    cout << count[0] << '\n' << count[1] << '\n' << count[2] << '\n';
    return 0;
}

void cut(int paper[][2187], int N){
    int first=paper[0][0];
    int flag=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(paper[i][j]!=first) flag=1;
        }
    }
    if(flag==0) count[first+1]++;
    else if(flag==1){
        int newarr[N/3][2187];
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i][j];
            }
        }
        cut(newarr, N/3);
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i][j+N/3];
            }
        }
        cut(newarr, N/3);
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i][j+2*(N/3)];
            }
        }
        cut(newarr, N/3);
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i+N/3][j];
            }
        }
        cut(newarr, N/3);
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i+N/3][j+N/3];
            }
        }
        cut(newarr, N/3);
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i+N/3][j+2*(N/3)];
            }
        }
        cut(newarr, N/3);
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i+2*(N/3)][j];
            }
        }
        cut(newarr, N/3);
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i+2*(N/3)][j+N/3];
            }
        }
        cut(newarr, N/3);
        for(int i=0;i<N/3;i++){
            for(int j=0;j<N/3;j++){
                newarr[i][j]=paper[i+2*(N/3)][j+2*(N/3)];
            }
        }
        cut(newarr, N/3);
    }
}