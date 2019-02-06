#include <iostream>
#define watch(x) (cout << #x << " = " << (x) << endl);
using namespace std;

int numerals[10];

void fast_io(){
	 freopen("number.in", "r", stdin);
	 freopen("number.out", "w", stdout);
	 ios_base::sync_with_stdio(false);
	 cout.tie(0);
	 cin.tie(0);
}

int main(){
	fast_io();
	char x;
	int n = 0;
	
	bool allOnes = true;
	
	while(cin>>x){
		if(x == '4'){
			numerals[2]+=2;
		} else
		if(x == '6'){
			numerals[2]++;
			numerals[3]++;
		} else
		numerals[x-'0']++;
		
		if(x=='0'){
			cout << 0;
			return 0;
		}
		if(x!='1')
			allOnes = false;
		
	}
	
	if(allOnes){
		cout << 1;
		return 0;
	}
	numerals[9] += numerals[3]/2;
	numerals[3]%=2;
	
	numerals[8] += numerals[2]/3;
	numerals[2]%=3;
	
	while(numerals[2]&&numerals[3]){
		numerals[6]++;
		numerals[2]--;
		numerals[3]--;
	}
	
	numerals[4] += numerals[2]/2;
	numerals[2]%=2;
	
	numerals[1] = 0;
	
	for(int i = 2; i<10; i++)
		for(int j = 0; j<numerals[i]; j++) cout << i;
	
	return 0;
}


