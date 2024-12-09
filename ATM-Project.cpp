#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/*Mini Project-ATM
-> check balance
-> cash withdaw
-> user details
-> update Mobile No
*/
class atm{

    private:                                        //private member variables
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;
    public:                                        //public member functions
       
        //setData function is sitting the data into the private member variables
        void setData(long int account_No_a,string name_a,int PIN_a,double balance_a,string mobile_No_a)
        {
            account_No=account_No_a;                //  assigning the formal to the private member variable
            name=name_a;
            PIN=PIN_a;
            balance=balance_a;
            mobile_No=mobile_No_a;
        }
        //getaccountNO function is returning the user's account no
         long int getaccountNo(){
          return account_No;
}
        //getName function is returning the user's Name
        string getname(){
            return name;
        }
        //getPIN function is returning the user's PIN
        int getPIN(){
            return PIN;
        }
            
            //getbalance function is returning the user's balance
            double getbalance(){
                return balance ;
            }
            //getmobileNO function is returning the user's mobile no
            string getmobileNo(){
                return mobile_No ;
            }
        //setmobile function is updating the user mobile no
        void setmobile(string mob_prev,string mob_new){
            if(mob_prev==mobile_No){                          //it will check old mobile no 
                mobile_No=mob_new;
                                           
                cout<<endl<<"successfully updated mobile_No";
                _getch();
                                            //getch is hold the screen (until user press any key)
            }
            else{
                cout<<endl<<"Incorrect !!!! Old Mobile No";
                _getch();                 //getch is to hold the screen(until user press any key)
            }
            
        }
        //cashwithdraw function is used to withdraw money from ATM
        void cashwithdraw(int amount_a){
            if (amount_a>0 && amount_a<balance){                                 //check entered amount validity
        
                balance-=amount_a;                                               //balance=balance-amount_a     
                cout<<endl<<"Please Collect Your Cash ";
                cout<<endl<<"Available balance" <<balance;
                getch();                                //getch is to hold the screen(until user press any key)
            }
            else{
                cout<< endl <<"Invalid Input or Insufficint Balance";
                getch();                                   //getch is to hod the scren (untill user press any key)
                

            }
        }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int choice=0,enterPIN;                                               //enterPIN and enterAccountNO.----->user authentication
    long int enteraccountNo;

    system("cls");

    //created User (object)
    atm user1;
    //Set User Details (int object)                        (setting Default Data)
    user1.setData(123456789, "Himanshu rai",1111,45000.90, "9772422464");


    do{
        system("cls");
        cout<< endl <<"<< Welcome to ATM >>"<<endl;
        cout<< endl <<"Enter Your account_No :";               //Asking user to enter account no
        cin>>enteraccountNo;

        cout<< endl <<"Enter PIN:";                           //Asking user to enter PIN
        cin>>enterPIN;


        //check whether enter values matches with user details
        if((enteraccountNo==user1.getaccountNo())&&(enterPIN==user1.getPIN()))
        {
            do{
                int amount=0;
                string oldmobileNo,newmobileNo;

                system("cls");
                //user interface
                cout<< endl <<"<< Welcome to ATM >>"<<endl;
                cout<< endl <<"Select Options";
                cout<< endl <<"1.Check Balance";
                cout<< endl <<"2.Cash withdrawl";
                cout<< endl <<"3.Show User Details";
                cout<< endl <<"4.Upadate Mobile no";
                cout<< endl <<"5.Exit"<<endl;
                cin>>choice;                                 //taking user choice

                switch(choice)                                         //switch condition
                {
                    case1:                                                    //if user presses 1
                    cout<< endl <<"Your Bank balance is :"<<user1.getbalance();
                                                //getBalance is printed to the users bank balance
                 _getch();
                 break;


                 case 2:                                                 //if user presses 2
                 cout<< endl <<"Enter the amount:";
                 cin>>amount;
                 user1.cashwithdraw(amount);                  //calling cashwithdraw function
                                                              //passing the withdeaw amount
                 break;


                case 3:
                cout<< endl << ">> User Details are >>";
                cout<< endl <<"-> Account_no:"<<user1.getaccountNo();
                cout<< endl <<"-> Name:"<<user1.getname();
                cout<< endl <<"-> Balance:"<<user1.getbalance();
                cout<< endl <<"-> Mobile No: "<<user1.getmobileNo();
                                                             //getting and printing user details
                _getch();
                break;


                case 4:

                cout<< endl <<"Enter old mobile No";                   //take old mobile no
                cin>>oldmobileNo;

                cout<< endl <<"Enter new mobile No";
                cin>>newmobileNo;                                      //take new mobile no

                user1.setmobile(oldmobileNo,newmobileNo);            //now set new mobile no
                break;


                case 5:
                    exit(0);                                      //exit application

                    default:                                    //handle invalid user inputs
                    cout<< endl <<"Enter valid data !!!!";
                }

            } while(1);                                   //Menu   //condition will always true and loop is capable of running infinite times
            

        }
        else{
            cout<< endl <<"user details are invalid !!!!";
            _getch();
        }
    } while(1);
    return 0;            //login //condition will always true and loop is capable of running inginite times
}





