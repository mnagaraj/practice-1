#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* root=NULL;
Node* root1=NULL;
queue<int> q1;

Node* GetNode(int data)
{
    Node*ptr=new Node();
    ptr->data=data;
    ptr->left=ptr->right=NULL;
    return ptr;
}
Node* insert(Node* root, int data){
    if(root==NULL){
        root=GetNode(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

bool search(Node*root, int data){
    if(root==NULL){return false;}
    else if(data==root->data){
        return true;
    }
    else if(data < root->data){
        return search(root->left,data);
    }
    else if(data > root->data){
        return search(root->right,data);
    }
}

int Getmin(Node* root)
{
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL)
    {
        return root->data;
    }
    return Getmin(root->left);
}

int Getmax(Node* root)
{
    if(root==NULL){
        return -1;
    }
    if(root->right==NULL)
    {
        return root->data;
    }
    return Getmax(root->right);
}

int getHeight(Node* root){
    if(root==NULL){
        return -1;
    }
    return max(getHeight(root->left),getHeight(root->right))+1;
}

void bfs(Node* root)
{
    if(root==NULL)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        if(temp!=NULL){
            cout<<temp->data<<"--";
        }
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        q.pop();
    }
}

void preorder(Node* root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data<<"--";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root==NULL){
        return;
    }
    cout<<"(";
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    cout<<")";
}

void inorder_special(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL){
        return;
    }
    inorder_special(root1->left,root2->left);
    if(root1->data < root2->data){
        q1.push(root2->data);
        if(root1->data < q1.front()){
            cout<<root1->data;
        }
        else{
            cout<<q1.front();
            q1.pop();
        }
        inorder_special(root1->right,root2->right);
    }
    else{
        q1.push(root1->data);
        if(root2->data < q1.front()){
            cout<<root2->data;
        }
        else{
            cout<<q1.front();
            q1.pop();
        }
        inorder_special(root1->right,root2->right);
    }
}

void postorder(Node* root)
{
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"--";
}

bool isbst(Node* root,long minval,long maxval){
    if(root==NULL){
        return true;
    }
    if(root->data>=minval && root->data<maxval && isbst(root->left,minval,root->data) && isbst(root->right,root->data,maxval)){
        return true;
    }
    return false;
}

Node* deletenode(Node* root,int val){
    if(root==NULL)return root;
    if(root->data < val){
        root->left=deletenode(root->left,val);
    }
    else if(root->data > val){
        root->right=deletenode(root->right,val);
    }
    else{
        Node* temp;
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
            return root;
        }
        else if(root->right==NULL){
            temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else if(root->left==NULL){
            temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else{
            temp->data=Getmin(temp);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
            return root;
        }
    }
}

int main() {
	// your code goes here
	root=insert(root,15);
	root=insert(root,20);
	root=insert(root,10);
	bool x=search(root,90);
	(x==true)?cout<<"found":cout<<"not found"<<endl;
	cout<<"Min element is:"<<Getmin(root)<<endl;
	cout<<"Max element is:"<<Getmax(root)<<endl;
	cout<<"height of tree:"<<getHeight(root)<<endl;
	bfs(root);
	cout<<endl;
	//preorder(root);
	//cout<<endl;
	inorder(root);cout<<endl;
	//postorder(root);cout<<endl;
	long z,y;
	z=y=1000000;
	isbst(root,z,y);
	//deletenode(root,10);
	//bfs(root);
	//cout<<endl;
	root1=insert(root1,30);
	root1=insert(root1,5);
	root1=insert(root1,35);
	inorder_special(root,root1);
	if(!q1.empty()){
	    cout<<q1.front();
	    q1.pop();
	}
	return 0;
}
