//ABC440 D-Forbidden list
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < int (n); i++)
#define ll long long

int check(vector<ll> &A, ll x, ll y){
	int bou = lower_bound(A.begin(), A.end(), x) - A.begin();
	int n = A.size();
	int ok = bou - 1;
	int ng = n;
	
	while(ng - ok > 1){
		int mid = (ng + ok)/2;
		ll num = A[mid] - x + 1 - (mid - bou + 1);
		if(num < y) ok = mid;
		else ng = mid;
	}
	
	return ok;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<ll> A(n);
	rep(i, n) cin >> A[i];
	
	sort(A.begin(), A.end());

	while(q--){
		ll x, y;
		cin >> x >> y;
		int bou1 = lower_bound(A.begin(), A.end(), x) - A.begin();
		int bou2 = check(A, x, y);
		int num = x + y - 1 + (bou2 - bou1 + 1);
		cout << num << "\n";
	}
}
