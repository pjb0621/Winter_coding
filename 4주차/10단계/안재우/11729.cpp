#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> moves;

void hanoi(int what, int from, int to){
    if(what == 0){
        moves.push_back({from+1, to+1});
        return;
    }
    int other = (from+1)%3;
    if(other == to) other++;
    other = other%3;

    hanoi(what-1, from, other);
    moves.push_back({from+1, to+1});
    hanoi(what-1, other, to);


}

int main(){
    int N;
    cin >> N;
    hanoi(N-1, 0, 2); // disk id: 0~N-1, position: 0~2
    cout << moves.size() << "\n";
    for(auto move: moves){
        cout << move.first << " " << move.second << "\n";
    }
}