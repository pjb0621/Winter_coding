// 캠핑 https://www.acmicpc.net/problem/4796

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int L, P, V;
    int I, R;
    vector<int> v;
    cin>>L>>P>>V;

    while(L!=0){
        I = V/P;
        R = V%P;
        if(L<R) R=L;

        v.push_back(I*L+R);

        cin>>L>>P>>V;
    }

    for(int i=0; i<v.size(); i++){
        cout<<"Case "<<i+1<<": "<<v[i]<<"\n";
    }
}
