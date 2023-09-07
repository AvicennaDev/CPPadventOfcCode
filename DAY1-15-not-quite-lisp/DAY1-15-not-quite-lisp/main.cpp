#include <iostream>
#include <fstream> // чтение и запись в файл
#include <string> //для строковой переменной

using namespace std;

int main()
{
    // запись в переменную line
    string line{};
    ifstream in("input.txt"); // окрываем файл для чтения

    if (in.is_open())
    {
        while (getline(in, line))
        {
            //cout << line << endl;
        }
    }
    in.close();// закрываем файл

    int floor{};
    // size_t разновидность int, i увеличивать до конца длины файла(строки)
    for (size_t i {}; i < line.length(); i++) { //. дает доступ к содержимому
        // сравнение элемента строки с символом
        if (line[i] == '(') {
            floor++;
        }
        else {
            floor--;
        }
        if (floor == -1) {
            cout << "i = " << i+1; // массив начинается с 0 эл., вывести номер шага на котором он попал в подвал
            return 0;
        }
    }
    cout << "floors = " << floor; //  для 1 части. вывод последнего номера этажа на которм остановился
    return 0;
}
