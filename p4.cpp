#include <iostream>
#include <string>
using namespace std;

int T,N,M;
int arr[15][15];
string str;
int main(){
	cin>>T;
	for(int CASE=1;CASE<=T;++CASE){
		cin>>N; getchar();
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				char c = getchar();
				arr[i][j] = c-'0';
			}
			getchar();
		}
		cin>>M;
		while(M--){
			cin>>str;
			//cout<<str<<endl;
		}
		printf("Case #%d\n",CASE);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
