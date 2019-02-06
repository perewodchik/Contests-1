#include <iostream>
#include <string>
#define watch(x) (cout << #x << " = " << (x) << endl);
using namespace std;
string s[110];

void fast_io(){
	 freopen("modest.in", "r", stdin);
	 freopen("modest.out", "w", stdout);
	 ios_base::sync_with_stdio(false);
	 cout.tie(0);
	 cin.tie(0);
}
bool shy(string s){
	string temp = s;
	for(int i = 0; i<s.size();i++){
		temp = temp.substr(s.size()-1, 1) + temp.substr(0, s.size()-1);
		if(temp<s) return false;
	}
	return true;
}

int main(){
	fast_io();
	string str; cin >> str;
	int left = 0;
	int lastRight = 0;
	int counter = 0;
	while(left < str.size()){
		int right = left + 1;
		bool gotNext = false;
		
		while(right <= str.size()){
			string firstPart = str.substr(left,right-left);
			string secondPart = str.substr(right, str.size()-right);
		
			if(shy(firstPart)&&(firstPart>secondPart)){
				lastRight = right;
				gotNext = true;
			}
			
			right++;
		}
		
		if(!gotNext) break;
		else {
			s[counter] = "("+str.substr(left, lastRight - left)+")";
			left = lastRight;
			counter++;
		}
	}
	for(int i = 0; i<counter;i++){
		cout << s[i];
	}
	return 0;
}


