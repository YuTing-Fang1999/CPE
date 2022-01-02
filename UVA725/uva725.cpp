#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int N;
bool used[10];
int usedNum;
bool valid;
bool isFind;

int main(){
	cin>>N;
	while(N){
		isFind=false;
		for(int i=1234; i<=98765; ++i){
			if(i%N==0) {
				memset(used,false,sizeof(used));valid=true;usedNum=0;
				int n1 = i;
				int n2 = i/N;
				
				if(n2<10000) {usedNum=1;used[0]=true;}
				while(n1){
					if(used[n1%10]){valid=false; break;}
					used[n1%10] = true; ++usedNum;
					n1/=10;
				}
				while(n2){
					if(used[n2%10]){valid=false; break;}
					used[n2%10] = true; ++usedNum;
					n2/=10;
				}
				if(usedNum!=10) valid = false;
					
					
				if(valid){
					isFind=true;
					printf("%d / %05d = %d\n",i,i/N,N);
				}
			}
		}
		if(!isFind) printf("There are no solutions for %d.\n",N);
		
		cin>>N;
		if(N) cout<<endl;
	}
	return 0;
}
