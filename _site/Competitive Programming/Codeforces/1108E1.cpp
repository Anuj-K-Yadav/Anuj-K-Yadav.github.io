#include <bits/stdc++.h>
#define FASTIO
#define endl "\n" // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n)             \
	for (int i = 0; i < (n); i++) \
		cin >> (c)[i];
#define exit_message(s) return 0 * printf(s)
#define show(c)           \
	for (auto i : (c))      \
		cout << i << " "; \
	cout << "\n";
#define display(c, n)           \
	for (int i = 0; i < (n); i++) \
		cout << (c)[i] << " ";    \
	cout << "\n";
#define forl(i, a, n) for (int (i) = (a); (i) < (n); (i)++)
#define dugbe(k) cout << "-\t> " << #k << " = " << k << "\n";

/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/

using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vill;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const int N = 1e5 + 5;
const long double eps = 1e-7;

ll mod_pow(ll a, ll b)
{
	if (b == 0)
		return 1LL;

	ll res = mod_pow(a, b >> 1);
	res = (res * res) % mod;
	if (b & 1LL)
		res = (res * a) % mod;

	return res;
}

vector<char> seive(ll n){
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
    	if (is_prime[i]) {
        	for (int j = i * i; j <= n; j += i)
            	is_prime[j] = false;
    	}
	}
	return is_prime;
}

int32_t main()
{
#ifdef FASTIO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#endif
	// freopen("in.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll n, m;
	cin>>n>>m;
	ll tm=-1*INT_MAX, tn=INT_MAX;
	vill v(n);
	forl(i,0,n) cin>>v[i], tm = max(v[i],tm), tn = min(tn, v[i]);
	vpr seg(m);
	forl(i,0,m) cin>>seg[i].first>>seg[i].second, seg[i].first--, seg[i].second--;
	
	if(m == 0){
		cout<<tm-tn<<"\n";
		cout<<"0\n";
		cout<<"\n";
	}

	else{ll ans = tm-tn, can=0;
	vill act;
	forl(i,0,n){
		ll mx = v[i];
		ll cnt=0;
		vill tmp = v;
		vill idx;
		ll mn = INT_MAX;
		forl(j,0,m){
			if(i < seg[j].first || i > seg[j].second){
				forl(k,seg[j].first,seg[j].second+1){
					tmp[k]--;
					mn = min(mn, tmp[k]);
				}
				cnt++;
				idx.pb(j+1);
			}	
		}
		ll t = mx-mn;
		if(t > ans){
			ans = t;
			can = cnt;
			act = idx;
		}
	}
	cout<<ans<<"\n";
	cout<<can<<"\n";
	forl(i,0,act.size()){
		cout<<act[i]<<" ";
	}}
	cout<<"\n";
	
	return 0;
}