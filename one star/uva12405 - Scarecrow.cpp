#include <iostream>
#include <string>
using namespace std;

int main(){
	int T, N; cin>>T;
	string str;
	for(int CASE=1;CASE<=T;++CASE){
		cin>>N;
		cin>>str;
		int ans = 0;
		for(int i=0;i<N;++i){
			if(str[i] == '.'){
				++ans;
				i+=2;
			}
		}
		printf("Case %d: %d\n",CASE, ans);
	}
	return 0;
}
