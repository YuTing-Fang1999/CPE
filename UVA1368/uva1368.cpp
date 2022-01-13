#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int T,n,m;
string str;
string strList[55];

int num[4]={0};
char c[4]={'A','C','G','T'};
int error;
string ans;

int main(){
	cin>>T;
	while(T--){
		
		error=0;
		ans="";
		
		cin>>n>>m;
		for(int i=0;i<n;++i){
			cin>>strList[i];
		}

		for(int j=0;j<m;++j){
			memset(num,0,sizeof(num));
			for(int i=0;i<n;++i){
				for(int k=0;k<4;++k){
					if(strList[i][j] == c[k]) {
						++num[k];
					}
				}			
			}
			int idx=0;
			for(int i=0;i<4;++i){
				if(num[i]>num[idx]) idx=i;
			}
			error+=(n-num[idx]); 
			ans+=c[idx];
		}
		
		cout<<ans<<endl;
		cout<<error<<endl;
	}
	return 0;
}

