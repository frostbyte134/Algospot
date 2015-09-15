#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;
int ary[101], pSum[102];
int dp[11][101];
int cost[101][101];

int main() {
	// your code goes here
	int numC = 0;
	scanf("%d", &numC);
	memset(cost, 0, sizeof(cost));
	for(int cases = 0; cases<numC; cases++){
		int N, S;
		scanf("%d %d", &N, &S);
		pSum[0] = 0;
		for(int i = 0; i<N; i++){
			scanf("%d", &ary[i]);
		}
		sort(ary, ary+N);
		for(int i = 0; i<N; i++)
			pSum[i+1] = pSum[i] + ary[i];
		for(int i = 0; i<N-1; i++){
			for(int j = i+1; j<N; j++){
				double summ = pSum[j+1]-pSum[i];
				int avg = summ/(j-i+1)+0.5;
				cost[i][j] = 0;
				for(int k = i; k<=j; k++){
					cost[i][j] += (ary[k]-avg)*(ary[k]-avg);
				}
			}
		}
		
		for(int i = 0; i<N; i++)dp[0][i] = cost[0][i];
		for(int s = 1; s<S; s++){
			for(int i = 1; i<N; i++){
				dp[s][i] = 987654321;
				for(int k = 1; k<=i; k++){
					dp[s][i] = min(dp[s][i], dp[s-1][k-1] + cost[k][i]); 
				}
			}
		}
		printf("%d\n", dp[S-1][N-1]);
	}
	return 0;
}
