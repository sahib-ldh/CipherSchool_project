#include<iostream>  
#include<string>  
#include<fstream>
using namespace std;  
string number ; 
class account  
{  
public :  
    string num ;    
    string name; 
    string key; 
    string ID;    
    string tel;    
    double money;  
    account *next; 
    
    void show_account(account*p)
	{  
 		cout<<"account number:"<<p->num<<endl;  
 		cout<<"username:"<<p->name<<endl;  
 		cout<<"password:"<<p->key<<endl;  
 		cout<<"ID number:"<<p->ID<<endl;  
 		cout<<"phone:"<<p->tel<<endl;  
 		cout<<"Amount:"<<p->money<<endl;  
	}  
	void output_account (account *head)
	{    
		if(head==NULL){  
    		cout<<"No Registration account";  
    		return ;   
		}   
		int i=1;  
 		account *s;  
 		s=head;  
 		while(s->next!=NULL)  
 		{  
  			cout<<"User registration code:"<<i<<endl;   
  			cout<<"account number:"<<s->num<<endl;  
  			cout<<"username: "<<s->name<<endl;  
  			cout<<"password:"<<s->key<<endl;  
  			cout<<"ID number:"<<s->ID<<endl;  
 		    cout<<"phone:"<<s->tel<<endl;  
  			cout<<"Amount:"<<s->money<<endl<<endl;  
  			s=s->next;  
  			i++;  
 		}  
 	cout<<"User registration code:"<<i<<endl;   
 	cout<<"account number:"<<s->num<<endl;  
 	cout<<"username: "<<s->name<<endl;  
 	cout<<"password:"<<s->key<<endl;  
 	cout<<"ID number:"<<s->ID<<endl;  
 	cout<<"phone:"<<s->tel<<endl;  
 	cout<<"Amount:"<<s->money<<endl;  
	}  
};  
int cheak_num(string str,account *head) 
{  
 int t=0;
 account * p=head;  
 if(head==NULL)  
  t=0;  
 else  
 {  
  while(p->next!=NULL)  
  {  
   if(p->num!=str)  
    p=p->next;  
   else  
   {t=1;  
   break;  
   }  
  }  
  if(t==0)  
   if(p->num==str)  
    t=1;  
 }  
 return t;
}  
account * get_account (account *head) 
{  
 account *s,*p;  
 s=new account;  
 cout<<"Please enter account:"<<endl;  
 cout<<"account number:";  
 cin>>s->num;  
 cout<<"username:";  
 cin>>s->name;  
 cout<<"password:";  
 cin>>s->key;  
 cout<<"ID number:";  
 cin>>s->ID;  
 cout<<"telephone number:";  
 cin>>s->tel;  
 cout<<"Balance:";  
 cin>>s->money;  
 cout<<endl<<"====================================account entered successfully========== ====================="<<endl;  
 while ( 1 )                                           
 {  
  char ch;  
  if( head==NULL )  
  {  
   head = s ;  
  }  
  else  
   p->next = s ;                                            
  cout<<"Whether to continue to enter account? Yes (1), (2) No"<<endl;  
  cin>>ch;  
  while(ch!='1' && ch!='2'){  
   cout<<"Please re-enter whether to continue to enter Yes (1) No (2)";  
   cin>>ch;  
  }  
  if(ch=='1'){  
   p = s ;
   p->next=NULL;  
   s=new account;  
   s->next=NULL;  
   cout<<"Please enter the registration account:"<<endl;  
   cout<<"account number:";  
   string str111;  
   cin>>str111;  
   int t;  
   t=cheak_num(str111,head);  
   while(t==1)            
   {  
    cout<<"The account already exists, please re-register:";  
    cin>>str111;  
    t=cheak_num(str111,head);  
   }  
   s->num=str111;  
   cout<<"username:";  
   cin>>s->name;  
   cout<<"password:";  
   cin>>s->key;  
   cout<<"ID number:";  
   cin>>s->ID;  
   cout<<"telephone number:";  
   cin>>s->tel;  
   cout<<"Balance:";  
   cin>>s->money;  
   cout<<endl;  
  }  
  else 
  {  
   s->next=NULL;  
   break;  
  }  
  cout<<endl<<"====================================account entered successfully========== ====================="<<endl;  
 }  
 return head;  
}  

