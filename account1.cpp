#include <iostream>
#include "account.h"
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <iterator>

using namespace std;

const int STAFF = 20;
#define MAX 1000000
vector <Account*> arr;

Account New("Petya", "357869241", 554.21);              ///Declaring and initializing a new object

void Account::show()const{                              ///Member function displays object information

    cout<<" Human name: "<<setw(20)<<left<<name <<" Account number: "
             << number<<"   Balance: "<< balance<<'\n';
};

void Account::get_max_values(Account*s){                ///Member function returns maximum value

    if(!s){                                             ///Check for correct pointer
    cerr<<"\n   You entered an invalid pointer...";
    exit (1);
    };
    float tmp_max=INT_MIN;
    Account* p=nullptr;
    for(int i=0; i<STAFF; i++,s++){                    ///In the loop we look for max and save in tmp
        if(s->get_balance()>tmp_max){
            tmp_max = s->get_balance();
            p =s;
        };
    };
    cout<<"\n   Maximum values:  "<<tmp_max<<'\n';      ///Display the value on the screen
    p->show(); cout<<'\n';
}

void Account::get_min_values(Account*s){                   ///Member function returns minimum value

    if(!s){                                                ///Check for correct pointer
    cerr<<"\n   You entered an invalid pointer...";
    exit (2);
    };
    float tmp_min=INT_MAX;
    Account* p=nullptr;
    for(int i=0; i<STAFF; i++,s++){                        ///In the loop we look for max and save in tmp
        if(s->get_balance()<tmp_min){
            tmp_min = s->get_balance();
            p =s;
        };
    };
    cout<<"\n   Minimum values:  "<<tmp_min<<'\n';             ///Display the value on the screen
    p->show(); cout<<'\n';
}

void Account::get_extremes_values(Account*s){                      ///Member function returns extremes values

    if(!s){
    cerr<<"\n   You entered an invalid pointer...";
    exit (3);
    };
    s->get_min_values(s);                                       ///print min value
    s->get_max_values(s);                                       ///Print max value
}

vector<Account*> Account::search_account(Account *s,vector<Account*> arr){  ///Method searches for the desired object

    string input_data;
    cout<<"\n   Enter name or account : "<<'\n';
    cin>>input_data;

    for(int i=0; i<STAFF; i++,s++){
         if(s->get_name()== input_data||s->get_number()==input_data) { ///Search through name or account number
              arr.push_back(s);                                        ///Keep matches in vector
         }
    }
    if(0==arr.size()){                                                 ///If there are no matches, report it and exit the function
        cout<<"\n  The data is not correct.\n";
        exit(4);
    }

return arr;                                                             ///Return vector
};

vector<Account*>  Account::check(vector<Account*> arr){                 ///The method checks for matches and refines the selection

    if(arr.size()>1){                                                   ///The method checks for matches...
            cout<<"\n  The data is not correct. Specify the necessary line ... \n";
        for(int i=0;i<arr.size();i++){
            cout<< i+1<<" "; arr[i]->show();
            };
        int correct=0;
        cin>>correct;
        if(correct<=arr.size()){                                        ///...and refines the selection
            arr[0]=arr[correct-1];
        }
        else {
            cout<<"\n You entered an invalid line...   \n"; exit(5);    ///If the choice is not correct, we report this and exit
        }
    }
    else return arr;
return arr;                                                             ///Return the refined vector
};

void Account::change_balance(vector<Account*>arr,float add_balance){   ///Method changes the balance of the desired account

        arr = this->check(arr);                                        ///Checks for matches and refines the selection

        if(!add_balance){                                              ///Enter, if not, value
        cout<<"\n   Enter summ: \n";
        cin>>add_balance;
        };
        arr[0]->change(add_balance);                                   ///Change value with check
        arr[0]->show();

        arr.resize(0);                                                 ///Set the vector to zero
};

void Account::change(float add_balance){                               ///Method changes value with check

   if((add_balance+balance)<0){
        cout<<"\n   Error! The value cannot be negative. \n"
            <<"   Enter summ: \n";                                     ///If the result is negative, please enter the value again
       add_balance=0;
        cin>>add_balance;
        change(add_balance);
   }
   else balance += add_balance;                                         ///If everything is ok, change the value
   };

int main(){

        Account  roster [STAFF] = {                                     ///A list of employees

    Account ("Vasya_Petrov","123456789",221.10),
    Account ("Masha_Peshkova","987654321",151.20),
    Account ("Fedor_Emelyanov","159487263",751.30),
    Account ("Andrew_Big","123451579",225.10),
    Account ("Vasya_Petrov","984354321",181.20),
    Account ("Ronaldo","196487263",118.30),
    Account ("Kabanova","123414354",212.10),
    Account ("Masha_Perepelkina","914374321",661.20),
    Account ("Freddi_Kryger","158516873",171.30),
    Account ("Genry_Ford","123487315",297.10),
    Account ("Vasya_Petrov","987678421",247.20),
    Account ("Madonna","159761263",147.30),
    Account ("Mickey_Mouse","135746889",322.10),
    Account ("Minnie_Mouse","914632921",511.20),
    Account ("Fedor_Bondarchyk","153586263",171.30),
    Account ("Vasya_Pupkin","123952429",282.10),
    Account ("Baba_Yaga","987674809",661.20),
    Account ("Ivan_Carevich","136820263",854.30),
    Account ("Vasilisa_Prekrasnaya","126184509",327.10),
    Account ("Masha_&_Medved","987219421",178.20),
    };

    Account* p = nullptr;
    p = &roster[0];

    p->get_max_values(p);

    arr = p->search_account(p,arr);
    p->change_balance(arr,0.0);

    p->get_extremes(p);


    for(int i=0; i<STAFF; i++){
        roster[i].show();
    };
     p->get_max_values(p);
     p = nullptr;
     p->get_min_values(p);


return 0;
}
