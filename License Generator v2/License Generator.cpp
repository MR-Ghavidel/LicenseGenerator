#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>     /* srand, rand */
#include <fstream>
#include <conio.h>
#include <string>
#if defined _MSC_VER
#include <direct.h>
#elif defined __GNUC__
#include <sys/types.h>
#include <sys/stat.h>
#endif
using namespace std;

string RandomString(int len)
{
   string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   string newstr;
   int pos;
   while(newstr.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    newstr += str.substr(pos,1);
   }
   return newstr;
}
void createFolder(string dir)
{
#if defined _MSC_VER
	_mkdir(dir.data());
#elif defined __GNUC__
	mkdir(dir.data());
#endif
}
void reverse_String(string& greet, int n,int i){

  if(n<=i){return;}

  swap(greet[i],greet[n]);
  reverse_String(greet,n-1,i+1);

}
int main()
{
	createFolder("Licenses");
	string ratio, a, b, c, d;
	string expString, owner;
	int r, exp;
	int num;
	cout<<"How Many License Do You Want to Generate?\n ";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		
	cout<<"\n-------------------------------------------\n";
	cout<<"Enter Name of The Owner["<<i+1<<"]: ";
	getline(cin>>ws,owner);
	string owner1 = owner;
	int ownerLength = owner.length(); // owner length
	int randomLenghth = 80 - ownerLength;
	
	reverse_String(owner,owner.length()-1,0);
 	//cout<<"String after reversal: "<<owner<<endl;
 	//system("pause");
	srand(time(0));
	string license = RandomString(randomLenghth); // string length
	license[3] = 'M';
	license[21] = 'r';
	license[14] = 'g';
	license[28] = 'h';
	
	
	cout<<"---Ratio: ";
	cin>>ratio;
	license[2] = ratio[0]; // zarib
	cout<<"Enter The License Exp: ";

	a = getch();
	license[6] = a[0]; // sadgan
	system("cls");
	cout<<"Enter The License Exp: ";
	cout<<ratio<<"x"<<a;

	b = getch();
	license[11] = b[0]; // dahgan
	system("cls");
	cout<<"Enter The License Exp: ";
	cout<<ratio<<"x"<<a+b;

	c = getch();
	system("cls");
	cout<<"Enter The License Exp: ";
	expString = a+b+c;
	cout<<ratio<<"x"<<expString<<endl;
	license[31] = c[0]; // yekan
	
	d = "@";
	license[randomLenghth-1] = d[0]; // start owner name
	license = license + owner;
	r = stoi(ratio);
	exp = stoi(expString);
	
	ofstream saveLicenseList("Generated Licenses.txt", ios::app);
	saveLicenseList <<"Owner: "<<owner1<<"\nLicense Code: "<<license<<"\nEXP: "<<r*exp<<" days"<<endl;
	saveLicenseList<<"-----------------------------------------------\n\n";
	
	ofstream saveLicenseSingle(("Licenses/" + owner1 + ".txt").c_str());
	saveLicenseSingle<<license;
	
	cout << license<<endl;
	
		}
		getch();
}
