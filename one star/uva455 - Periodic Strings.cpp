#include <iostream>
#include <string>
using namespace std;

bool isPeriod(string str, int p){
	if(str.size()%p!=0) return false;
	
	int i=p;
	while(i<str.size()){
		if(str[i-p]!=str[i]) return false;
		i+=1;
	}
	return true;
}

string str;
int N;
int main(){
	cin>>N;
	while(N--){
		getchar();
		cin>>str;
		
		int ans=-1;
		for(int p=1;p<=str.size()/2;++p){
			if(isPeriod(str,p)){
				ans = p;
				break;
			}
		}
		
		if(ans==-1) ans = str.size();
		printf("%d\n",ans);
		if(N) printf("\n");
	}
	return 0;
}

