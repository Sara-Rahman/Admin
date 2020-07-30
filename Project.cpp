#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>


using namespace std;

class sara
{
private :

    char serial[100],name_h[100],name_w[100],age_h[5],age_w[5],marriage[10],div_date[10],reason[50],child[10],child_stay[10];
    double percent,stock;
public :
    sara()
    {
        strcpy(serial,"Not inserted");
        strcpy(name_h,"Not inserted");
        strcpy(name_w,"Not inserted");
        strcpy(age_h,"Not inserted");
        strcpy(age_w,"Not inserted");
        strcpy(marriage,"Not inserted");
        strcpy(div_date,"Not inserted");
        strcpy(reason,"Not inserted");
        strcpy(child,"Not inserted");
        strcpy(child_stay,"Not inserted");
        percent =0;
        stock=0;

    }
    void insert_data();
    void show_data();
    void store_data_to_file();
    void view_all_data();
    void see_data();
    void search_data( char *);
    void search_data_with_update( char *);
    void edit_data();
    void delete_file_data(char *);
    void delete_data();




};


void sara ::insert_data()
{




    cout << endl<<endl<<endl;
    cout << "Enter Serial No : ";
    cin>>serial;
    cout << "Enter Husband's Name : ";
    cin>>name_h;
     cout << "Enter Wife's Name : ";
    cin>>name_w;
    cout << "Enter Husband's Age : ";
    cin>>age_h;
    cout << "Enter Wife's Age : ";
    cin>>age_w;
    cout << "Enter Marriage Date : ";
    cin>>marriage;
    cout << "Enter Divorce Date : ";
    cin>>div_date;
    cout << "Enter Reason : ";
    cin>>reason;
    cout << "Enter Number Of Children  : ";
    cin>>child;
     cout << "Enter Children Stay With  : ";
     cin>>child_stay;
      cout << "Enter Percentage   : ";
      cin>>percent;



}


void sara::show_data()
{
  cout <<"Serial No :"<<serial<<" [] "<<"Husband's Name :"<<name_h<< "[] "<<"Wife's Name :"<<name_w<<" [] "<<"Husband's Age :"<<age_h<<" [] "<<"Wife's Age :"<<age_w<<" [] "<<"Marriage Date :"<<marriage<<" [] "<<"Divorce Date :"<<div_date<<" [] "<<"Reason :"<<reason<<" [] "<<"Number Of Children :"<<child<<" [] "<<"Children Stay With :"<<child_stay<<" [] "<<"Percentage :"<<percent<<endl;

}

void sara::store_data_to_file()
{

    if(serial == "Not inserted")
        {
            cout<< "Data is not inserted";
        }
    else
        {
            ofstream file;
            file.open("SARA.txt",ios::app|ios::binary);
            file.write((char*)this,sizeof(*this));
            file.close();

        }

}

void  sara::view_all_data()
{
 ifstream file ;

 file.open("SARA.txt",ios::in|ios::binary);
 if(!file)
 {
     cout << "File does not exist" <<endl;

 }
 else
    {
    file.read((char*)this,sizeof(*this));
    while(!(file.eof()))
    {
       show_data();
       file.read((char*)this,sizeof(*this));

    }
    file.close();


   }
}

void sara::search_data(char *t)
{
    ifstream file;
    int ck=0;
    file.open("SARA.txt",ios::in|ios::binary);
    if(!file)
        {
            cout << "File does not exist  "<<endl;
        }
    else
        {
            file.read((char *)this,sizeof(*this));
            while(!file.eof())
            {
                if(!strcmp(t,serial))
                {
                    show_data();
                    ck++;


                }
                file.read((char *)this,sizeof(*this));
            }
            if(ck==0)
            {
                cout << "Record does not found " <<endl;
            }
            file.close();
        }
}

void sara::search_data_with_update(char *k)
{
    fstream file;
    int ck=0;
    file.open("SARA.txt",ios::in|ios::ate|ios::out|ios::binary);
    file.seekg(0);
    file.read((char *)this,sizeof(*this));
    while(!file.eof())
     {
       if(!strcmp(k,serial))
        {
          cout << "You are trying to see the data "<<endl<<endl;
          show_data();
          edit_data();
          file.seekg(file.tellp()-sizeof(*this));
          file.write((char *)this,sizeof(*this));
          ck++;
        }
         file.read((char *)this,sizeof(*this));
     }
     if(ck==0)
     {
         cout << "Invalid insertion "<<endl;
     }

file.close();
}

