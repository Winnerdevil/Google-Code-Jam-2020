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
        vector<pair<int, int >> v, org;
        map<pair<int, int>, vector<char>> mp;
        for (int i = 0, a, b; i < n; i++){
            cin >> a >> b;
            v.pb({a, b});
            org.pb({a, b});
        }
        sort(v.begin(), v.end());
        bool pass = true;
        int preC = 0, preJ = 0;
        int pf = v[0].ff, ps = v[0].ss;
        preC = ps;
        mp[{pf, ps}].pb('C');
        pf = v[1].ff;
        ps = v[1].ss;
        if (preC > pf){
            mp[{pf, ps}].pb('J');
            preJ = ps;
        }else{
            mp[{pf, ps}].pb('C');
            preC = ps;
        }
        for (int i = 2; i < n; i++){
            pf = v[i].ff;
            ps = v[i].ss;
            if (preC > pf){
                if (preJ > pf){
                    pass = false;
                    break;
                }else{
                    mp[{pf, ps}].pb('J');
                    preJ = ps;
                }
            }else{
                mp[{pf, ps}].pb('C');
                preC = ps;
            }
        }
        string fin_ans = "";
        if (pass){
            for (int i = 0; i < n; i++){
                int f = org[i].ff, s = org[i].ss;
                auto it = mp[{f, s}].begin();
                fin_ans += *it;
                mp[{f, s}].erase(it);
            }
        }else{
            fin_ans = "IMPOSSIBLE";
        }
        cout << "Case #" << tt << ": " << fin_ans << endl;
    }


    return 0;
}
