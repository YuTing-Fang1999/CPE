#include <iostream>
#include <string>
using namespace std;

string preTree, inTree;
int preIdx;

// 有空再自己寫一次 
// preorder  (root, left subtree, right subtree) 第一次碰到就印出 
// inorder   (left subtree, root, right subtree) 第二次碰到就印出  
// postorder (left subtree, right subtree, root) 第三次碰到就印出 
// 如果給定一二元樹的中序-後序、或者中序-前序都可以求得唯一的二元樹，但是前序-後序則無法求得 

// 先藉由 preorder 得到 root
// 再由 inorder 分成 (left subtree, root, right subtree)

struct Tree{
	Tree* right;
	Tree* left;
	char val;
	Tree(char v){
		this->left = NULL;
		this->right = NULL;
		this->val = v;
	}
};

Tree* buildTree(int left, int right){
	Tree* root = new Tree(preTree[preIdx++]);
	if(left<right){
		int rootIdx = 0;
		for(int i=left;i<=right;++i){
			if(inTree[i] == root->val){
				rootIdx = i;
				break;
			}
		}
		if(left<rootIdx) root->left = buildTree(left, rootIdx-1);
		if(right>rootIdx) root->right = buildTree(rootIdx+1, right);
	}	
	
	return root;
}

void postoder(Tree *node){
	if(node->left!=NULL) postoder(node->left);
	if(node->right!=NULL) postoder(node->right);
	cout<<node->val;
}

int main(){
	while(cin>>preTree>>inTree){
		preIdx = 0;
		Tree* root = buildTree(0, preTree.size()-1);
		postoder(root);
		printf("\n");
	}
	
	return 0;
}
