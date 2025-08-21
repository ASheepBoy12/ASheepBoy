#include <windows.h>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
using namespace std;
int Gs;
string Gsp;
string GVS = "Officialversion:2.8";
string ans;
string Title="",Username="";
bool Regedit_used,Developer;
enum ConsoleColor
{
    Black       = 0,
    Blue        = 1,
    Green       = 2,
    Cyan        = 3,
    Red         = 4,
    Magenta     = 5,
    Yellow      = 6,
    White       = 7,
    Gray        = 8,
    LightBlue   = 9,//2
    LightGreen  = 10,//3
    LightCyan   = 11,
    LightRed    = 12,
    LightMagenta= 13,
    LightYellow = 14,//1
    BrightWhite = 15
};

string Gsaj(long long x)
{
	string ans = "";
	for (int i = 1; i <= x; i++)
	{
		ans += '.';
	}
	return ans;
}
void cls()
{
	cout<<endl;
	if(Developer)
	{
		return;
	}
	string cls = "cls";
	system(cls.c_str());
	Gs+=5;
}
void Write_regedit(DWORD Writingvalue)
{
	cout<<endl;
    HKEY hKey;
    LONG result;
    const wchar_t *subKey = L"Software\\ASheepBoy";
    const wchar_t *valueName = L"ASheepBoy";
    const DWORD valueData = Writingvalue;
    printf("Writing...\n");
    printf("Path: HKEY_CURRENT_USER\\Software\\ASheepBoy\n");
    printf("Name: ASheepBoy\n");
    printf("Data: %d\n",Writingvalue);
    result = RegCreateKeyExW(HKEY_CURRENT_USER,subKey,0,NULL,REG_OPTION_NON_VOLATILE,KEY_WRITE | KEY_READ,NULL,&hKey,NULL);
    if (result != ERROR_SUCCESS)
    {
        printf("ERROR:%d\n", result);
	    cout<<"Please press any key to continue.";
	    getch();
        return;
    }
    result = RegSetValueExW(hKey,valueName,0,REG_DWORD,(const BYTE *)&valueData,sizeof(DWORD));
    if (result != ERROR_SUCCESS)
    {
        printf("ERROR:%d\n", result);
	    cout<<"Please press any key to continue.";
	    getch();
	    return;
    }
    else
    {
        printf("Success:Data=%d\n",Writingvalue);
    }
    RegCloseKey(hKey);
    cout<<endl;
    cls();
}
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

DWORD Read_regedit()
{
    HKEY hKey;
    LONG result;
    const wchar_t *subKey = L"Software\\ASheepBoy";
    const wchar_t *valueName = L"ASheepBoy";
    DWORD valueData = 0;
    DWORD dataSize = sizeof(DWORD);
    DWORD type = REG_DWORD;
    result = RegOpenKeyExW(HKEY_CURRENT_USER,subKey,0,KEY_READ,&hKey);
    if (result != ERROR_SUCCESS)
    {
        printf("ERROR:%d\n", result);
        return 0;
    }
    result = RegQueryValueExW(hKey,valueName,NULL,&type,(LPBYTE)&valueData,&dataSize);
    if (result != ERROR_SUCCESS)
    {
        printf("ERROR:%d\n", result);
    }
    else if (type != REG_DWORD)
    {
        printf("ERROR:TypeError_Not_REG_DWORD(%d))\n", type);
    }
//    else
//    {
//        printf("%d", valueData);
//    }
    RegCloseKey(hKey);
    return valueData;
}
long long Gsap(string x)
{
	return x.size();
}

