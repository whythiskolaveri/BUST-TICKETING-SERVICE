#include<fstream.h>
#include<iostream.h>
#include<conio.h>


#define p2 "---------------------------------------------------------------\n"
#define p1 "\n--------------------------------------------------------------------------------"
class logdetails
{
	int userno;
	char fname[21];
	char lname[21];
	int age;           //or DOB ?
	char email[20];
	char pw[15];
	char pno[11];
	public:
		logdetails()
		{
			userno=0;
		}
		char* emailreturn()
		{
			return email;
		}
		char* pwreturn()
		{
			return pw;
		}

		int returnno()
		{
			return userno;
		}

		void signup();
		void signin();
		void display()
		{

			cout<<"USER ID     : "<<userno;
			cout<<"\nFNAME       : "<<fname;
			cout<<"\nLNAME       : "<<lname;
			cout<<"\nAGE         : "<<age;
			cout<<"\nEMAIL       : "<<email;
			cout<<"\nPW          : "<<pw;
			cout<<"\nPNO         : "<<pno;
			cout<<p1;
		}

	};


void main()
{
	clrscr();
	fstream f;
	logdetails l;
	f.open("logdetails.dat",ios::binary|ios::in);

     //	f.seekg(0,ios::beg);
	while(!f.eof())
{
	f.read((char *)&l, sizeof(l));
	l.display();
}
getch();
f.close();
}


