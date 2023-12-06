#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum vectorStatus
{
	TEXT,
	ENCRYPTED_TEXT,
	KEY
};

void VigenereCypherCoding(vector<string>& text_and_encrypted_text)
{
	setlocale(LC_ALL, "Russian");
	string message, key;

	std::cin.clear();
	cout << "������� �����, ������� ���� ����������� �� ����������: ";
	getline(cin, message);//���� ���������
	

	text_and_encrypted_text.push_back(message);//��������� ��������� � ������ TEXT
	text_and_encrypted_text.push_back(message);//��������� ��������� � ������ ��� �������� ENCRYPTED_TEXT
	
	cout << "������� ����: ";
	getline(cin, key); //���� ���������
	std::cin.clear();

	if (key.size() > text_and_encrypted_text[TEXT].size())//�������� �� ������ ����� � ���������� ���������
	{
		key.erase(text_and_encrypted_text[TEXT].size()); // ���� ���� > ��������� ��������� - ������� ���� �� ������� ������
	}
	else if (key.size() < text_and_encrypted_text[TEXT].size()) // ���� ���� < ��������� ��������� - ��������� ������ ����� �� ������� ������
	{
		int counter = text_and_encrypted_text[TEXT].size() - key.size(); //������� ����� �������� ���������� ��������� � �������� �����

		for (int i = 0; i < counter; i++)
		{
			key += key[i];
		}
	}

	text_and_encrypted_text.push_back(key); //������� ���� � ������ KEY

	int table_difference_ascii; // ���������� ��� ������� ������� ����� ���������� � ASCII �������, �.� ������ ������������ � �������

	for (int i = 0; i < text_and_encrypted_text[TEXT].size(); i++)
	{
		if (int(text_and_encrypted_text[KEY][i]) >= int('a') && int(text_and_encrypted_text[KEY][i]) <= int('z')) // ������ a-z
		{
			table_difference_ascii = int(text_and_encrypted_text[KEY][i]) % int('a');
		}
		else if (int(text_and_encrypted_text[KEY][i]) >= int('A') && int(text_and_encrypted_text[KEY][i]) <= int('Z')) // ������ A-Z
		{
			table_difference_ascii = int(text_and_encrypted_text[KEY][i]) % int('A');
		}
		else
		{
			cout << "��������� ���� ����!" << endl;
			break;
		}
		text_and_encrypted_text[ENCRYPTED_TEXT][i] += table_difference_ascii;
	}
	cout << "����������� �����: " << endl;
	cout << text_and_encrypted_text[TEXT] << endl;
	cout << "���������� ����: " << endl;
	cout << text_and_encrypted_text[KEY] << endl;
	cout << "���������� ������������ �����: " << endl;
	cout << text_and_encrypted_text[ENCRYPTED_TEXT] << endl;

	if (text_and_encrypted_text.size() != 0)
	{
		text_and_encrypted_text.clear();
	}
}


void VigenereCypherDeoding(vector<string>& text_and_encrypted_text)
{
	setlocale(LC_ALL, "Russian");
	string message, key;

	std::cin.clear();
	cout << "������� ������������� �����: ";
	getline(cin, message);//���� ���������


	text_and_encrypted_text.push_back(message);//��������� ��������� � ������ TEXT
	text_and_encrypted_text.push_back(message);//��������� ��������� � ������ ��� �������� ENCRYPTED_TEXT

	cout << "������� ����: ";
	getline(cin, key); //���� ���������
	std::cin.clear();

	if (key.size() > text_and_encrypted_text[ENCRYPTED_TEXT].size())//�������� �� ������ ����� � ���������� ���������
	{
		key.erase(text_and_encrypted_text[ENCRYPTED_TEXT].size()); // ���� ���� > ��������� ��������� - ������� ���� �� ������� ������
	}
	else if (key.size() < text_and_encrypted_text[ENCRYPTED_TEXT].size()) // ���� ���� < ��������� ��������� - ��������� ������ ����� �� ������� ������
	{
		int counter = text_and_encrypted_text[ENCRYPTED_TEXT].size() - key.size(); //������� ����� �������� ���������� ��������� � �������� �����

		for (int i = 0; i < counter; i++)
		{
			key += key[i];
		}
	}

	text_and_encrypted_text.push_back(key); //������� ���� � ������ KEY

	int table_difference_ascii; // ���������� ��� ������� ������� ����� ���������� � ASCII �������, �.� ������ ������������ � �������

	for (int i = 0; i < text_and_encrypted_text[ENCRYPTED_TEXT].size(); i++)
	{
		if (int(text_and_encrypted_text[KEY][i]) >= int('a') && int(text_and_encrypted_text[KEY][i]) <= int('z')) // ������ a-z
		{
			table_difference_ascii = int(text_and_encrypted_text[KEY][i]) % int('a');
		}
		else if (int(text_and_encrypted_text[KEY][i]) >= int('A') && int(text_and_encrypted_text[KEY][i]) <= int('Z')) // ������ A-Z
		{
			table_difference_ascii = int(text_and_encrypted_text[KEY][i]) % int('A');
		}
		else
		{
			cout << "��������� ���� ����!" << endl;
			break;
		}
		text_and_encrypted_text[TEXT][i] -= table_difference_ascii;
	}

	cout << "���������� ������������� ���������: " << endl;
	cout << text_and_encrypted_text[ENCRYPTED_TEXT] << endl;
	cout << "���������� ����: " << endl;
	cout << text_and_encrypted_text[KEY] << endl;
	cout << "����������� �����: " << endl;
	cout << text_and_encrypted_text[TEXT] << endl;

	if (text_and_encrypted_text.size() != 0)
	{
		text_and_encrypted_text.clear();
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");

	vector<string> text_and_encrypted_text;
	VigenereCypherCoding(text_and_encrypted_text);

	cout << "---------------" << endl;

	VigenereCypherDeoding(text_and_encrypted_text);

	return 0;
}