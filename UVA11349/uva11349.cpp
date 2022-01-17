#include <iostream>
using namespace std;

int T,N;
char c;
long long arr[105][105];
bool sym;

int main(){
	cin>>T;
	for(int i=1;i<=T;++i){
		sym=true;
		cin>>c>>c>>N;
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j){
				cin>>arr[i][j];
				if(arr[i][j]<0) sym=false;
			}
			
		if(sym)				
			for(int i=0;i<=N/2;++i)
				for(int j=0;j<N;++j)
					if(arr[i][j] != arr[N-i-1][N-j-1]){
						sym=false;
						break;
					}
			
		printf("Test #%d: ",i);
		if(sym) cout<<"Symmetric."<<endl;
		else cout<<"Non-symmetric."<<endl;
	}
	return 0;
}
