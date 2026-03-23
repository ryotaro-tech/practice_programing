//ABC435 D-Teleport Maze
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;

	vector<vector<char>> v(h, vector<char>(w));
	vector<vector<pair<int, int>>> warp(26);

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> v[i][j];
			if('a' <= v[i][j] && v[i][j] <= 'z') warp[v[i][j] - 'a'].push_back({i, j});
		}
	}

	vector<vector<int>> dist(h, vector<int>(w, -1));
	queue<pair<int, int>> q;

	q.push({0, 0});
	dist[0][0] = 0;

	vector<bool> used(26, false);

	int dy[4] = {0, 0, -1, 1};
	int dx[4] = {-1, 1, 0, 0};

	while(!q.empty()){
		auto [y, x] = q.front();
		q.pop();

		if(y == h - 1 && x == w - 1){
			cout << dist[y][x] << endl;
			return 0;
		}

		// 4方向
		for(int d = 0; d < 4; d++){
			int ny = y + dy[d];
			int nx = x + dx[d];
			if(ny < 0 || ny > h - 1 || nx < 0 || nx > w - 1) continue;
			if(v[ny][nx] == '#') continue;
			if(dist[ny][nx] != -1) continue;

			dist[ny][nx] = dist[y][x] + 1;
			q.push({ny, nx});
		}

		// ワープ
		if('a' <= v[y][x] && v[y][x] <= 'z'){
			int c = v[y][x] - 'a';
			if(!used[c]){
				used[c] = true;
				for(auto [ny, nx] : warp[c]){
					if(dist[ny][nx] == -1){
						dist[ny][nx] = dist[y][x] + 1;
						q.push({ny, nx});
					}
				}
			}
		}
	}

	cout << -1 << endl;
}

