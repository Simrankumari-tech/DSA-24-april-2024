#include<bits/stdc++.h>
using namespace std;
class node{
    public :
int data ;
node *next;
node(int d){
    data = d;
    next = NULL;
}
};
void insertAtend(node*&head , node*&tail , int d){
    if(head == NULL){
        node* n= new node (d);
        head = tail = n;
    }
    else{
        node*n = new node(d);
        tail-> next = n;
        tail = n;

    }
}
node*mid(node*head){
    node*s = head;
    node*f = head->next;
    while(f!= NULL and f->next !=NULL){
        f= f->next ->next;
        s= s->next;
    }
    return s;
}

void printLL(node*head){
    while(head != NULL){
        cout << head->data << "--->" ;

        head = head->next;

    }
    cout << "null" << endl;
}
int main(){
    node*head= NULL , *tail = NULL;
    insertAtend(head , tail , 1);
    insertAtend(head , tail , 2);
    insertAtend(head , tail , 3);
    insertAtend(head , tail , 4);
    insertAtend(head , tail , 5);
        insertAtend(head , tail , 8);
    printLL(head);
    
    node*ans = mid(head);
    cout << "middle : " << ans->data << endl;

     return 0;


}