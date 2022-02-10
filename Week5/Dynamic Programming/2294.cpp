/*
    동전 2
    https://www.acmicpc.net/problem/2294
*/

#include <iostream>

using namespace std;
int count[10005]={0,};
void countfill(int coin[], int n, int k);

int main() {
    int n, k;
    cin >> n >> k;
    int coin[n];
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    countfill(coin, n, k);
    if(count[k]==0) cout << "-1\n";
    else cout << count[k] << '\n';
}

void countfill(int coin[], int n, int k){
    int x=0;
    while(x<=k){
        for(int i=0;i<n;i++){
            if(x+coin[i]>k);
            else if(x!=0 && count[x]==0) break;
            else if(count[x+coin[i]]==0) count[x+coin[i]]=count[x]+1;
            else if(count[x+coin[i]]>count[x]+1) count[x+coin[i]]=count[x]+1;
        }
        x++;
    }
}