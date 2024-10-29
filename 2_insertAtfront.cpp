#include<bits/stdc++.h>
using namespace std;
class node{
public :
int data;
node*next;
node(int d){
    data = d;
    next = NULL;
}
};
void insertatend(node*&head , node*&tail , int d){
    if(head == NULL){
        node*n = new node(d);
    head = tail = n;

    }
    else{
        node*n = new node(d);
        tail ->next = n;
        tail = n;
    }
}
void insertatfront(node*&head , node*&tail , int d){
    if(head == NULL ){
         node*n = new node(d);
    head = tail = n;
    }
    else{
         node*n = new node(d);
    n -> next = head;
    head = n;
    }
}
void printll(node*head){
    while(head != NULL){
    cout << head -> data << "--->";
    head = head->next ;
}
cout << "null" ;
}

int main(){
    node*head = NULL, *tail = NULL;
    insertatend(head , tail , 1);
    insertatend(head , tail ,2);
    insertatend(head , tail , 3);
    insertatend(head , tail , 4);
    insertatfront(head , tail , 5);
    printll(head);
    return 0;
}

