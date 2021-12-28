#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
	char graph[55][55];
	int endIdx[55];
	int N; cin>>N;
	for(int c=1;c<=N;++c){
		printf("Case #%d:\n",c);
		//init 
		memset(graph,' ',sizeof(graph));
		memset(endIdx,-1,sizeof(endIdx));
		//input
		string str; cin>>str;
		//find low, high
		int low=0,high=0,x=0,y=0;
		for(int i=0;i<str.size();++i){
			if(str[i] == 'R')  {
				++y;	
				if(y > high) high = y;
			}
			if(str[i] == 'F')  {
				--y;
				if(y < low) low = y;
			}
		}
		//find h,init y
		int h = high-low; y=-low;
		//input graph
		for(x=0;x<str.size();++x){
			if(str[x] == 'R')  {
				graph[x][h-y]='/';
				endIdx[h-y] = x;
				++y;
				
			}
			if(str[x] == 'C')  {
				graph[x][h-y]='_';
				endIdx[h-y] = x;
			}
			if(str[x] == 'F')  {
				--y;
				graph[x][h-y]='\\';
				endIdx[h-y] = x;
			}
			
		}
		
		x=y=0;
		//如果第一行沒東西就不要print 
		if(endIdx[0] == -1) ++y;
		
		for(;y<=h;++y){
			cout<<"| ";
			for(x=0;x<str.size();++x){
				cout<<graph[x][y];
				if(x == endIdx[y]){
					cout<<endl;
					break;
				}
			}
		}
		cout<<"+";
		for(int x=0;x<str.size()+2;++x){
			cout<<"-";
		}
		cout<<endl<<endl;
	}
	return 0;
}
