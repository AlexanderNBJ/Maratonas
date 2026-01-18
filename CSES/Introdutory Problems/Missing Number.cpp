/*
    Missing Number - 1083
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    vector<long long> arr;

    cin >> n;
    
    for(int i=0; i<n-1; i++){
        long long aux;
        cin >> aux;

        arr.push_back(aux);
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n-1; i++){
        if((i+1) != arr[i]){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << n << endl;
}