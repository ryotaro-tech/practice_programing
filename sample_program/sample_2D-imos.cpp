//ABC434 D-Clouds
#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 2005;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> C(n, vector<int>(4));

	for(int i = 0; i < n; i++){
		cin >> C[i][0] >> C[i][1] >> C[i][2] >> C[i][3];
	}

	static int imos[SIZE][SIZE] = {};

	// 2D imos
	for(int i = 0; i < n; i++){
		int x1 = C[i][0] - 1;
		int x2 = C[i][1];
		int y1 = C[i][2] - 1;
		int y2 = C[i][3];

		imos[x1][y1]++;
		imos[x2][y1]--;
		imos[x1][y2]--;
		imos[x2][y2]++;
	}

	// 横累積
	for(int i = 0; i < 2000; i++){
		for(int j = 1; j < 2000; j++){
			imos[i][j] += imos[i][j - 1];
		}
	}

	// 縦累積
	for(int j = 0; j < 2000; j++){
		for(int i = 1; i < 2000; i++){
			imos[i][j] += imos[i - 1][j];
		}
	}

	int zero = 0;

	static int one[SIZE][SIZE] = {};

	for(int i = 0; i < 2000; i++){
		for(int j = 0; j < 2000; j++){
			if(imos[i][j] == 0) zero++;
			if(imos[i][j] == 1) one[i + 1][j + 1] = 1;
		}
	}

	// 2D累積和
	for(int i = 1; i <= 2000; i++){
		for(int j = 1; j <= 2000; j++){
			one[i][j] += one[i - 1][j] + one[i][j - 1] - one[i - 1][j - 1];
		}
	}

	for(int i = 0; i < n; i++){
		int x1 = C[i][0];
		int x2 = C[i][1];
		int y1 = C[i][2];
		int y2 = C[i][3];

		int cnt = one[x2][y2] - one[x1 - 1][y2] - one[x2][y1 - 1] + one[x1 - 1][y1 - 1];

		cout << zero + cnt << "\n";
	}
}


