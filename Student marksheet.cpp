#include<conio.h>
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

class student
{
 private:
 string name,rollnumber,semester,subject1,subject2,subject3,subject4,subject5,subject6,grade,result;
 float per;
 int marks1,marks2,marks3,marks4,marks5,marks6,sum;
 public:
       void menu();
       void insert();
       void display();
       void deleted();
       void record_update();
       void records();
};

void student::menu()
{  start:
	system("cls");
	int choice;
	char x;
    
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t HITEC University Taxila "<<endl;
	cout<<"\n\t\t\t\t\t Student Marks Sheet Management System" <<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
    cout<<"1.\t Enter new student data "<<endl;
    cout<<"2.\t Display Individual student marks sheet "<<endl;
    cout<<"3.\t Delete student "<<endl;
    cout<<"4.\t Update an individual student record"<<endl;
    cout<<"5.\t Show all students records"<<endl;
    cout<<"6.\t exit"<<endl;
    cout<<"Enter the choice:"<<endl;
   	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cin>>choice;
    
    switch(choice)
    {
    	case 1:
    	do
    	{
    		insert();
    		cout<<"\n--> Add New Record (y/n)";
    		cin>>x;
		}while(x=='Y'||x=='y');
    	break;
		
	    case 2:
	   	    display();
	   	    break;
	   	
	   	case 3:
	   		deleted();
	   		break;
		
		case 4:
			record_update();
			break;
			
		case 5:
			records();
			break;
					  	
		case 6:
			exit(0);
		default:
			cout<<"\n-->Invalid Choice..!! Please Try Again "<<endl;
			
	}
	getch();
    goto start;
}


void student::insert()
{
   fstream file;
   system("cls");
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t\t | Enter data for new Student |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   cout<<"\t\t\t--> Enter Name : ";
   cin>>name;
   cout<<"\t\t\t--> Enter Roll Number : ";
   cin>>rollnumber;
   cout<<"\t\t\t--> Enter semester number : ";
   cin>>semester;
   cout<<"\t\t\t--> Enter subject 1 name :";
   cin>>subject1;
   cout<<"\t\t\t--> Enter subject 1 marks :";
   cin>>marks1;
   cout<<"\t\t\t--> Enter subject 2 name : ";
   cin>>subject2;
   cout<<"\t\t\t--> Enter subject 2 marks : ";
   cin>>marks2;
   cout<<"\t\t\t--> Enter subject 3 name : ";
   cin>>subject3;
   cout<<"\t\t\t--> Enter subject 3 marks : ";
   cin>>marks3;
   cout<<"\t\t\t--> Enter subject 4 name : ";
   cin>>subject4;
   cout<<"\t\t\t--> Enter subject 4 marks :";
   cin>>marks4;
   cout<<"\t\t\t--> Enter subject 5 name :";
   cin>>subject5;
   cout<<"\t\t\t--> Enter subject 5 marks :";
   cin>>marks5;

   sum=marks1+marks2+marks3+marks4+marks5;
   per=(sum/5)*100;
  if(per>=80)
   {
   	 grade="A";
   	 result="PASS";
   }
   else if(per>=60)
   {
   	grade="B";
   	result="PASS";
   }
   else if(per>=35)
   {
   	grade="C";
   	result="PASS";
   }
   else
   {
   	grade="F";
   	result="FAIL";
   }
 // creating a file STUDENTRESULT.TXT to store the records of stuednts........
   file.open("studentresult.txt",ios::out | ios::app);
   file<<" "<<name<<" "<<rollnumber<<" "<<semester<<" "<<subject1<<" "<<marks1<<" "<<subject2<<" "<<marks2<<" "<<subject3<<" "<<marks3<<" "<<subject4<<" "<<marks4<<" "<<subject5<<" "<<marks5<<" "<<subject6<<" "<<marks6<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<"\n";
   file.close();
   getch();
   
    
}

