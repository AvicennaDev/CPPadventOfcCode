#include <iostream>
#include <string> // для строковой переменной
#include <fstream>

using namespace std;

int main()
{
    string line {};
    // открываем файл для чтения input file stream
    ifstream in("DAY2-17.txt");
    int sum{};
    bool isFirstNumber = true; //флаг для присвоения первого значения max min

    // is_open метод класса то что и функция
    // ifstream класс
    // in экземпляр класса

    if (in.is_open()) // проверяем работает ли этот поток(фаил)
    {
        // getline метод библиотеки
        // считваем строки до конца файла
        while (getline(in, line))
        {
            int number{}, minNumber{}, maxNumber{};
            for (size_t i{}; i < line.length(); i++ )
            {
                // (line[i] - '0') в аски символах символ 2 это 50,
                // символ 0 это 48, 50-48 приходим к значению 2 (так для 0-9)
                // у каждого символа есть порядковый № в аски и работаем с этим номером

                //определяем встречу символа \t, вместо пробела использован
                if (line[i] != '\t')
                {
                    //операция + должна быть раньше *
                    number += (line[i]-'0');
                    number *= 10;
                }
                //заполнение min  max переменных
                // если поставить else, то не зайдет сюда после последнего умножения
                if (line[i] == '\t' || i + 1 == line.length())
                {
                    // тк последнее умножение уведичит число в 10
                    number /= 10;
                    // первичное заполнение max min значения в строке 0
                    if (isFirstNumber)
                    {
                        minNumber = number;
                        maxNumber = number;
                        isFirstNumber = false;
                    }
                    else if (minNumber > number) minNumber = number;
                    else if (maxNumber < number) maxNumber = number;

                    number = 0;
                }
            }
            // разность крайних значений в строках, суммируется в sum
            sum +=maxNumber - minNumber;
            // обнуление флага для заполнения max min
            isFirstNumber = true;

        }

    }
cout << " sum = " << sum;




    return 0;
}
