#include <iostream>
#include <stack>
#include <queue>
using namespace std;
//要注意判斷structure為空的情況 
//priority_queue包含在queue裡面 
int n,type,x;
bool isStack,isQueue,isPriority;
int main(){
	while(cin>>n){
		//init
		stack< int > bagS;
		queue< int > bagQ;
		priority_queue< int > bagP;
		isStack=isQueue=isPriority=true;
		
		while(n--){
			cin>>type>>x;
			if(type==1){
				if(isStack) bagS.push(x);
				if(isQueue) bagQ.push(x);
				if(isPriority) bagP.push(x);
			}
			else if(type==2){
				if(isStack) {
					if(!bagS.empty() && bagS.top()==x) bagS.pop();
					else isStack=false;
				}
				if(isQueue) {
					if(!bagQ.empty() && bagQ.front()==x) bagQ.pop();
					else isQueue=false;
				}
				if(isPriority){
					if(!bagP.empty() && bagP.top()==x) bagP.pop();
					else isPriority=false;
				}
			}
		}
		//cout<<isStack<<isQueue<<isPriority<<endl;
		if(isStack+isQueue+isPriority>1) cout<<"not sure"<<endl;
		else if(isStack) cout<<"stack"<<endl;
		else if(isQueue) cout<<"queue"<<endl;
		else if(isPriority) cout<<"priority queue"<<endl;
		else cout<<"impossible"<<endl;
	}
	return 0;
}