int check_keys(string number,string keys,account *head) 
{  
 int t=0;  
 account *p=head;  
 while(p->next!=NULL)  
 {  
  if(p->num!=number)  
   p=p->next;  
  else  
  {  
   if(p->key==keys)  
   {t=3;
   break;  
   }  
   else  
   {t=2;
   break;  
   }  
  }  
 }  
 if(t==0)  
  if(p->num==number)  
   if(p->key==keys)  
    t=3; 
   else  
    t=2;
   return t;  
}  
void saveoutput_account(account *p)
{
	account acc;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	acc.output_account(p);
	outFile.write(reinterpret_cast<char *> (&acc), sizeof(account));
	outFile.close();
}
void take_money(account * p) 
{  
 double m;  
 cout<<"Please enter the withdrawal amount:";  
 cin>>m;  
 if(m<=p->money)  
 {   p->money=p->money-m;  
 cout<<"Withdrawal successful"<<endl;  
 }  
 else  
 {  
  while(m>p->money)
  {cout<<"Insufficient balance, please try again"<<endl;  
  cout<<"Please enter the withdrawal amount:";  
  cin>>m;  
  }  
  p->money=p->money-m;
  cout<<endl<<"===================================== Successful withdrawal========= ========================="<<endl;  
 }  
}  
void save_money(account *p)
{  
 double m;  
 cout<<"Please enter the deposit amount:";  
 cin>>m;  
 p->money=p->money+m;
 cout<<endl<<"===================================== Deposit successful========= ========================="<<endl;  
}  
account*cheak_number(string number,account *head)
{  
 int a=0 ;
 account *p=head;  
 while(p->next!=NULL)  
 {  
  if(p->num==number)  
  { a=1;  
  break;  
  }  
  else  
   p=p->next;  
 }  
 if(p->num==number)  
  a=1;  
 if(a==0)  
  p=NULL;  
 return p; 
}  
void move_money(account *p,account *head)
{  
 account *x;
 x=NULL ;  
 double m; 
 string str;
 char ch ;
 cout<<"Please enter the account number to be transferred:";  
 cin>>str;  
 x=cheak_number(str,head); 
 while(x==NULL) 
 {  
  x=cheak_number(str,head);  
  cout<<"The account does not exist, do you want to re-operate: (1) Yes (2) No"<<endl;  
  cin>>ch;  
        if(ch=='1')  
  {  
   cout<<"Please re-enter the account you want to transfer:";  
   cin>>str;  
   x=cheak_number(str,head);  
  }  
  else  
   break;  
 }  
 if(x!=NULL)
 {  
  cout<<"Please enter the transfer amount:";  
        cin>>m;  
  while(p->money<m)  
  {cout<<"The balance is insufficient, please re-enter the transfer amount:"<<endl;  
  cin>>m;  
  }  
  x->money=x->money+m ;  
  p->money=p->money-m;  
  cout<<endl<<"===================================== successful transfer========== ======================"<<endl;  
 }  
}  
void change_pswd(account *p)
{
	string str,str1;
	cout<<"Please enter the original password:";  
     cin>>str;  
     while(p->key!=str)  
     {  
      cout<<"Inconsistent with the original password, please re-enter the original password:";  
      cin>>str;  
     }  
     cout<<"Please enter a new password:";  
     cin>>str;  
     cout<<"Please confirm your password:";  
     cin>>str1;  
     while(str!=str1)  
     {  
      cout<<"Different from the first input, please reset:";  
      cout<<"Please enter a new password:";  
      cin>>str;  
      cout<<"Please confirm your password:";  
      cin>>str1;  
     }  
     cout<<endl<<"===============================The setting is successful, please remember the new password ========= ================="<<endl; 
}
void revise_account(account *p)   
{  
 string str,str1;
 char ch; 
 while(1)  
 {  
  cout<<"Please select the account to be modified (1) account number (2) user name (3) password (4) ID number (5) telephone (6) exit to modify current account account";  
  cin>>ch;  
  while(ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5')  
  {  
   cout<<"Please re-enter a valid business:";  
   cin>>ch;  
  }  
  if( ch=='1')
  {  
   cout<<"Please enter a new account number:";  
   cin>>str;  
   p->num=str;  
   cout<<endl<<"====================================Modified account success========== ======================"<<endl;  
  }  
  else  
   if( ch=='2') 
   {  
    cout<<"Please enter a new username:";  
    cin>>str;  
    p->name=str;  
    cout<<endl<<"=================================== Successfully modified username========== ===================="<<endl;  
   }  
   
    else  
     if( ch=='3')
     {  
      cout<<"Please enter a new ID number:";  
      cin>>str;  
      p->ID=str;  
      cout<<endl<<"================================== Successfully modified ID card=========== ===================="<<endl;  
     }  
     else  
      if( ch=='4')
      {  
       cout<<"Please enter a new phone number:";  
       cin>>str;  
       p->tel=str;  
       cout<<endl<<"================================== Phone number modified successfully =========== =================="<<endl;  
      }  
      else  
       break;
 }  
}  

void save_account(account*p)
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
	ac.show_account(p);
}


