#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int p,c,root,T=0;
//無設定陣列範圍就用map 
unordered_map< int, vector< int > > node;
unordered_map<int, int> in;
unordered_map<int, bool> isNode;
unordered_map<int, bool> visit;
unordered_map<int, bool>::iterator it;
bool isTree;

bool DFS(int p){
	visit[p]=true;
	for(int i=0;i<node[p].size();++i){
		int c = node[p][i];
		if(visit[c]) return false;
		visit[c]=true;
		if(!DFS(c)) return false;
	}
	return true;
}
int main(){
	while(cin>>p>>c && p>-1 && c>-1){
		isTree=true;
		
		if(p && c){ //注意empty tree的case 
			//init
			node.clear();
			in.clear();
			isNode.clear();
			visit.clear();
			
			node[p].push_back(c);
			isNode[p]=isNode[c]=true;
			in[c]++;
			
			
			while(cin>>p>>c && p && c){
				
				node[p].push_back(c);
				isNode[p]=isNode[c]=true;
				in[c]++;
			}
			
			//find root
			for(it=isNode.begin();it!=isNode.end();++it){
				if(it->second && in[it->first]==0){
					root=it->first;
					isTree = DFS(root);
					break;
				}
			}
			
			for(it=isNode.begin();it!=isNode.end();++it){
				if(it->second && !visit[it->first]){
					isTree=false;
					break;
				}
			}
		}
		
		printf("Case %d is ",++T);
		if(isTree) printf("a tree.\n");// Root is %d.,root
		else printf("not a tree.\n");
		
	}
}
