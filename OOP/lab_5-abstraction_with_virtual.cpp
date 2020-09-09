#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

class Person{
    public:
        string name, gender;
            Person(string name, string gender){
                this->name = name;
                this->gender = gender;
            }
            virtual void work() = 0;
};

class Student : public Person{
    string sid;
    public:
        Student(string name, string gender, string sid):Person(name,gender){
            this->name = name;
            this->sid = sid;
        }
        void work(){ cout << "Studies" << endl; }
};


class Marks{
    virtual void percent() = 0;
};

class A : public Marks{
    double marks[3];
    public:
        A(double marks[]):Marks(){
            for(int i=0;i<3;i++)
                this->marks[i] = marks[i];
        }

        void percent(){
            double sum = 0;
            for(int i=0;i<3;i++)
                sum = sum + marks[i];
            cout << "Percentage: " << sum/3;
        }
};

class Shape{
    virtual void rect_area(double l,double w) = 0;
    virtual void circle_area(double r) = 0;
};

class Area : public Shape{
    public:
        void rect_area(double l, double w){
            cout << "Area rectangle is " << l*w << endl;
        }
        void circle_area(double r){
            cout << "Area circle is " << 3.14*r*r << endl;
        }
};

class Book{
    public:
        string name;
        Book(string name){
            this->name = name;
        }
        virtual void display() = 0;
};

class MyBook : public Book{
    string name;
    double price;
    public:
        MyBook(string name, double price):Book(name){
            this->name = name;
            this->price = price;
        }

        void display(){
            cout << "Book " << name << " and price " << price << endl;
        }
};


int main(){
    MyBook A("A",130);
    A.display();


    return 0;
}