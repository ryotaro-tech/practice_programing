#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll l, r;
vector<ll> S;

int check(ll num){
	if(r <= 2*num) return 2;
	
	ll num1 = *(upper_bound(S.begin(), S.end(), 2*num) - 1);
	if(num == num1) return -1;
	int ret = check(num1);
	return (ret < 0 ? ret : ret + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin>>T;
	while(T--){
		int N;cin>>N;
		S.resize(N);
		for(int i = 0; i < N; i++) cin>>S[i];
		
		l = S[0];
		r = S[N - 1];
		sort(S.begin(), S.end());

		int ans = check(l);
		cout << ans << "\n";
	}
}
