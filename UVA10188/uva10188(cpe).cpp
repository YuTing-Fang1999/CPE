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
		int y=-N; //扣掉換行的個數 
		ans=res="";
		//ans
		getchar();
		while(N--){
			getline(cin,str);
			ans+=(str+'\n'); //注意換行的地方如果不一樣也算PE 
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
		y += ans.size();
		printf("Run #%d: ",++T);
		if(ans == res ) printf("Accepted %d\n",y);
		else{
			ans.erase(remove(ans.begin(),ans.end(),' '),ans.end());
			res.erase(remove(res.begin(),res.end(),' '),res.end());
			ans.erase(remove(ans.begin(),ans.end(),'\n'),ans.end());
			res.erase(remove(res.begin(),res.end(),'\n'),res.end());
			if(ans==res){
				printf("Presentation Error %d\n",y);
			}else{
				printf("Wrong Answer %d\n",y);
			}
		}
	}
	return 0;
}
