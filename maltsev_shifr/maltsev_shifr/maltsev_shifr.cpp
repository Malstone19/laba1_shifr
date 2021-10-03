#include <iostream>
#include <fstream>
using namespace std;

void encryption(string output_file, string input_file, string password)
{
    char letter;
    ofstream output;
    ifstream input;
    output.open(output_file + ".txt", ios::binary);
    input.open(input_file + ".txt", ios::binary);
    int number = 0;
    while (true)
    {
        if (input.eof())
        {
            input.close();
            output.close();
            break;
        }
        input.get(letter);
        output << (unsigned char)(letter + password[number % password.length()]);
        number++;
    }
}

void decryption(string output_file, string input_file, string password)
{
    char letter;
    ofstream output;
    ifstream input;
    output.open(output_file + ".txt", ios::binary);
    input.open(input_file + ".txt", ios::binary);
    int number = 0;
    while (true)
    {
        if (input.eof())
        {
            input.close();
            output.close();
            break;
        }
        input.get(letter);
        output << (unsigned char)(letter - password[number % password.length()]);
        number++;
    }
}

void create_files_and_password(string& input_file, string& output_file, string& password)
{
    cout << "Входной файл: ";
    cin >> input_file;
    cout << "Выходной файл: ";
    cin >> output_file;
    cout << "Пароль: ";
    cin >> password;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    string password, input_file, output_file;
    cout << "зашифровать файл на 1" << endl;
    cout << "расшифровать файл на 2" << endl;
    int command;
    cin >> command;
    switch (command)
    {
    case 1:
    {
        create_files_and_password(input_file, output_file, password);
        encryption(output_file, input_file, password);
        break;
    }
    case 2:
    {
        create_files_and_password(input_file, output_file, password);
        decryption(output_file, input_file, password);
        break;
    }
    }
}