void query_money(account *p)
{  
 cout<<"Your balance is:";  
 cout<<p->money<<endl;  
}  
account* logon(account *head)
{  
 account *s;  
 string str;
 cout<<"Please enter the registered account number:";  
 cin>>str;  
 int t;  
 if(head==NULL)
 	t=0; 
 else  
  t=cheak_num(str,head);
 while(t==1)
 {  
  cout<<"The account already exists, please re-register:";  
  cin>>str;  
  t=cheak_num(str,head);  
 }  
 s=new account ;
 s->num=str;  
 if(head==NULL)  
   number=str;  
 cout<<"username:";  
 cin>>s->name;  
 cout<<"password:";  
 cin>>s->key;  
 cout<<"ID number:";  
 cin>>s->ID;  
 cout<<"telephone number:";  
 cin>>s->tel;  
 cout<<"Balance:";  
 cin>>s->money;  
 if(head==NULL) 
 {  
  head=s;  
  head->next=NULL;  
 }  
 else
 {  
  s->next=head->next;  
  head->next=s;  
 }  
 cout<<endl<<"==================================== Registration successful========== ========================="<<endl;  
 return head;  
}  


account * choose(account *head) 
{  
 int t,loginmark=0;  
 if(head==NULL){     
    cout<<endl<<"The login function cannot be completed without account registration, please register account account first"<<endl<<"Do you register now: (1) Yes, (2) Register later"<<endl;  
    int x;  
    cin>>x;  
    while(x!=1&&x!=2){  
        cout<<"Please select again:";  
         cin>>x;   
    }  
   if(x==1){  
   head=logon(head);  
   loginmark=1;  
   }  
   else  
    return head ;     
 }  

 account *p; 
 string number,keys;
  if(loginmark==0){  
  cout<<"Please enter your account number:";  
 cin>>number;  
 cout<<"Please enter your account password:";  
 cin>>keys;  
 t=check_keys(number,keys,head);       
 while(t==0||t==2)
 {  
  if(t==2)
  {cout<<"The password is incorrect, please re-enter the account and password";  
  cout<<"account number:";  
  }  
  else  
   cout<<"The account does not exist, please re-enter the account and password, account number:";  
  cin>>number;  
  cout<<"password:";  
  cin>>keys;  
  t=check_keys(number,keys,head);  
 }   
 }  
 else  
 number=number;  

 cout<<endl<<"================================== Ordinary user login successfully=========== ==================="<<endl<<endl;  
 cout<<"Please select a business: (1) Withdraw money (2) Deposit money (3) Transfer (4) Modify account (5) Change Password (6) Balance inquiry (7) Display account details (8) Exit account"<<endl;  
 p=cheak_number(number,head);      
 char ch;      
 cin>>ch;  
 while(1)  
 {  
  while(ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5'&&ch!='6'&&ch!='7')
  {cout<<"Please re-enter the required business: (1) Withdraw money (2) Deposit (3) Transfer (4) Modify account (5) Change Password (6) Balance inquiry (7) Display account details (8) Exit account"<<endl;  
  cin>>ch;   
  }  
  if(ch=='8')    
   break;  
  else  
  {  
   switch(ch)  
   {  
   case '1':take_money(p);break;           
   case '2':save_money(p);break;          
   case '3':move_money(p,head);break;     
   case '4':revise_account(p);break;
   case '5':change_pswd(p);break;     
   case '6':query_money(p);break;          
   case '7':save_account(p);break;      
   }  
   cout<<"Please choose a business: (1) Withdraw money (2) Deposit money (3) Transfer (4) Modify account (5) Balance inquiry (6) Display account details (7) Exit account"<<endl;  
   cin>>ch;  
  }  
 }  
 return head;  
}  

string change_monitor_keys(string monitor)  
{  
 string string1,string2;
 cout<<"Please enter the original password:";  
 cin>>string1;  
 while(string1!=monitor)
 {  
  cout<<"Does not match the original password, do you re-enter it? (1) Yes (2) No"<<endl;  
  char chra;  
  cin>>chra;
  while(chra!='1'&&chra!='2')
  {  
   cout<<"The selection is wrong, please select again: (1) Yes (2) No"<<endl;  
   cin>>chra;  
  }  
  if(chra=='1') 
  {  
   cout<<"Please enter the original password again:";  
   cin>>string1;  
  }  
  else{
  cout<<endl<<"==================================Password has not been modified============ ========================"<<endl;  
   break;  
   }  
 }  
 if(string1!=monitor)
  return monitor;  
 cout<<"Please enter a new password:";  
 cin>>string1;  
 cout<<"Please enter again to confirm and change the password:";  
 cin>>string2;  
 while(string1!=string2)
 {  
  cout<<"The two passwords are not the same, please choose whether to continue to modify: (1)Yes (2)No"<<endl;  
  char jilu;
  cin>>jilu;  
  while(jilu!='1'&&jilu!='2')
  {  
   cout<<"Please revise and choose whether to revise: (1) Yes (2) No"<<endl;  
   cin>>jilu;  
  }  
  if(jilu=='1') 
  {  
   cout<<"Please enter a new password:";  
   cin>>string1;     
   cout<<"Please enter again to confirm and change the password:";  
   cin>>string2;  
  }  
  else{ 
   break;  
  }  
 }  
 if(string2==string1) 
 {  
  monitor=string1;  
  cout<<endl<<"===================================Password modification succeeded========== ====================="<<endl;  
 }  
 else  
  cout<<endl<<"==================================Password has not been modified============ =================="<<endl;  
 return monitor;  
}  
void choose_model(account *head,string monitor)
{  
 account *p;  
 char ch,mon_cho;
 string str;
 cout<<"============================== Welcome to the bank management system============== ================"<<endl;  
 while(1)  
 {  
  cout<<"Please select an entry mode:"<<endl;  
  cout<<"(1) Administrator mode (2) Normal user mode (3) Exit the system"<<endl;  
  cin>>ch;  
  while(ch!='1'&&ch!='2'&&ch!='3') 
  {   cout<<"Please select an entry mode:"<<endl;  
  cout<<"(1) Administrator mode (2) Normal user mode (3) Exit the system"<<endl;  
  cin>>ch;  
  }  
  if(ch=='1')
  {  
   cout<<"You have entered the administrator mode"<<endl<<"Please enter the administrator password:";  
   cin>>str;  
   if(monitor!=str)  
   {  
    char judge; 
    while(monitor!=str)
    {  
     cout<<"The administrator password is entered incorrectly, do you want to re-enter it? (1)Yes (2)No"<<endl;//It is considered here that it may be that the customer accidentally entered and can choose to exit the administrator mode  
     cin>>judge;  
     while(judge!='1'&&judge!='2')
     {  
      cout<<"Please re-select whether to re-enter the password (1) Yes (2) No"<<endl;  
     }  
     if(judge=='1')
     {  
      cout<<"Please re-enter the administrator password:";  
      cin>>str;
     }  
     else  
     {break;
     }  
    }  
   }  
   if(monitor==str)  
   {  
    cout<<endl<<"==================================Administrator login succeeded=========== ===================="<<endl;  
    while(1)  
    {  

     cout<<endl<<endl<<"Please enter the action to be performed"<<endl;  
     cout<<"(1) Enter customer account (2) Manage customer account (3) Modify administrator password (4) Display all account details (5) Exit administrator mode"<<endl;  

     cin>>mon_cho;
     while(mon_cho!='1'&&mon_cho!='2'&&mon_cho!='3'&&mon_cho!='4'&&mon_cho!='5')
     {  
      cout<<endl<<endl<<"Please re-select mode"<<endl;  
      cout<<"(1) Enter customer account (2) Manage customer account (3) Modify administrator password (4) Display all account details (5) Exit administrator mode"<<endl;  
      cin>>mon_cho;  
     }  
     if(mon_cho=='1') 
      head=get_account(head);  
     else  
      if(mon_cho=='2')  
      {  
       if(head==NULL){  
        cout<<"Sorry, because there is no account registration account, this operation cannot be performed"<<endl;  
        continue;   
       }  
       cout<<"Please enter the customer account number to be modified:";  
       cin>>str;  
       p=cheak_number(str,head);
       while(p==NULL)
       {  
        cout<<"The account does not exist, please re-enter:";  
        cin>>str;  
        p=cheak_number(str,head);  
       }  
       revise_account(p); 
      }  
      else  
       if(mon_cho=='5') 
        break;  
       else  

        if(mon_cho=='4') 
         saveoutput_account (head);  
        else
         monitor=change_monitor_keys(monitor);  

    }  
   }  
  }  
  else  
   if(ch=='2') 
   {  
    char jilu; 
    cout<<"============================== Welcome to the bank management system============== ================"<<endl;  
    while(1)  
    {  
     cout<<"Please select the business you need: (1) Register (2) Login (3) Exit ordinary user mode"<<endl;  
     cin>>jilu;  
     while(jilu!='1'&&jilu!='2'&&jilu!='3')
     {  
      cout<<"Input error, please re-select the business: (1) Register (2) Login (3) Exit the normal user mode"<<endl;  
      cin>>jilu;  
     }  
     if(jilu=='1') 
      head=logon(head);  
     else  
      if(jilu=='2') 
       head=choose(head);  
      else  
       break; 
    }  
   }  
   else 
    break;  
  }  

}  
int main ()  
{   account *head=NULL;  
string monitor="123";  
choose_model(head,monitor);  
return 0;  
}
