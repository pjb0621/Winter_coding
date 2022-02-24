#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, newInt;
stack<int> st;
string s;
vector<int> res;

void push(){
    cin>>newInt;
    st.push(newInt);
}

void top(){
    if(st.empty()){
        res.push_back(-1);
    }
    else{
        res.push_back(st.top());
    }
}

void pop(){
    if(st.empty()){
        res.push_back(-1);
    }
    else{
        res.push_back(st.top());
        st.pop();
    }
}

void size(){
    res.push_back(st.size());
}

void empty(){
    res.push_back(st.empty());
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>s;
        if(s=="push") push();
        else if(s=="top") top();
        else if(s=="pop") pop();
        else if(s=="size") size();
        else empty();
    }

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<"\n";
    }
}