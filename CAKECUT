#include <iostream>
using namespace std;

int dp[21][21][21];

int main() {
	// your code goes here
	int w, h, m;
	for(int i = 1; i<=20; i++){
		for(int j = 1; j<=20; j++)	dp[i][j][1] = i*j;
	}
	while(cin>>w>>h>>m){
		if(w == 0)break;
		if(w < h)swap(w, h);
		for(int i = 0; i<=w; i++)for(int j = 0; j<=h;j++)for(int t = 0; t<=m; t++)dp[i][j][t] = 987654321;
		for(int i = 1; i<=w; i++){
				for(int j = 1; j<=h; j++){
					dp[i][j][1] = i*j;
					for(int t = 2; t<=i*j && t<=20; t++){
						for(int a = 1; a<i; a++){
							for(int b = 1; b<t; b++){
								dp[i][j][t] = min(dp[i][j][t], max(dp[a][j][b], dp[i-a][j][t-b]));
							}
						}
						for(int a = 1; a<j; a++){
							for(int b = 1; b<t; b++){
								dp[i][j][t] = min(dp[i][j][t], max(dp[i][a][b], dp[i][j-a][t-b]));
							}
						}
					}
				}
			}
		cout<<dp[w][h][m]<<endl;
		
	}
	return 0;
}
