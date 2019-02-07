#include <iostream>
#define watch(x) (cout << #x << " = " << (x) << endl);
using namespace std;

void fast_io(){
	 freopen("vessels.in", "r", stdin);
	 freopen("vessels.out", "w", stdout);
	 ios_base::sync_with_stdio(false);
	 cout.tie(0);
	 cin.tie(0);
}

int min_n = 1000;
bool canWe(int a, int b){     //Можем ли мы перелить из сосуда a в сосуд b
	if(a>=b) return true;
	
	return false;
}
void search(int a, int b, int c, int current){
	if(min_n<current) return;
	if((a==b)&&(b==c)) {          //Случай если все сосуды равны
		current+=1;
		a = 0; b = 0; c = 0;
	}
	if((a==0)||(b==0)||(c==0)){
		if(min_n > current){
			min_n = current;
			return;
		}
	}
	if(canWe(a,b)) search(a-b,b*2,c, current+1);
	if(canWe(b,a)) search(a*2,b-a,c, current+1);
	if(canWe(a,c)) search(a-c,b,c*2, current+1);
	if(canWe(c,a)) search(a*2,b,c-a, current+1);
	if(canWe(b,c)) search(a,b-c,c*2, current+1);
	if(canWe(c,b)) search(a,b*2,c-b, current+1);
	return;
}


int main(){
	fast_io();
	int a,b, c;
	cin >> a >> b >> c;
	search(2, 3, 4, 0);
	cout << min_n;
	
	return 0;
}


