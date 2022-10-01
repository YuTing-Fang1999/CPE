#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n, m;
	int n1, n2;
	while(cin>>n && n){ //n=�`�I���ƥ� m=�䪺�ƥ�
		cin>>m;
		vector< vector< int > > conn(n);
		vector< int > color(n, -1);
		//�ϧάO�j�s�q���A�]�N�O����2�`�I�����Ҧ����|�۳s�C
		for(int i=0;i<m;++i){
			cin>>n1>>n2;
			conn[n1].push_back(n2);
			conn[n2].push_back(n1);
		}
		
		bool isBICOLORABLE=true;
		int now=0, next=-1;
		queue <int> q;
    	q.push(now);
    	color[now]=0;
    	// BFS
    	while(!q.empty() && isBICOLORABLE){
    		now = q.front(); q.pop();
    		for(int i=0;i<conn[now].size();++i){
    			next=conn[now][i];
    			
				if(color[next]==-1){
					color[next]=!color[now];
					q.push(next);
				}
				else{
					if(color[next]==color[now]){
						isBICOLORABLE=false;
						break;
					}
				}
			}
		}
		
		if(isBICOLORABLE) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
		
	}
	return 0;
}

//DFS: https://knightzone.studio/2012/03/17/1498/uva%EF%BC%9A10004%EF%BC%8Dbicoloring/
