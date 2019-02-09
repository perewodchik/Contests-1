#include <iostream>
#define watch(x) (cout << #x << " = " << (x) << endl);
#define int long long
using namespace std;

void draganov_style(){
	 freopen("eclipse.in", "r", stdin);
	 freopen("eclipse.out", "w", stdout);
	 ios_base::sync_with_stdio(false);
	 cout.tie(0);
	 cin.tie(0);
}

signed main(){
	draganov_style();
	int a;
	cin >> a;
	int b = a; int c = a;
	int counter = 0;
	for(int i = b; i>0;i-=2)
		counter+=i;
		
	cout << counter;
	
	return 0;
}


