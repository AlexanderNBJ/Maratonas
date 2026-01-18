/*
    Number Spiral - 1071
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;

    while(t--){
        long long x, y;
        cin >> y >> x;
        long long res = 0;

        if(x >= y){
            if(x%2){
                res = x*x-y+1;
            }
            else{
                res = (x-1)*(x-1) +y;
            }
        }
        else{
            if(y%2){
                res = (y-1)*(y-1)+x;
            }
            else{
                res = y*y-x+1;
            }
        }
        cout << res << endl;
    }
}