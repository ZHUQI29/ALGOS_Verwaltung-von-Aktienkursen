#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


int main()
{
	// 读文件 Datei lesen
	ifstream inFile("/Users/zhuqi/Desktop/ALGOS/Aufgabe1/MSFT.csv", ios::in);
	string lineStr;
	vector<vector<string> > strArray;
	while (getline(inFile, lineStr))
	{
		// 打印整行字符串ganze Zeile des Strings drucken
		cout << lineStr<<'\n' << endl;
		// 存成二维表结构Als zweidimensionale Tabellenstruktur speichern
		stringstream ss(lineStr);
		string str;
		vector<string> lineArray;
		// 按照逗号分隔durch Komma getrennt
		while (getline(ss, str, ' '))
			lineArray.push_back(str);
		strArray.push_back(lineArray);
	}

	getchar();
	return 0;
}
