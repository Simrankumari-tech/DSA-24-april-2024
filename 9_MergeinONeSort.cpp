
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
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
node* mid(node* head){
    node*s = head;
    node*f = head->next;
    while(f!=NULL and f->next !=NULL){
        f = f->next->next;
        s = s->next;
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
node* merge(node*head){
    // base case
    if(head == NULL or head->next == NULL) return head;

    // recursive case
    //1. divide
    node*a = head;
    node*m = mid(head);
    node*b = m->next;
    m->next = NULL;
    //2. sort divided linked list
    a = merge(a);
    b= merge(b);
    //3.merge two list
    node*nH = mergell(a,b);
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
        
    insertAtend(head , tail , 1);
    insertAtend(head , tail , 2);
    insertAtend(head , tail , 17);
    insertAtend(head , tail , 4);
    insertAtend(head , tail, 15);
        insertAtend(head , tail , 18);
        
    printLL(head);
    
    head = merge(head);
        printLL(head);

     return 0;


}