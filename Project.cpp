#include <iostream>
#include <fstream>
#include<windows.h>
#include<conio.h>
using namespace std;
class teacher;
class student
{
private:

    string userid, password, user, pass, mail, mobile, studentname, sec, gender,roll,checkname,checkroll,filename,fileroll,rollno,collage;
    string sub;
    float oops, maths, datastructure, dcld, coalp;
    public:

    void welcome();
    void studentchoice();
    void signup();
    void login();
    void afterlogin();
    void showdata();
};
void student::signup()
{
    int var = 254;
    system("cls");
    fstream file;
    cout << "\t   WELCOME TO AMRITSAR GROUP OF COLLAGE\n";
    cout << "\n\t------------------------------------------\n";
	cout << "\t|          STUDENT SIGNUP PAGE              |\n";
	cout << "\t------------------------------------------\n";
    cout << "\t\tSpace and New line not allow!!\n";
    cout << "\n\t\tEnter Userid:";
	cin >> userid;
	cout << "\t\tEnter Password:";
	cin >> password;
    cout << "\t\tEnter Roll No:";
	cin >>roll;
    cout << "\t\tEnter Email Id:";
    cin >> mail;
    cout << "\t\tEnter your mobile no:";
    cin >>mobile;
    file.open("usersignup2.dat", ios::app | ios::out|ios::binary);
    file << " " << userid << " " << password<<" "<<roll<<" "<<mail<<" "<<mobile << "\n";
    file.close();
	cout << "Plese Wait";
	for (int i = 0; i < 8;i++)
    {
	    cout <<(char)var;
        Sleep(1000);
    }
    system("cls");
    cout << "\t\t\tDear " << userid << " Your Id Successfully Created " << endl;
    Sleep(2000);
    student l;
    l.login();
}
void student::login()
{
    int var = 254;
    login:
    int total=0;
    student s;
    system("Cls");
    system("color FC");
    string user1, password1;
    fstream file;
    file.open("usersignup2.dat", ios::in|ios::out|ios::binary);
	cout << "\n\t------------------------------------------\n";
	cout << "\t|          STUDENT LOGIN PAGE              |\n";
	cout << "\t------------------------------------------\n";
    if (!file)
    {
        cout << "\n\t\t\tNo Such  Data Is Present...";
        file.close();
    }
    else
    {
        cout << "\n\n\t\tuserid:";
        cin >> user1;
        cout << "\t\tpassword:";
        cin >> password1;
        while (!file.eof())
        {
            file >> user >> pass;
            if (user1 == user && password1 == pass)
            {
                total++;
                cout << "\nPlese Wait";
              for (int i = 0; i < 8; i++)
                {
                    cout <<(char)var;
                    Sleep(1000);
                }
                system("cls");
                 system("color 2");
                cout << "\n\n\n\n\t\t\t Sucessfuly Login MR/MS " << user;
                Sleep(2000);
                s.showdata();
                return;
            }
        }
        if(total==0)
        {
            system("cls");
            system("color 0A ");
            cout << "\n\n\n\t\t\tINVALID CREDENTATION\n\t\t\tTry Again Dear "<<user1;
            Sleep(2000);
            goto login;
        }
    }
    file.close();
}
void student::showdata()
{
    student ob;
    s:
    system("cls");
    char ch;
    cout << "\n\n\n\t\t\tWELCOME TO AMRITSAR GROUP OF COLLEGE , AMRITSAR(PUNJAB)\n\n\t\t MARKS CHECKING"<<endl;
    string name, rollno;
    float  dcld1, datastructure1,oops1,coalp1,maths1;
    fstream file;
    int total;
    file.open("studentmark2.dat", ios::in|ios::binary);
    if(!file)
    {
        cout << "\n NO SUCH FILE EXIST!!\n";
        file.close();
    }
    else
    {
        cout << "Enter name=";
        cin >> checkname;
        cout << "Enter roll no=";
        cin >> checkroll;
        while (!file.eof())
        {
            file >> fileroll >> filename;
            file >> dcld1 >> datastructure1 >> oops1 >> coalp1 >> maths1;
            if (checkroll == fileroll && checkname == filename)
            {
                file >>dcld1 >> datastructure1 >> oops1 >> coalp1 >> maths1;
                cout << "STUDENT's NAME=" << filename<<"\n"<<"ROLLNO="<<fileroll<<endl;
                cout << "Dcld Marks=" << dcld1 << "\n DataStructure Marks=" << datastructure1 << "\n Oop's Marks=" << oops1 << "\n Colap Marks=" << coalp1 << "\n Maths Marks=" << maths1 << endl;
                total = 1;
                Sleep(2000);
                break;
            }
        }
    }
    if(total!=1)
            {
                cout << "This record not available Try Again!!\n";
                Sleep(1000);
                goto s;
            }
    file.close();
}
void student::studentchoice()
{
    student project;
    int choice;
    char x;
    start:
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1.Signup" << endl;
    cout << "\t\t\t 2.Login" << endl;
    cout << "\t\t\t 3.Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your choice?? ";
    cin >> choice;
    	switch (choice)
	{
	 case 1:
		project.signup();
		break;
	 case 2:
		project.login();
        break;
        case 3:
            cout << "Thank You To Use This Program " << endl;
     default:
         cout << "\n\t\t\t Invalid Choice Please Try Again..";
        Sleep(2000);
         goto start;
    }
}
void student::afterlogin()
{
    system("cls");
    system("color 0C");
    Sleep(2000);
    student s;
    s.showdata();
}
class teacher
{
    string userid, password, id, mail, mobile,gender,user,pass,studentname,rollno,checkname,checkroll,fileroll,filename;
    string sub;
    float oops, maths, datastructure, dcld, coalp;
    public:
    void teachersignup();
     void teacherlogin();
    void addmarks();
    void modify();
    void deletedata();
    void show2();
    void teacherchoice()
    {
        system("cls");
        system("color 9");
        teacher teacherob;
        int choice;
        char x;
        start:
        system("cls");
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t| TEACHER MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t\t1.Signup" << endl;
        cout << "\t\t\t\t2.Login" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\tChoose Option:[1/2]" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "Enter Your choice?? ";
        cin >> choice;
    	switch (choice)
	    {
	      case 1:
             teacherob.teachersignup();
             break;
	    case 2:
             teacherob.teacherlogin();
            break;
        default:
            cout << "\n\t\t\t Invalid Choice Please Try Again..";
            Sleep(2000);
        goto start;
    }
   }
   void selectteacher();
};
void teacher::deletedata()
{
    system("cls");
    teacher s;
    cout << "\t\t\t------------------------------" << endl;
    cout << "\t\t\t| STUDENT DATA DELETION |"<<endl;
    cout << "\t\t\t-------------------------------"<<endl;
    float oops1,maths1, datastructure1, dcld1, coalp1;
    ifstream file1;
    ofstream file2;
    string roll_no;
    file1.open("Studentmark2.dat",ios::in|ios::binary);
    if(!file1)
    {
        cout << "No such file Exists!!";
    }
    else
    {
        cout << "Enter Roll To Delete Data = ";
        cin >> roll_no;
        file2.open("edit2.dat", ios::out | ios::app|ios::binary);
        while(!file1.eof())
        {
            file1>>rollno>>user >> dcld >> datastructure>> oops >> coalp >> maths;
            if (rollno != roll_no)
            {
               file2 << rollno<<" "<<user << " " << dcld << " " << datastructure << " " << oops << " " << coalp << " " << maths << endl;
            }
        }
            file2.close();
            file1.close();
            remove("Studentmark2.dat");
            rename("edit2.dat", "Studentmark2.dat");
            cout << "Student Details Deleted Successful [Press Any Key To Continue]";
            getch();
            s.selectteacher();
    }
}
void teacher::selectteacher()
{
    system("cls");
    int choice;
	teacher ob;
    student ob2;
    s:
	cout << "\t   WELCOME TO AMRITSAR GROUP OF COLLAGE\n";
    cout << "\n\t------------------------------------------\n";
	cout << "\t|          STUDENT ADD & MODIFY MARKS         |\n";
	cout << "\t------------------------------------------\n";
	cout << "\n\t\t\t(1)ADD MARKS";
    cout << "\n\t\t\t(2)MODIFY MARKS";
    cout << "\n\t\t\t(3)Show Student's Details ";
    cout << "\n\t\t\t(4)Delete Student's Detauls ";
    cout << "\n\t\t\t(5)Go To Teacher Signin/Signup Page ";
    cout << "\n\t\t\t(6)Exit ";
    cout << "\nSelect Your Chice [1,2,3,4,5,6]=";
    cin >> choice;
    switch(choice)
	{
		case 1:
			ob.addmarks();
			break;
		case 2:
			ob.modify();
			break;
        case 3:
            ob.show2();
            break;
        case 4:
            ob.deletedata();
        case 5:
            ob.teacherchoice();
        case 6:
            system("cls");
            cout << "Thank You To Use This Program " << endl;
            exit(0);
            default:
			 cout << "Invalid Choice!!";
			 goto s;
	}
}
void teacher::teachersignup()
{
    int var = 254;
    system("cls");
    fstream file;
    cout << "\t   WELCOME TO AMRITSAR GROUP OF COLLAGE\n";
    cout << "\n\t------------------------------------------\n";
	cout << "\t|          TEACHER SIGNUP PAGE              |\n";
	cout << "\t------------------------------------------\n";
    cout << "\t\tSpace and New line not allow!!\n";
    cout << "\n\t\tEnter Userid:";
	cin >> userid;
	cout << "\t\tEnter Password:";
	cin >> password;
    cout << "\t\tEnter Email Id:";
    cin >> mail;
    cout << "\t\tEnter your mobile no:";
    cin >>mobile;
    cout << "\t\tEnter Your Gender=";
    cin >> gender;
    file.open("teachersignup2.dat", ios::app | ios::out|ios::binary);
    file << " " << userid << " " << password <<" " << mail << " " << mobile <<" "<<gender<<"\n";
    file.close();
	cout << "Plese Wait";
	for (int i = 0; i < 8;i++)
    {
	    cout <<(char)var;
        Sleep(1000);
    }
    system("cls");
    cout << " Congratulation Mr/Ms." << userid << " Your Id Successfully Created " << endl;
    Sleep(2000);
    teacher ob;
    ob.teacherlogin();
}
void teacher::teacherlogin()
{

    int var = 254;
    login:
    int total=0;
    teacher s;
    system("Cls");
    system("color FC");
    string user1, password1;
    fstream file;
    file.open("teachersignup2.dat", ios::in|ios::binary);
	cout << "\n\t------------------------------------------\n";
	cout << "\t|          TEACHER LOGIN PAGE              |\n";
	cout << "\t------------------------------------------\n";
    if (!file)
    {
        cout << "\n\t\t\tNo Such  Data Is Present...";
        file.close();
    }
    else
    {
        cout << "\n\n\t\tuserid:";
        cin >> user1;
        cout << "\t\tpassword:";
        cin >> password1;
        while (!file.eof())
        {
            file >> user >> pass;
            if (user1 == user && password1 == pass)
            {
                total++;
                cout << "\nPlese Wait";
              for (int i = 0; i < 8; i++)
                {
                    cout <<(char)var;
                    Sleep(1000);
                }
                system("cls");
                system("color 2");
                cout << "\n\n\n\n\t\t\t Successfully Login MR/MS " << user;
                Sleep(2000);
                cout << "\n";
                s.selectteacher();
                return;
            }
        }
        if(total==0)
        {
            system("cls");
            system("color 0A ");
            cout << "\n\n\n\t\t\tINVALID CREDENTATION\n\t\t\tTry Again Dear "<<user1;
            Sleep(2000);
            goto login;
		}
    }
    file.close();
}
void  teacher::addmarks()
{
    teacher s;
    char terminate='y';
    system("cls");
    cout << "\t\t\t------------------------------" << endl;
    cout << "\t\t\t| Student marks Addition |"<<endl;
    cout << "\t\t\t-------------------------------"<<endl;
    cout << "\n\t\t\tSPACE AND SPECIAL SYMBOLE NOT ALLOW!!\n";
    int p = 0;
    fstream f1;
    f1.open("Studentmark2.dat",ios::app|ios::out|ios::binary);
    while(terminate!='n')
    {
            cout << "\t\t\tStudent's Name=";
            cin >> studentname;
            cout << "\t\t\tRoll no=";
            cin >> rollno;
            cout << "--------------------------------------------------------------------------------------------------------\n";
            cout << "\n\t\t\t\t\t\t\tENTER YOUR MARKS\n ";
            cout << "\t\t\tDCLD=";
            cin >> dcld;
            cout << "\t\t\tDATASTRUCTURE=";
            cin >> datastructure;
            cout << "\t\t\tOOPS=";
            cin >> oops;
            cout << "\t\t\tCOALP=";
            cin >> coalp;
            cout << "\t\t\tMATHS=";
            cin >> maths;
            cout << "________________________________________________________________________________________________________________\n";
            f1<<rollno<<" " <<studentname<<" "<<dcld<<" "<< datastructure<<" "<< oops<<" "<< coalp <<" " << maths<<endl;
            cout << "Do you Want to add more = ";
            cin >> terminate;
            if(terminate!='y')
            {
                s.selectteacher();
            }
    }
          f1.close();
}
void teacher::modify()
{
    system("cls");
    teacher s;
    cout << "\t\t\t------------------------------" << endl;
    cout << "\t\t\t| Student Details Modify |"<<endl;
    cout << "\t\t\t-------------------------------"<<endl;
    float oops1,maths1, datastructure1, dcld1, coalp1;
    ifstream file1;
    ofstream file2;
    string roll_no;
    file1.open("Studentmark2.dat",ios::in|ios::binary);
    if(!file1)
    {
        cout << "No such file Exists!!";
    }
    else
    {
        cout << "Enter Roll To Modify Data = ";
        cin >> roll_no;
        file2.open("edit2.dat", ios::out | ios::app|ios::binary);
        while(!file1.eof())
        {
            file1>>rollno>>user >> dcld >> datastructure>> oops >> coalp >> maths;
            if (rollno != roll_no)
            {
               file2 << rollno<<" "<<user << " " << dcld << " " << datastructure << " " << oops << " " << coalp << " " << maths << endl;
            }
            else
            {
                cout << "\t\t\tNEW DETAILS";
                cout << "\n\t\t\t-----------\n";
                cout << "Enter Roll No=";
                cin >> roll_no;
                cout << "Enter name=";
                cin >> studentname;
                cout << "Dcld=";
                cin >> dcld1;
                cout << "Data Structure=";
                cin >> datastructure1;
                cout << "OOPs=";
                cin >> oops1;
                cout << "Coalp=";
                cin >> coalp1;
                cout << "Maths=";
                cin >> maths1;
                cout << "Student Details Sucessfuly Modify [Press Enter To Continue]";
                getch();
                file2 <<roll_no<< " " << studentname << " " << dcld1<< " " << datastructure1 << " " << oops1 << " " << coalp1 << " " << maths1 << endl;
                s.selectteacher();
                break;
            }
        }
            file2.close();
            file1.close();
            remove("Studentmark2.dat");
            rename("edit2.dat", "Studentmark2.dat");
    }
}
void teacher::show2()
{
    teacher ob;
    s:
    system("cls");
    char ch;
    cout << "\n\n\n\t\t\tWELCOME TO AMRITSAR GROUP OF COLLEGE , AMRITSAR(PUNJAB)\n\n\t\t MARKS CHECKING"<<endl;
    string name, rollno;
    float  dcld1, datastructure1,oops1,coalp1,maths1;
    fstream file;
    int total;
    file.open("studentmark2.dat", ios::in|ios::binary);
    if(!file)
    {
        cout << "\n NO SUCH FILE EXIST!!\n";
        file.close();
    }
    else
    {
        cout << "Enter name=";
        cin >> checkname;
        cout << "Enter roll no=";
        cin >> checkroll;
        while (!file.eof())
        {
            file >> fileroll >> filename;
            file >> dcld1 >> datastructure1 >> oops1 >> coalp1 >> maths1;
            if (checkroll == fileroll && checkname == filename)
            {
                file >>dcld1 >> datastructure1 >> oops1 >> coalp1 >> maths1;
                cout << "STUDENT's NAME=" << filename<<"\n"<<"ROLLNO="<<fileroll<<endl;
                cout << "Dcld Marks=" << dcld1 << "\n DataStructure Marks=" << datastructure1 << "\n Oop's Marks=" << oops1 << "\n Colap Marks=" << coalp1 << "\n Maths Marks=" << maths1 << endl;
                total = 1;
                cout << "Pres Any key To Continue ";
                getch();
                ob.selectteacher();
                break;
            }
        }
    }
    if(total!=1)
            {
                cout << "This record not available Try Again!!\n";
                Sleep(2000);
                goto s;
            }
    file.close();
}
void logo()
{

    int mark=254;
    system("cls");
    cout << "\n\n\n\t\t\tWELCOME TO AMRITSAR GROUP OF COLLEGE , AMRITSAR(PUNJAB)"<<endl;
    system("color 2");
    cout << "\n\t\t\tPlease Wait";
    for (int i = 0; i < 8; i++)
    {
        cout << (char)mark;
        Sleep(1000);
    }
}
void intro()
{
    system("cls");
	system("color 2c");
	cout<< "\n\n\t\t------------------------------" << endl;
	cout << "\t\t|\tINTRODUCTION         |" << endl;
	cout << "\t\t------------------------------" << endl;
	cout << "\n"<< "####################################################################" << endl;
	cout << "|SUBMITTED BY:-                                                    |" << endl;
	cout << "|\t\tAdarsh Paritosh (2000052)                          |" << endl;
	cout << "|\t\tAhishek Kumar (2000051)                            |" << endl;
	cout << "|\t\tAman Mandal (2000056)                              |" << endl;
	cout << "|\t\tAshish Gupta (2000073)                             |" << endl;
	cout<< "####################################################################" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t   ###################################################################" << endl;
	cout << " \t\t\t\t\t\t\t\t\t   |SUBMITTED TO:-                                                   |" << endl;
	cout << " \t\t\t\t\t\t\t\t\t   |\t\t      ER.Sakshi Mahajan                             |" << endl;
	cout << " \t\t\t\t\t\t\t\t\t   |                                                                 |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t   ###################################################################" << endl;
    Sleep(7000);
}
int main()
{
    logo();
    intro();
    student obj;
    teacher ob;
        int c;
        start:
        system("cls");
        cout << "\t\t\tWELCOME TO AMRITSAR GROUP OF COLLAGE\n";
        cout << "\n\t\t\t\t(1)TEACHER LOGIN";
        cout << "\n\t\t\t\t(2)STUDENT LOGIN";
        cout << "\n\n\t\t\tENTER YOUR CHOICE=";
        cin >> c;
        switch (c)
        {
        case 1:
           ob.teacherchoice();
            break;
        case 2:
            obj.studentchoice();
            break;
        default:
            cout << "INVALID CHOICE";
            goto start;
            break;
        }
    return 0;
}