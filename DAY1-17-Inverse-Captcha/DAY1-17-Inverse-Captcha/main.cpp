#include <iostream>
#include <string> //для строковой переменной
#include <fstream> // чтение и запись в файл

using namespace std;

int main()
{
    string line {};
    // открываем файл для чтения
    ifstream in("DAY1-17-Inverse-Captcha-input.txt");
    int sum{};

    //  . открываем поле доп информации
    if (in.is_open())
    {
        while (getline(in, line))
        {
            // ? почему хранить в билд
        }
    }
    in.close();// закрываем файл

//    int firstNumber = line[0] - '0';

    for(size_t i{};i < line.length();i++) {
        if (line[i] == line[(i+line.length()/2)%line.length()]) sum += (line[i]-'0');

        // вывод число сумму
        //cout << "i = " << i << " sum = " << sum << endl;
    }








    cout << "sum " << sum;

    return 0;
}
