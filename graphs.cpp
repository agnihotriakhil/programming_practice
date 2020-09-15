#include<stdio.h>
#include<iostream>
#include <bits/stdc++.h> 

using namespace std;
#define print(x) cout << x << " "
#define miv map<int,vector<int>>
#define mii  map<int,int>

void print1d(vector<int> &A) {for(auto a:A) print(a);cout<<endl;}

miv A;
mii visited;

void edge(int a, int b){ A[a].push_back(b);
    // A[b].push_back(a); 
}

int graph_1(){
    edge(1,0);edge(0,2);edge(2,1);edge(0,3);edge(3,4); return 5;}
int graph_2(){
    edge(0,1);edge(0,2);edge(1,3);edge(4,1);
    edge(6,4);edge(5,6);edge(5,2);edge(6,0); return 7;}
int graph_3(){
    edge(1,2);edge(2,3);edge(3,9);edge(3,4);edge(4,5);edge(5,6);
    edge(6,4);edge(7,6);edge(7,8);edge(8,7);edge(8,10); return 10;
}
int graph_4(){
    edge(0,1);edge(0,3);edge(1,2);edge(2,3);
    return 4;
}

int make_graph(int num){
    if(num==1) return graph_1();
    else if(num==2) return graph_2();
    else if(num==3) return graph_3();
    else if(num==4) return graph_4();
    return 0;
}
void print_graph(){
    for(auto it=A.begin();it!=A.end();it++){
    print(it->first);print(":");for(auto b:it->second) print(b);cout<<endl;}
}
miv reverse_graph(){

    miv B;
    for(auto it=A.begin();it!=A.end();it++){
        for(auto v:it->second) B[v].push_back(it->first);
    }
    return B;
}

map<pair<int,int>,int> Kruskal(map<pair<int,int>,int> edge){
    map<pair<int,int>,int> A;
    set<pair<int,int>> MST;
    map<int,vector<pair<int,int>>> s_edge;
    map<int,int> set_number;
    map<int,set<int>> sets;

    edge[{1,2}]=35;edge[{1,3}]=40;edge[{2,3}]=25;edge[{2,4}]=10;
    edge[{3,4}]=20;edge[{3,5}]=15;edge[{4,5}]=30;

    set<int> vertices = {1,2,3,4,5};

    for(auto i=edge.begin();i!=edge.end();i++){
        s_edge[i->second].push_back(i->first);
    }

    queue<pair<int,int>> q;

    for(auto i=s_edge.begin();i!=s_edge.end();i++){
        for(auto a:i->second) q.push(a);
    }
    
    set<set<int>> VS; int i=1;
    for(auto v:vertices) {VS.insert({v});sets[i]={v};set_number[v]=i++;}
    int u,v;
    set<int> s1,s2;

    while(VS.size()>1 and !q.empty()){
        u = q.front().first; v = q.front().second; q.pop();
        if(set_number[u]!=set_number[v]){
            s1 = sets[set_number[u]]; s2 = sets[set_number[v]];
            sets[set_number[u]].insert(s2.begin(),s2.end());
            sets.erase(set_number[v]);
            for(auto x:s2) set_number[x]=set_number[u];
            VS.erase(s1);VS.erase(s2);
            s1.insert(s2.begin(),s2.end());
            VS.insert(s1);
            MST.insert({u,v});
        }       
    }
    u=0;
    for(auto i=MST.begin();i!=MST.end();i++){
        A[{i->first,i->second}] = edge[{i->first,i->second}];
        u+=edge[{i->first,i->second}];
    }
    print(u);
    return A;
}

map<pair<int,int>,int> Prim(vector<int> vertices,map<pair<int,int>,int> edge){
    map<pair<int,int>,int> ans;
    // vector<int> vertices; map<pair<int,int>,int> edge;
    
    edge[{1,2}]=35;edge[{1,3}]=40;edge[{2,3}]=25;edge[{2,4}]=10;
    edge[{3,4}]=20;edge[{3,5}]=15;edge[{4,5}]=30;
    vertices = {1,2,3,4,5};

    map<int,vector<int>> m;
    map<pair<int,int>,int> included;
    for(auto it=edge.begin();it!=edge.end();it++){
        m[it->first.first].push_back(it->first.second);
        m[it->first.second].push_back(it->first.first);
    }

    set<int> s,s1; s.insert(vertices[0]);
    set<pair<int,int>> T;
    for(int i=1;i<vertices.size();i++) s1.insert(vertices[i]);
    int a,b,d,x;

    while(s.size()!=vertices.size()){
        d = 1e9;
        for(auto u:s){
            for(auto v:m[u]){
                x = max(edge[{v,u}],edge[{u,v}]);
                if(included[{u,v}]>0 || x==0) continue;
                if(x<d){ a=u;b=v;d=x; }
            }
        }
        print(a);print(b);cout<<endl;
        s.insert(b); s1.erase(b);
        T.insert({a,b});
        included[{a,b}]++; included[{b,a}]++;
    }


    for(auto a:T) ans[a]=edge[a];

    return ans;
}


int main(){

    A.clear();visited.clear();

    int vertices = make_graph(3);

        

    return 0;
}


