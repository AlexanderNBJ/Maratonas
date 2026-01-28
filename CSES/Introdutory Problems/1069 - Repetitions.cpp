/*
    Repetitions - 1069
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string txt;
    cin >> txt;

    long long greatestLength = 0;
    long long size = txt.length();

    for(int i=0; i<size;){
        char lastChar = txt[i];
        long long currentLength = 0;

        while(txt[i]==lastChar){
            currentLength++;
            i++;
        }

        greatestLength = max(greatestLength, currentLength);
    }

    cout << greatestLength << endl;
}