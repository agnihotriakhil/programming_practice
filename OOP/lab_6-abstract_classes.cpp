#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

class Employee{
    string fname, lname, pan;
    public:
        Employee(string fname, string lname, string pan){
            this->fname = fname;
            this->lname = lname;
            this->pan = pan;
        }

        virtual void earnings() = 0;
};

class Salary : public Employee{
    double salary;
    public:
        Salary(string fname,string lname,string pan,double salary):Employee(fname,lname,pan){
            this->salary = salary;
        }

        void earnings(){ cout << "Salary: " << salary << endl; }
};

class Commision : public Employee{
    double salary;
    public:
        Commision(string fname,string lname,string pan,double salary,double comm):Employee(fname,lname,pan){
            this->salary = (1+comm/100)*salary; 
        }

        void earnings(){ cout << "Commision: " << salary << endl; }
};

int main(){
    Salary sal("A","A","xyz",100);
    Commision comm("B","B","mno",100,10);


    return 0;
}