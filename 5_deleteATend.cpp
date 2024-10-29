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
void deleteATend(node*&head , node*&tail){
    if(head == NULL) return;
    else if(head->next == NULL){
        delete head;
        head = tail =NULL;
    }
    else{
        node*temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
        delete tail;
       tail = temp;
       tail->next = NULL;
    }
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
     printLL(head);
    deleteATend(head, tail);
    printLL(head);

     return 0;


}