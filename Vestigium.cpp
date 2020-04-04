#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <ext/pb_ds/detail/standard_policies.hpp>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()

using namespace std;
#define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout << endl;}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
#define fbo find_by_order
#define ook order_of_key
#define mod (int)(1e9 +7)


signed main(){

    fastIO
 
    int t, tt = 0;
    cin >> t;
    while(t--){
        tt++;
        int n;
        cin >> n;
        int tra = 0;
        int r = 0, c = 0;
        int a[n][n];
        for (int i = 0; i < n; i++){
            set<int> s;
            int cnt = 0;
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
                if (i == j) tra += a[i][j];
                if (s.empty()){
                    s.insert(a[i][j]);
                }else{
                    if (s.find(a[i][j]) != s.end() && !cnt){
                        cnt++;
                        r++;
                    }
                }
                s.insert(a[i][j]);
            }
        }
        for (int j = 0; j < n; j++){
            set<int> s;
            int cnt = 0;
            for (int i = 0; i < n; i++){
                if (s.empty()){
                    s.insert(a[i][j]);
                }else{
                    if (s.find(a[i][j]) != s.end() && !cnt){
                        cnt++;
                        c++;
                    }
                }
                s.insert(a[i][j]);
            }
        }
        cout << "Case #" << tt << ": " <<tra << ' ' << r << " " << c << endl;
    }


    return 0;
}
