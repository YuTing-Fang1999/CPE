#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--){
		int r;
		cin>>r;
		
		int s[r];
		for(int i=0;i<r;++i){
			cin>>s[i];
		}
		sort(s,s+r);
		
		int mid = s[r/2];
		int distances = 0;
		for(int i=0;i<r;++i){
			distances+=abs(s[i]-mid);
		}
		
		printf("%d\n",distances);
		
	}
	return 0;
}
