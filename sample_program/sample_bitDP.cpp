//ABC424 D-2x2 Eracing
#include <bits/stdc++.h>
using namespace std;

#define INF (int) 1e9
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(){
	int t;
	cin>>t;
	rep(_,t){
		int h,w,k;
		cin>>h>>w;
		k=1<<w;

		vector<string>s(h);
		rep(i,h)cin>>s[i];

		vector<vector<bool>> allow(k,vector<bool>(k,true));
		rep(i,k){
			rep(j,k){
				rep(ii,w-1){
					if((((i>>ii)&3)==3)&&(((j>>ii)&3)==3)){
						allow[i][j]=false;
						break;
					}
				}
			}
		}

		vector<int>dp(k,INF);
		dp[0]=0;
		rep(i,h){
			int state=0;
			rep(j,w)if(s[i][j]=='#')state+=(1<<j);
			vector<int>dp2(k,INF);
			rep(j,k){
				if((j|state)==state){
					rep(jj,k){
						if(allow[jj][j])dp2[j]=min(dp2[j],dp[jj]+__builtin_popcount((unsigned int)(j^state)));
					}
				}
			}
			dp=dp2;
		}

		int ans=INF;
		rep(i,k)ans=min(ans,dp[i]);
		cout << ans << endl;
	}

	return 0;
}

