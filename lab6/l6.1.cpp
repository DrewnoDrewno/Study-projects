// zadanie1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#pragma warning(disable : 4996)  
using namespace std;
class LFile
{
public:
	static int return_num_fopen();
	LFile();
	LFile(string);
	void reopen(string);
	~LFile();
	void close_file();
	int read_file(void *ptr, size_t size, size_t nitems);
	int write_file(const void *ptr, size_t size, size_t nitems);

private:
	static int counter;
	//string file_name;
	FILE * file_ptr;

};
int LFile::counter = 0;
int main()
{
	try
	{
		LFile myFile("dane.txt");
		LFile myFile1("dane1.txt");
		LFile myFile2("dane2.txt");
		LFile myFile3("dane3.txt");
		LFile myFile4("dane4.txt");
		LFile myFil5("dane5.txt");
		cout << LFile::return_num_fopen() << endl;
		throw runtime_error("Cos sie popsulo");
	}
	catch (string &error)
	{
		cout << error << endl;
	}
	catch (runtime_error)
	{
		cout << LFile::return_num_fopen() << endl;
		cout << "odebranie bledu" << endl;
	}
	cout << LFile::return_num_fopen() << endl;
	cout << "tu wyglada wszysko dobrze" << endl;
    return 0;
}
LFile::LFile() {};
int LFile::return_num_fopen()
{
	return counter;
}

LFile::LFile(string file_n)
{
	file_ptr = 0;
	if (counter == 5)
	{
		cout << "Nie mozna otworzyc zbyt duzej ilości plikow." << endl;
		this->file_ptr = 0;
		//return;
	}
	else
	{
		counter++;
		if (!(file_ptr = fopen(file_n.c_str(), "a+")))
		{
			cout << "Blad otwarcia pliku:" << file_n << endl;
			counter--;
			//exit(1); //other instructions 
			//this->file_ptr = 0;
		}

	}


}
void LFile::reopen(string file_n)
{
	if (file_ptr)
	{
		cout << "Nie można otworzyc danego pliku, przed zamknieciem poprzedniego.";
		return;
	}
	LFile::LFile(file_n);
}
void LFile::close_file()
{
	fclose(file_ptr);
}
int LFile::read_file(void *ptr, size_t size, size_t nitems)
{
	return fread(ptr, size, nitems, file_ptr);
}
int LFile::write_file(const void *ptr, size_t size, size_t nitems)
{
	return fwrite(ptr, size, nitems, file_ptr);
}
LFile::~LFile()
{
	if (file_ptr)
	{
		LFile::close_file();
		counter--;
	}
}


