#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string filename1, filename2;

    // test1.txt, test2.txt (2 текстовых файла)
    cout << "Введите имя первого файла(.txt): ";
    cin >> filename1;
    cout << "Введите имя второго файла(.txt): ";
    cin >> filename2;

    ifstream file1(filename1);
    ifstream file2(filename2);

    if (!file1.is_open() || !file2.is_open())
    {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    string line1, line2;
    int lineNumber = 1;
    bool filesAreEqual = true;

    while (getline(file1, line1) && getline(file2, line2))
    {
        if (line1 != line2)
        {
            cout << "Файлы отличаются в строке " << lineNumber << ":" << endl;
            cout << "Файл 1: " << line1 << endl;
            cout << "Файл 2: " << line2 << endl;
            filesAreEqual = false;
            break;
        }
        lineNumber++;
    }

    if (getline(file1, line1))
    {
        cout << "Файл 1 содержит дополнительные строки после строки " << lineNumber << endl;
        filesAreEqual = false;
    }
    else if (getline(file2, line2))
    {
        cout << "Файл 2 содержит дополнительные строки после строки " << lineNumber << endl;
        filesAreEqual = false;
    }

    if (filesAreEqual)
    {
        cout << "Файлы идентичны." << endl;
    }

    file1.close();
    file2.close();

    return 0;
}
