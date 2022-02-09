#include <iostream>
#include <string>
using namespace std;
//�N�G�i���୼�Q�i��A�P�_s1,s2�O�_�㦳���]�� => GCD����1 
//�`�N�G�i����Q�i�쪺��k 
int N;
string s1,s2;
int n1,n2;

int GCD(int a,int b){
	while((a%=b) && (b%=a));
	return (a+b);
}
int main(){
	cin>>N;
	for(int CASE=1;CASE<=N;++CASE){
		
		cin>>s1>>s2;
		n1=n2=0;
		for(int i=0;i<s1.size();++i) n1=2*n1+(s1[i]-'0');
		for(int i=0;i<s2.size();++i) n2=2*n2+(s2[i]-'0');
//		printf("%d %d %d\n",n1,n2,GCD(n1,n2));
		printf("Pair #%d: ",CASE);
		if(GCD(n1,n2)==1) printf("Love is not all you need!\n");
		else printf("All you need is love!\n");
	}
	return 0;
}
