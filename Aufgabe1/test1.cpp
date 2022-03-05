#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void import(){
	// 读文件 Datei lesen
	std::cout << "Ziehen Sie per Drag&Drop die Datei für den import" << '\n';
	string str;
	std::cin >> str;
	std::cout << std::endl;

	ifstream inFile(str, ios::in);
	if( inFile.fail( ) ) {
            cerr << "Error: Datei nicht gefunden oder kann nicht geöffnet werden" << str <<endl<< endl;
            import();  // Error;
        }
	// ifstream inFile("/Users/zhuqi/Desktop/ALGOS/Aufgabe1/MSFT.csv", ios::in);
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
}
char frage(){
	char a;
	std::cout << "1. ADD 2. DEL 3. IMPORT 4. SEARCH 5. PLOT 6. SAVE 7. LOAD 8. QUIT" << '\n';
	std::cin >>a;
	return a;
}

int main()
{
	int i=1;
	while(i){
		switch (frage()) {
			case '1':std::cerr << "noch nicht schreiben" << '\n';break;
			case '2':std::cerr << "noch nicht schreiben" << '\n';break;
			case '3':import();break;
			case '4':std::cerr << "noch nicht schreiben" << '\n';break;
			case '5':std::cerr << "noch nicht schreiben" << '\n';break;
			case '6':std::cerr << "noch nicht schreiben" << '\n';break;
			case '7':std::cerr << "noch nicht schreiben" << '\n';break;
			case '8':i=0;break;
		}
	}


	getchar();
	return 0;
}
