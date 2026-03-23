//ABC442 D-Swap and Range Sum
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

struct BIT {
	int n;
	vector<ll> bit;

	BIT (int n) : n(n), bit(n + 1, 0) {}

	void add(int i, ll x){
		for(++i; i <= n; i += i & -i)
			bit[i] += x;
	}

	ll sum(int i){
		ll s = 0;
		for(++i; i > 0; i = i & -i)
			s += bit[i];
		return s;
	}

	ll range(int l, int r){
		return sum(r) - (l ? sum(l - 1): 0);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;

	vector<ll> A(N);
	BIT bit(N);

	for(int i = 0; i < N; i++){
		cin >> A[i];
		bit.add(i, A[i]);
	}

	while(Q--){
		int t;
		cin >> t;

		if(t == 1){
			int x;
			cin >> x;
			x--;
			
			ll old1 = A[x];
			ll old2 = A[x + 1];

			swap(A[x], A[x + 1]);

			bit.add(x, A[x] - old1);
			bit.add(x + 1, A[x + 1] - old2);
		}
		else{
			int l, r;
			cin >> l >> r;
			l--;
			r--;

			cout << bit.range(l, r) << "\n";
		}
	}
}
