#include <iostream>
#include <algorithm>
#define SIZE_MAX 110
#define MAX_N 2147483647;

using namespace std;

int dp[SIZE_MAX][SIZE_MAX];
int solved[SIZE_MAX][SIZE_MAX];

int search(int i, int j){
	if(solved[i][j]) return dp[i][j];
	
	int min_hor = MAX_N;
	int min_ver = MAX_N;
	
	if(i == 1)
		return j-1;
	if(j == 1)
		return i-1;
	if(i == j)
		return 0;
		
	for(int k = 1;k<j;k++){
		dp[i][j-k] = search(i,j-k);
		dp[i][k] = search(i,k);
		solved[i][j] = 1;
		min_ver = min(/*search(i,j-k)+search(i,k)+1*/dp[i][j-k]+dp[i][k]+1, min_ver);
	}
	for(int k = 1;k<i;k++){
		dp[k][j] = search(k,j);
		dp[i-k][j] = search(i-k,j);
		solved[i][j] = 1;
		min_hor = min(/*search(k,j)+search(i-k,j)+1*/dp[k][j]+dp[i-k][j]+1, min_hor);
	}
	
	return min(min_hor,min_ver);
}
int main(){
	freopen("Input.txt","r",stdin);
	freopen("Output.txt","w",stdout);
	int n, m;
	cin >> n >> m;
	
	cout << search(n,m);
	//cout << dp[n][m];
	
	return 0;
}
	




