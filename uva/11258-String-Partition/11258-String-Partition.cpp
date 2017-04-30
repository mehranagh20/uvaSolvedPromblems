//In the name of God
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
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
typedef vector<long long> vll;

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))

const ll limit = pow(2, 31);

string str;
vll memo;
ll cut(int ind){
    if(ind == str.size()) return 0;
    ll &ans = memo[ind];
    if(ans != -1) return ans;

    ll num = 0;
    for (int i = ind; i < str.size(); ++i) {
        num = num * 10 + (str[i] - '0');
        if(num >= limit)
            break;
        ans = max(ans, num + cut(i + 1));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--){
        cin >> str;
        memo.assign(str.size() + 10, -1);
        cout << cut(0) << endl;
    }

    return 0;
}
