////**********************************************Student Catalogue System**********************************************//////////////
//including header files
#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include<fstream>
using namespace std;


//functions required for the management of the contacts
void addContact();
void searchContact();
void help();
void my_exit();
void showAll();
bool check_digits(string phone_num);
bool check_number(string phone_num);


//globally declaring my always used variables
string fname,lname,phone_num,hnumber,email,year,bname,event;
int main()
{
    int choice;
    system("Color 73");
    cout<<"\n\n\n\t\t\t Welcome to Students Catalouge\t\t\t"<<endl;
    cout<<"\n\n\t1.Add Participant\n\n\t2.Search Participant\n\n\t3.View All Participant\n\n\t4.Help\n\n\t5.Exit\n\n\n\t\t"<<endl;
    cin>>choice; //taking choices from the user

    switch (choice) //defining the choice its work according to need using Switch statement
    {
    case 1:
        addContact(); //for adding a contact
        break;
    case 2:
        searchContact(); // for searching a contact
        break;
    case 3:
        showAll(); //for seeing all the contacts in the catalogue
        break;

    case 4:
        help(); //for seeing help option
        break;
    case 5:
        my_exit(); //exit from Contact Catalogue
        break;
    default:
        cout<<"\n\n\t Invalid Choice!"<<endl;
        cout<< "\n\t Press any key to continue"<<endl;
        getch();
        main();
    }


    return 0;

}


//function initialisation of exiting code
void my_exit()
{
    system("cls");
    system("Color 0C"); //chaning the background as well as foreground color to make console interactive
    cout<<"\n\n\n\t\t Thank You for Using!"<<endl;
    exit(1);

}

//function initialisation of help
void help()
{
    system("cls");
    cout<<"\n\n\n\t\t\tHelp\t\t\t\n\n"<<endl;
    cout<<"\t\t Press 1 to Add  Contact\n"<<endl;
    cout<<"\t\t Press 2 to Search Contact\n"<<endl;
    cout<<"\t\t Press 3 to View All Contacts\n"<<endl;
    cout<<"\t\t Press 4 for Help\n"<<endl;
    cout<<"\t\t Press 5 to Exit the menu\n"<<endl;


    main();
}

//function intialisation of adding participant detail
void addContact()
{
        ofstream phone("number.txt",ios::app); //making a file name number.txt and adding contacts to it.

    system("cls");
    cout<<"\n\n\tEnter Participant First Name: "<<endl;
    cin>>fname;
    cout<<"\n\tEnter Participant Last Name: "<<endl;
    cin>>lname;
    cout<<"\n\tEnter Participant 10-Digit Phone Number: "<<endl;
    cin>>phone_num;
    cout<<"\n\tEnter Participant Hostel Number: "<<endl;
    cin>>hnumber;
    cout<<"\n\tEnter Participant email"<<endl;
    cin>>email;
    cout<<"\n\tEnter Participant Year"<<endl;
    cin>>year;
    cout<<"\n\tEnter Participant Branch Name"<<endl;
    cin>>bname;
    cout<<"\n\tEnter Event you want to participate"<<endl;
    cin>>event;


    if(check_digits(phone_num)) //if the number provided by user contains only digits or not
    {
        if(check_number(phone_num)) //if the number provided by the used is a 10-digits(considering contact detail of INDIAN only) or not
        {
            if(phone.is_open()) //if number.txt if able to open then the code below gets executed
            {
                phone<<fname<<" "<<lname<<" "<<phone_num<<" "<<hnumber<<" "<<email<<" "<<year<<" "<<bname<<" "<<event<<endl;
                system("cls");
                system("Color  7C");
                cout<<"\n\t\tContact Saved Successfully!"<<endl;
                main();
            }
            else{
                    system("cls");
            cout<<"\n\t Error Opening File!"<<endl;
            getch();
            main();
            }
        }
        else
        {
             system("cls");
            cout<<"\n\tA phone number must contain digits only!"<<endl;
            main();
        }
    }
    else
    {
         system("cls");
        cout<<"\n\t A phone number must contain 10 digits!"<<endl;
        getch();
        main();
    }
    phone.close();

}

//func. initialisation for searching a participant
void searchContact()
{
    bool flag = false;
    ifstream searchfile("number.txt"); //creating a file object searchfile to check whether the provided keyword is in the file number.txt or not
    string keyword;
    cout<<"\n\t\tEnter the keyword to search : "<<endl;
    cin>>keyword;
    while(searchfile >> fname >> lname >> phone_num)
    {
        if(keyword == fname || keyword ==lname || keyword == phone_num || keyword == hnumber || keyword == email || keyword == year || keyword == bname || keyword == event)
        {

            system("cls");
            cout<<"\n\n\t Participant First Name: "<<fname;
            cout<<"\n\t Participant Last Name: "<<lname;
            cout<<"\n\t ParticipantPhone Number: "<<phone_num;
            cout<<"\n\t Participant Hostel Number: "<<hnumber;
            cout<<"\n\t Participant Email: "<<email;
            cout<<"\n\t Participant Year: "<<year;
            cout<<"\n\t Participant Branch: "<<bname;
            cout<<"\n\t Event Participated: "<<event<<endl;
            flag = true;
            break;

        }
    }
    if(!flag)
    {
        system("cls");
        cout<<"\n\n\n\t\t\tNo Such Contact found!"<<endl;

    }
    main();
}

//function initialisation for viewing all the participants details at once
void showAll()
{
    system("cls");
      std::ifstream f("number.txt"); //creating a file object f of number.txt file to view all its content

    if (f.is_open())
        {
            cout<<"\n\n";
            std::cout <<f.rdbuf()<<endl;
            main();
        }
        else
        {
            system("cls");
            cout<<"\n\n\n\t\t\tError Opening File !"<<endl;
            getch();
            main();
        }


}

 //fun. for checking phone number contains 10 digits or not
bool check_digits(string phone_num)
{
    if(phone_num.length() == 10)
    {
        return true;
    }
    else
        {
            return false;
        }
}

 //fun. for checking the phone number provided contains only digits or not
bool check_number(string x)
{
    bool flag = true;
    for(int i=0;i< x.length();i++)
    {
        if(!(int(x[i])>=48 && int(x[i])<=57))
        {
            flag = false;
            break;
        }

    }
    return flag;
}


