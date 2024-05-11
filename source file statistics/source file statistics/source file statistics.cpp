#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string inputFilename, outputFilename;

    cout << "Введите имя исходного файла: ";
    cin >> inputFilename;
    cout << "Введите имя файла для статистики: ";
    cin >> outputFilename;

    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    string line;
    while (getline(inputFile, line))
    {
        lineCount++;
        for (char c : line)
        {
            charCount++;
            if (isdigit(c))
            {
                digitCount++;
            }
            else if (isalpha(c))
            {
                char lowerC = tolower(c);
                if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u')
                {
                    vowelCount++;
                }
                else
                {
                    consonantCount++;
                }
            }
        }
    }

    outputFile << "Статистика файла " << inputFilename << ":" << endl;
    outputFile << "Количество символов: " << charCount << endl;
    outputFile << "Количество строк: " << lineCount << endl;
    outputFile << "Количество гласных букв: " << vowelCount << endl;
    outputFile << "Количество согласных букв: " << consonantCount << endl;
    outputFile << "Количество цифр: " << digitCount << endl;

    cout << "Статистика записана в файл " << outputFilename << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
