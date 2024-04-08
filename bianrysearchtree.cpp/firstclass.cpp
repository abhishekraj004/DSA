#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node*right;
    Node(int value){
        this->data=value;
        this->right=NULL;
        this->left=NULL;
    }
};

Node*insertintobst( Node*root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    // its not the first node 
    if(data>root->data){
       root->right= insertintobst(root->right,data);
    }
    else{
        root->left=insertintobst(root->left,data);
    }
    return root;
}

void createBST(Node*&root){
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    while(data!=-1){
        root= insertintobst(root,data);
        cin>>data;
    }

}
void levelorder(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

void preorder(Node*root){
    //nlr
    if(root==NULL){
        return ;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node*root){
    // lnr
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);

}

void postorder(Node*root){
    // lrn;
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    
    cout<<root->data;

}

Node* minvalue(Node*root){
    if(root==NULL){
        cout<<"no min value"<<endl;
        return NULL;
    }
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;

}

Node*maxvalue(Node*root){
    if(root==NULL){
        return NULL;
    }
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;

    }
    return temp;
}

bool searchinbst(Node*root,int target){
    // base case 
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    // than recursion 
    bool leftans=false;
    bool rightans=false;
    if(target>root->data){
        rightans=searchinbst(root->right,target);
    }
    else{
        leftans=searchinbst(root->left,target);
    }
    return leftans|| rightans;
}


// delete a node ,*** very important code

Node*deletefrombst(Node*root,int target){
    // first find the target than delete the target
    if(root==NULL){
        return NULL;
    }
    if(target==root->data){
        // than delete the node
        // 4 case are possible
        

        // 1 case leaf node delte
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 2 case left non null and right null
         else if(root->left!=NULL && right==NULL){
            Node*childsubtree=root->left;
            delete root;
            return childsubtree;
        }
        // 3 case left null and right not null 
       else if(root->left==NULL && right!=NULL){
            Node*childsubtree= root->right;
            delete root;
            return childsubtree;
        }
        // 4 case both left and right are not null 
        else{
            // left subtree ki max value lao
           Node*maxi= maxvalue(root->left);
           root->data=maxi->data;

           // delete actual maxi element
          root->left= deletefrombst(root->left,maxi->data);
          return root;
        }
    }
    else if(root->data>target){
        // left mein jao 
        root->left=  deletefrombst(root->left,target);
    }
    else{
       root->right=  deletefrombst(root->right,target);
    }
    return root;
}


Node *bstfrominorder(int inorder[],int s,int e){
    // base case
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    int element=inorder[mid];
    Node*root=new Node(element);
    root->left=bstfrominorder(inorder,s,mid-1);
    root->right=bstfrominorder(inorder,mid+1,e);
    return root; 

}

// convert bst into sorted doubly linked list
void convertbsttodll(Node*root,Node*head){
    if(root==NULL){
        return;
    }
    // rnl
    convertbsttodll(root->right,head);
    /* node part */
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    // left part
    convertbsttodll(root->left,head);
}

void printll(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
}



int main(){
    Node*root=NULL;
    createBST(root);
}