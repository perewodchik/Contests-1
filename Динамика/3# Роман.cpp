#include <iostream>
#define SIZE_MAX 110
#define FOR(start, end) for(int i = start; i<=end;i++)
#define MAX_N (int)2e10;
typedef long long ll;

using namespace std;

ll a[SIZE_MAX];
ll dp[SIZE_MAX][SIZE_MAX];
int solved[SIZE_MAX][SIZE_MAX];

ll search(int N, int K){
	
	if(dp[N][K]!=0) return dp[N][K];
	
	//1. N == K 1-ый частный случай
	if(N==K){
		ll max_pages = 0;
		FOR(1,N) max_pages = max(max_pages, a[i]);
		//solved[N][K] = 1;
		dp[N][K] = max_pages;
		
		return max_pages;
	}
	
	//2. K == 1 2-ой частный случай
	if(K==1){
		ll max_pages = 0;
		FOR(1,N) max_pages+=a[i];
		//solved[N][K] = 1;
		dp[N][K] = max_pages;
		return max_pages;
	}
	
	ll max_pages = 0;
	ll min_max_pages = MAX_N;
	for(int i = N-1;i>=K-1;i--){
		ll sum = 0;
		for(int j = i+1; j<=N; j++) sum+=a[j];
		/*int lower = search(i, K-1);
		max_papers = max(lower, sum);
		min_max_papers = min(max_papers,min_max_papers);*/
		dp[i][K-1] = search(i, K-1);
		max_pages = max(dp[i][K-1], sum);
		min_max_pages = min(max_pages,min_max_pages);
		
	}
	return min_max_pages;
}

int main(){
	freopen("Input.txt","r",stdin);
	freopen("Output.txt","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	
	cin >> n >> k;
	
	FOR(1,n) cin >> a[i];
	
	
	cout << search(n,k);
	
	return 0;
}
