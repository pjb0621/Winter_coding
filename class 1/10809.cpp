/*
단어 s가 주어지면,
각각의 알파벳에 대해서 a가 처음 등장하는 위치... z가 처음 등장하는 위치를
공백으로 구분해서 출력한다.

등장하지 않으면 -1
단어의 첫번째 글자는 0번째 위치 ( 인덱스와 동일 )

아스키코드 체크.
a - 97
z - 122

해당 아스키코드값에서 97을 뺀만큼의 배열 인덱스에
단어에서 몇번째 위치인지 값을 저장하자.

이때, 이미 배열의 값이 != -1 이면 pass

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string word;

    cin >> word;

    vector<int> alphabet(26,-1);

    for(int i = 0 ; i < word.size(); i++){
        
        int index = int(word.at(i))-97;
        if(alphabet[index] == -1){
            alphabet[index] = i;
        }
    }

    for(int i = 0; i < alphabet.size(); i++){
        cout << alphabet[i] << " ";
    }




}