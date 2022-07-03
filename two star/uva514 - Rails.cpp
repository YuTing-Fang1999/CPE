#include <iostream>
#include <stack>
using namespace std;
//�����i�J�����ǩT�w�O�q1~N
//�n�P�_�O�_����D�ت��������} 
int main(){
	int N;
	int order[1005];
	while(cin>>N && N){
		while(cin>>order[0] && order[0]){
			for(int i=1;i<N;++i) cin>>order[i];
			stack< int > S; 
			int idx = 0;
			for(int i=1;i<=N;++i){
				S.push(i);
				while(!S.empty() && S.top() == order[idx]) {
					S.pop();
					++idx;
				}
			}
			if(S.empty()) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
