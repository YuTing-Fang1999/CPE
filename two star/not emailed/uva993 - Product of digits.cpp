#include <iostream>
using namespace std;

int main(){
	int T, N; 
	int num[] = {9,8,7,6,5,4,3,2};
	int ans[15];
	int cur;
	
	cin>>T;
	while(T--){
		cin>>N;
		if(N==1) cout<<N<<endl;
		else if(N==0) cout<<10<<endl; //因為0不是自然數 
		else{
			cur=-1;
			for(int i=0;i<8;++i){
				while(N%num[i]==0 && N>1) {
					ans[++cur]=num[i];	
					N/=num[i];
				}
			}
			if(N==1){
				for(int i=cur;i>=0;--i) cout<<ans[i];
				cout<<endl;
			}
			else cout<<-1<<endl;
		}
	} 
	
	return 0;
}
