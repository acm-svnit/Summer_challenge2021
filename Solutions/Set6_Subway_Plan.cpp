#include <iostream>
using namespace std;
//to learn doubly linked lists, use stl list for normal usage.
struct dll{
    int data;
    dll* prev;
    dll* next;
};

void insert(dll* node,int val){
    dll* temp = new dll();
    temp->prev = node;
    temp->next = node->next;
    temp->data = val;
    if(node->next)node->next->prev=temp;
    node->next = temp;
}

int main(){
    int n,q,t,a,b;
    dll* list = new dll();
    dll* temp = list;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>t;
        insert(temp,t);
        temp = temp->next;
    }
    temp = list->next;
    for(int i=0;i<q;i++){
        cin>>t;
        if(t==1){
            cin>>a;
            for(int j=0;j<a;j++)temp = temp->prev;
        }else if(t==2){
            cin>>a;
            for(int j=0;j<a;j++)temp = temp->next;
        }else{
            cin>>a>>b;
            insert(temp,a);
            temp->next->next->data=b;
        }
    }
    list = list->next;
    while(list){
        cout<<list->data<<" ";
        list = list->next;
    }
    cout<<"\n";
}