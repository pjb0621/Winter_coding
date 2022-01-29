#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, sum=0;
    vector<int> v(9);
    vector<int> ans(7);

    for(int i=0; i<9; i++){
        cin>>n;
        v[i]=n;
        sum += n;
    }
    for(int i=0; i<9; i++){
        for(int j=i; j<9; j++){
            if(i!=j && v[i]+v[j]==sum-100){
                v.erase(v.begin()+i);
                v.erase(v.begin()+j-1);
                break;
            }
        }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<7; i++){
        cout<<v[i]<<"\n";
    }
}