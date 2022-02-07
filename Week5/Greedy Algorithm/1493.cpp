/*
    박스채우기
    https://www.acmicpc.net/problem/1493
*/

#include <iostream>
#include <cmath>

using namespace std;

void box(long cube[], int j, long L, long W, long H);

int main() {
    long L, W, H, min=0;
    //길이, 너비, 높이 입력받기
    cin >> L >> W >> H;
    //길이, 너비, 높이 중 최솟값 찾기
    if(L<W) min=L;
    else min=W;
    if(H<min) min=H;
    //최솟값보다 작거나 같은 최대 2의 제곱수 찾기
    int sqrtmax=0;
    while(pow(2,sqrtmax)<=min){
        sqrtmax++;
    }
    sqrtmax--;
    int n;
    //큐브 종류의 수 입력 받기
    cin >> n;
    long cubes[n][2];
    long count=0;
    //큐브의 종류와 갯수 입력 받기
    for(int i=0;i<n;i++){
        long len, num;
        cin >> len >> num;
        cubes[i][0]=len;
        cubes[i][1]=num;
    }
    int N=sqrtmax+1, flag=0;
    long cube[N]={0,};
    box(cube, sqrtmax, L, W, H);
    for(int j=sqrtmax;j>=0;j--){
        for(int k=n-1;k>=0;k--){
            if(cubes[k][0]==j){
                if(cubes[k][1]>=cube[j]){
                    count+=cube[j];
                    cubes[k][1]-=cube[j];
                    cube[j]=0;
                    break;
                }
                else{
                    count+=cubes[k][1];
                    if(j==0) flag=1;
                    else{
                        cube[j-1]+=(cube[j]-cubes[k][1])*8;
                        cube[j]=0;
                        cubes[k][1]=0;
                    }
                    break;
                }
            }
            else if(k==0){
                if(j==0 && cube[j]!=0) flag=1;
                else cube[j-1]+=cube[j]*8;
            }
        }
    }
    if(flag==1) cout << "-1\n";
    else cout << count << '\n';
    return 0;
}

void box(long cube[], int j, long L, long W, long H){
    if(L*W*H!=0){
        long x=pow(2, j);
        if((L/x)*(W/x)*(H/x)>0){
            cube[j]+=(L/x)*(W/x)*(H/x);
            box(cube, j-1, L%x, W-W%x, H-H%x);
            box(cube, j-1, L-L%x, W%x, H-H%x);
            box(cube, j-1, L-L%x, W-W%x, H%x);
            box(cube, j-1, L%x, W%x, H-H%x);
            box(cube, j-1, L%x, W-W%x, H%x);
            box(cube, j-1, L-L%x, W%x, H%x);
            box(cube, j-1, L%x, W%x, H%x);
        }
        else {
            box(cube, j-1, L, W, H);
        }
    }
}