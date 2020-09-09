#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

class Dog{
    protected: string name; int weight;
    public:
        Dog(string name){
            this->name = name;
        }

        Dog(string name, int weight){
            this->name = name;
            this->weight = weight;
        }
        string get_name(){ return this->name; }
        void speak(){ cout << "Woof"; }
        int get_weight(){ return this->weight; }
        int get_weight(Dog d){ return d.get_weight(); }
};

class Lab : public Dog{
    string colour;
    public:
        Lab(string name, string colour, int weight):Dog(name,weight){
            this->colour = colour;
        }
        void speak(){ cout << "WOOF"; }
};

class York : public Dog{
    public:
        York(string name, int weight):Dog(name,weight){
            Dog::name = name;
        }
        void speak(){ cout << "woof"; }
};

class Player{
    string name;
    int id;
    public:
        Player(string name, int id){
            this->name = name;
            this->id = id;
        }

        static void is_same(Player p1, Player p2){
            if(p1.name == p2.name and p1.id == p2.id) { cout << "Same"; }
            else { cout << "Not Same"; }
            
        }
};

int main(){
    Dog dog("Dog");
    Lab lab("Taffy","brown",35);
    York york("Juju",45);
    lab.speak();

    // string n1,n2;
    // int i1,i2;
    // cout << "Player 1 Name and integer ID" << endl;
    // cin >> n1 >> i1;
    // cout << "Player 2 Name and integer ID" << endl;
    // cin >> n2 >> i2;
    // Player p1(n1,i1);
    // Player p2(n2,i2);
    // Player::is_same(p1,p2);

    return 0;
}