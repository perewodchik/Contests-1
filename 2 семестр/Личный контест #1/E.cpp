#include <iostream>
#include <algorithm>
#define watch(x) (cout << #x << " = " << (x) << endl);
using namespace std;

void fast_io(){
	 freopen("rating.in", "r", stdin);
	 freopen("rating.out", "w", stdout);
	 ios_base::sync_with_stdio(false);
	 cout.tie(0);
	 cin.tie(0);
}
struct sort_pair {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
    	if(left.second == right.second) return left.first<right.first;
        return left.second > right.second;
    }
};

int getScoreByPlace(int i){
	if(i == 1) return 15;
	if(i == 2) return 12;
	if(i == 3) return 9;
	if(i>=4&&i<=10) return 10-i+1;
	if(i == 13) return (-10);
}
pair<int,int> players[1010];

int main(){
	fast_io();
	int n;
	int t;
	cin >> t >> n;
	for(int i = 0;i<n;i++)
		players[i].first = i+1;
	for(int i = 0; i<t;i++){
		int difficult, plrs;
		cin >> difficult;
		cin >> plrs;
		
		for(int i = 1; i<=plrs;i++){
			int player;
			cin >> player;
			if(player>n) continue;
			int balls = getScoreByPlace(i);
			
			players[player-1].second+=balls*difficult;
		}
	}
	sort(players,players+n, sort_pair());
	
	for(int i = 0; i<n;i++){
		if(players[i].second<1||i>9) break;
		cout << i+1 << " " << players[i].first <<" "<<players[i].second << endl;
	}
	
	return 0;
}


