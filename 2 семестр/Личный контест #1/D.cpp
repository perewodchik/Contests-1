#include <iostream>
#define watch(x) (cout << #x << " = " << (x) << endl);
#define NMAX 210
#define ANY '*'
using namespace std;

int h, w;

char workplace[NMAX][NMAX];
char piece[NMAX][NMAX];

void nullPiece(){
	for(int i = 0; i<NMAX;i++){
		for(int j = 0; j<NMAX;j++)
			piece[i][j] = 0;
	}
}
void getPiece(int a){
	nullPiece();
	for(int i = 1; i<=a;i++){
		for(int j = 1; j<=a; j++)
			piece[i][j] = workplace[i][j];
	}
}

bool overlay(int a){
	for(int i = 1; i<=h; i++)
		for(int j = 1; j<=w; j++){
			if(workplace[i][j]==ANY) continue;
			if(workplace[i][j]!=piece[(i-1)%a + 1][(j-1)%a + 1])
				return false;
		}
	
	return true;
}

void fast_io(){
	 freopen("picture.in", "r", stdin);
	 freopen("picture.out", "w", stdout);
	 ios_base::sync_with_stdio(false);
	 cout.tie(0);
	 cin.tie(0);
}

int main(){
	fast_io();
	cin >> h >> w;
	for(int i = 1; i<=h;i++)
		for(int j = 1; j<=w; j++)
			cin >> workplace[i][j];
			
	if(h>w)
		for(int i = 1; i<=h;i++)
			for(int j = w+1; j<=h; j++)
				workplace[i][j] = ANY;
		
	if(w>h)
		for(int i = h+1; i<=w; i++)
			for(int j = 1; j<=w;j++)
				workplace[i][j] = ANY;
				
	for(int i = 1; i<=max(h,w); i++){
		getPiece(i);
		if(overlay(i)){
			cout << i;
			return 0;
		}
	}
	return 0;
}
