//	SIGN UP MODULE DONE @ 12.23 AM ; 22/9/17
// 	SIGN IN MODULE COMPLETEED @12:30 Am ; 25/9/17
//      FILE INCORPORATION PENDING ;;;
// 	FILE 95% INCORPORATED : 25/9 @4:07 PM
//      unable to login; probably failure in comparing email and pw
//      INSTRUCTIONS :clear file, test contents and proceed again
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<ctype.h>

int usernu=0;
#define p2 "---------------------------------------------------------------\n"
#define p1 "\n--------------------------------------------------------------------------------"

char* toupperstring(char a[])
{
	for(int i=0;a[i]!='\0';i++)
		a[i]=toupper(a[i]);
	return a;
}
class logdetails
{
	int userno; // REMOVAL PENDING
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

	      /*	int returnno()
		{
			return userno;
		} */   // - REMOVAL PENDING

		void signup();
		void signin();
	};
/*   CLASS LOGDETAILS
	SIZE = 92 BYTES   -2 = 90
	*/

void fsignup()
{
	fstream f;
	logdetails l;
	f.open("logdetails.dat",ios::binary|ios::app);
	if(!f)
	{
		clrscr();
		cout<<"ERROR 404 ------ FILE NOT FOUND\N";
		return;
	}

	l.signup();
	f.write((char *)&l, sizeof(l));

	cout<<"Sign Up Successfull!\n";

	f.close();
}
void logdetails::signup()
{
	clrscr();
	char pw1[11];

	cout<<"Hello Guest\n\n";
	cout<<"Enter Sign Up Details\n";
	cout<<p1;


	cout<<"         First Name: ";
	gets(fname);
	cout<<p1;

	cout<<"         Last Name       : ";
	gets(lname);
	cout<<p2;

	cout<<"         Age             : ";
	cin>>age;
	cout<<p2;

	cout<<"         E-Mail ID       : ";
	gets(email);
	cout<<p2;

	 label1: cout<<"         Password        : ";
	gets(pw);
	cout<<p2;

	if(strlen(pw)<8)
	{	cout<<"Minimum of 8 characters required\n ";
		goto label1;
	}

	cout<<"         Confirm Password: ";
	gets(pw1);
	cout<<p2;

	if(strcmpi(pw,pw1)!=0)
	{
		cout<<"\nPass words do not match\n";
		goto label1;
	}


	cout<<"         Phone Number: ";
	gets(pno);

	//loading animation goes here

	clrscr();



	cout<<"\n"<<p1;
	//cout<<"\n\nSign Up Successful!\n";
	usernu++;


}

void TREAD_WITH_CARE_WANDERER()
{
	clrscr();
	cout<<"FILE CLEARED\n";
	fstream f("logdetails.dat",ios::out);
	f.close();
}

void logdetails::signin()
{

	clrscr();  // BE WARE
	fstream f;
	f.open("logdetails.dat",ios::binary|ios::in);
	logdetails l;

	labela2:cout<<"Hello User\n";

	char semail[20],femail[30];;
	char spw[15],fpw[15];
	cout<<p1;
	labela1:cout<<"Enter Email ID:";
	gets(semail);
	cout<<p2;
	// semail id is compared with each email id is in the logdetails FILE;
	// if it exists go to recieve password
	// if it does not ask user to reenter and/or give an option to redirect to sign up page(how?)




	cout<<"Enter Password: ";
	gets(spw);
	cout<<p2;
	//compare passwords with return function; no other way out ("secure"?)

	//
	while(!f.eof())
	{
		f.read((char *)&l,sizeof(l));
		//EMAIL CHECK
		strcpy(femail,l.emailreturn());
		cout<<fmail;   //check
		if(strcmpi(femail,semail)!=0)
		{
			cout<<"User does not exist\n";
			cout<<"Type NEW if you are a new member          ";
			cout<<"Type NO to re- enter Email ID\n";
			char ans[5];
			cin>>ans;
			toupperstring(ans);
    /*!!!!!!!!!!!!!*//*       INTEGRATE BELOW "IF" WHEN COMPLETE */
			if(strcmpi(toupperstring(ans),"NEW")==0)
			{
				fsignup();
				cout<<"PRESS ANY KEY TO CONTINUE\n";
				getch();
				clrscr();

				goto labela2;
			}

			else if(strcmpi(ans,"NO")==0)
				goto labela1;
			else
				return;
		}

		//PW CHECK

		strcpy(fpw,l.pwreturn());
		if(strcmpi(fpw,spw)==0)
			break;

		else
		{       cout<<"INCORRECT PASSWORD\n";
			goto labela1;
		}


	}

	cout<<"\n\n\         WELCOME:    "<<fname<<endl;
}




void main()
{
	logdetails l;
	fstream f;
	//f.open("logdetails.dat",ios::binary|ios::in|ios::out);



      // IDIOTLOOKCAREFULLYTREAD_WITH_CARE_WANDERER();
       l.signin();


	getch();
	f.close();
}