void SetWindow()
{
	int w, h, x, y;
	ifstream sw("Temp\\GameWindowInformation.bat");
	if (!sw.is_open())
	{
		w = 900;
		h = 450;
		x = 200;
		y = 200;
	}
	else
		sw >> w >> h >> x >> y;
	HWND hwnd = GetForegroundWindow();
	RECT rect;
	GetWindowRect(hwnd, &rect);
	int newWidth = w;
	int newHeight = h;
	SetWindowPos(hwnd, NULL, rect.left, rect.top, newWidth, newHeight, SWP_NOZORDER | SWP_NOMOVE);
	int newX = x;
	int newY = y;
	SetWindowPos(hwnd, NULL, newX, newY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}
void Uptempnew()
{
	cls();
	Gs += 2;
	cout << "Please provide feedback to your email if there are any errors:ASheepBoy@qq.com" << endl;
	cout << "The new of the " << GVS << ':' << " (2025.6.21)" << endl;

	cout << "  -Add Data Export function." << endl;
	cout << "  -Add Data Import function." << endl;
	cout << "  -Fix known error." << endl;
	cout << "  -Update title system." << endl;
	cout << "  -Update the shop." << endl;
	cout << "  -Reset the feedback email adress." << endl;
	cout << "  -Optimized the interface." << endl;
	cout << "  -Update Game score storage mechanism." << endl;
	

	// Add here
	cout << "If you want to know more about this Game,you can input 1 to download the 'UpDate.txt''" << endl;
	cout << "Input 0 to continue" << endl;
	string uta;
	cin >> uta;
	if (uta == "1")
	{
		cout << "'UpDate.txt' is download...";
		ofstream utn("UpDate.txt");
		utn << "NEWS(Officialversion:1.1)2024.1.11" << endl
			<< "--------------------" << endl
			<< "  -Add News." << endl
			<< "  -Add the 'NEW' flags." << endl
			<< "  -Reset the window." << endl
			<< "  -Optimized performance." << endl
			<< "  -If you input 20 times wrong password,your PC will shutdown." << endl
			<< endl;
		utn << "NEWS(Officialversion:1.2)2024.1.30" << endl
			<< "--------------------" << endl
			<< "  -Add Mouse linker." << endl
			<< "  -Fixed known errors." << endl
			<< "  -Optimized performance." << endl
			<< "  -Add error feedback." << endl
			<< "  -Optimized the interface." << endl
			<< "  -Add the testing website." << endl
			<< endl;
		utn << "NEWS(Officialversion:1.3)2024.2.2" << endl
			<< "--------------------" << endl
			<< "  -Optimized program code." << endl
			<< "  -Revised bonus point rules." << endl
			<< "  -Optimized performance." << endl
			<< "  -Fixed known errors." << endl
			<< "  -Add the date in update information." << endl
			<< "  -Add the system time." << endl
			<< endl;
		utn << "NEWS(Officialversion:1.4)2024.2.16" << endl
			<< "--------------------" << endl
			<< "  -Optimized performance." << endl
			<< "  -Fixed known errors." << endl
			<< "  -Add random in Stone Scissors And Cloth." << endl
			<< "  -Add Guess Number." << endl
			<< "  -Add random in Hide And Seek." << endl
			<< "  -Add protective measures." << endl
			<< "  -Add pleasantly surprised." << endl
			<< "  -Changed the location of the file" << endl
			<< endl;
		utn << "NEWS(Officialversion:1.5)2024.2.20" << endl
			<< "--------------------" << endl
			<< "  -Fixed the Surprise." << endl
			<< "  -Fixed the code." << endl
			<< "  -Add settings." << endl
			<< "  -Optimized performance." << endl
			<< "  -Add setting colors." << endl
			<< "  -Add Remember colors." << endl
			<< endl;
		utn << "NEWS(Officialversion:1.6)2024.2.30" << endl
			<< "--------------------" << endl
			<< "  -Fix settings." << endl
			<< "  -Add window setting." << endl
			<< "  -Add operator settings." << endl
			<< "  -Optimized performance." << endl
			<< "  -Fixed known errors." << endl
			<< "  -Add password safety application." << endl
			<< "  -Fixed the operator settings." << endl
			<< "  -Add more color at settings." << endl
			<< endl;
		utn << "NEWS(Officialversion:1.7)2024.3.17" << endl
			<< "--------------------" << endl
			<< "  -Fix the password texting." << endl
			<< "  -Fix the Game score rule." << endl
			<< "  -Add Reactivity Test." << endl
			<< "  -Add folder at the main page." << endl
			<< "  -Fix the shutdown time." << endl
			<< "  -Optimized performance." << endl
			<< "  -Add password at Game score." << endl
			<< endl;
		utn << "NEWS(Officialversion:1.9)2024.4.1" << endl
			<< "--------------------" << endl
            << "  -Add work countdown." << endl
            << "  -Add time tools." << endl
			<< endl;
		utn << "NEWS(Officialversion:2.0+2.1)2025.4.12" << endl
			<< "--------------------" << endl
			<< "  -Fixed known errors." << endl
			<< "  -Optimized performance." << endl
			<< "  -Use Regedit to save Game Score."<<endl
			<< "  -Optimized program code."<<endl
			<< "  -Fix time tools."<<endl
			<< endl;
		utn << "NEWS(Officialversion:2.2)2025.4.26" << endl
			<< "--------------------" << endl
			<< "  -Fix Regedit Gamescore" << endl
			<< "  -Fixed known errors." << endl
			<< "  -Optimized performance." << endl
			<< "  -Add Developer mod." << endl
			<< "  -Mainly Use Regedit to save gamescore." << endl
			<< "  -Optimized Stone Scissors And Cloth."
			<< endl;
		utn << "NEWS(Officialversion:2.3)2025.5.3" << endl
			<< "--------------------" << endl
			<< "  -Fixing Unknow error." << endl
			<< "  -Add Regedit Gamescore check." << endl
			<< "  -Add Local Gamescore file check." << endl
			<< "  -Fixing Regedit Gamescore and Local file Gamescore check." << endl
			<< "  -Changing the Feedback email." << endl
			<< "  -Add password when go into Operator settings." << endl
			<< "  -Fix the random of Stone Scissors And Cloth." << endl
			<< "  -Optimized performance." << endl
			<< endl;
		utn << "NEWS(Officialversion:2.4)2025.5.10" << endl
			<< "--------------------" << endl
			<< "  -Add Typing Speed Test." << endl
			<< "  -Fix Typing Speed Test." << endl
			<< "  -Fix unknow bugs." << endl
			<< "  -Add Memory Game." << endl
			<< "  -Fix Memory Game." << endl
			<< "  -Optimized the interface."<<endl
			<< "  -Show instructions when open the game first." << endl
			<< "  -Show the update information when update." << endl
			<< "  -Add the Game Using information." << endl
			<< "  -Optimized adding Game Score." << endl
			<< "  -Modify the logic for storing scores." << endl
			<< endl;
		utn << "NEWS(Officialversion:2.5)2025.5.17" << endl
			<< "--------------------" << endl
			<< "  -The user's permission to modify the text color is canceled." << endl
			<< "  -Optimized text and interface." << endl
			<< "  -Added text color." << endl
			<< "  -Optimized performance." << endl
			<< "  -Optimized code." << endl
			<< "  -Support changing user name." << endl
			<< endl;
		utn << "NEWS(Officialversion:2.6)2025.8.3" << endl
			<< "--------------------" << endl
			<< "  -Not allowed to change the username." << endl
			<< "  -Open the ASheepBoy's shop." << endl
			<< "  -Add products 'Name-changing card'." << endl
			<< "  -Add products 'Title-changing card'." << endl
			<< "  -Add products 'Custom Title card'." << endl
			<< "  -Hide the password." << endl
			<< "  -Add Username Welcome." << endl
			<< endl;
		utn << "NEWS(Officialversion:2.7)2025.8.6" << endl
			<< "--------------------" << endl
		  	<< "  -Add Title System." << endl
			<< "  -Optimized performance." << endl
			<< "  -Fixed known errors." << endl
			<< "  -Update the shop." << endl
			<< "  -Update sign up interface." << endl
			<< "  -Fix the title system." << endl
			<<endl;

		if (utn.is_open())
		{
			cout << "Download Accept,please read this file on your folder" << endl;
			cout << "Please press any key to continue." << endl;
			getch();
			Gs += 5;
		}
		else
		{
			cout << "Download Fail,please check your system..." << endl;
			cout << "Please press any key to continue." << endl;
			getch();
			Gs += 10;
		}
		utn.close();
	}
	else
	{
		cls();
	}
	cls();
}
void UsingInformation()
{
	cls();
	cout<<"Please input strictly according to the program requirements"<<endl;
	cout<<"If this regulation is violated,"<<endl;
	cout<<"the author will not be responsible for any bugs that occur in the subsequent program"<<endl;
	cout<<endl<<"Please input 1 to accept the rules"<<endl;
	cout<<"Input 0 or others if you disagree the rules and exit the program"<<endl;
	string UsingInformationans;
	cin>>UsingInformationans;
	if(UsingInformationans=="1")
	{
		cls();
		return;
	}
	else
	{
		ofstream ogi("Temp\\GameInformation.ini");
		ogi << Gsaj(Gs);
		Write_regedit(Gs);
		cls();
		if(Developer)
		{
			getch();
		}
		exit(0);
	}
}
void UpDate()
{
	ifstream udt("Temp\\UpDateTemp.ini");
	string update;
	if(udt.is_open())
	{
		udt >> update;
	}
	udt.close();
	system("mkdir Temp 2>nul");
	if (update != GVS)
	{
		cout << "Please wait for the update..." << endl;
		Sleep(500);
		cls();
		for (int i = 1; i <= 3; i++)
		{
			cout << "Please wait for the update..." << endl;
			cout << "Update is loading";
			for (int j = 1; j <= 3; j++)
			{
				cout << ".";
				Sleep(100);
			}
			cls();
		}
		for (int i = 1; i <= 99; i++)
		{
			cls();
			cout << "Updating..." << endl;
			if (i % 3 == 0)
				continue;
			cout << "Update is finish %" << i;
		}
		Sleep(200);
		ofstream udt("Temp\\UpDateTemp.ini");
		udt << GVS;
		udt.close();
		cls();
		cout << "Updating..." << endl
			 << "Update is finish %100" << endl;
		cout << "Update is complete" << endl;
		cout << "Please press any key to continue";
		getch();
		cls();
		Uptempnew();
	}
	cls();
}
string addpd(string upd)
{
	for (int i = 0; i < upd.size(); i++)
	{
		upd[i] = upd[i] + 'A' + 'S' + 'h' + 'e' + 'e' + 'p' + 'B' + 'o' + 'y' + 'X' + 'T' + 'H';
		if (i == 1)
			upd[i] += 2011;
		if (i == 3)
			upd[i] += 1;
		if (i == 13)
			upd[i] += 13;
	}
	return upd + upd + upd;
}
void User()
{
	ifstream ut("Temp\\UserInformation.ini");
	ifstream titin("Temp\\Title.ini");
	if(titin.is_open())
	{
		titin>>Title;
		titin.close();
	}
	else
	{
		titin.close();
		ofstream titout("Temp\\Title.ini");
		titout<<"(None)";
		titout.close();
		Title="(None)";
	}
	if (ut.is_open())
	{
		string tun, tup;
		ut >> tun >> tup;
		ut.close();
		int times = 0;
		while (1)
		{
			if (times >= 20)
			{
				for (int i = 10; i > 0; i--)
				{
					cout << "Your computer will shutdown in 10 seconds" << endl;
					cout << i;
					Sleep(10000);
					cls();
				}
				system("shutdown /s /t 0");
			}
			if (times >= 5)
			{
				cout << "Please wait for 1 minute and try again";
				Sleep(1000 * 60);
				cls();
			}
			Username=tun;
			cout << "Please input ";
			if(Title!="(None)")
			{
				if(Title=="Admin")
				{
					setColor(Red);
					cout << '('<<Title<<')';
					setColor(White);
				}
				else
				{
					setColor(LightBlue);
					cout << '('<<Title<<')';
					setColor(White);
				}
			}
			cout << tun << "'s password" << endl;
			string passwd="";
			char passwdc;
			while(1)
			{
				passwdc=getch();
				if(passwdc=='\r')
				{
					break;
				}
				else
				{
					passwd+=passwdc;
					cout<<'*';
				}
			}
			if (addpd(passwd) == tup)
			{
				ifstream gi("Temp\\GameInformation.ini");
				if (gi.is_open())
				{
					gi >> Gsp;
				}
				else
				{
					Gs = 0;
				}
				cls();
				ifstream devinput("Temp\\Developer_mod.ini");
				if(devinput.is_open())
				{
					string devs;
					bool devc;
					devinput>>devs>>devc;
					Developer=devc;
					if(Developer)
					{
						cout<<"WARNING Developer mod is open!"<<endl;
						cout<<"Developer Value="<<Developer<<endl;
					}
					devinput.close();
				}
				else
				{
					devinput.close();
				}
				cout << "Welcome!" << endl;
				cout << "Please press any key to continue." << endl;
				getch();
				cls();
				break;
			}
			else
			{
				cls();
				cout << "Wrong password,please input again!" << endl;
				times++;
				cout << "Please press any key to continue." << endl;
				getch();
			}
			cls();
		}
	}
	else
	{
		ut.close();
		cout << "This computer does not have user information, please register an account" << endl;
  		string username="", upasswd="";
		while (1)
		{
			username="";
			upasswd="";
			cout << "Please input the username:";
			cin >> username;
			cout << endl
				 << "Please input the password:";
			char passwdc;
			while(1)
			{
				passwdc=getch();
				if(passwdc=='\r')
				{
					cout<<endl;
					break;
				}
				else
				{
					upasswd+=passwdc;
					cout<<'*';
				}
			}
			cout<<"Please input the password again:";
			string pswda="";
			while(1)
			{
				passwdc=getch();
				if(passwdc=='\r')
				{
					cout<<endl;
					break;
				}
				else
				{
					pswda+=passwdc;
					cout<<'*';
				}
			}
			if(pswda!=upasswd)
			{
				cout<<"The password are not same,please input again"<<endl;
				cout<<"Please press any key to continue"<<endl;
				getch();
				cls();
				continue;
			}
			if (upasswd.size() < 6)
			{
				cout << "Please input a longer password" << endl;
				cout << "Please press any key to continue" << endl;
				getch();
				cls();
				continue;
			}
			if (upasswd == username)
			{
				cout << "The password can't include the username" << endl;
				cout << "Please press any key to continue" << endl;
				getch();
				cls();
				continue;
			}
			if (upasswd == "111111" or upasswd == "123456" or upasswd == "000000")
			{
				cout << "The password is not safty,please change another" << endl;
				cout << "Please press any key to continue" << endl;
				getch();
				cls();
				continue;
			}
			break;
		}
		ofstream oui("Temp\\UserInformation.ini");
		oui << username << endl
			<< addpd(upasswd);
		Username=username;
		oui.close();
		ofstream outi("Temp\\GameInformation.ini");
		outi << "0";
		outi.close();
		ofstream reg("Temp\\Regedit.reg");
		reg << "Regeit_Used: "<< 1 << "\n";
		reg << "Weather_Continue: "<< 1 << "\n";
		reg.close();
		ofstream tit("Temp\\Title.ini");
		tit << "(None)";
		tit.close();
		string tun, tup;
		ut >> tun >> tup;
		Write_regedit(1);
		ut.close();
		cout << "User data configuration completed, please log in." << endl;
		cout << "Please press any key to continue";
		getch();
		oui.close();
		cls();
		ifstream ut("Temp\\UserInformation.ini");
		string un, up;
		ut >> un >> up;
		ut.close();
		int times = 0;
		while (1)
		{
			if (times >= 5)
			{
				cout << "Please wait for 1 minute and try again";
				Sleep(1000 * 60);
				cls();
			}
   			cout << "Please input ";
   			if(Title!="(None)")
			{
				if(Title=="Admin")
				{
					setColor(Red);
					cout << '('<<Title<<')';
					setColor(White);
				}
				else
				{
					setColor(LightBlue);
					cout << '('<<Title<<')';
					setColor(White);
				}
			}
			cout << un << "'s password" << endl;
			string passwd;
			char passwdc;
			while(1)
			{
				passwdc=getch();
				if(passwdc=='\r')
				{
					cout<<endl;
					break;
				}
				else
				{
					passwd+=passwdc;
					cout<<'*';
				}
			}
			if (addpd(passwd) == up)
			{
				ifstream gi("Temp\\GameInformation.ini");
				if (gi.is_open())
					gi >> Gsp;
				else
					Gs = 0;
				cls();
				cout << "Welcome!" << endl;
				cout << "Please press any key to continue." << endl;
				getch();
				cls();
				break;
			}
			else
			{
				cls();
				cout << "Wrong password,please input again!" << endl;
				times++;
				cout << "Please press any key to continue." << endl;
				getch();
			}
			cls();
		}
	}
}
int Rand(int ranse)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	int Rlocal = sys.wMilliseconds / ranse;
	return Rlocal;
}
void rock()
{
	cls();
	while (1)
	{
		cout << "Please enter gesture number:" << endl
			 << "1.Stone 2.Scissors 3.Cloth" << endl
			 << "Enter 0 to exit";
		int rock_num;
		//int rock_rand = Rand(100);
		int rock_rand;
		//if (rock_rand <= 2) rock_rand = 1;
		//else if (rock_rand <= 6) rock_rand = 2;
		//else rock_rand = 3;
		cout << endl;
		auto start = chrono::high_resolution_clock::now();
		rock_num=getch();
		rock_num-=48;
	    auto end = chrono::high_resolution_clock::now();
	    double time = chrono::duration<double>(end - start).count();
	    if(time<=0.2)
	    {
	    	setColor(Red);cout<<endl<<"The input speed is too fast"<<endl;
	    	cout<<"Please slow down!"<<endl;
			setColor(White);
			Sleep(3000);
			return;
		}
		if (rock_num == 0) break;
		else if (rock_num == 1)
		{
			rock_rand=3;//
			if (rock_rand == 1)
			{
				cout << "SCORE DRAW! The robot input STONE!" << endl;
				Gs += 2;
			}
			if (rock_rand == 2)
			{
				cout << "YOU WIN! The robot input SCISSORS!" << endl;
				Gs += 3;
			}
			if (rock_rand == 3)
			{
				cout << "The robot wins,the robot inputs CLOTH!" << endl;
				Gs += 1;
			}
		}
		else if (rock_num == 2)
		{
			rock_rand=3;//
			if (rock_rand == 1)
			{
				cout << "SCORE DRAW! The robot input SCISSORS!" << endl;
				Gs += 2;
			}
			if (rock_rand == 2)
			{
				cout << "YOU WIN! The robot input CLOTH!" << endl;
				Gs += 3;
			}
			if (rock_rand == 3)
			{
				cout << "The robot wins,the robot inputs STONE!" << endl;
				Gs += 1;
			}
		}
		else if (rock_num == 3)
		{
			rock_rand=3;//
			if (rock_rand == 1)
			{
				cout << "SCORE DRAW! The robot input CLOTH!" << endl;
				Gs += 2;
			}
			if (rock_rand == 2)
			{
				cout << "YOU WIN! The robot input STONE!" << endl;
				Gs += 3;
			}
			if (rock_rand == 3)
			{
				cout << "The robot wins,the robot inputs SCISSORS!" << endl;
				Gs += 1;
			}
		}
		else
			cout << "Input error,please re-enter..." << endl;
		cout << endl;
		cout << "Please press any key to continue"<<endl;
		getch();
		cls();
	}
	cls();
}
void help()
{
	cls();
	cout << "Do you want to download the file:'How To Use This Game.txt'" << endl;
	cout << "1.Yes  2.No" << endl;
	int helpans;
	cin >> helpans;
	if (helpans == 1)
	{
		cout << "The file is downloading..." << endl;
		ofstream heof("How To Use This Game.txt");
		heof << "I don't know..." << endl;
		if (heof.is_open())
		{
			cout << "Download Accept,please read this file on your folder" << endl;
			cout << "Please press any key to continue." << endl;
			getch();
			Gs += 5;
		}
		else
		{
			cout << "Download Fail,please check your system..." << endl;
			cout << "Please press any key to continue." << endl;
			getch();
			Gs += 10;
		}
		heof.close();
	}
	else if (helpans == 2)
	{
		cout << "Download is ended" << endl;
		cout << "Please press any key to continue." << endl;
		getch();
		Gs += 1;
	}
	else
	{
		cout << "Input error." << endl;
		Sleep(1000);
		cls();
	}
	cls();
}

