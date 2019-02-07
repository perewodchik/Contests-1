#include <iostream>
#define watch(x) (cout << #x << " = " << (x) << endl);
#define int long long
using namespace std;

void fast_io(){
	 freopen("veryhard.in", "r", stdin);
	 freopen("veryhard.out", "w", stdout);
	 ios_base::sync_with_stdio(false);
	 cout.tie(0);
	 cin.tie(0);
}

signed main(){
	fast_io();
	
	int curr, needed;
	cin >> curr >> needed;
	int years = 0;
	while((curr<needed)&&(years<100)){
		curr*=2;
		years++;
	}
	years>=100?cout<<100:cout<<years;
	
	return 0;
}


