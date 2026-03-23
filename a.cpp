#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin>>T;
	using ll = long long;
	
	while(T--){
		ll N,M; cin>>N>>M;
		ll sum = 0;
		vector<ll> A(N), B(N);
		for(auto& a : A){
			cin >> a;
			a %= M;
			sum += a;
		}
		for(auto& b : B){
			cin >> b;
			b %= M;
			sum += b;
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		ll cnt = 0;
		ll l = 0;
		for(int i = N - 1; i >= 0; i--){
			ll itr = lower_bound(B.begin() + l, B.end(), M - A[i]) - B.begin();
			if(itr == N) break;
			cnt++;
			l = ++itr;
		}

		sum -= cnt*M;
		cout << sum << "\n";
	}
}

