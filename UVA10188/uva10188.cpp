#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T=0;
int N,M;
string ans;
string res;
string str;
int main(){
	
	while(cin>>N && N){
		int y=-N; //�������檺�Ӽ� 
		ans=res="";
		//ans
		getchar();
		while(N--){
			getline(cin,str);
			ans+=(str+'\n'); //�`�N���檺�a��p�G���@�ˤ]��PE 
		}
		//res
		cin>>M; getchar();
		while(M--){
			getline(cin,str);
			res+=(str+'\n');
		}
//		cout<<ans<<endl;
//		cout<<res<<endl;
//		cout<<endl;
		y += ans.size();//CPE���n�D 
		printf("Run #%d: ",++T);
		if(ans == res ) printf("Accepted\n");
		else{
			//if all NUMERIC characters match (and in the same order)
			string s1="", s2="";
			for(int i=0;i<ans.size();++i){
				if('0'<=ans[i] && ans[i]<='9')
					s1+=ans[i]; 
			} 
			for(int i=0;i<res.size();++i){
				if('0'<=res[i] && res[i]<='9')
					s2+=res[i]; 
			} 
			if(s1==s2){
				printf("Presentation Error\n");
			}else{
				printf("Wrong Answer\n");
			}
		}
	}
	return 0;
}
