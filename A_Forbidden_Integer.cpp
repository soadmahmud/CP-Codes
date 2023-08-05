#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"

#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

const int N = 1e6 + 10;
const int M = 1e9 + 7;


void Goal() {
    char a[4][4];
    for(int i = 1; i <= 3; ++i) {
        for(int j = 1; j <= 3; ++j) {
            char c; cin >> c;
            a[i][j] = c;
        }
    }
    char ans = 't';
    char tt = a[1][1];
    if((a[1][2] == tt and a[1][3] == tt) or (a[2][1] == tt and a[3][1] == tt)) {
        if(tt != '.') {cout << tt << endl;return;}
    }
    char tt2 = a[1][2];
    if((a[1][1] == tt2 and a[1][3] == tt2) or (a[2][2] == tt2 and a[3][2] == tt2)) {
        if(tt2 != '.') {cout << tt2 << endl;
        return;}
    }
    char tt3 = a[1][3];
    if((a[1][1] == tt3 and a[1][2] == tt3) or (a[2][3] == tt3 and a[3][3] == tt3)) {
        if(tt3 != '.') {cout << tt3 << endl;
        return;}
    }
    char tt4 = a[2][1];
    if((a[2][2] == tt4 and a[2][3] == tt4) or (a[1][1] == tt4 and a[3][1] == tt4)) {
        if(tt4 != '.') {cout << tt4 << endl;return;}
    }
    char tt5 = a[2][2];
    if((a[2][1] == tt5 and a[2][3] == tt5) or (a[1][2] == tt5 and a[3][2] == tt5) or (a[1][1] == tt5 and a[3][3] == tt5) or (a[1][3] == tt5 and a[3][1] == tt5)) {
        if(tt5 != '.') {cout << tt5 << endl;return;}
    }
    char tt6 = a[2][3];
    if((a[2][1] == tt6 and a[2][2] == tt6) or (a[1][3] == tt6 and a[3][3] == tt6)) {
        if(tt6 != '.') {cout << tt6 << endl;return;}
    }
    char tt7 = a[3][1];
    if((a[3][2] == tt7 and a[3][3] == tt7) or (a[1][1] == tt7 and a[2][1] == tt7)) {
        if(tt7 != '.') {cout << tt7 << endl;return;}
    }
    char tt8 = a[3][2];
    if((a[3][1] == tt8 and a[3][3] == tt8) or (a[1][2] == tt8 and a[2][2] == tt8)) {
        if(tt8 != '.') {cout << tt8 << endl;return;}
    }
    char tt9 = a[3][3];
    if((a[3][1] == tt9 and a[3][2] == tt9) or (a[1][3] == tt9 and a[2][3] == tt9)) {
        if(tt9 != '.') {cout << tt9 << endl;return;}
    }
    cout << "DRAW\n";
}


int32_t main() {

    fastIO;
    #ifndef ONLINE_JUDGE
        fileIO;
    #endif
 
    int t;
    cin >> t;
    while(t--) {
        Goal();
    }
    return 0;
}