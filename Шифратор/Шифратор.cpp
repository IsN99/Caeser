#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

string Alphabet;

int CryptKey() {
	int K;
	cout << "Введи ключ" << endl;
	cin >> K;
	return K;
}


string Decrypting(string temp) {
	
	int Key = CryptKey();
	int alen = Alphabet.length();
	int tlen = temp.size();
	for (int i = 0; i < tlen; i++) {
		for (int j = 0; j < alen; j++) {
			if (temp[i] == Alphabet[j]) {
				temp[i] = Alphabet[((j - Key ) % alen + alen) % alen];
				break;
			}
		}
	}
	return temp;
}

string Crypting(string temp) {
	
	int Key = CryptKey();
	for (int i = 0; i < temp.length(); i++) {
		for (int j = 0; j < Alphabet.length(); j++) {
			if (temp[i] == Alphabet[j]) {
				temp[i] = Alphabet[(j + Key) % Alphabet.length()];
				break;
			}
		}
	}
	return temp;
}


string Paste_Text() {
	cout << "\nВставь текст\n\n";
	string original_text;
	SetConsoleCP(1251);
	cin.ignore();
	getline(cin, original_text);
	return original_text;
	SetConsoleCP(866);
}


string CryptFoo() {
	string N = Paste_Text();
	cout << "\n\n";
	string C = Crypting(N);
	return C;
}

string DecryptFoo() {
	string N = Paste_Text();
	cout << "\n\n";
	string S = Decrypting(N);
	return S;
}


int menu () {
	cout << "1) Криптор \n2) Декриптор \n\n" << endl;
	int select;
	cin >> select;
	return select;
}

void Quite() {
		cout << "Введите любой символ для того чтобы завершить\n\n";
	int a;
	cin >> a;
}


int main() {
	setlocale(LC_ALL, "Russian");
	Alphabet = "0123456абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,\";-_?!@#№";
	string(*foo)() {};
	switch (menu()) {
	case 1:
		foo = CryptFoo;
		cout << foo() << endl << endl;
		break;
	case 2:
		foo = DecryptFoo;
		cout << foo() << endl << endl;
		break;
	default:
		cout << "Ошибка" << endl << endl;
		break;
	}
	Quite();
	return 0;
}