#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

char encryptChar(char ch, int key)
{
    if (isalpha(ch))
    {
        bool isUpper = isupper(ch);
        char base = isUpper ? 'A' : 'a';
        return base + (ch - base + key) % 26; // Исправленная строка
    }
    else
    {
        return ch;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    string inputFilename, outputFilename;
    int key;

    cout << "Введите имя исходного файла: ";
    cin >> inputFilename;
    cout << "Введите имя файла для зашифрованного текста: ";
    cin >> outputFilename;
    cout << "Введите ключ (сдвиг): ";
    cin >> key;

    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        for (char& c : line) {
            c = encryptChar(c, key);
        }
        outputFile << line << endl;
    }

    cout << "Текст зашифрован и записан в файл " << outputFilename << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
