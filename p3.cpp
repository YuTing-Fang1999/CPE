#include <iostream>
#include <string>
using namespace std;

int T;
long long C,M,Y;
string str;
int main(){
	cin>>T;
	while(T--){
		cin>>M>>Y>>C;
		getline(cin, str);
		for(int i=1;i<str.size();++i){
			if(str[i] == 'M') { M--; }
			if(str[i] == 'Y') { Y--; }
			if(str[i] == 'C') { C--; }
			if(str[i] == 'R') { M--;Y--; }
			if(str[i] == 'B') { M--;Y--;C--; }
			if(str[i] == 'G') { Y--;C--; }
			if(str[i] == 'V') { M--;C--; }
			if(str[i] == 'W') { ; }
		}
		if( M>=0 && C>=0 && Y >=0) printf("YES %lld %lld %lld\n",M,Y,C);
		else printf("NO\n");
	}
	return 0;
}
