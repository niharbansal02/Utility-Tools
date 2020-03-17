#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc,char *argv[])
{
	system("xrandr | grep \"primary\" > takein.txt");
	ifstream fin("takein.txt",ios::binary);
	string display;
	fin>>display;
	fin.close();
	system("rm takein.txt");

	double lvl;
	if(argc>1)
		lvl=atof(argv[1]);
	char a[100];
	double val;
	if(argc==1)
	{
		cout<<"\033[1;32m Enter \033[1;33mbrightness \033[1;32mvalue: \033[1;34m";
		cin>>val;
		cout<<"\033[0m";
	}
	else
		val=lvl;
	strcpy(a,"xrandr --output ");
	strcat(a,display.c_str());
	strcat(a," --brightness ");
	strcat(a,to_string(val).c_str());
	system(a);
	return 0;
}
