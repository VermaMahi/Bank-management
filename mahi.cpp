#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class temp{
    int account_no;
	char first_name[25];
	char father_name[25];
	char CNIC[25];
	char phone_number[10];
	char email[25];
	float amount;
	int new_amount;
    fstream file,file1;

    public:
	int search;

    void create_account(void);   // declaration of create account function
    void deposit_amount(void);   // declaration of deposit amount function
    void withdraw_amount(void);  // declaration of withdrawn amount function
    void check_info(void);       // declaration of check info function
};

int main(){

    temp obj;
    char choice;

    cout<<"\n\n\t\t......:::Mahi's Bank:::......";
	cout<<"\n\t\t:: Press 1 to Login  Account :: ";
	cout<<"\n\t\t:: Press 2 to Create Account ::";
	cout<<"\n\t\t:: Press 0 to Exit           ::";
	cout<<"\n\t\t:: ......................... ::\n\t\t\t";
	cin>>choice;
    
    switch(choice){
        case '1':
            cout<<"Enter your account no :: ";
	        cin>>obj.search;
        while(1){

            cout<<"\n\n\t\t.......:::Mahi's Bank:::.......";
            cout<<"\n\t\t:: Press 1 to Deposit  Amount  :: ";
            cout<<"\n\t\t:: Press 2 to Withdraw Amount  ::";
            cout<<"\n\t\t:: Press 3 to Check    Info    ::";
            cout<<"\n\t\t:: Press 0 to Exit     Menu    ::";
            cout<<"\n\t\t:: ........................... ::\n\t\t\t";
            cin>>choice;

            switch (choice)
            {
            case '1':
                obj.deposit_amount();
            break;
            case '2':
                obj.withdraw_amount();
            break;
            case '3':
                obj.check_info();
            break;
            case '0':
                return 0;
            break;
            default:
                cout<<"Invalid Choice!!!";
            break;
            }
            system("pause");
            system("cls");
        }
        break;
        case '2':
            obj.create_account();
        break;
        case '0':
            system("exit");
        break;
        default :
            cout<<"\n Invalid choice!!! ";
        break;
    }
    return 0;
}
// Declaration of create account function
void temp :: create_account(){

    srand(time(0));
	account_no=rand()*rand()+rand()*rand();
	
	cout<<"Enter Your first Name : ";
	cin>>first_name;
	
	cout<<"Enter Your Father first Name : ";
	cin>>father_name;

	cout<<"Enter Your CNIC : ";
	cin>>CNIC;
	
	cout<<"Enter Your Phone no. : ";
	cin>>phone_number;
	
	cout<<"Enter Your Email Id : ";
	cin>>email;
	
	cout<<"Enter Your Amount : ";
	cin>>amount;
	
	cout<<endl<<"This is your account number " << account_no<<"\n";
	cout<<"Please save it :) \n\n";
	
	file.open("doc.txt",ios::out|ios::app);
	file<<account_no<<"\t"<<first_name<<"\t"<<father_name<<"\t"<<CNIC<<"\t"<<phone_number<<"\t"<<email<<"\t"<<amount<<endl;
	file.close();
}
// Declaration of deposit amount function
void temp :: deposit_amount(){
   
	cout<<"Enter amount to deposit : ";
	cin>>new_amount;

	file.open("doc.txt",ios::in);
	file1.open("doc1.txt",ios::out|ios::app);
	file>>account_no>>first_name>>father_name>>CNIC>>phone_number>>email>>amount;
	
	while(!file.eof()) {
		if(account_no==search){
			cout<<"\nCurrent amount :: "<<amount;
			amount=amount + new_amount;
			cout<<"\nUpdated amount :: "<<amount<<endl;
			file1<<account_no<<"\t"<<first_name<<"\t"<<father_name<<"\t"<<CNIC<<"\t"<<phone_number<<"\t"<<email<<"\t"<<amount<<endl;
		}else{
			file1<<account_no<<"\t"<<first_name<<"\t"<<father_name<<"\t"<<CNIC<<"\t"<<phone_number<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>account_no>>first_name>>father_name>>CNIC>>phone_number>>email>>amount;
	}
	
	file.close();
	file1.close();
	remove("doc.txt");
	rename("doc1.txt","doc.txt");
}
// Declaration of withdrawn amount function
void temp :: withdraw_amount(){
    
	cout<<"Enter amount to withdraw :: ";
	cin>>new_amount;

	file.open("doc.txt",ios::in);
	file1.open("doc1.txt",ios::out|ios::app);
	file>>account_no>>first_name>>father_name>>CNIC>>phone_number>>email>>amount;
	
	while(!file.eof()) {
		if(account_no==search){
			cout<<"\nCurrent amount :: "<<amount;
			amount=amount - new_amount;
			cout<<"\nUpdated amount :: "<<amount<<endl;
			file1<<account_no<<"\t"<<first_name<<"\t"<<father_name<<"\t"<<CNIC<<"\t"<<phone_number<<"\t"<<email<<"\t"<<amount<<endl;
		}else{
			file1<<account_no<<"\t"<<first_name<<"\t"<<father_name<<"\t"<<CNIC<<"\t"<<phone_number<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>account_no>>first_name>>father_name>>CNIC>>phone_number>>email>>amount;
	}
	
	file.close();
	file1.close();
	remove("doc.txt");
	rename("doc1.txt","doc.txt");
}
// Declaration of check info function
void temp :: check_info(){
    
	
	fstream file;
	file.open("doc.txt",ios::in);
	if(!file){
		cout<<"File opening error!!!";
	}
	file>>account_no>>first_name>>father_name>>CNIC>>phone_number>>email>>amount;
	while(!file.eof()){
		if(account_no==search){
            cout<<"\n---------------------------\n";
            cout<<endl<<"\t::: Account Number ::: ";
            cout<<"\t   "<<account_no<<endl;
            cout<<"\t::: User first Name      ::: ";
            cout<<"\t   "<<first_name<<"\n";
            cout<<"\t::: Father first Name    ::: ";
            cout<<"\t   "<<father_name<<"\n";
            cout<<"\t::: CNIC number    ::: ";
            cout<<"\t   "<<CNIC<<"\n";
            cout<<"\t::: Phone Number   ::: ";
            cout<<"\t   "<<phone_number<<"\n";
            cout<<"\t::: Email Id          ::: ";
            cout<<"\t   "<<email<<"\n";
            cout<<"\t::: Current amount ::: ";
            cout<<"\t   "<<amount<<endl;
            cout<<"\n---------------------------\n\n";
		
	    }
		file>>account_no>>first_name>>father_name>>CNIC>>phone_number>>email>>amount;
	}
	
	file.close();
}

