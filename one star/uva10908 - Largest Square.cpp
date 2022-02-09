#include <iostream>
using namespace std;

int T,M,N,Q,r,c;
char grid[105][105];

int largestSquare(int r,int c,int len){
	if(r+len>=M || r-len<0 || c+len>=N || c-len<0) return 2*len-1;
	for(int i=r-len;i<=r+len;++i){
		for(int j=c-len;j<=c+len;++j){
//			printf("%d %d \n",i,j);
			if(grid[r][c]!=grid[i][j])
				return 2*len-1;
		}
	}
	return largestSquare(r,c,len+1);
}
int main(){
	cin>>T;
	while(T--){
		cin>>M>>N>>Q;
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				cin>>grid[i][j];
			}
		}
		printf("%d %d %d\n",M,N,Q);
		while(Q--){
			cin>>r>>c;
			cout<<largestSquare(r,c,1)<<endl;
		}
	}
	return 0;
}
