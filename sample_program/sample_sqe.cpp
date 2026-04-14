//ABC397 D-Cubes
#include <iostream>
using namespace std;

long sol(long a, long b, long c){
	long l = 0, r = 600000001;
	while(r - l > 1){
		long mid = (l + r)/2;
		if(a*mid*mid + b*mid + c <= 0){
			l = mid;
		}
		else r = mid;
	}

	if(a*l*l + b*l + c == 0) return l;
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long n;cin>>n;
	for(long d = 1; d*d*d <= n; d++){
		if(n%d != 0) continue;
		long m = n/d;
		long k = sol(3, 3*d, d*d - m);
		if(k > 0){
			cout << k + d << ' ' << k << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
