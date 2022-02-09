#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool isBoring;
vector< int > a;
int main(){
	while(cin>>n>>m){
		isBoring=false;
		a.clear();
		
		//注意除以0的case(m不可為0) 
		//題目定義k不可小於1所以n一定要大於1 
		if(n<=1 || m<=1){
			isBoring=true;
		}else{
			while(n!=1){
				if(n%m){ isBoring=true; break; }
				a.push_back(n);
				n/=m;
			}
		}
		
		if(isBoring) printf("Boring!\n");
		else{
			for(int i=0;i<a.size();++i){
				printf("%d ",a[i]);
			}
			printf("1\n");
		}
		
	}
	return 0;
}
