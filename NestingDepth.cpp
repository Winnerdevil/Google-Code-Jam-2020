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
        string s;
        cin >> s;
        string fin_ans = "";
        int n = s.length(), cnt = 0, check = 0;
        for (int i = 0; i < n; i++){
            if (s[i] > 0 && !check){
                check = 1;
                for (int j = 0; j < s[i]- '0'; j++){
                    fin_ans += '(';
                    cnt++;
                }
                fin_ans += s[i];
            }else if (s[i] > 0){
                if (s[i-1] == s[i]){
                    fin_ans += s[i];
                }else if (s[i-1] < s[i]){
                    for (int j = 0; j < abs(s[i] - s[i-1]); j++){
                        fin_ans += '(';
                        cnt++;
                    }
                    fin_ans += s[i];
                }else if (s[i-1] > s[i]){
                    for (int j = 0; j < abs(s[i] - s[i-1]); j++){
                        fin_ans += ')';
                        --cnt;
                    }
                    fin_ans += s[i];
                }
            }else if (s[i] == 0){
                for (int i = 0; i < cnt; i++){
                    fin_ans += ')';
                }
                cnt = 0;
                fin_ans += s[i];
            }
        }
        if (cnt > 0){
            for (int i = 0; i < cnt; i++){
                fin_ans += ')';
            }
            cnt = 0;
        }
        cout << "Case #" << tt << ": " << fin_ans << endl;
    }


    return 0;
}
