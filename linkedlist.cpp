#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(){
        this->next=NULL;
    }
    node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void printll(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;

}
int getlength(node*head){
    node*temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}
// pass by reference always
void insertathead(node*&head , node*&tail,int data){
    if(head==NULL){
        node*newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
    node*newnode=new node(data);
    newnode->next=head;
    head =newnode;
    }
}

void insertattail(node*&head , node*&tail,int data){
    if(head==NULL){
        node*newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node*newnode=new node(data);
        tail->next=newnode;
        tail=newnode;
    }

    
}


void createtail(node*head,node*&tail){
    node*temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    tail=temp;
}

void insertatposition(node*&head,node*&tail,int data, int position){
    // if(position <1){
    //     cout<<"cannot insert at this positon";
    //     return;
    // }
    int length=getlength(head);
    // if(position>length){
    //     cout<<"cannot insert";
    //     return;
    // }
    if(position<=1){
        insertathead(head,tail,data);
    }
    else if(position>length){
        insertattail(head,tail,data);
    }
    else{
        node*newnode=new node(data);
        node*prev=NULL;
        node*curr=head;
        while(position!=1){
            prev=curr;
            curr=curr->next;
            position--;
        }
        prev->next=newnode;
        newnode->next=curr;

    }
}

void deletenode(node*&head,node*&tail,int position){
    if(head==NULL){
        cout<<"cannot delete";
    }

    if(head==tail){
        node*temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return ;

    }
    int len =getlength(head);
    if(position==1){
        node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else if(position==len){
        node *prev=head;
        while(prev->next!=NULL){
          prev=  prev->next;
        }
        prev->next=NULL;
        delete tail;
        prev=tail;
    }
    else{
        node*prev=NULL;
        node*curr=head;
        while(position!=1){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }

}
int main(){
    node*head=NULL;
    node*tail=NULL;
    insertathead(head,tail,10);
    insertathead(head,tail,20);
    insertathead(head,tail,30);
    insertathead(head,tail,40);
    insertattail(head,tail,60);

    // //node a; //static
    // node* first=new node(10);
    // node* second=new node(20);
    // node* third=new node(30);
    // node* fourth=new node(40);
    // node* fifth=new node(50);

    // first->next=second;
    // second->next=third;
    // third->next=fourth;
    // fourth->next=fifth;

    // node *head=first;
    // node*tail=fifth;
    // insertattail(head,tail,60);
     printll(head);
    // //cout<<getlength(head);

}