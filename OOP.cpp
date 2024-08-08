#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class university
{
public:
    virtual void getdata()=0;
};

class student : public university
{public:

	string name,course_name,s_pw,id;
    int age;

	char all[999];
	void getdata()
	{
		ofstream out("student.txt",ios::app);
		{
		cout<<"enter your name :";
		cin>>name;
		cout<<"enter the student id :";
		cin>>id;
		cout<<"enter your age :";
		cin>>age;
		cout<<"enter your student password :";
		cin>>s_pw;
		cout<<"what is the course are you want to register :";
		cin>>course_name;
		}
		out<<"\nstudent name :"<<name<<"\nstudent id :"<<id<<"\nage :"<<age<<"\ncourse name :"<<course_name<<"\npassword :"<<s_pw<<endl;
		out.close();
		cout<<"\nsaved \nsuccesfully register to the course"<<endl;

	}
	void showdata()
	{
		ifstream in("student.txt");
		{
			if(!in)
			{
				cout<<"file error"<<endl;
			}
			while(!(in.eof()))
			{
				in.getline(all,999);
				cout<<all<<endl;
			}
			in.close();
		}
	}



};


class managment_staff : public university,student
{
	public:
		string m_id,m_name;
		int pw;
		void getdata(){

		    ofstream manag("management.txt",ios::app);
		    {
		        cout<<"management staff name :";
		        cin>>m_name;
		        cout<<"enter management id :";
                cin>>m_id;
                cout<<"enter the password :";
                cin>>pw;
		    }

		    manag<<"\nstaff name : "<<m_name<<"\nstaff id :"<<m_id<<"\nmanagement password :"<<pw<<endl<<endl;
		    manag.close();

		system("cls");

		if(pw == 123)
		{

            cout<<"*********Registered Students are**********";
            ifstream in("student.txt");
            {
                    if(!in)
                    {
                        cout<<"file error"<<endl;
                    }
                    while(!(in.eof()))
                    {
                        in.getline(all,999);
                        cout<<all<<endl;
                    }
                    in.close();
            }
            }
        else
            cout<<"wrong password "<<endl;
		}

};

class administration : public university,student
{
public :
    int id, pw,code;
    int year,credit;
    string course_name,c_id,instructor_name,name;
    void getdata()
    {
        cout<<"enter the name :";
        cin>>name;
        cout<<"enter the admin's id :";
        cin>>id;
        cout<<"enter the password :";
        cin>>pw;
    if(pw==147)
    {
        ofstream adm("course.txt",ios::app);
		{
        cout<<"create a course \n\n";
        cout<<"enter course id :";
        cin>>c_id;
        cout<<"enter the year :";
        cin>>year;
        cout<<"enter the credit :";
        cin>>credit;
        cout<<"enter the course code :";
        cin>>code;
        cout<<"enter the course name :";
        cin>>course_name;
        cout<<"enter the course instructor name :";
        cin>>instructor_name;
		}
		adm<<"\n"<<c_id<<"\t"<<year<<credit<<code<<"\t"<<course_name<<"\ncourse instructor :"<<instructor_name<<endl<<endl;
		adm.close();
		cout<<"*****Successfully Course Created****** "<<endl;

    }
    else
        cout<<"wrong password "<<endl;

    }
    void showdata()
    {
        cout<<"\nCreated courses are "<<endl;

        ifstream ad("course.txt");
		{
			if(!ad)
			{
				cout<<"file error"<<endl;
			}
			while(!(ad.eof()))
			{
				ad.getline(all,999);
				cout<<all<<endl;
			}
			ad.close();
		}
    }

    void create_account()
    {
        string dep,name,mail_id;
        int id;
        cout<<"\ncreate account \n";
        ofstream create("accounts.txt",ios::app);
        {
            cout<<"enter the name :";
            cin>>name;
            cout<<"enter the department :";
            cin>>dep;
            cout<<"enter the account id :";
            cin>>id;
            cout<<"enter the mail id :";
            cin>>mail_id;
        }
        create<<"\nname :"<<name<<"\ndepartment :"<<dep<<"\nid :"<<id<<"\nmail id :"<<mail_id<<endl<<endl;
        create.close();
        cout<<"*****Successfully Created Account********"<<endl;
    }
    void show()
    {
         ifstream create("accounts.txt");
		{
			if(!create)
			{
				cout<<"file error"<<endl;
			}
			while(!(create.eof()))
			{
				create.getline(all,999);
				cout<<all<<endl;
			}
			create.close();
		}
    }

};
class user : public university,student
{
    public :
        string name,user_pw, user_type;
        void getdata()
        {
        cout<<"which details do you want :\nstudent\nmanagement\nadmin\n";
        cin>>user_type;
        if(user_type == "student")
        {
                        ifstream in("student.txt");
            {
                    if(!in)
                    {
                        cout<<"file error"<<endl;
                    }
                    while(!(in.eof()))
                    {
                        in.getline(all,999);
                        cout<<all<<endl;
                    }
                    in.close();
            }
        }
        else if(user_type == "admin")
        {
            ifstream create("accounts.txt");
		{
			if(!create)
			{
				cout<<"file error"<<endl;
			}
			while(!(create.eof()))
			{
				create.getline(all,999);
				cout<<all<<endl;
			}
			create.close();
		}
        }
        else if(user_type == "management")
        {
            ifstream manag("management.txt");
            {
                cout<<"\nmanagement staff details are :\n"<<endl;
                    if(!manag)
                    {
                        cout<<"file error"<<endl;
                    }
                    while(!(manag.eof()))
                    {
                        manag.getline(all,999);
                        cout<<all<<endl;
                    }
                    manag.close();
            }
        }
        }

};

int main()
{
	student s;
	managment_staff m;
	administration a;
	user u;

	int choice,c,o;
	cout<<"*************************************************************************************"<<endl;
	cout<<"***************************************WELCOME***************************************"<<endl<<endl;
	cout<<"\t\t\t\t\tMenu\t\t\t\t"<<endl;
	cout<<"1 for Resigtration \n2 for management staff \n3 for administration \n4 for users  "<<endl;

	cout<<"enter your choice :";
	cin>>choice;

	switch(choice)
	{
		case 1:
                s.getdata();
                s.showdata();


			break;
		case 2:
			m.getdata();
			break;
        case 3:
            cout<<"enter the option for \n1 for create course \n2 for create account :";
            cin>>c;
            if(c==1)
            {
                a.getdata();
                a.showdata();
            }
            else
            {
                a.create_account();
                a.show();
            }
            break;
        case 4:
            u.getdata();
            break;

		 default :
			cout<<"Exit";


	}
	return 0;
}

