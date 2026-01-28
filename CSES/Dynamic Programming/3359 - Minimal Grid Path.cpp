/*
    Minimal Grid Path - 3359
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3005;

int main() {
    string grid[MAXN];
    bool visited[MAXN][MAXN];

    long long n;
    cin >> n;

    for(long long i=0; i<n; i++){
        cin >> grid[i];
    }

    string ans = "";
    ans += grid[0][0];

    vector<pair<long long, long long>> current_cells;
    current_cells.push_back({0, 0});

    for(long long step = 0; step < 2*n -2; step++){
        char min_char = 'Z'+1;

        for(auto p: current_cells){
            long long r = p.first;
            long long c = p.second;

            if(c+1 < n) {
                min_char = min(min_char, grid[r][c+1]);
            }
            if (r+1 < n){
                min_char = min(min_char, grid[r+1][c]);
            }
        }

        ans += min_char;
        vector<pair<long long, long long>> next_cells;
        
        for(auto p: current_cells){
            long long r = p.first;
            long long c = p.second;

            if(c+1 < n){
                if(grid[r][c+1] == min_char && !visited[r][c+1]){
                    visited[r][c+1] = true;
                    next_cells.push_back({r, c+1});
                }
            }
            if(r+1 < n){
                if(grid[r+1][c] == min_char && !visited[r+1][c]){
                    visited[r + 1][c] = true;
                    next_cells.push_back({r + 1, c});
                }
            }
        }
        current_cells = next_cells;
    }

    cout << ans << endl;
}