void find8()
{
	cls();
	cout << "Please find the '8' in the '0' and enter the position of 8" << endl;
	cout << "Please press any key to continue" << endl;
	getch();
	cls();
	int randans = Rand(10);
	if (randans <= 0 || randans >= 100)
		randans = 64;
	for (int i = 1; i <= 100; i++)
	{
		if (i == randans)
		{
			cout << 8;
			continue;
		}
		cout << 0;
	}
	cout << endl
		 << "Please input your answer:";
	int fans;
	cin >> fans;
	if (fans == randans)
	{
		cout << "Congratulations,you answered is correctly.";
		cout << "The game score will be increased by 10" << endl;
		cout << "Please press any key to continue." << endl;
		getch();
		Gs += 10;
		cls();
	}
	else
	{
		cout << "Wrong answer..." << endl;
		cout << "Please press any key to continue." << endl;
		getch();
		Gs += 1;
		cls();
	}
}
void create()
{
	cls();
	cout << "Are you feeling frustrated about not being able to create files";
	cout << " Use this tool to make sure you don't feel frustrated" << endl;
	string cfname, cfcon;
	cout << "Please enter the file name:";
	cin >> cfname;
	cout << endl
		 << "Please enter the file content:";
	cin >> cfcon;
	cfname = cfcon + ".txt";
	ofstream cfile(cfname.c_str());
	cfile << cfcon;
	if (cfile.is_open())
	{
		cout << endl
			 << "Create success,please read this file on your folder" << endl;
		const string folderPath;
		ShellExecuteA(NULL, "open", folderPath.c_str(), NULL, NULL, SW_SHOW);
		Gs += 5;
	}
	else
	{
		cout << endl
			 << "Create fail" << endl;
		Gs++;
	}
	cfile.close();
	cout << "Please press any key to continue" << endl;
	getch();
	cls();
}
void calculator()
{
	cls();
	cout << "This is a calculator that can help you to count" << endl;
	cout << "Only supports addition (+), subtraction (-), multiplication (*), division (/)" << endl;
	cout<<"Input '0/0' to exit"<<endl;
	while(1)
	{
		cout<<endl;
		double n1, n2;
		char fh;
		cin >> n1 >> fh >> n2;
		if(n1==0 && fh=='/' && n2==0)
		{
			Gs+=5;
			cls();
			return;
		}
		if (fh == '+')
			cout << n1 << '+' << n2 << '=' << n1 + n2 << endl;
		else if (fh == '-')
			cout << n1 << '-' << n2 << '=' << n1 - n2 << endl;
		else if (fh == '*')
			cout << n1 << '*' << n2 << '=' << n1 * n2 << endl;
		else if (fh == '/')
		{
			if(n2==0)
			{
				cout << "Input error..." << endl;
				continue;
			}
			cout << n1 << '/' << n2 << '=';
			printf("%.6lf\n",n1/n2*1.0);
		}
		else
			cout << "Input error..." << endl;
		Gs += 2;
	}
}
void Surprise()
{
	for (int i = 1; i <= 10; i++)
	{
		system("color a0");
		system("color b0");
		system("color c0");
		system("color d0");
		system("color e0");
		system("color f0");
		system("color a");
	}
	cls();
	Gs += 1;
}
void Mousefp()
{
	cls();
	cout << "Please enter the click interval duration(in ms)(Fastest 1 millisecond):" << endl;
	int midt;
	cin >> midt;
	cls();
	cout << "Press F2 to execute,press F4 to stop,press ESC to exit" << endl;
	cout << "Speed:" << midt << "ms/x" << endl;
	cout << "(CPS testing website:'5vmc.com/cps')" << endl;
	Gs += 10;
	while (1)
	{
		if (GetAsyncKeyState(VK_F2))
		{
			while (1)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				if (GetAsyncKeyState(VK_F4))
				{
					break;
				}
				Sleep(midt);
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
	}
	cls();
}
void Guess()
{
	cls();
	int gans;
	int guenum = Rand(10);
	if (guenum <= 0 || guenum >= 100)
		guenum = 64;
	cout << "The robot is thinking a number..." << endl;
	cout << "The robot is ready,please input a number first(0~100)" << endl;
	while (1)
	{
		cout << "Input -1 to exit" << endl;
		cin >> gans;
		if (gans == -1)
			break;
		else if (gans == guenum)
		{
			cout << "Congratulations,you answered is correctly.";
			cout << "The game score will be increased by 10" << endl;
			cout << "Please press any key to continue." << endl;
			getch();
			Gs += 10;
			cls();
			break;
		}
		else if (gans > guenum)
			cout << "Your number is too big!" << endl;
		else if (gans < guenum)
			cout << "Your number is too small!" << endl;
		else
		{
			cout << "Wrong answer..." << endl
				 << endl;
			Gs++;
		}
	}
	cls();
}
void Settings()
{
	cls();
	cout << "1.Set window" << endl;
	setColor(Yellow);cout << "2.Operator settings(Non professionals are not allowed to use)" << endl;setColor(White);
	cout << "3.Reset the password" << endl;
	cout << "4.Logout"<<endl;
	cout << "5.Data Export"<<endl;
	cout << "6.Data Import"<<endl;

	cout<<endl;
	cout<<"Input 0 to exit"<<endl;
	cout<<"Please input the number:";
	char setans;
	cin >> setans;
	Gs+=5;
	if (setans == '1')
	{
		cls();
		cout << "Please input the Window's weight(in pixel):";
		int aw, ah;
		cin >> aw;
		cout << endl
			 << "Please input the Window's hight(in pixel):";
		cin >> ah;
		ofstream sws("Temp\\GameWindowInformation.bat");
		sws << aw << endl
			<< ah << endl
			<< 200 << endl
			<< 200;
		sws.close();
		SetWindow();
	}
	else if (setans == '2')
	//Add Game Score
	//Developer_mod
	{
		cls();
		cout<<"Please input the password:";
		string setting_op_pw;
		cin>>setting_op_pw;
		if(setting_op_pw!="ASheepBoy")
		{
			cls();
			return;
		}
		else
		{
			cout<<"Success"<<endl;
		}
		while (1)
		{
			string kfs;
			getline(cin, kfs);
			if (kfs == "-1")
			{
				break;
			}
			else if (kfs == "Add Game Score")
			{
				cls();
				cout << "Loading";
				for (int i = 1; i <= 3; i++)
				{
					cout << '.';
					Sleep(500);
					Gs += 5000;
				}
				cout << endl;
				cout << "Complete!" << endl;
				continue;
			}
			else if(kfs == "Developer_mod")
			{
				ifstream devmifo("Temp\\Developer_mod.ini");
				if(!devmifo.is_open())
				{
					devmifo.close();
					ofstream dev("Temp\\Developer_mod.ini");
					dev<<"Developer_mod_is_open: "<< 0;
					dev.close();
				}
				else
				{
					devmifo.close();
				}
				ifstream dev("Temp\\Developer_mod.ini");
				string devcnt;
				bool devc;
				dev>>devcnt>>devc;
				cout<<endl<<"Developer_mod_is_open_value="<<Developer<<endl;
				cout<<"Developer_mod_is_open_local="<<devc<<endl;
				cout<<"Input 1 to ";
				if(devc)
				{
					cout<<"close"<<endl;
				}
				else
				{
					cout<<"open"<<endl;
				}
				string devans;
				cin>>devans;
				if(devans=="1")
				{
					if(devc)
					{
						cout<<"Developer mod is close"<<endl;
						ofstream devl("Temp\\Developer_mod.ini");
						devl<<"Developer_mod_is_open: "<< 0;
						Developer=0;
						devl.close();
					}
					else
					{
						cout<<"Developer mod is open"<<endl;
						ofstream devl("Temp\\Developer_mod.ini");
						devl<<"Developer_mod_is_open: "<< 1;
						Developer=1;
						devl.close();
					}
				}
				ifstream deva("Temp\\Developer_mod.ini");
				deva>>devcnt>>devc;
				deva.close();
				cout<<"*Developer_mod_is_open_value="<<Developer<<endl;
				cout<<"*Developer_mod_is_open_local="<<devc<<endl<<endl;
				cout<<"Developer_mod_setting is exit"<<endl;
			}
			else
			{
				system(kfs.c_str());
			}
		}
	}
	else if(setans == '3')
	{
		cout << "Please input your username:";
		ifstream setuser("Temp\\UserInformation.ini");
		string setname, setpasswd, setinname, setinpass;
		cin >> setname;
		setuser >> setinname >> setinpass;
		setuser.close();
		if (setname != setinname)
		{
			cout << "The username is wrong,please input again." << endl;
			cout << "Please press any key to continue." << endl;
			getch();
			cls();
			return;
		}
		else
		{
			cout << endl << "Please input your old password:";
			cin >> setpasswd;
			if (addpd(setpasswd) != setinpass)
			{
				cout << "The userpassword is wrong,please input again." << endl;
				cout << "Please press any key to continue." << endl;
				getch();
				cls();
				return;
			}
			else
			{
				cout << "Please input your new userpassword:";
				cin >> setpasswd;
				cout<<endl<<"Please input your new userpassword again:";
				string setnewpasswd;
				cin>>setnewpasswd;
				if(setpasswd==setnewpasswd)
				{
					cout << "Please wait..." << endl;
					Sleep(500);
					ofstream setuse("Temp\\UserInformation.ini");
					setuse << setinname << endl
						   << addpd(setpasswd);
					setuse.close();
					cout << "Complete!" << endl;
					cout << "Please press any key to re-login." << endl;
					getch();
					cls();
					User();
					Gs += 5;
					return;
				}
				else
				{
					cout<<"The password is not same,please try again."<<endl;
					cout<<"Please press any key to continue"<<endl;
					getch();
					return;
				}
			}
		}
	}
	else if (setans == '4')
	{
		cls();
		cout<<"Are you sure you want to cancel this account?"<<endl;
		cout<<"If you cancel, all data under your account will be deleted"<<endl;
		cout<<"Please press any key to continue"<<endl;
		getch();
		cout<<"Please input 1 to confirm"<<endl;
		string nihaowoyouyigemaoshan1;
		cin>>nihaowoyouyigemaoshan1;
		if(nihaowoyouyigemaoshan1=="1")
		{
			string logoutn,logoutp;
			cout<<"Please input your uername and password to confirm"<<endl;
			cout<<"Username:";
			cin>>logoutn;
			cout<<"Password:";
			cin>>logoutp;
			ifstream outuser("Temp\\UserInformation.ini");
			string outname, outpasswd;
			outuser >> outname >> outpasswd;
			outuser.close();
			if(logoutn!=outname || addpd(logoutp)!=outpasswd)
			{
				cout<<"Your username or password is not correct,please try again"<<endl;
				cout<<"Please press any key to continue"<<endl;
				getch();
				cls();
				return ;
			}
			else
			{
				cout<<"Are you sure?"<<endl;
				cout<<"This is the last warning!"<<endl;
				cout<<"Press 1 to continue"<<endl;
				string nihaowoyouyigemaoshan2;
				cin>>nihaowoyouyigemaoshan2;
				if(nihaowoyouyigemaoshan2=="1")
				{
					Write_regedit(0);
					cout<<"delete Computer/HKEY_CURRENT_USER/Software/ASheepBoy/ASheepBoy"<<endl;
					cout<<"Loading";
					for(int i=1;i<=3;i++)
					{
						cout<<'.';
						Sleep(300);
					}
					cout<<endl;
					cout<<"delete Temp/UserInformation.ini:";
					if(remove("Temp\\UserInformation.ini")==0) cout<<"Success"<<endl;
					else cout<<"Failed"<<'('<<remove("Temp\\UserInformation.bat")<<')'<<endl;
					
					cout<<"delete Temp/GameWindowInformation.bat:";
					if(remove("Temp\\GameWindowInformation.bat")==0) cout<<"Success"<<endl;
					else cout<<"Failed"<<'('<<remove("Temp\\GameWindowInformation.bat")<<')'<<endl;
					
					cout<<"delete Temp/GameInformation.ini:";
					if(remove("Temp\\GameInformation.ini")==0) cout<<"Success"<<endl;
					else cout<<"Failed"<<'('<<remove("Temp\\GameInformation.bat")<<')'<<endl;
					
					cout<<"delete Temp/Regedit.reg:";
					if(remove("Temp\\Regedit.reg")==0) cout<<"Success"<<endl;
					else cout<<"Failed"<<'('<<remove("Temp\\Regedit.bat")<<')'<<endl;
					
					cout<<"delete Temp/Developer_mod.ini:";
					if(remove("Temp\\Developer_mod.ini")==0) cout<<"Success"<<endl;
					else cout<<"Failed"<<'('<<remove("Temp\\Developer_mod.bat")<<')'<<endl;
					
					cout<<"delete Temp/Title.ini:";
					if(remove("Temp\\Title.ini")==0) cout<<"Success"<<endl;
					else cout<<"Failed"<<'('<<remove("Temp\\Title.bat")<<')'<<endl;
					

					cout<<endl<<"Complete!"<<endl;
					cout<<endl<<"Please press any key to restart"<<endl;
					getch();
					exit(0);
				}
				else
				{
					cls();
					return;
				}
			}
		}
		else
		{
			cls();
			return ;
		}
	}
	//UserInformation.ini(Username&Userpassword)
	//GameInformation.ini(Gamescore)
	//Title.ini
	/*const string folderPath;
ShellExecuteA(NULL, "open", folderPath.c_str(), NULL, NULL, SW_SHOW);*/
	else if (setans == '5')//export
	{
		cls();
		cout<<"Are you sure to export you Game Information"<<endl;
		cout<<"0.No 1.Yes"<<endl;
		string setans5;
		cin>>setans5;
		if(setans5=="1")
		{
			cls();
			cout<<"Please wait..."<<endl;
			string username,userpassword;
			ifstream userinformation_input("Temp\\UserInformation.ini");
			if(userinformation_input.is_open())
			{
				userinformation_input>>username>>userpassword;
				userinformation_input.close();
				ofstream Export("Export_Data.expd");
				Export<<username<<endl<<userpassword<<endl;
				Export<<Title<<endl;
				for(int i=1;i<100000000;i++)
				{
					Export<<'*';
					if(i==Gs)
					{
						Export<<'G';
						continue;
					}
					if(i%1000000==0)
					{
						cls();
						cout<<"Please wait..."<<endl;
						cout<<i/1000000<<'%'<<endl;
					}
				}
				cout<<"Success"<<endl;
				Export.close();
				cout<<endl<<"Export Success"<<endl;
				cout<<"Please press any key to continue"<<endl;
				getch();
				const string folderPath;
				ShellExecuteA(NULL, "open", folderPath.c_str(), NULL, NULL, SW_SHOW);
			}
			else
			{
				cout<<"Something went wrong,please try again later..."<<endl;
				userinformation_input.close();
				cout<<"Please press any key to continue"<<endl;
				getch();
			}
		}
	}
	else if (setans == '6')//import
	{
		cls();
		cout<<"Please place the file('Export_Data.expd') in the folder below where you will be checking in"<<endl;
		cout<<"Press any key to open the file"<<endl;
		getch();
		const string folderPath;
		ShellExecuteA(NULL, "open", folderPath.c_str(), NULL, NULL, SW_SHOW);
		cout<<endl;
		setColor(Yellow);
		cout<<"Please press any key to check the file('Export_Data.expd')"<<endl;
		getch();
		setColor(White);
		cout<<"Please wait..."<<endl;
		ifstream export_read("Export_Data.expd");
		cout<<endl;
		string username,userpassword,usertitle;
		char export_Gs_input_check;
		export_read>>username>>userpassword>>usertitle>>export_Gs_input_check;
		if(export_Gs_input_check!='*')
		{
			setColor(Yellow);
			cout<<"The file is invalid"<<endl;
			setColor(White);
			cout<<"Press any key to continue"<<endl;
			getch();
			return;
		}
		if(export_read.is_open())
		{
			setColor(Yellow);
			cout<<"[Warning]Import the file will cover the local data!"<<endl;
			setColor(White);
			cout<<"Whether continue?"<<endl;
			cout<<"0.No 1.Yes"<<endl;
			string exportans;
			cin>>exportans;
			if(exportans=="1")
			{
				cls();
				cout<<"Please wait..."<<endl;
				ofstream userinformation_output("Temp\\UserInformation.ini");
				userinformation_output<<username<<endl<<userpassword;
				userinformation_output.close();
				ofstream usertitle_output("Temp\\Title.ini");
				usertitle_output<<usertitle;
				usertitle_output.close();
				for(int i=1;i<=999995;i++)
				{
					char export_Gs_input;
					export_read>>export_Gs_input;
					if(export_Gs_input=='G')
					{
						Gs=i;
						break;
					}
					if(i%999995==0)
					{
						cls();
						cout<<"Please wait..."<<endl;
						cout<<i/1000000<<'%'<<endl;
					}
				}
				cls();
				cout<<"Please wait..."<<endl;
				cout<<"100%"<<endl;
				ofstream Gamescore_output("Temp\\GameInformation.ini");
				Gamescore_output<<Gs;
				Gamescore_output.close();
				cout<<"Success"<<endl;
				cout<<"Please press any key to restart"<<endl;
				getch();
				exit(0);
			}
			else
			{
				cls();
				return;
			}
		}
		else
		{
			setColor(Yellow);
			cout<<"No files detected"<<endl;
			setColor(White);
			cout<<"Press any key to continue"<<endl;
			getch();
			return;
		}
	}
	cls();
	Gs += 2;
}
void Passwdt()
{
	cls();
	string pst, psj = "";
	int ptimes = 0;
	cout << "Please input your password:";
	getline(cin, pst);
	getline(cin, pst);
	cls();
	cout << "Please wait..." << endl;
	cout << "The command is getting your password..." << endl;
	for (int i = 0; i < pst.size(); i++)
	{
		int cnt = 0;
		bool flag = false;
		for (int j = 0; j < 128; j++)
		{
			if ((char)j == pst[i])
			{
				psj += (char)j;
				flag = true;
				ptimes++;
				Sleep(2);
			}
		}
		if (flag = false)
		{
			psj[i] += pst[i];
		}
	}
	Sleep(1000);
	ptimes += psj.size() + Rand(100);
	if (psj != pst)
		return;
	cout << "Your password is: " << psj << endl
		 << "Used " << ptimes * 10 << " ms" << endl
		 << endl;
	cout << (ptimes > 20 ? "Your password is strong." : "Your password is too easy.") << endl;
	cout << "Please press any key to continue." << endl;
	getch();
	cls();
	Gs += (psj.size() >= 10 ? 4 : 2);
}
void fylcs()
{
    cls();
    std::cout << "This is a Reactivity Test\n"
              << "Press SPACE when the screen color changes!\n"
              << "Press any key to begin...\n";
    _getch();
    cls();
    cout<<"Wait...";
    Sleep(2500);
    system("color 7C");
    cls();
    const DWORD timeout = 3000;
    DWORD start = GetTickCount();
    bool reacted = false;
    while (GetTickCount() - start < timeout)
    {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            reacted = true;
            break;
        }
        Sleep(10);
    }
    system("color 07");
    cls();
    if (reacted)
    {
		DWORD reactionTime = GetTickCount() - start;
		unsigned long long fylcsans=reactionTime;
    	for(int i=5;i>=1;i--)
    	{
	        std::cout << "Success! Reaction time: " << fylcsans << "ms\n"
	                  << "Add " << (fylcsans<=1000 ? fylcsans<=200 ? fylcsans<=100 ? fylcsans<=50 ? fylcsans<=10 ? 20 : 15 :15 :10 :5 : 1) << " points added to your score!\n";
	        Gs += 10;
	        cout<<"Auto exit after " << i << " seconds"<<endl;
	        Sleep(1000);
	        cls();
	    }
    }
    else
    {
    	for(int i=5;i>=1;i--)
    	{
			std::cout << "No response detected. Try to be quicker next time!\n";
	        cout<<"Auto exit after " << i << " seconds"<<endl;
	        Sleep(1000);
	        cls();
	    }
    }
    cls();
}
void DisplayTime(long long h, long long m, long long s)
{
    {
        std::cout << std::setfill('0')
                  << std::setw(2) << h << ":"
                  << std::setw(2) << m << ":"
                  << std::setw(2) << s << "\n";
    }
}
void Timetools()
{
	Gs+=5;
    while (true)
    {
        cls();
        std::cout << "1. Time Countdown\n2. Time Count\nInput 0 to exit\nPlease press the number:";
        string choice;
        cin>>choice;
        if(choice=="1")
        {
        	Gs++;
            cls();
            long long minutes = 0;
            std::cout << "Enter minutes: ";
            while (!(std::cin >> minutes) || minutes < 0)
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                cls();
                std::cout << "Invalid input! Re-enter minutes: ";
            }
            long long h = minutes / 60;
            long long m = minutes % 60;
            long long s = 0;
            while (h >= 0)
            {
                cls();
                DisplayTime(h, m, s);
                std::cout << "Long press ESC to exit\n";

                if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
                {
                    return;
                }
                s--;
                if (s < 0)
                {
                    m--;
                    s = 59;
                }
                if (m < 0)
                {
                    h--;
                    m = 59;
                }
                if (h < 0)
                {
                    cls();
                    std::cout << "Time's up!\nPress any key to continue";
                    _getch();
                    break;
                }
                Sleep(1000);
            }
            break;
        }
        else if(choice=="2")
        {
        	Gs++;
            long long h = 0, m = 0, s = 0;
            bool paused = true;
            while (true)
            {
                cls();
                DisplayTime(h, m, s);
                std::cout << (paused ? "PAUSED (Long press F4:Resume)" : "RUNNING (Long press F2:Pause)")
                          << "\nLong press ESC to exit\n";
                if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
                {
                    return;
                }
                if (GetAsyncKeyState(VK_F2) & 0x8000)
                {
                    paused = true;
                }
                if (GetAsyncKeyState(VK_F4) & 0x8000)
                {
                    paused = false;
                }
                if (!paused)
                {
                    s++;
                    if (s >= 60)
                    {
                        s = 0;
                        m++;
                    }
                    if (m >= 60)
                    {
                        m = 0;
                        h++;
                    }
                }

                Sleep(1000);
            }
            break;
        }
        else
        {
        	return;
		}
    }
}
void Regedit_Check()
{
	int Read_Gamescore_from_Regedit=Read_regedit();
	Gs=Read_Gamescore_from_Regedit;
	ifstream Read_Gamescore("Temp\\GameInformation.ini");
	string Read_Gamescore_String;
	Read_Gamescore>>Read_Gamescore_String;
	int Read_Gamescore_from_File=Read_Gamescore_String.size();
	//Regedit_Value:Read_Gamescore_from_Regedit
	//Local_Value:Read_Gamescore_from_File
	if(Read_Gamescore_from_Regedit!=Read_Gamescore_from_File)
	{
		cout<<"Game score ERROR"<<endl;
		cout<<"  Local Gamescore="<<Read_Gamescore_from_File<<endl;
		cout<<"  Regedit Gamescore="<<Read_Gamescore_from_Regedit<<endl;
		cout<<endl<<"Auto Fixing..."<<endl;
		ofstream Write_to_Local_File("Temp\\GameInformation.ini");
		Write_to_Local_File<<Read_Gamescore_from_Regedit;
		Write_to_Local_File.close();
		cout<<"Success"<<endl;
		cls();
	}
	else
	{
		return;
	}
}
void typingGame()
{
    cls();
    vector<string> sentences = {
        "Hello world",
        "C++ is fun",
        "Type this sentence quickly",
        "ASheepBoy",
        "#include <iostream>",
        "#include <bits/stdc++.h>",
        "using namespace std;",
        "int main()",
        "return 0;",
		"asdfghjkl;'"};
    string text = sentences[rand() % sentences.size()];
    cout << "Type the following:\n\n"
         << text << "\n\nPress Enter to start...";
    getch();
    cls();
    cout << "GO!\n\n"
         << text << endl;
    auto start = chrono::high_resolution_clock::now();
    string input;
    getline(cin, input);
    getline(cin, input);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration<double>(end - start).count();
    int correct = 0;
    for (int i = 0; i < min(text.size(), input.size()); i++)
    {
        if (text[i] == input[i])
        {
            correct++;
        }
    }
    double accuracy = (double)correct / text.size() * 100;
    int score = 0;
    score += (accuracy == 100 ? 5 : (accuracy == 0 ? 0 : 3));
    Gs += score;
    cout << "\nTime: " << time << "s | Accuracy: " << accuracy << "%" << endl;
    cout << "Score: +" << score << " points!" << endl;
    getch();
    cls();
}
void memoryGame()
{
    cls();
    cout << "Memory Game: Remember the numbers!" << endl;
    cout << "Press any key to start...";
    getch();
    long long difficulty;
    while (1)
    {
        cout << endl;
        cout << "Please choose the difficulty level (1-10):";
        cin >> difficulty;
        if (difficulty < 1 || difficulty > 10)
        {
            cout << "Invalid difficulty level.Please re-input" << endl;
        }
        else
        {
            cout << "You have chosen difficulty level " << difficulty << endl;
            break;
        }
    }
    cout << "You will see " << difficulty << " numbers and input them again" << endl;
    cout << "Please press any key to continue" << endl;
    getch();
    vector<int> numbers;
    for (int i = 0; i < difficulty; i++)
    {
        numbers.push_back(rand() % 10);
    }
    cls();
    cout << "\nNumbers: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }
    Sleep(2000);
    cls();
    cout << "Enter the numbers (separated by spaces):";
    vector<int> userInput;
    for (int i = 0; i < difficulty; i++)
    {
        int input;
        cin >> input;
        userInput.push_back(input);
    }
    if (userInput == numbers)
    {
        cout << "Correct! +5 points." << endl;
        Gs += 5;
    }
    else
    {
        cout << "Wrong! The numbers were: ";
        for (int num : numbers)
        {
            cout << num << " ";
        }
        Gs += 1;
    }
    getch();
    cls();
}
void First_Open_Check()
{
	ifstream foc("Temp\\UpDateTemp.ini");
	if(!foc.is_open())
	{
		UsingInformation();
	}
}
void Shop()
{
	cls();
	//LightYellow/LightBlue/LightGreen/White
	cout<<"Welcome to ASheepBoy's shop!"<<endl;
	cout<<"On sale products:"<<endl;
	cout<<endl;
	setColor(LightYellow);cout<<"1.Custom Title card   12000Gs"<<endl;setColor(White);
	setColor(LightBlue);cout<<"2.Name-changing card   5000Gs"<<endl;setColor(White);
	
	cout<<"0.Exit";
	cout<<endl;
	cout<<"Please input product number:";
	string shopans;
	cin>>shopans;
	if(shopans=="0")
	{
		cls();
		return;
	}
	else if(shopans=="1")
	{
		cls();
		cout<<"Are you sure to exchange 'Name-changing card'"<<endl;
		cout<<"1.I'm sure"<<endl;
		cout<<"2.Not certain"<<endl;
		cin>>shopans;
		if(shopans=="1")
		{
			if(Gs<12000)
			{
				cout<<"Game score are not enough!"<<endl;
				cout<<"Please input any key to contiune"<<endl;
				getch();
				Shop();
				return;
			}
			cls();
			cout<<"Please input your title:";
			string shoptitle;
			cin>>shoptitle;
			if(shoptitle=="Admin")
			{
				cls();
				cout<<"The Title is forbidden"<<endl;
				cout<<"Please press any key to continue"<<endl;
				char shoptitlef = getch();
				if(shoptitlef=='a')
				{
					cls();
					cout<<"Please press any key to continue"<<endl;
					shoptitlef = getch();
					if(shoptitlef=='s')
					{
						cls();
						cout<<"Please press any key to continue"<<endl;
						shoptitlef = getch();
						if(shoptitlef=='h')
						{
							cls();
							cout<<"Please press any key to continue"<<endl;
							shoptitlef = getch();
							if(shoptitlef=='e')
							{
								cls();
								cout<<"Please press any key to continue"<<endl;
								shoptitlef = getch();
								if(shoptitlef=='e')
								{
									cls();
									cout<<"Please press any key to continue"<<endl;
									shoptitlef = getch();
									if(shoptitlef=='p')
									{
										cls();
										cout<<"Please press any key to continue"<<endl;
										shoptitlef = getch();
										if(shoptitlef=='b')
										{
											cls();
											cout<<"Please press any key to continue"<<endl;
											shoptitlef = getch();
											if(shoptitlef=='o')
											{
												cls();
												cout<<"Please press any key to continue"<<endl;
												shoptitlef = getch();
												if(shoptitlef=='y')
												{
													cout<<"Success"<<endl;
													getch();
												}
												else
												{
									 				Shop();
													return;
												}
											}
											else
											{
								 				Shop();
												return;
											}
										}
										else
										{
							 				Shop();
											return;
										}
									}
									else
									{
						 				Shop();
										return;
									}
								}
								else
								{
					 				Shop();
									return;
								}
							}
							else
							{
				 				Shop();
								return;
							}
						}
						else
						{
			 				Shop();
							return;
						}
					}
					else
					{
		 				Shop();
						return;
					}
				}
				else
				{
	 				Shop();
					return;
				}
			}
			cout<<"Preview:"<<endl;
			if(shoptitle=="Admin")
			{
				setColor(Red);
				cout<<'('<<shoptitle<<')';
				setColor(White);
			}
			else
			{
				setColor(LightBlue);
				cout<<'('<<shoptitle<<')';
				setColor(White);
			}
			cout<<Username<<endl;
			cout<<endl;
			cout<<"Are you sure to change the title?"<<endl;
			cout<<"1.Yes"<<endl<<"0.No"<<endl;
			string shoptitleans;
			cin>>shoptitleans;
			if(shoptitleans=="1")
			{
				Gs-=12000;
				ofstream titout("Temp\\Title.ini");
				titout<<shoptitle;
				titout.close();
				Title=shoptitle;
				cout<<endl;
				cout<<"Success"<<endl;
				cout<<"Please press any key to continue";
				getch();
				return;
			}
			else
			{
				Shop();
				return;
			}
		}
		else
		{
			Shop();
			return;
		}
	}
	else if(shopans=="2")
	{
		cls();
		cout<<"Are you sure to exchange 'Name-changing card'"<<endl;
		cout<<"1.I'm sure"<<endl;
		cout<<"2.Not certain"<<endl;
		cin>>shopans;
		if(shopans=="1")
		{
			if(Gs<5000)
			{
				cout<<"Game score are not enough!"<<endl;
				cout<<"Please input any key to contiune"<<endl;
				getch();
				Shop();
				return;
			}
			cls();
			cls();
			cout<<"Please input your old user name:";
			string Setting_Username,Setting_Userpassword;
			cin>>Setting_Username;
			cout<<"Please input your password:";
			cin>>Setting_Userpassword;

			ifstream Setting_Userpassword_input_from_file("Temp\\UserInformation.ini");
			string Username_file, Userpassword_file;
			Setting_Userpassword_input_from_file >> Username_file >> Userpassword_file;
			Setting_Userpassword_input_from_file.close();
			if(Setting_Username==Username_file && addpd(Setting_Userpassword)==Userpassword_file)
			{
				cout << "Please input your new user name:";
				string Setting_new_username;
				cin>>Setting_new_username;
				cout<<"Wait..."<<endl;
				Gs-=5000;
				Sleep(100);
				ofstream Setting_change("Temp\\UserInformation.ini");
				Setting_change << Setting_new_username << endl << Userpassword_file;
				Setting_change.close();
				cout << "Complete!" << endl;
				cout << "Please press any key to re-login." << endl;
				getch();
				cls();
				User();
				Gs += 5;
				return;
			}
			else
			{
				cout<<"The username or password is not same,please try again."<<endl;
				cout<<"Please press any key to continue"<<endl;
				getch();
				return;
			}
		}
		else
		{
			Shop();
			return;
		}
	}
	
	else
	{
		Shop();
		return;
	}
}
void Titleoutput()
{
	cout<<"Welcome,";
	if(Title!="(None)")
	{
		if(Title=="Admin")
		{
			setColor(Red);
			cout<<'('<<Title<<')';
			setColor(White);
		}
		else
		{
			setColor(LightBlue);
			cout<<'('<<Title<<')';
			setColor(White);
		}
	}
	cout<<Username<<'!'<<endl;
}
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
POINT p;
HWND h = GetForegroundWindow();

