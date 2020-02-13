#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string.h>
#include <vector>


using namespace std;

class Account {
private:
    string name;
    string number;
    float balance;
    vector <Account*> arr;

public:
    Account (const string &_name, string _number, float _balance):
                name(_name),number(_number),balance(_balance) {}

        void show()const;
        string get_name() const {return name;}
        string get_number() const{return number;}
        float get_balance() const{return balance;}
        void get_max_values(Account*);
        void get_min_values(Account*);
        void get_extremes_values(Account*);
        vector<Account*> search_account(Account*,vector<Account*>);
        void change(float add_balance);
        void change_balance(vector<Account*>,float);
        vector<Account*> check(vector<Account*>);
    ~Account(){};
};

#endif // KEEPING_H
