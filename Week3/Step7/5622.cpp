/*
    다이얼
    https://www.acmicpc.net/problem/5622
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string words;
    cin >> words;
    int sum=0;
    for(int i=0;i<words.length();i++){
        int x=words[i]-'A';
        if(x>=0 && x<=2) sum=sum+3; // 0,1,2->2
        else if(x<=5) sum=sum+4; // 3,4,5->3
        else if(x<=8) sum=sum+5; //6,7,8->4
        else if(x<=11) sum=sum+6; //9,10,11->5
        else if(x<=14) sum=sum+7; //12,13,14->6
        else if(x<=18) sum=sum+8; //15,16,17->7
        else if(x<=21) sum=sum+9; //18,19,20,21->8
        else sum=sum+10; //22,23,24->9
    }
    cout << sum << endl;
    return 0;
}