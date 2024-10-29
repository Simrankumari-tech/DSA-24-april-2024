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

void deleteatfront(node*&head , node*& tail){
if(head == NULL) return;
else if(head->next == NULL){
    delete head;
    head = tail = NULL;
}
else{
    node*temp = head;
    head = head ->next ;
    delete temp;
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

int lengthll(node*head){
    int cnt = 0;
    while(head!= NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
void deleteATmid(node*&head , node*&tail , int pos){
    if(pos == 0){
        deleteatfront(head, tail);
    }
    else if(pos>=lengthll(head)){
        deleteATend(head , tail);

    }
   else{
    node*temp = head;
    for(int i = 0; i< pos -1 ; i++){
       temp = temp->next;
    
    temp = temp->next;
    }
    node*n = temp->next;
    temp ->next = n->next;
    delete n;
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

    deleteATmid(head , tail , 0);
    printLL(head);

     return 0;


}