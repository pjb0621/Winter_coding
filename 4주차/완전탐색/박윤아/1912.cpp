#include <iostream>
using namespace std;

int main(){
    int N, n, min=0, max=-2000;
    cin>>N;

    int v[N+1];
    v[0]=0;

    for(int i=1; i<N+1; i++){
        cin>>n;
        v[i]=v[i-1]+n;
    }

    for(int i=1; i<N+1; i++){
        if(v[i]-min>max) max=v[i]-min;
        if(v[i]<min) min=v[i];
    }
    cout<<max;

}

//O(n) 알고리즘



//O(n^2) 알고리즘
/*
#include <iostream>
using namespace std;

int main(){
    int N, n, m, temp, sum;
    cin>>N;

    int v[N];
    int dp[N];

    for(int i=0; i<N; i++){
        cin>>n;
        v[i]=n;
    }

    for(int D=0; D<N; D++){

        sum=0;

        for(int i=0; i<N-D; i++){

            sum+=v[i+D];

            if(D==0){
                dp[i] = v[i];
            }
            else{
                temp = dp[i];
                if(dp[i+1]>temp) temp = dp[i+1];
                if(sum>temp) temp=sum;
                dp[i] = temp;
            }
            //cout<<i<<" "<<i+D<<" "<<dp[i]<<"\n";
        }
    }
    cout<<dp[0];

}
*/