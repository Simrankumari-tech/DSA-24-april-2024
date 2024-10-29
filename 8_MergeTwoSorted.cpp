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
node*mergell(node*a  , node*b){
    // base case
    if(b == NULL ) return a;
    if(a == NULL) return b;


    // recursive case
    node*nH;
    if(a->data < b->data){
        nH = a;
        nH->next = mergell(a->next , b);
    }
    else{
        nH= b;
         nH->next = mergell(a, b->next);
    }
    return nH;
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
        node*head1= NULL , *tail1 = NULL;
    insertAtend(head , tail , 1);
    insertAtend(head , tail , 2);
    insertAtend(head , tail , 17);
    insertAtend(head1 , tail1 , 4);
    insertAtend(head1 , tail1, 15);
        insertAtend(head1 , tail1 , 18);
        head = mergell(head, head1);
    printLL(head);
    
    node*ans = mid(head);
    cout << "middle : " << ans->data << endl;

     return 0;


}