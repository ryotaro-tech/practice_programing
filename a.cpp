#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long n;
long cnt(long l){
	vector<long> v(n);
	for(int i = 0; i < n; i++) cin>>v[i];
	sort(v.rbegin(), v.rend());
	long sum = 0;
	long r = n;
	for(int i = 0; i < n; i++){
		sum += v[i];
		if(sum > l){
			r = i + 1;
			break;
		}
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long x,y;cin>>n>>x>>y;
	//long a = cnt(x), b = cnt(y);
	//cout << min(a, b) << endl;
	//cout << a << ' ' << b << endl;
	cout << min(cnt(x), cnt(y)) << endl;
}
