#include <iostream>
#include <fstream> // чтение и запись в файл
#include <string> //для строковой переменной

using namespace std;

int main()
{
    // запись в переменную line
    string line {};
    int totalSquare {};
    int totalFeet{};

    ifstream in("day2-input.txt"); // окрываем файл для чтения

    if (in.is_open())  //  . открываем поле доп информации
    {
        while (getline(in, line))
        {
            int length {}; // длина
            int width {}; // ширина
            int height {}; //высота
            size_t i{};
            int square{};
            int squareLittle {};

            for ( i ; line[i]  != 'x'; i++){

                // (line[i] - '0') в аски символах символ 2 это 50,
                // символ 0 это 48, 50-48 приходим к значению 2 (так для 0-9)
                // у каждого символа есть порядковый № в аски и работаем с этим номером
                if (line[i+1] != 'x') length = (line[i] - '0') * 10; //++i изменит i
                else if (line[i+1] == 'x') length += (line[i] - '0');
            }
            i++;

            for (i ; line[i]  != 'x'; i++){
                if  (line[i+1] != 'x') width = (line[i] - '0') * 10;
                else if ( line[i+1] == 'x') width += (line[i] - '0');
            }
            i++;
            for (i ; i < line.length(); i++){ // length количество сим в линии
                // line[i+1] конкретный символ
                if  (i + 1 != line.length()) height = (line[i] - '0') * 10;
                else if (i + 1 == line.length()) height += (line[i] - '0');
            }

            // площадь 1 подарка


        /*
            int min1 = (height*length <= width*length ? height*length : width*length);
            int min2 = (length*height <= height*width ? length*height : height*width);
            int min3 = min1 <= min2 ? min1 : min2;
        */


             // поиск общей площади, часть 1
            int min = (height*length <= width*length ? height*length : width*length);
            min = (min <= height*width ? min : height*width);
            square = 2*length*width + 2*width*height + 2*height*length + min;
            // записывааем площади суммируя их с предыдущими
            totalSquare+=square;


            // часть 2, найти длину ленты

            min = 2*(height+length) <= 2*(width+length) ? 2*(height+length) : 2*(width+length);
            min = (min <= 2*(height+width) ? min : 2*(height+width));
            // длину мин периметра для обвязки и V для бантика
            // что даст всю длину ленты
            int feet = height*length*width + min;
            // общая длина
            totalFeet+=feet;


        }
    }
    in.close();// закрываем файл

    cout << "Total square: " << totalSquare << "\nTotal feet: " << totalFeet;

    return 0;
}
