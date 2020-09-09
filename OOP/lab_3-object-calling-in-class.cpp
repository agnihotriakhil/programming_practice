#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

class Account{
    public:
        double bal;
        int num;

        Account(){}   

        Account(double bal, int num){
            this->bal = bal;
            this->num = num;
        }

        void add(double sum){
            bal = bal + sum;
        }

        void print(){
            cout << "Account number " << num << " with balance " << bal << endl; 
        }

};

class Savings : public Account{
    public:
        int mul;

        Savings(){};
        Savings(double bal, int num, int mul):Account(bal,num){
            this->mul = mul;
        }

        void apply(){
            cout << "Applied multiply of value " << mul << endl;
            int a = bal*mul;
            cout << "Old value was " << bal << " and new value is " << a << endl;
        }
};

class Bank{
    public:
        Account B[2];

        Bank(Account x[]){
            for(int i =0;i<2;i++)
                B[i] = *(x+i);
        }

        void print(){
            for(auto x:B)
                cout << "Balance: " << x.bal << " and account num: " << x.num << endl;
        }
};



int main(){
    Account A(100,53);
    A.add(20);
    Savings B(500,21,2);
    Account arr[2] = {A,B};
    Bank bank(arr);
    bank.print();

    return 0;
}