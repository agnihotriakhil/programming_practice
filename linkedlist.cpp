#include <iostream>

using namespace std;

struct Node{

    int data;
    Node* link;
};

void insert(Node* head,Node* A, int pos){
    Node* prev = head;
    for(int i=0;i<pos-2;i++)
        prev = prev->link;
    A->link = prev->link;
    prev->link = A;    
}

void qwe(Node* current, Node* next, Node* prev){
    Node* n2next = next->link;
    if(n2next!=NULL){
        next->link = current;
        current->link = prev;
        prev = current;
        qwe(next,n2next,prev);
    }
    else{
        next->link = current;
        current->link = prev;
    }
}

void reverse(Node* current){
    Node* next = current->link;
    Node* prev;
    qwe(current,next,prev);
}

void great(Node* A, Node* X, Node* N){
    if(A->data >= X->data)
        N->data = A->data;
    else
        N->data = X->data;
    if(A->link!=NULL){
        Node* temp = new Node();
        N->link = temp;
        great(A->link,X->link,temp);
    }
    else{
        N->link = NULL;
        return;
    }
}

int main(){
    Node* A = new Node();
    Node* B = new Node();
    Node* C = new Node();
    Node* X = new Node();
    Node* Y = new Node();
    Node* Z = new Node();
    A->data = 2;
    B->data = 3;
    C->data = 4;
    insert(A,B,2);
    insert(A,C,3);
    X->data = 1;
    Y->data = 6;
    Z->data = 7;
    insert(X,Y,2);
    insert(X,Z,3);
    Node* N = new Node(); 
    great(A,X,N);
    cout << N->data << (N->link)->data << ((N->link)->link)->data;
    
    return 0;
}