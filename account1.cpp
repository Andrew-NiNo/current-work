//
//      15.02.2020  Andrew M.
//      Task implementation: list of employees for the bank/
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "account1.h"
#include <iomanip>
#include <cstdlib>
#include <iterator>


#define MAX 1000000
#define PTR_OBJECT Account*
#define VECTOR std::vector<Account*>

const int STAFF = 20;
VECTOR search_res;

using namespace std;


Account New("Petya", "357869241", 554.21);              ///Declaring and initializing a new object

void Account::show()const{                              ///Member function displays object information

    cout<<" Human name: "<<setw(20)<<left<<name <<" Account number: "
             << bank_acc<<"   Balance: "<< balance<<'\n';
};

void Account::get_extremes_values(PTR_OBJECT s){           ///Member function returns extremes value

    if(!s){                                                 ///Check for correct pointer
    cerr<<"\n   You entered an invalid pointer...";
    exit (1);
    };

    float tmp_max=INT_MIN;
    float tmp_min=INT_MAX;
    PTR_OBJECT p_max=nullptr;
    PTR_OBJECT p_min=nullptr;

    for(int i=0; i<STAFF; i++,s++){                         ///In the loop we look for max/min and save in tmp
        if(s->get_balance()>tmp_max){
            tmp_max = s->get_balance();
            p_max=s;
        }
        if(s->get_balance()<tmp_min){
            tmp_min = s->get_balance();
            p_min=s;
        }
    };
    cout<<"\n   Extremes values:  \n"<<tmp_max<<'\n';
    p_max->show(); cout<<'\n'<<tmp_min<<'\n';
    p_min->show(); cout<<'\n';
}

VECTOR Account::search_acc(PTR_OBJECT s,VECTOR search_res){  ///Method searches for the desired object

    string input_data;
    cout<<"\n   Enter name or account : "<<'\n';
    cin>>input_data;

    for(int i=0; i<STAFF; i++,s++){
         if(s->get_name()== input_data||s->get_bank_acc()==input_data) {            ///Search through name or account number
              search_res.push_back(s);                                              ///Saves matches in vector
         }
    }
    if(0==search_res.size()){                                        ///If there are no matches, report it and exit the function
        cout<<"\n  The name is not correct.\n";
        exit(2);
    }

return search_res;
};

VECTOR Account::check(VECTOR search_res){          ///The method checks for matches and refines the selection

    if(search_res.size()>1){                                                   ///The method checks for matches...
            cout<<"\n  The data is not correct. Specify the necessary line ... \n";
        for(int i=0;i<search_res.size();i++){
            cout<<i+1<<" "; search_res[i]->show();
            };

        int correct=0;
        cin>>correct;
        if(correct<=search_res.size()){                                        ///...and refines the selection
            search_res[0]=search_res[correct-1];
        }
        else {
            cout<<"\n You entered an invalid line...   \n";             ///If the choice is not correct, we report this and exit
            exit(3);
        }
    }
    else return search_res;
return search_res;
};

void Account::change_balance(VECTOR search_res,float add_balance){     ///Method changes the balance of the desired account

        search_res = this->check(search_res);                                   ///Checks for matches and refines the selection

        if(!add_balance){                                                       ///Enter, if not, value
        cout<<"\n   Enter summ: \n";
        cin>>add_balance;
        };
        search_res[0]->replacement(add_balance);                                     ///Change value with check
        search_res[0]->show();

        search_res.clear();
        search_res.shrink_to_fit();                                                  ///Set the vector to zero
};

void Account::replacement(float add_balance){                                    ///Method changes value with check

   if((add_balance+balance)<0){
        cout<<"\n   Error! The value cannot be negative. \n"
            <<"   Enter summ: \n";
                                                                ///If the result is negative, please enter the value again
        add_balance=0;
        cin>>add_balance;
        replacement(add_balance);
   }
   else balance += add_balance;                                         ///If everything is ok, change the value
   };

int main(){


        Account roster[STAFF] = {                                     ///A list of employees

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

    PTR_OBJECT p = nullptr;
    p = &roster[0];

    search_res = p->search_acc(p,search_res);
    p->change_balance(search_res,0.0);
    p->get_extremes_values(p);

    for(int i=0; i<STAFF; i++){
        roster[i].show();
    };


return 0;
}
