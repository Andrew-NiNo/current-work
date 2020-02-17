#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string.h>
#include <vector>


class Account {
private:
    std::string name;
    std::string bank_acc;
    float balance;

public:
    Account (const std::string &n_name, std::string n_bank_acc, float n_balance):
                name(n_name),bank_acc(n_bank_acc),balance(n_balance) {}

        void show()const;
        std::string get_name() const {return name;}
        std::string get_bank_acc() const{return bank_acc;}
        float get_balance() const{return balance;}
        void get_extremes_values(Account*);
        std::vector<Account*> search_acc(Account*,std::vector<Account*>);
        void change_balance(std::vector<Account*>,float);
        void replacement(float add_balance);
        std::vector<Account*> check(std::vector<Account*>);
    ~Account(){};
};

#endif // KEEPING_H
