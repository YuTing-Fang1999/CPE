#include <iostream>
#include <string.h>
using namespace std;

int T=0;
int n,m;
char arr[105][105];
char c;
int changeX[] = {-1,0,1,1,1,0,-1,-1};
int changeY[] = {-1,-1,-1,0,1,1,1,0};

int main(){
	while(cin>>n>>m && n && m){
		memset(arr,'0',sizeof(arr));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>c;
				if(c=='*'){
					arr[i][j]='*';
					for(int k=0;k<8;++k){
						int x=i+changeX[k];
						int y=j+changeY[k];
						if(x>=0 && y>=0 && x<n && y<m && arr[x][y]!='*') 
							arr[x][y]+=1;
					}
					
				}
			}
		}
		if(T) cout<<endl;
		printf("Field #%d:\n",++T);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
