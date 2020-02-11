#include <iostream>
#include "account.h"
#include <cstring>



const int STAFF = 20;
#define MAX 1000000

Account New("Petya", "357869241", 554.21);              //��������� � ������������� ������ �������

void Account::show()const{                              //����� ������� �� ����� ���������� �� �������

    cout<<" Human name: "<< name <<" Account number: "
             << number<<"   Balance: "<< balance<<'\n';
};

void Account::get_balance(Account*s){                   //����� ������� ������� ��� ������� ��������

    string token;
    cout<<"\n   Find out higth value ~ press + "        //����� ���� + ��� - �������� �����
        <<"     Find out lower value ~ press - "<<'\n';
        cin>>token;

        if(token=="+"){
            float tmp=-MAX;
            for(int i=0; i<STAFF; i++){                    //� ����� ���� ������� � ��������� � ���������� tmp
                if(s->get_balance()>tmp)                   //����� ����� ������ �������� �����
                    tmp = s->get_balance();
                s++;
            }
        cout<<"\n   Higth value: "<<tmp<<'\n';              //������� �������� �� �����
        }
        else if(token=="-"){
            float tmp=MAX;                                  //� ����� ���� ������� � ��������� � ���������� tmp
            for(int i=0; i<STAFF; i++){
                if(s->get_balance()<tmp)
                    tmp = s->get_balance();
                s++;
            }
        cout<<"\n   Lower value: "<<tmp<<'\n';                 //������� �������� �� �����
        }

}

Account* Account::change (Account *s){                  //����� ���� ������ ������ � ������ ������
    string _input;
    cout<<"\n   Enter name or account : "<<'\n';
    cin>>_input;
    float add_balance;
    int flag = 0;

    for(int i=0; i<STAFF; i++){
         if (s->get_name()== _input||s->get_number()==_input){  //����� ���� �� ����� ��� ������ �����
                flag = 1;
         }
         else s++;
    };
    if(flag){                                           //���� ���� ����������
        s->show();
        cout<<"\n   Enter summ: \n";
        cin>>add_balance;
        s->change(add_balance);                         //����� ������������� ����� ������ �������� �������
        s->show();
    }
    else cout<<"\n  Data not found \n";                 //���� ��� ����������, �������� �� ����

return s;
};

void Account::change(float add_balance){                //������������� ����� ������ �������
    balance += add_balance;};

int main(){

    Account  roster [STAFF] = {                             //������ �����������

    Account ("Vasya_Petrov","123456789",221.10),
    Account ("Masha_Peshkova","987654321",151.20),
    Account ("Fedor_Emelyanov","159487263",751.30),
    Account ("Andrew_Big","123451579",225.10),
    Account ("Liza_Blohina","984354321",181.20),
    Account ("Ronaldo","196487263",118.30),
    Account ("Kabanova","1234143549",212.10),
    Account ("Masha_Perepelkina","914374321",661.20),
    Account ("Freddi_Kryger","158516873",171.30),
    Account ("Genry_Ford","123487315",297.10),
    Account ("Liza_Peskova","987678421",247.20),
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

     Account* p = & roster[0];                                  //����� ��������� �� �������������

     p->change(p);                                              //�������� ����� ������ ������� � ������ �������� �������
     p->get_balance(p);                                         //�������� ����� ����������� �������� max � min


     for(int i=0; i<STAFF; i++){                                //� ����� ������� ���������� �� ��������
            roster[i].show();
    };

return 0;
}
