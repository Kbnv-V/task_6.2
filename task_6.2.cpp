#include <iostream>
#include "Windows.h"
#include "Counter.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str{};
    char cmd{};
    int value{}, attempt{};
    Counter* count = nullptr;

    while (attempt <= 5)
    {
        if (attempt == 5)
        {
            std::cout << "Аварийное завершение программы!\nИспользовано максимальное количество попыток ввода." << std::endl;
            return -1;
        }

        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> str;

        if (str == "да")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> value;

            count = new Counter(value);
            break;
        }
        else if (str == "нет")
        {
            count = new Counter;
            break;
        }
        else
        {
            ++attempt;
            std::cout << "Ошибка! Проверьте регистр ввода. Введите команду в нижем регистре.\nПопыток " << attempt << " из 5" << "\n\n";
        }
    }

    while (true)
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> cmd;

        switch (cmd)
        {
        case '+':
            count->Increase();
            break;
        case '-':
            count->Decrease();
            break;
        case '=':
            std::cout << count->GetCounter() << std::endl;
            break;
        case 'x':
            std::cout << "До свидания!" << std::endl;
            delete count;
            return 0;
        default:
            std::cout << "Неизвестная команда!" << std::endl;
            break;
        }
    }
}