// defination of display function........
void student::display()
{
	system("cls");
	fstream file;
	
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t\t | Student Result Table |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   file.open("studentresult.txt",ios::in);
   if(!file)
   {
      cout<<"\n\t\t\t No Data Is Found ......";
	  file.close();	
   
   }
   else
   {
   	   file>>name>>rollnumber>>semester>>subject1>>marks1>>subject2>>marks2>>subject3>>marks3>>subject4>>marks4>>subject5>>marks5>>subject6>>marks6>>sum>>per>>grade>>result;
   	   while(!file.eof())
   	   {

   	   	
   		 cout<<"Enter Student Roll number: : "<<rollnumber<<endl;
   		
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t HITEC University Taxila "<<endl;
	cout<<"\n\t\t\t\t\t Student Marks Sheet Management System" <<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
    
   		 
   		 cout<<"Name : "<<name<<endl;
   		 cout<<"Roll number : "<<rollnumber<<endl;
   		 cout<<"Semester number: "<<semester<<endl;

   		 
   		 cout<<"\n\t----------------------------------------------------------------------------------------";               //whole structure of the result table........
   		 cout<<"\n\t   Subject Name            \t           Marks    ";
   		 cout<<"\n\t----------------------------------------------------------------------------------------";
   		 cout<<"\n\t\t"<<subject1<<"           \t      "<<marks1<<"         "<<endl;
   		 cout<<"\t \t "<<subject2<<"           \t      "<<marks2<<"          "<<endl;
   		 cout<<"\t \t "<<subject3<<"           \t      "<<marks3<<"         "<<endl;
   		 cout<<"\t \t "<<subject4<<"           \t      "<<marks4<<"         "<<endl;
   		 cout<<"\t \t "<<subject5<<"           \t      "<<marks5<<"         "<<endl;
   		 cout<<"\t----------------------------------------------------------------------------------------";
   		cout<<"\n Total Marks: 500 "<<endl; 
		cout<<"\n Obtained Marks: "<<sum<<endl;
		cout<<"\n Percentage:"<<per<<endl;
		cout<<"\n GPA on basis to total marks: "<<grade<<endl;;
   	
   		
   		cout<<"\n\n\t-----------------------------------------------------------------------------------------------------";
   		
   		cout<<" \n\n\n\n Press any key to continue to main menu";
   		
   		file>>name>>rollnumber>>semester>>subject1>>marks1>>subject2>>marks2>>subject3>>marks3>>subject4>>marks4>>subject5>>marks5>>subject6>>marks6>>sum>>per>>grade>>result;
	    break;
	   }	   
   }
     file.close();	
     
   
}


