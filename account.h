#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string.h>


using namespace std;

class Account {
private:
    string name;
    string number;
    float balance;

public:
    Account (const string &_name, string _number, float _balance):
                name(_name),number(_number),balance(_balance) {}

        void show()const;
        string get_name() const {return name;}
        string get_number() const{return number;}
        float get_balance() const{return balance;}
        void get_balance(Account*);
        void change(float add_balance);
        Account* change(Account *s);




};



#endif // KEEPING_H
