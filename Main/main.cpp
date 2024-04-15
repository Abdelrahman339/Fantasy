#pragma execution_character_set("utf-8")
#include <iostream>
#include <fcntl.h>
#include <io.h>
using namespace std;
int main(){
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	cout << "don't forget to delete your code after test it." << endl;
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////


	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"①" << endl;
	wcout << L"②     ③     ④      ⑤" << endl;
	wcout << L"⑥     ⑦     ⑧      " << endl;
	wcout << L"⑨     ⑩     ⑪      " << endl;
	wcout << L"①" << endl;
	wcout << L"②     ③     ④   " << endl;
	wcout << L"⑤     ⑥     ⑦     ⑧      " << endl;
	wcout << L"⑨     ⑩     ⑪      " << endl;

}