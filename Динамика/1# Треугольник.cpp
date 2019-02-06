#include <iostream>

using namespace std;

int a[110][110];

int main(){
	freopen("Input.txt","r",stdin);
	freopen("Output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=i;j++)
			cin >> a[i][j];
			
	for(int i = n-1;i>0;i--){
		//cout << i << endl;
		for(int j = 1;j<=i;j++){
			//cout << j << " ";
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
		//	cout << a[i][j] << " ";
		}
		//cout << endl;
	}
	
	cout << a[1][1];			
	
	return 0;
}