int main()
{
	First_Open_Check();
	SetWindow();
	UpDate();
	User();
	Regedit_Check();
	while (1)
	{
		Write_regedit(Gs);
		cls();
		SYSTEMTIME sys;
		GetLocalTime(&sys);
		Titleoutput();
		setColor(Green); cout <<"Current version:"<< GVS <<endl; setColor(White);
		printf("Now system time:%4d/%02d/%02d %02d:%02d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute);
		if(Developer)
		{
			setColor(LightRed); cout<<"WARNING Developer mod is open!"<<endl; setColor(White);
		}
		else cout<<endl;
		//Achievement
		cout << "1.ASheepBoy's Shop" << endl;
		cout << "2.About" << endl;
		cout << "3.Little Game" << endl;
		cout << "4.Practical tools" << endl;
		cout << "5.Texting tools" << endl;

		// add here
		cout << endl;
		
		cout << "Your Game score is ";
		setColor(LightBlue); cout<<Gs<<endl; setColor(White);
		cout << "Please input the folder number:";
		cin >> ans;
		if (ans == "0")
		{
			ofstream ogi("Temp\\GameInformation.ini");
			ogi << Gsaj(Gs);
			Write_regedit(Gs);
			cls();
			if(Developer)
			{
				getch();
			}
			return 0;
		}
		else if (ans == "1")
		{
			Shop();
		}
		else if (ans == "2")
		{
			cls();
			cout << "About:" << endl;
			cout << "  1.Help" << endl;
			cout << "  2.What's New" << endl;
			cout << "  3.Game Using Information" << endl;
			cout << "  4.Settings" << endl;
			cout << endl;
			cout << "Input 0 to exit" << endl;
			cout << "Please input the number:";
			cin >> ans;
			if (ans == "1")
				help();
			else if (ans == "2")
				Uptempnew();
			else if (ans == "3")
				UsingInformation();
			else if (ans == "4")
				Settings();
			else
				continue;
		}
		else if (ans == "3")
		{
			cls();
			cout << "Little Game:" << endl;
			cout << "  1.Stone Scissors And Cloth" << endl;
			cout << "  2.Hide And Seek" << endl;
			setColor(Yellow);cout << "  3.Do Not Press" << endl;setColor(White);
			cout << "  4.Guess Number" << endl;
			cout << "  5.Memory Game" << endl;
			cout << endl;
			cout << "Input 0 to exit" << endl;
			cout << "Please input the number:";
			cin >> ans;
			if (ans == "1")
				rock();
			else if (ans == "2")
				find8();
			else if (ans == "3")
				Surprise();
			else if (ans == "4")
				Guess();
			else if (ans == "5")
				memoryGame();
			else
				continue;
		}
		else if (ans == "4")
		{
			cls();
			cout << "Practical tools:" << endl;
			cout << "  1.Create Files" << endl;
			cout << "  2.Calculator" << endl;
			cout << "  3.Mouse linker" << endl;
			cout << "  4.Time Tools" << endl;
			cout << "  5.Typing Speed Test" << endl;
			cout << endl;
			cout << "Input 0 to exit" << endl;
			cout << "Please input the number:";
			cin >> ans;
			if (ans == "1")
				create();
			else if (ans == "2")
				calculator();
			else if (ans == "3")
				Mousefp();
			else if (ans=="4")
			 	Timetools();
			else if (ans=="5")
				typingGame();
			else
				continue;
		}
		else if (ans == "5")
		{
			cls();
			cout << "Texting tools:" << endl;
			cout << "  1.Password Text" << endl;
			cout << "  2.Reactivity Test" << endl;
			cout << endl;
			cout << "Input 0 to exit" << endl;
			cout << "Please input the number:";
			cin >> ans;
			if (ans == "1")
				Passwdt();
			else if (ans == "2")
				fylcs();
			else
				continue;
		}

		// add here
		else
			cls();
	}
}


