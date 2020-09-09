#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include <bits/stdc++.h> 

using namespace std;
#define print(x) cout << x << " "


struct Node{
    int val;
    int h;
    struct Node* l;
    struct Node* r;
};

int height(Node* A){
    if(!A) return 0;
    int l=-1,r=-1;
    if(A->l) l=height(A->l);
    if(A->r) r=height(A->r);
    return max(l,r)+1;
}

int balance(Node* A){
    return height(A->l) - height(A->r);
}

Node* Rrot(Node* A){
    Node* t = A->l;
    A->l = t->r;
    t->r = A;
    A->h = 1 + max(height(A->l),height(A->r));
    t->h = 1 + max(height(t->l),height(t->r));
    return t;
}

Node* Lrot(Node* A){
    Node* t = A->r;
    A->r = t->l;
    t->l = A;
    A->h = 1 + max(height(A->l),height(A->r));
    t->h = 1 + max(height(t->l),height(t->r));
    return t;
}

Node* add(Node* &A, int x){
    if(A==NULL) { Node* t = new Node(); t->val=x; t->l=NULL; t->r=NULL; return t;}
    else if(x < A->val) A->l = add(A->l,x);
    else if(x > A->val) A->r = add(A->r,x);

    A->h = max(height(A->l),height(A->r)) + 1;
    int b = balance(A);

    if(b>1){
        if(x < A->l->val) A=Rrot(A);
        else { A->l=Lrot(A->l); A=Rrot(A); } 
    }
    else if(b<-1){
        if(x > A->r->val) A=Lrot(A);
        else { A->r=Rrot(A->l); A=Lrot(A); } 
    }

    return A;
}


Node* del(Node* A, int x){
    if(x>A->val) A->r = del(A->r,x);
    else if(x<A->val) A->l = del(A->l,x);
    else{
        Node* t = new Node();
        if(A->l==NULL) { t=A->r; free(A); return t; }
        else if(A->r==NULL) { t=A->l; free(A); return t; }
        else{
            t = A->r;
            while(t->l) t=t->l;
            A->val = t->val;
            A->r = del(A->r,t->val);
        }
    }
    return A;

}

struct Trie{
    unordered_map<char,struct Trie*> m;
    bool end;
};


void add_word(Trie* t, string s){
    if(s.size()==0) { t->end=1; return; }
    if(t->m.find(s[0])==t->m.end()){
        Trie* n = new Trie(); 
        t->m[s[0]] = n;
        n->end = 0;
    }
    add_word(t->m[s[0]],s.substr(1));
    
}



int main(){
    string D[3] = {"A","B","C"};
    // for(auto it=m.begin();it!=m.end();it++)
    //   { if(it->second <= threshold) m.erase(it); }

    Node* A = new Node(); A->val=50; A->l=NULL; A->r=NULL;A->h=0;
    add(A,30);add(A,20);add(A,10);add(A,15);add(A,40);add(A,60);add(A,55);add(A,80);
    
    Trie* t = new Trie;

    return 0;
}