#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n;
	while(cin>>n && n){
		queue< int > Q;
		for(int i=1;i<=n;++i) Q.push(i);
		printf("Discarded cards:");
		while(Q.size()>2){
			printf(" %d,", Q.front()); 
			Q.pop();
			int c = Q.front();
			Q.pop();
			Q.push(c);
		}
		if(Q.size()==2){
			printf(" %d", Q.front()); 
			Q.pop();
			int c = Q.front();
			Q.pop();
			Q.push(c);
		}
		printf("\nRemaining card: %d\n", Q.front()); 
		Q.pop();
	}
	return 0;
}
