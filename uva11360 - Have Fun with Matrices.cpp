#include <iostream>
#include <string>
using namespace std;


int T,N,M,a,b;
int arr[15][15];
string str;


void row(int arr[15][15], int a, int b){
	for(int i=0;i<N;++i) swap(arr[a][i],arr[b][i]);
}

void col(int arr[15][15], int a, int b){
	for(int i=0;i<N;++i) swap(arr[i][a],arr[i][b]);
}

void inc(int arr[15][15]){
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			arr[i][j] = (arr[i][j]+1)%10;
}

void dec(int dec[15][15]){
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			arr[i][j] = (arr[i][j]+10-1)%10;
}

void transpose(int dec[15][15]){
	for(int i=0;i<N;++i)
		for(int j=i;j<N;++j)
			 swap(arr[i][j],arr[j][i]);
}


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
			if(str == "row") {
				cin>>a>>b;
				row(arr,a-1,b-1);
			}
			else if(str == "col") {
				cin>>a>>b;
				col(arr,a-1,b-1);
			}
			else if(str == "inc") inc(arr);
			else if(str == "dec") dec(arr);
			else if(str == "transpose") transpose(arr);
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
