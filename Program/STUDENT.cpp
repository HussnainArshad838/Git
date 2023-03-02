#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;
string choice;
string un="ADMIN"; 
	string pw="12345";
void loginn();
string username1,password1;
string username,password;
void updatinglogin();
void add();
	void LLL();
void main_menu();
void edit();
int display();
void search();
void quit();
int delet();
	

struct student
{
	string name;
	string fn;
	string rn;
	string mn;
	float CGPA;
};
student arr[30];
int main()
{
	
	
	ofstream sd("login.text");
	sd << un <<endl <<pw<<endl;
	sd.close();
	cout<<"\t              STUDENT DATABASE SOFTWARE   V1.0                 \n";
	cout<<"\n\n\t           DEVELOPERS:                   \n";
    cout<<"\n\t                          1. M.SUFYAN VIRK                  \n";
    cout<<"\n\t                          2. M.SUFYAN VIRK                  \n";
	cout<<"\n\t                          3. M.SUFYAN VIRK                  \n";
	cout<<"\n\t                          4. M.SUFYAN VIRK                  \n";
	cout<<"\n\n\n\t\t            ****************************  "<<endl;
	cout<<"\t\t            Account Verification Process  "<<endl;
	cout<<"\t\t            ****************************  "<<endl;
	cout<<"\n\n\t>Enter 1 for login\n\t>Enter 2 for Update Login\n\t>Enter 3 for Exit\n";
//cin>>choice;
	main_menu();
	if(choice=="1"){
		loginn();
	}
	else if(choice=="2")
	{
		updatinglogin();
	}
	else if(choice=="3")
{
	system ("cls");
	cout<<"Thank You\n";

}
else
{
	cout<<"Enter Valid Option \nPlease Re-Enter Your Option : ";
}

}

void loginn()

{
	system("cls");
	system("color 8");
	cout << "\t\t\t\t                                         \n";
	cout << "\t\t\t\t                                         \n";
	cout << "\t\t\t\t                                         \n";

	cout << "|*-*-*-*-*-* PLEASE ENTER YOUR LOGIN*-*-*-*-*-*|" << endl;
DON1:
	ifstream kf("login.text");
	kf >> un >> pw;
	kf.close();

	cout << "|   ENTER USERNAME   |";
	cin >> username;
		if (username!= un){
		cout << "INVALID\n";
		goto DON1;
	}
	DON2:
		
		
		cout << "|   ENTER PASSWORD   |";
	cin>>password;
		
		if (pw != password)
		{
			cout << "INVALID\n";
			goto DON2;
		}
		else

		{
			cout << "\t\t\t\t                                         \n";
			cout << "\t\t\t\t                                         \n";

			cout << "******LOGIN SUCCESSFULLY*****\n";
			system("cls");
			main_menu();
		}
}





void updatinglogin()
{
	system("color 5A");

	ifstream kf("login.text");
	kf >> un >> pw;
	kf.close();
DON3:
	cout << "|   ENTER YOUR OLD USERNAME   |";

	cin >> username1;
	if (username1 !=un){
		cout << "INVALID\n";
		goto DON3;
	}

DON4:

	cout << "|   ENTER YOUR OLD PASSWORD   |";
cin>>password1;
	
	
	if (pw != password1){
		cout << "INVALID\n";
		goto DON4;
	}

	cout << "1)UPDATING USERNAME\n2)UPDATING PASSWORD\n";
	cin >> choice;


	if (choice == "1")
	{
		cout << "|   ENTER NEW USERNAME   |";
		cin >> un;
		cout << "|-*-*-*-*-*SUCCESSFULLY CHANGED -*-*-*-*-*|";

		ofstream sd("login.text");
		sd << un << endl << pw << endl;
		sd.close();
		ifstream kf("login.text");
		kf >> un >> pw;
		kf.close();
	}
	else
	if (choice == "2"){
		 LLL();
	}
}
	void LLL()
	{
		cout << "| ENTER NEW PASSWORD |";
		cin >> pw;
			cout << "|-*-*-*-*-*SUCCESSFULLY CHANGED-*-*-*-*-*|";
		
		ofstream sd("login.text");
		sd << un << endl << pw  << endl;
		sd.close();
		ifstream kf("login.text");
		kf >> un >> pw;
		kf.close();

}

	void main_menu()
	{
	system("cls");
	system("color 18");
	menu:
	int select;
	
	cout<<"\t              Welcome to Main Menu                    \n";
	cout<<"\t******************************************************\n";
	cout<<"\t***************  1- Add Record     *******************\n";
	cout<<"\t***************  2- Edit Record    *******************\n";
	cout<<"\t***************  3- Search Record  *******************\n";
	cout<<"\t***************  4- Display Record *******************\n";
	cout<<"\t***************  5- Delet Record   *******************\n";
	cout<<"\t***************  6- Quit           *******************\n";
	cout<<"\t******************************************************\n";
	cout<<"\t***        Please select the above one:";
	cin>>select;
	
	
	
	switch(select)
	{
		case 1:
			add();
			goto menu;
			break;
		case 2:
			edit();
			goto menu;
			break;
		case 3:
			search();
			goto menu;
			break;
		case 4:
			display();
			goto menu;
			break;
		case 5:
			delet();
			goto menu;
			break;
		case 6:
			quit();
			break;
		default:
			cout<<"Your Choice is invalid...!!!\n";
			system("pause");
			system("cls");
			goto menu;
			break;
			
			system ("pause");
	}
    }
