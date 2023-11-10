// gospodi 1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cmath>

// Функция для перевода числа из исходной системы счисления в десятичную
int toDecimal(std::string number, int fromBase) {
    
    int decimalNumber = 0;
    int power = 0;

    for (int i = number.length() - 1; i >= 0; i--) {
        char digit = number[i];
        int digitValue = (isdigit(digit)) ? (digit - '0') : (toupper(digit) - 'A' + 10);
        decimalNumber += digitValue * pow(fromBase, power);
        power++;
    }

    return decimalNumber;
}

// Функция для перевода числа из десятичной системы счисления в целевую
std::string fromDecimal(int decimalNumber, int toBase) {
    std::string convertedNumber = "";

    while (decimalNumber > 0) {
        int remainder = decimalNumber % toBase;
        char digit = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        convertedNumber = digit + convertedNumber;
        decimalNumber /= toBase;
    }

    return convertedNumber;
}

int main() {
    setlocale(LC_ALL, "");
    std::string numberToConvert;
    int fromBase, toBase;

    std::cout << "Введите число для конвертации: ";
    std::cin >> numberToConvert;

    std::cout << "Введите исходную систему счисления: ";
    std::cin >> fromBase;

    std::cout << "Введите целевую систему счисления: ";
    std::cin >> toBase;

    // Переводим число в десятичную систему
    int decimalNumber = toDecimal(numberToConvert, fromBase);

    // Переводим число из десятичной системы в целевую
    std::string result = fromDecimal(decimalNumber, toBase);

    std::cout << "Результат конвертации: " << result << std::endl;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
