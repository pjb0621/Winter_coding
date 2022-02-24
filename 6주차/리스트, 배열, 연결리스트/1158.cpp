#include <iostream>
#include <vector>
#include <list>

using namespace std;

int N, K, i=0;
list<int> LL;
list<int>::iterator iter = LL.begin(), temp;
vector<int> res;

void next(){
    ++iter;
    if(iter==LL.end()){
        iter = LL.begin();
    }
}

int main(){
    cin>>N>>K;

    for(int i=1; i<=N; i++){
        LL.push_back(i);
    }

    cout<<"<";
    while(N>1){
        for(int i=0; i<K; i++){
            next();
        }
        cout<<*iter<<", ";
        res.push_back(*iter);
        temp = iter;
        temp--;
        LL.erase(iter);
        iter = temp;
        N--;
    }

    cout<<*LL.begin()<<">";

}