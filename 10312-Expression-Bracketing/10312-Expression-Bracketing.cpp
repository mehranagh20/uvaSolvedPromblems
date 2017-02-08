//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    vector<ull> supCat = {1, 1}, cat = {1};
    for(int i = 3; i <= 27; i++) {
        ull now = 3 * (2 * i - 3) * supCat.back() - (i - 3) * supCat[supCat.size() - 2];
        supCat.push_back(now / i);
    }
    for(int i = 1; i <= 27; i++) {
        ull now = 2 * (2 * i - 1) * cat.back();
        cat.push_back(now / (i + 1));
    }

    int n;
    while(cin >> n) {
        cout << supCat[n - 1] - cat[n - 1] << endl;
    }


    return 0;
}