void add()
{
	char ch;
	int i=0;
	fstream outFile;
	outFile.open("account.txt",ios::app|ios::in|ios::out);	

	
	do
{
	
	
	cout<<"Enter The Record of  New student.....!!!!!!\n";
        cout<<"\n\n Name : ";
	cin>>arr[i].name;
	outFile<<arr[i].name<<"\t\t";
        cout<<"\n\n Father Name : ";
	cin>>arr[i].fn;
    outFile<<arr[i].fn<<"\t\t";
	    cout<<"\n\n Roll Number : ";
	cin>>arr[i].rn;
        outFile<<arr[i].rn<<"\t\t";
		cout<<"\n\n Mobile Number : ";
	cin>>arr[i].mn; 
	outFile<<arr[i].mn<<"\t\t";
	cout<<"\n\n CGPA : ";
	CG:
	cin>>arr[i].CGPA;
	if(arr[i].CGPA>4){
		cout<<"CGPA Must be Less Than OR Equal to 4.0\n";
		cout<<"Plzz. Enter Again...: ";
		goto CG;
	} 
	outFile<<arr[i].CGPA<<"\t\t";
	i++;
    outFile<<endl;
    cout<<"New record is Added...!\n";
    cout<<endl;
    cout<<"iF YOU WANT TO CONTINUE :'Y'\n PRESS ANY KEY TO GO MAIN MENU:";
  PF:
  {
  cin>>ch;
}
if(ch=='N')
{
	quit();
}
else if(ch=='Y')
{
	add();
}
    
}while(ch=='Y');
system("cls");
	
	outFile.close();
}
int display()
{
	system("cls");
	fstream infile("account.txt",ios::in|ios::out);
	int i=0;
	int count=0;
	
	        
	while( !infile.eof())
	{
		infile>>arr[i].name>>arr[i].fn>>arr[i].rn>>arr[i].mn>>arr[i].CGPA;
		
		i++;
	count++;
		
	}
	cout<<"*******************          Data of Students      ****************************"<<endl;
	cout<<"________________________________________________________________________________________________________________________"<<endl;
cout<<"  SR.no | "<<left<<setw(10)<<"Student Name"<<left<<setw(20)<<"|  Father Name"<<left<<setw(10)<<"|  Roll Number"<<right<<setw(10)<<"|  Mobile Number"<<left<<setw(40)<<"|  CGPA    "<<endl;
cout<<endl;
	
	count=count-1;
	for(int i=0;i<count;i++){
		
		cout<<"  "<<i+1<<"     |"<<right<<setw(10)<<arr[i].name<<"   |"<<right<<setw(10)<<arr[i].fn<<right<<setw(10)<<"         |    "<<arr[i].rn<<right<<setw(9)<<"|  "<<arr[i].mn<<right<<setw(10)<<"| "<<arr[i].CGPA<<right<<endl;
		
		cout<<"_______________________________________________________________________________________________________________________"<<endl;
	}

	infile.close();
	system("pause");
	system("cls");
	return count;
}
void edit()
{
	int count=0;
	
	count=display();
		fstream outFile;
	outFile.open("account.txt",ios::in|ios::out);	
	cout<<"****************************************************************"<<endl;
	cout<<"\tThe data of student is above which can be edited "<<endl;
	cout<<"****************************************************************"<<endl;
	int num;
	int rollnum;
	cout<<"Search the data by Entering the Serial number of student :"<<endl;
	cin>>rollnum;
	for(int i=0;i<count;i++)
	{
		if(rollnum==i+1)
		{
			cout<<arr[i].name<<"\t|"<<arr[i].fn<<"\t|"<<arr[i].rn<<"\t|"<<arr[i].mn<<"\t|"<<arr[i].CGPA;
			cout<<"\nEnter the CODE for your favourite option  "<<endl;
			cout<<" 1- Edit Name"<<endl<< " 2- Edit Father Name "<<endl<< " 3- Roll Number "<<endl<<" 4- Edit Mobile Number"<<endl<<" 5- Edit CGPA"<<endl;
			cin>>num;
			switch(num)
			{
				case 1:
					cout<<"Enter the New Name : ";
					cin>>arr[i].name;
					break;
				case 2:
					cout<<"Enter The New Father Name : ";
					cin>>arr[i].fn;
					break;
				case 3:
					cout<<"Enter The New Roll Number " ;
					cin>>arr[i].rn;
					break;
				case 4:
					cout<<"Enter The New Mobile Number : ";
					cin>>arr[i].mn;
					break;
				case 5:
					cout<<"Enter The New CGPA : ";
					cin>>arr[i].CGPA;
					break;
				default:
					cout<<"Your Choice is invalid\n";
				
			}
			
		}
		
	}
	for(int i=0;i<count;i++)
	{
		
		outFile<<arr[i].name<<"\t\t"<<arr[i].fn<<"\t\t"<<arr[i].rn<<"\t\t"<<arr[i].mn<<"\t\t"<<arr[i].CGPA<<endl;
		
	
	
	}
	cout<<"****************************  New Data of Students       *********************"<<endl;
	cout<<"___________________________________________________________________________________________________________"<<endl;
cout<<"  SR.no      Studenr Name\t   Father Name\t\tRoll Number\t\tMobile Number\t\tCGPA    "<<endl;
	        
	for(int i=0;i<count;i++)
	{

		cout<<"\t"<<i+1<<"\t|\t"<<arr[i].name<<"\t|\t"<<arr[i].fn<<"\t|\t"<<arr[i].rn<<"\t|\t"<<arr[i].mn<<"\t|\t"<<arr[i].CGPA<<endl;
		
	
		cout<<"_____________________________________________________________________________________________________________________"<<endl;

}
	outFile.close();
system("pause");
system("cls");

}
void search()
{
	
	system("cls");
	fstream infile("account.txt",ios::in|ios::out);
	int i=0,count=0;
	while(!infile.eof())
	{
		infile>>arr[i].name>>arr[i].fn>>arr[i].rn>>arr[i].mn>>arr[i].CGPA;
	i++;
	count++;
	}
	infile.close();
	count=count-1;
	again:
	cout<<"What do you want to Searching with "<<endl;
	cout<<" 1- Name\n 2- Father name\n 3- Roll Number \n 4- Mobile Number"<<endl;
	int z;
	string nm,father,mobile,rollnumber;
	
	cin>>z;
	switch(z)
	{
		case 1:
			cout<<"Enter The Name Of student :";
			cin>>nm;
			for(int i=0;i<count;i++)
			{
				if(nm==arr[i].name)
				{
					cout<<"The Data Of Student is: ";
					cout<<arr[i].fn<<"   "<<arr[i].rn<<"  "<<arr[i].mn<<"  "<<arr[i].CGPA<<endl;
				}
			}
			break;
		case 2:
			cout<<"Enter The Father Name Of student :";
			cin>>father;
			for(int i=0;i<count;i++)
			{
				if(father==arr[i].fn)
				{
					cout<<"The Data Of Student is: ";
					cout<<arr[i].name<<"   "<<arr[i].rn<<"  "<<arr[i].mn<<"  "<<arr[i].CGPA<<endl;
				}
			}
			break;
		case 3:
			cout<<"Enter the Roll Number of Student: ";
			cin>>rollnumber;
			for(int i=0;i<count;i++)
			{
				if(rollnumber==arr[i].rn)
				{
					cout<<"The Data Of Student is: ";
					cout<<arr[i].name<<"   "<<arr[i].fn<<"  "<<arr[i].mn<<"  "<<arr[i].CGPA<<endl;
				}
			}
			break;
		case 4:
			cout<<"Enter The Mobile Number Of student :";
			cin>>mobile;
			for(int i=0;i<count;i++)
			{
				if(mobile==arr[i].mn)
				{
					cout<<"The Data Of Student is: ";
					cout<<arr[i].name<<"   "<<arr[i].fn<<"  "<<arr[i].rn<<"  "<<arr[i].CGPA<<endl;		
                }
            }
            break;
        default:
        	cout<<"Invalid choice..!\n";
        	cout<<"Enter Again..!\n";
			goto again;
			break;
    }
}
int delet()
{
	string srnum;
	int count=0;
	

	fstream newfile;

	newfile.open("account.txt",ios::in|ios::out);
	int i=0;
	count=display();

	newfile.close();

	remove("account.txt");

	newfile.open("account.txt",ios::out);

	cout<<"Enter the ROLL number you want to Delet :";
	cin>>srnum;

	for(int i=0;i<count;i++){
	
	if(srnum==arr[i].rn){
		
		cout<<"Record is Deleted...!!!";
		
		i++;
		
	}
	newfile<<arr[i].name<<"\t\t"<<arr[i].fn<<"\t\t"<<arr[i].rn<<"\t\t"<<arr[i].mn<<"\t\t"<<arr[i].CGPA<<endl;

}
	
newfile.close();
cout<<endl;
system("pause");
system("cls");
}
void quit()
{
	cout<<"system is quited";
}