void sara::delete_file_data(char *l)
{
    ifstream fin;
    ofstream fout;
    fin.open("SARA.txt",ios::in|ios::binary);
    if(!fin.is_open())
    {
        cout << "Error opening file "<<endl;
    }
    else
    {
        fout.open("tem.dat",ios::out|ios::binary);
        fin.read((char *)this,sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(l,serial))
            {
              fout.write((char *)this,sizeof(*this));
            }
             fin.read((char *)this,sizeof(*this));

        }
        fin.close();
        fout.close();
        remove("SARA.dat");
        rename("Sara.dat","SARA.dat");

    }


}




void sara::edit_data()
{
 double a;
 cout << "Enter How many data you want to see : ";
 cin >> a ;
 if (a >0 && stock >=a)
 {

     stock =stock - a;
     cout << " Thank You " <<endl;
 }
 else
    {
     cout << "Data is not available " <<endl;
    }
}
void sara::see_data()
{
    cout <<endl<<endl<<"Serial No :"<<serial<<" [] "<<"Husband's Name :"<<name_h<< "[] "<<"Wife's Name :"<<name_w<<" [] "<<"Husband's Age :"<<age_h<<" [] "<<"Wife's Age :"<<age_w<<" [] "<<"Marriage Date :"<<marriage<<" [] "<<"Divorce Date :"<<div_date<<" [] "<<"Reason :"<<reason<<" [] "<<"Number Of Children :"<<child<<" [] "<<"Children Stay With :"<<child_stay<<" [] "<<"Percentage :"<<percent<<endl<<endl;
    view_all_data();
    char p[100];
    double a;
    cout <<endl<<endl<< "Enter Serial No : ";
    cin>>p;
    search_data_with_update(p);
}
int Menu()
{
    int ch;
    cout << endl<<"\t<<----------------- Welcome To The Database Of Divorced People In BD --------------->> " << endl <<endl <<endl;
    cout << "1.  Admin  " << endl;
    cout << "2. User " << endl;
    cout << "Press 0 to exit " << endl;
    cout << endl<<endl<<"Enter your choice : ";
    cin>> ch;
    return ch;
}
int admin()
{
    cout  <<endl<<endl<< "You have successfully logged in as Admin " <<endl <<endl;
    cout << "1. Insert Data"<<endl;
    cout << "2. View all data"<<endl;
    cout << "3. Search data"<<endl;
    cout << "4. Delete specific data " <<endl;
    cout << "5. Delete whole file " <<endl;
    cout << "6. Main menu " <<endl;
    cout << "Press 0 to exit" <<endl;
    int a;
    cout << endl<<endl<<"Enter your choice : ";
    cin >> a;
    return a;
}
int user()
{

    cout << "1. View all member"<<endl;
    cout << "2. See specific one"<<endl;
    cout << "Press 0 to exit" <<endl;
    int a;
    cout << endl<<endl<<"Enter your choice : ";
    cin >> a;
    return a;
}
void details ()
{
    cout <<endl<<endl<<"Serial No" <<" [] " << " Husband's Name"<<" [] " << " Wife's Name"<<" [] " << " Husband's Age"<< " Wife's Age"<< " Marriage Date "<< " Divorce Date"<< " Number Of Children "<<" Children Stay With" <<"  [] "<<"  Percentage  "<<" [] "<<endl<<endl;

}
int main()
{
      cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\t\t\t      WELCOME TO IUBAT"<<endl;
    cout<<"\t\t\t             __ "<<endl;
    cout<<"\t\t\t   _       |____|        _"<<endl;
    cout<<"\t\t\t  |_   |  [==||==]   |  _|"<<endl;
    cout<<"\t\t\t    | |  _   ||      | |   "<<endl;
    cout<<"\t\t\t    | | | )  ||  /\\  | |   "<<endl;
    cout<<"\t\t\t    | | |_)  || /--\\ | |   "<<endl;
    cout<<"\t\t\t    | |      ||      | |   "<<endl;
    cout<<"\t\t\t    '. '.____||____.' .'  "<<endl;
    cout<<"\t\t\t       '---|____|---'     "<<endl;
    cout<<" "<<endl;
    cout<<"\t\t *****************************************"<<endl;
    cout<<"\t \t                "<<endl;
    cout<<"" <<endl;
    cout<<" Name : Shahida Rahman"<<endl;
    cout<<" ID   : 18103214"<<endl;
    cout<<" Sec  : B"<<endl;
      cout<<endl;
        cout<<endl;
           cout<<endl;
    cout<<"\t\t\t  WELCOME TO THE DATABASE OF DIVORCED PEOPLE IN BD        "<<endl;
    cout<<"\t\t--------------------------------------------"<<endl;
      cout<<endl;
        cout<<endl;
          cout<<endl;
            cout<<endl;


 string pass ="";
   char ch;
   cout << "Enter Password\n";
   ch = _getch();
   while(ch != 13)
    {
      pass.push_back(ch);
      cout <<'*';
      ch = _getch();
   }
   if(pass == "123"){
      cout << "\nAccess granted :P\n";
   }else{
      cout << "\nAccess aborted...\n";
      cout<<"Serial No :"<<" [] "<<"Husband's Name :"<< "[] "<<"Wife's Name :"<<" [] "<<"Husband's Age :"<<" [] "<<"Wife's Age :"<<" [] "<<"Marriage Date :"<<" [] "<<"Divorce Date :"<<" [] "<<"Reason :"" [] "<<"Number Of Children :"<<" [] "<<"Children Stay With :"<<" [] "<<"Percentage :"<<endl;
   }
     sara c1;

     x:
     while(1)
     {

             system("cls");

            switch(Menu())
            {
                case 1:
                    switch(admin())
                        {
                            case 1:
                                c1.insert_data();
                                c1.store_data_to_file();
                                system("cls");
                                cout<< endl<<"Data Successfully Recorded to the file "<<endl;

                                cout<< "Press any key";
                                getch();
                                break;
                            case 2:
                                details ();

                                c1.view_all_data();

                                cout<<endl<< "Press any key";
                                getch();
                                break;
                            case 3:
                                    system ("cls");
                                    char p[100];
                                    cout <<endl<<endl<<"You are going to search from here --->" <<endl;
                                    details ();
                                    c1.view_all_data();
                                    cout << endl<<"Enter Serial No to  : ";
                                    cin>>p;
                                    system ("cls");
                                    cout << "Search result ==>>"<<endl<<endl;

                                    c1.search_data(p);
                                    cout<<endl<<endl<< "Press any key";
                                    getch();
                                    break;
                            case 4:
                                   char o[100];
                                    details ();
                                    c1.view_all_data();
                                    cout << endl<<"Enter Serial No to delete : ";
                                    cin>>o;
                                    system ("cls");
                                    c1.view_all_data();
                                    c1.delete_file_data(o);
                                    cout << endl<<"You have successfully deleted the record "<<endl<<endl;
                                    getch();
                                    cout <<endl<<endl<< "Press any key "<<endl;
                                    break;
                            case 5:
                                system("cls");
                                char c;
                                cout << endl<<endl<<endl<< "Are you sure for deleting the whole file ??  ";
                                cout << endl<<endl<< "You can not reach the file again";
                                cout << endl<< "Press ( Y ) to confirm";
                                cout << endl<< "Press ( N ) to confirm";
                                cout << endl<< "Enter your choice : ";
                                cin>>c;
                                if(c=='Y' ||c=='y')
                                    {
                                       remove("cycle.dat");
                                       cout<<endl <<endl<<"You have successfully Deleted the whole file ...."<<endl;
                                       break;
                                    }
                                else
                                    {
                                         system("cls");
                                         goto x;

                                    }

                            case 6:
                                system("cls");
                                goto x;

                            case 0:
                                cout << endl<<"You have Successfully logged out "<<endl;
                                cout<<endl<<endl<< "Press any key";
                                getch();
                                exit(0);
                                break;
                            default :
                                cout << "Invalid Choice "<<endl;
                                exit(0);

                        }
                        goto x;

                    case 2:
                        y:
                        switch(user()){
                            case 1:
                                system("cls");
                                details ();
                                c1.view_all_data();
                                cout<<endl<<endl<< "Press any key";
                                getch();
                                system("cls");
                                goto y;

                            case 2:
                                c1.see_data();
                                cout<<endl<<endl<< "Press any key";
                                getch();
                                break ;
                            case 0:
                                cout <<endl<<endl<<endl<< "             THANK YOU              " << endl;
                                cout<<endl<<endl<< "Press any key";
                                getch();
                                exit(0);
                                break;

                            default:
                                cout << "Invalid choice " <<endl;

                        }

                        case 0:
                            cout <<endl<<endl<<endl<< "                         THANK YOU              " << endl;
                            cout<<endl<<endl<< "Press any key";
                            getch();
                            exit(0);
                            break;
                        default:
                            cout <<endl<<endl<< "Invalid choice " <<endl;

                            cout<<endl<<endl<< "Press any key";
                              getch();
                            exit(0);

            }
     }
    return 0;
}

