//演習問題集 054-FIbonacci Hard (mod 1000000000)
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const long MOD = 1e9;

struct Matrix{
	long a[2][2];
};

Matrix multiply(Matrix x, Matrix y){
	Matrix r{};
	for (int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				r.a[i][j] += x.a[i][k]*y.a[k][j];
				r.a[i][j] %= MOD;
			}
		}
	}

	return r;
}

Matrix power(Matrix base, long n){
	Matrix r{{
		{1, 0},
		{0, 1}
	}};

	while(n > 0){
		if (n & 1) r = multiply(r, base);
		base = multiply(base, base);
		n >>= 1;
	}

	return r;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long n;cin>>n;
	Matrix A{{
		{1, 1},
		{1, 0}
	}};

	Matrix R = power(A, n - 2);
	long ans = (R.a[0][0] + R.a[0][1])%MOD;
	cout << ans << endl;
}