void student::deleted()
{
	system("cls");
	fstream file,file1;
	string rollno;
	int found=0;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t\t | Delete Student Record |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   
    file.open("studentresult.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Found ......";
	  file.close();	
				
	}
	else
	{
		cout<<"\n\t\t\t--> Enter Roll No. Of Student Which You Want To delete The Data : ";
		cin>>rollno;
		file1.open("temp.txt",ios::out | ios::app);
		
		file>>name>>rollnumber>>semester>>subject1>>marks1>>subject2>>marks2>>subject3>>marks3>>subject4>>marks4>>subject5>>marks5>>subject6>>marks6>>sum>>per>>grade>>result;
		while(!file.eof())
		{
			if(rollnumber!=rollnumber)
			{
				 file<<" "<<name<<" "<<rollnumber<<" "<<semester<<" "<<subject1<<" "<<marks1<<" "<<subject2<<" "<<marks2<<" "<<subject3<<" "<<marks3<<" "<<subject4<<" "<<marks4<<" "<<subject5<<" "<<marks5<<" "<<subject6<<" "<<marks6<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<"\n";
				 
			}
			else
			{  found++;
			   cout<<"\n\t\t\t Record Is Successfully Deleted.....";
			   
			   	
			}	
			
			file>>name>>rollnumber>>semester>>subject1>>marks1>>subject2>>marks2>>subject3>>marks3>>subject4>>marks4>>subject5>>marks5>>subject6>>marks6>>sum>>per>>grade>>result;
		break;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Student Roll Number Is Not found...!!! ";
		}
		file.close();
		file1.close();
		
		remove("studentresult.txt");
		rename("temp.txt","studentresult.txt");
	}
	getch();
	
}
void student::record_update() {
    system("cls");
    fstream file, temp;
    string rno;
    int found = 0;

    cout << "\n\t--> Enter Roll Number to Update Record: ";
    cin >> rno;

    file.open("studentresult.txt", ios::in);
    temp.open("temp.txt", ios::out);

    while (file >> name >> rollnumber >> semester >>
           subject1 >> marks1 >> subject2 >> marks2 >> subject3 >> marks3 >>
           subject4 >> marks4 >> subject5 >> marks5 >>
           sum >> per >> grade >> result) {
        
        if (rno == rollnumber) {
            found++;

            cout << "\n\t--> Updating record for Roll Number: " << rno << "\n";
            cout << "\t--> Enter new Name: ";
            cin >> name;
            cout << "\t--> Enter new Semester: ";
            cin >> semester;

            cout << "\t--> Enter subject 1 name and marks: ";
            cin >> subject1 >> marks1;
            cout << "\t--> Enter subject 2 name and marks: ";
            cin >> subject2 >> marks2;
            cout << "\t--> Enter subject 3 name and marks: ";
            cin >> subject3 >> marks3;
            cout << "\t--> Enter subject 4 name and marks: ";
            cin >> subject4 >> marks4;
            cout << "\t--> Enter subject 5 name and marks: ";
            cin >> subject5 >> marks5;

            sum = marks1 + marks2 + marks3 + marks4 + marks5;
            per = sum / 5.0;

            if (per >= 80) {
                grade = "A";
                result = "PASS";
            } else if (per >= 60) {
                grade = "B";
                result = "PASS";
            } else if (per >= 35) {
                grade = "C";
                result = "PASS";
            } else {
                grade = "F";
                result = "FAIL";
            }

            temp << name << " " << rno << " " << semester << " "
                 << subject1 << " " << marks1 << " "
                 << subject2 << " " << marks2 << " "
                 << subject3 << " " << marks3 << " "
                 << subject4 << " " << marks4 << " "
                 << subject5 << " " << marks5 << " "
                 << sum << " " << per << " " << grade << " " << result << "\n";

            cout << "\n\t--> Record updated successfully!";
        } else {
            // copy other records as-is
            temp << name << " " << rollnumber << " " << semester << " "
                 << subject1 << " " << marks1 << " "
                 << subject2 << " " << marks2 << " "
                 << subject3 << " " << marks3 << " "
                 << subject4 << " " << marks4 << " "
                 << subject5 << " " << marks5 << " "
                 << sum << " " << per << " " << grade << " " << result << "\n";
        }
    }

    file.close();
    temp.close();
    remove("studentresult.txt");
    rename("temp.txt", "studentresult.txt");

    if (found == 0) {
        cout << "\n\t--> No record found with roll number " << rno;
    }

    getch();
}

void student::records() {
    system("cls");
    fstream file;
    file.open("studentresult.txt", ios::in);

    cout << "\n\n\t\t\t\t\t All Students Records\n";
    cout << "------------------------------------------------------------------------------------\n";
    cout << "Name\tRoll#\tSemester\tTotal\t%age\tGrade\tResult\n";
    cout << "------------------------------------------------------------------------------------\n";

    while (file >> name >> rollnumber >> semester >>
           subject1 >> marks1 >> subject2 >> marks2 >> subject3 >> marks3 >>
           subject4 >> marks4 >> subject5 >> marks5 >>
           sum >> per >> grade >> result) {
        cout << name << "\t" << rollnumber << "\t" << semester << "\t\t"
             << sum << "\t" << per << "\t" << grade << "\t" << result << "\n";
    }

    file.close();
    getch();
}

// defination of main function..........
int main()
{    
    student s;              
    s.menu();                
    
	getch();
	return (0);
}
