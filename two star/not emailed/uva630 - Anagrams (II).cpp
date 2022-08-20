#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
//ÅÜ¦ì¦rÁ¼
int T,N;
string str, str2;
int main(){
	cin>>T;
	while(T--){
		getchar();
		cin>>N;
		map< string, vector< string > > Anagrams;
		for(int i=0;i<N;++i){
			cin>>str;
			str2 = str;
			sort(str2.begin(),str2.end());
			Anagrams[str2].push_back(str);
		}
		
		while(cin>>str && str!="END"){
			str2 = str;
			sort(str2.begin(),str2.end());
			vector< string > ans = Anagrams[str2];
			
			printf("Anagrams for: %s\n",str.c_str());
			if(ans.empty()){
				printf("No anagrams for: %s\n", str.c_str());
			}
			else{
				for(int i=0;i<ans.size();++i){
					printf("  %d) %s\n", i+1, ans[i].c_str());
				}
			}
		}
		if(T) printf("\n");
	}
	return 0;
}
