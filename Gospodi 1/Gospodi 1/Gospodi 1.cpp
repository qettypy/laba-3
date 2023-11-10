// Gospodi 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <algorithm>

struct Participant {
    int id;
    int points;
};

bool compareParticipants(const Participant& p1, const Participant& p2) {
    return p1.points > p2.points; // Сортируем по убыванию баллов
}

int main() 
{
    setlocale(LC_ALL, "");
    int numParticipants;

    // Получаем количество участников
    std::cout << "Введите количество участников: ";
    std::cin >> numParticipants;

    // Создаем вектор для хранения данных об участниках
    std::vector<Participant> participants;

    // Вводим данные об участниках
    for (int i = 0; i < numParticipants; ++i) {
        Participant participant;
        std::cout << "Введите идентификационный номер участника " << i + 1 << ": ";
        std::cin >> participant.id;

        std::cout << "Введите количество баллов для участника " << i + 1 << ": ";
        std::cin >> participant.points;

        participants.push_back(participant);
    }

    // Сортируем участников по баллам
    std::sort(participants.begin(), participants.end(), compareParticipants);

    // Выводим отсортированный список участников
    std::cout << "\nОтсортированный список участников:\n";
    for (const auto& participant : participants) {
        std::cout << "Идентификационный номер: " << participant.id << ", Баллы: " << participant.points << std::endl;
    }

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
