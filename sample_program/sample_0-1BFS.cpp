//演習問題集 048-Small Multple
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int INF = 1e9;
	int k;
	cin>>k;

	vector<int> dist(k, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for(int d = 1; d <= 9; d++){
		int r = d%k;
		if(dist[r] > d){
			dist[r] = d;
			pq.push({d, r});
		}
	}

	while(!pq.empty()){
		auto [cost, r] = pq.top();
		pq.pop();

		if(cost > dist[r]) continue;
		for(int d = 0; d <= 9; d++){
			int nr = (r * 10 + d)%k;
			int nc = cost + d;
			
			if(dist[nr] > nc){
				dist[nr] = nc;
				pq.push({nc, nr});
			}
		}
	}
	
	cout << dist[0] << endl;
}
