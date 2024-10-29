#include<iostream>
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
int lengthll(node* head){
      int cnt = 0;
    while(head != NULL){
      cnt++ ;
    
    head = head ->next;
    }
    return cnt ;

}
void insertATend(node*&head , node*&tail , int d){
    if(head == NULL){
        node*n = new node(d);
        head = tail = n;

    }
    else{
        node*n = new node(d);
        tail->next = n;
        tail = n;
    }
}



void bubblesort(node*&head){
int len = lengthll(head);
for(int i =0 ; i<=len-1 ; i++){
node*c =head ,*p= NULL,*n;
while(c!=NULL and c->next!=NULL){
    n=c->next;
    if(c->data > n->data){  // // swapping hogi
     // head chnge hoga
     if(p == NULL){
        c->next = n->next;
        n->next= c;
        head = p= n;
    }
    
    //haed chynge mhi hoga
   else{

   c->next = n->next;
        n->next= c;
        p->next = n;
        p= n;
    }
    }
    // swappinh nhi hogi
    else{
        p= c;
         c= n;
    }
}
}
}
void printll(node*head ){
    while(head!= NULL){
        cout << head->data << "->" ;
        head = head->next;
    }
    cout << "NULL" ;
}
int main(){
    node*head = NULL ,*tail = NULL;
    insertATend(head , tail , 10);
    insertATend(head , tail , 8);
    insertATend(head , tail , 11);
    insertATend(head , tail , 5);
    
    printll(head);
    bubblesort(head);
    cout << endl;
    printll(head);
    return 0;

    
    
    
    

    
    

}
