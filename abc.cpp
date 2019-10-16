#include<fstream.h>
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include<time.h>
#include<string.h>
class airline
{
	char	name[20];
	char 	addr[30];
	char 	email[20];
	long int phone;
	long int passno;
	long int date;
	char 	source[30];
	char 	dest[30];
	char 	dep[20];
	char 	arrv[20];
	int 	pword;
	public:
	void reserve();
	void display();
	void cancel();
}ob;
ifstream fin;
ofstream fout;
int choice;
int size=sizeof(airline);
void line()
{
	cout<<"\n";
	for(int i=0;i<80;i++)
		cout<<"-";
	cout<<"\n";
}

void main()
{
		do
		{
				clrscr();
				line();
				cout<<"\n\t\t\tAIRLINE RESERVATION";
 				cout<<"\SYSTEM\n";
				line();
				cout<<"\n\tMENU:\n";
				cout<<"\n1:RESERVATION";
				cout<<"\n2:DISPLAY";
				cout<<"\n3:CANCELLATION";
				cout<<"\n4:EXIT";
				cout<<"\n\nEnter your choice	:	";
				fflush(stdin);
				cin>>choice;
				line();
				switch(choice)
				{
					case	1:	fout.open("nel.cpp",ios::app);
							ob.reserve();
							fout.write((char*)&ob,size);
							fout.close();
							getch();
							break;
					case 2:	ob.display();
							getch();
							break;
					case 3:	ob.cancel();
							getch();
							break;
					case 4:	exit(0);
				}
		}while(choice<4);
		getch();
}


void airline::reserve()
{
	int	mode,plno;
	char	pname[10];
		clrscr();
		cout<<"\nEnter passengers details	:	";
		cout<<"\nName	-	";
		gets(name);
		cout<<"\nAddress	-	";
		gets(addr);
		cout<<"\nE-Mail ID	-	";
		gets(email);
		cout<<"\nTelephone no	-	";
		cin>>phone;
		cout<<"\nEnter the date of travelling	:	";
		cin>>date;
		line();
		cout<<"\n\t1:Domestic\n\t2:International\nEnter the mode:";
		cin>>mode;
		if(mode==1)
		{
			cout<<"\nEnter the plane 1 or 2 or 3	-	";
			cin>>plno;
			switch(plno)
			{
				case 1:	strcpy(pname,"aado1");
						strcpy(source,"Chennai");
						strcpy(dest,"Mumbai");
						strcpy(dep,"10:00");
						strcpy(arrv,"11:00");
						break;

				case 2:  	strcpy(pname,"aado2");
						strcpy(source,"Mumbai");
						strcpy(dest,"Kolkata");
						strcpy(dep,"12:00");
						strcpy(arrv,"13:15");
						break;


				case 3:  	strcpy(pname,"aado3");
						strcpy(source,"Kolkata");
						strcpy(dest,"Chennai");
						strcpy(dep,"17:00");
						strcpy(arrv,"18:00");
						break;
			}
		}
		else
		if(mode==2)
		{
			cout<<"\nEnter the plane 1 or 2 or 3	-	";
			cin>>plno;
			switch(plno)
			{
		
				case 1:	strcpy(pname,"aai01");
						strcpy(source,"Mumbai");
						strcpy(dest,"London");
						strcpy(dep,"00:30");
						strcpy(arrv,"10:30");
						break;
		
				case 2:  	strcpy(pname,"aai02");
						strcpy(source,"Delhi");
						strcpy(dest,"Paris");
						strcpy(dep,"03:20");
						strcpy(arrv,"13:20");
						break;

				case 3:  	strcpy(pname,"aaio3");
						strcpy(source,"Chennai");
						strcpy(dest,"Colombo");
						strcpy(dep,"19:30");
						strcpy(arrv,"20:30");
						break;
			}
		}


		randomize();
		pword=random(1000);
		cout<<"\nPASSWORD\t"<<pword;
		getch();
		line();
		clrscr();
}
void airline::display()
{
			cout<<"\n\n\t1:Passenger Reports\n";
			line();
			cout<<"RESNO"<<setw(12)<<"NAME"<<setw(12) ;
cout<<"ADDRESS"<<setw(12)<<"SOURCE";
cout<<setw(16)<<"DESTINATION\n";
			fin.open("nel.cpp");
			line();
			while(fin.read((char*)&ob,size))
			{
				cout<<pword<<setw(12)<<name;
cout<<setw(12)<<addr<<setw(12);
cout<<source<<setw(16)<<dest<<"\n";
			}
			line();
			fin.close();
}
void airline::cancel()
{
	int	login,p=0;
		fin.open("nel.cpp");
		fout.open("tempfile1.cpp");
		cout<<"\nEnter your password	:	";
		cin>>login;
		while(fin)
		{
			if(login==pword)
				p=1;
			if(login!=pword)
				fout.write((char*)&ob,size);
			fin.read((char*)&ob,size);
		}
		fin.close();
		fout.close();
		remove("nel.cpp");
		rename("tempfile1.cpp","nel.cpp");
		clrscr();
		if(p==0)
			cout<<"\nNo match found";
		else
			cout<<"\nReservation cancelled";
}

















