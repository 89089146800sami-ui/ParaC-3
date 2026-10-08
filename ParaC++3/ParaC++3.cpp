#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
/*

Тип_возврата имя_функции(аргументы_функции) {

}

*/
/*
double FillArray(double a[], int b);
char FillArray(char a[], int b);
int FillArray(int a[], int b);
double ShowArray(double a[], int b);
char ShowArray(char a[], int b);
int ShowArray(int a[], int b);


template <typename T1, typename Alex>
T1 Substruct(T1 one, Alex two) {
    return one - two;
}


int Factorial(int num) {
    if (num < 0) {
        return 0;
    }
    else if (num == 0) {
        return 1;
    }
    return num * Factorial(num - 1);
}

int Prois(int num1, int num2) {
    if (num2 == 0) {
        return 0;
    }
    return num1 + Prois(num1, (num2 - 1));
}

double Delen(double num1, double num2, int num3) {
    if (num1 == 0) {
        return num3;
    }
    else if (num1 <= 0 || num1 < num2) {
        return num3;
    };
    return Delen((num1 - num2), num2, (num3 + 1));
}
*/

std::string corsina_name[64]{};
int corsina_price[64]{};
int corsina_col[64]{};
bool five_petr = FALSE;
bool trinad_proc = FALSE;
bool fruct = FALSE;
int sum = 0;
int petr = 0;
int luk = 0;
int skid_luk = 0;
double skid = 0;

int corsina_add(std::string num1, int num2, int num3) {
    for (size_t i = 0; i < 64; ++i) {
        if (corsina_name[i] == "") {
            corsina_name[i] = num1;
            corsina_price[i] = num2;
            corsina_col[i] = num3;
            std::cout << num1 << ", " << num2 << " рублей за литр, "
                << num3 << " литров | Успешно добавлено в корзину\n";
            return 0;
        }
    }
    std::cout << "Корзина заполнена, нельзя добавить товар.\n";
    return -1;
}

double skidka() {
    five_petr = FALSE;
    trinad_proc = FALSE;
    sum = 0;
    petr = 0;
    luk = 0;
    skid_luk = 0;
    skid = 0;
    for (size_t i = 0; i < 64; i++)
    {
        sum += (corsina_price[i]*corsina_col[i]);
        if (corsina_name[i] == "Петрушевый") {
            petr += corsina_col[i];
            if (petr >= 3) {
                five_petr = TRUE;
                for (size_t i = 0; i < 64; i++) {
                    if (corsina_name[i] == "Петрушевый") {
                        skid += (corsina_price[i] / 100 * 5);
                    }
                }
            }
        }
        else if (corsina_name[i] == "Луковый") {
            luk += corsina_col[i];
            skid_luk = luk / 4;
        }
    }
    if (sum > 3000) {
        skid += (sum / 100 * 13);
        trinad_proc = TRUE;
    }
    return 0;
}

bool AntiBayr() {
    bool nast = FALSE;
    for (size_t i = 0; i < 64; i++)
    {
        if (corsina_name[i] == "Боярышник") {
            corsina_name[i] == "";
            corsina_price[i] == 0;
            corsina_col[i] == 0;
            nast = TRUE;
        }
    }
    if (nast == TRUE){
        return TRUE;
    }
    else { return FALSE; }
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    std::string input;
    char choose = ' ';

    const int fructs_size = 4;
    const int ovoch_size = 3;
    const int chai_size = 2;
    const int nasto_size = 1;
    
    int fructs_price[fructs_size]{ 200, 200, 300, 150 };
    std::string fructs[fructs_size]{ "Яблочный", "Апельсиновый", "Абрикосовый", "Грушевый" };
    int ovoch_price[ovoch_size]{ 250, 150, 150 };
    std::string ovoch[ovoch_size]{ "Томатный", "Луковый", "Огуречный" };
    int chai_price[chai_size]{ 250, 250 };
    std::string chai[chai_size]{ "Чесночный", "Петрушевый" };
    int nasto_price[nasto_size]{ 1000 };
    std::string nasto[nasto_size]{ "Боярышник" };

    while (true) {
        system("cls");
        std::cout << "\n\n\t\tМагазин \"Соки Александра\"\n\n";
        std::cout << "\tМагазин спциализируется на продаже напитков в банках\n\n";
        std::cout << "1 - Соки\n";
        std::cout << "2 - Чаи\n";
        std::cout << "3 - Настойки\n";
        std::cout << "\n4 - Скидки\n";
        std::cout << "\n5 - Посмотреть корзину\n\n";
        std::cout << "0 - Выход\n";
        std::cout << "\nВвод: ";
        std::getline(std::cin, input);

        choose = input[0];

        if (choose == '1') {
            int gues;
            while (true) {
                system("cls");
                std::cout << "\n\nВыбрана катеория соки" << "\n";
                std::cout << "1 - Фруктовые\n";
                std::cout << "2 - Овощные\n";
                std::cout << "0 - Вернуться\n";
                std::cout << "\nВвод: ";
                std::getline(std::cin, input);
                choose = input[0];
                if (input.empty()) continue;
                if (choose == '0') { break; }
                else if (choose == '1') {
                    while (true) {
                        system("cls");
                        std::cout << "\n\nКакой именно фруктовый сок вы хотите?" << "\n";
                        for (size_t i = 0; i < fructs_size; i++)
                        {
                            std::cout << i + 1 << " " << fructs[i] << " (" << fructs_price[i] << " р/л)" << " | ";
                        }
                        std::cout << "\n0 - Вернуться\n";
                        std::cout << "\nВвод: ";
                        std::getline(std::cin, input);
                        choose = input[0];
                        if (input.empty()) continue;
                        if (choose == '0') { break; }
                        else {
                            gues = std::stoi(input) - 1;
                            while (true) {
                                system("cls");
                                std::cout << "\n\nСколько " << fructs[gues] << " сока вы хотите в литрах" << "\n";
                                std::cout << "\n0 - Вернуться\n";
                                std::cout << "\nВвод: ";
                                std::getline(std::cin, input);
                                choose = input[0];
                                if (input.empty()) continue;
                                if (choose == '0') { break; }
                                else {
                                    corsina_add(fructs[gues], fructs_price[gues], std::stoi(input));
                                    fruct = TRUE;
                                    if (AntiBayr() == TRUE) { std::cout << "\nБоярышник ликвидирован!\n"; }
                                    system("pause");
                                    break;
                                }
                            }
                        }
                    }
                }
                else if (choose == '2') {
                    while (true) {
                        system("cls");
                        std::cout << "\n\nКакой именно овощной сок вы хотите?" << "\n";
                        for (size_t i = 0; i < ovoch_size; i++)
                        {
                            std::cout << i + 1 << " " << ovoch[i] << " (" << ovoch_price[i] << " р/л)" << " | ";
                        }
                        std::cout << "\n0 - Вернуться\n";
                        std::cout << "\nВвод: ";
                        std::getline(std::cin, input);
                        choose = input[0];
                        if (input.empty()) continue;
                        if (choose == '0') { break; }
                        else {
                            gues = std::stoi(input) - 1;
                            while (true) {
                                system("cls");
                                std::cout << "\n\nСколько " << ovoch[gues] << " сока вы хотите в литрах" << "\n";
                                std::cout << "\n0 - Вернуться\n";
                                std::cout << "\nВвод: ";
                                std::getline(std::cin, input);
                                choose = input[0];
                                if (input.empty()) continue;
                                if (choose == '0') { break; }
                                else {
                                    corsina_add(ovoch[gues], ovoch_price[gues], std::stoi(input));
                                    system("pause");
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (choose == '2') {
            int gues;
            while (true) {
                system("cls");
                std::cout << "\n\nКакой именно чай вы хотите?" << "\n";
                for (size_t i = 0; i < chai_size; i++)
                {
                    std::cout << i + 1 << " " << chai[i] << " (" << chai_price[i] << " р/л)" << " | ";
                }
                std::cout << "\n0 - Вернуться\n";
                std::cout << "\nВвод: ";
                std::getline(std::cin, input);
                choose = input[0];
                if (input.empty()) continue;
                if (choose == '0') { break; }
                else {
                    gues = std::stoi(input) - 1;
                    while (true) {
                        system("cls");
                        std::cout << "\n\nСколько " << chai[gues] << " сока вы хотите в литрах" << "\n";
                        std::cout << "\n0 - Вернуться\n";
                        std::cout << "\nВвод: ";
                        std::getline(std::cin, input);
                        choose = input[0];
                        if (input.empty()) continue;
                        if (choose == '0') { break; }
                        else {
                            corsina_add(chai[gues], chai_price[gues], std::stoi(input));
                            system("pause");
                            break;
                        }
                    }
                }
            }
        }
        else if (choose == '3') {
            int gues;
            while (true) {
                system("cls");
                std::cout << "\n\nКакую именно настойку вы хотите?" << "\n";
                for (size_t i = 0; i < nasto_size; i++)
                {
                    std::cout << i + 1 << " " << nasto[i] << " (" << nasto_price[i] << " р/л)" << " | ";
                }
                std::cout << "\n0 - Вернуться\n";
                std::cout << "\nВвод: ";
                std::getline(std::cin, input);
                choose = input[0];
                if (input.empty()) continue;
                if (choose == '0') { break; }
                else {
                    gues = std::stoi(input) - 1;
                    while (true) {
                        system("cls");
                        std::cout << "\n\nСколько " << nasto[gues] << " сока вы хотите в литрах" << "\n";
                        std::cout << "\n0 - Вернуться\n";
                        std::cout << "\nВвод: ";
                        std::getline(std::cin, input);
                        choose = input[0];
                        if (input.empty()) continue;
                        if (choose == '0') { break; }
                        else {
                            if (fruct == FALSE) {
                                corsina_add(nasto[gues], nasto_price[gues], std::stoi(input));
                                system("pause");
                                break;
                            }
                            else {
                                std::cout << "\nВ корзине есть фруктовый сок, добавление настоек запрещено!\n\n";
                                system("pause");
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (choose == '4') {
            skidka();
            while (true) {
                system("cls");
                std::cout << "\nВсе скидки в нашем магазине:" << "\n\n";
                std::cout << "Текущая скидка: " << skid;
                std::cout << "\nТекущая сумма: " << sum << "\n\n";
                std::cout << "1) При покупке 3л петрушевого чая, скидка 5% на них - "; 
                if (five_petr == TRUE) { std::cout << "Активна\n"; } else { std::cout << "Неактивна\n"; }
                std::cout << "2) Если стоимость покупки превышает 3000 рублей, то скидка 13% на весь чек - ";
                if (trinad_proc == TRUE) { std::cout << "Активна\n"; } else { std::cout << "Неактивна\n"; }
                std::cout << "3) Каждый четвёртый литр лукового сока в подарок - Сейчас " << skid_luk << " литра бесплатно\n";
                std::cout << "\n0 - Вернуться\n";
                std::cout << "\nВвод: ";
                std::getline(std::cin, input);
                choose = input[0];
                if (input.empty()) continue;
                if (choose == '0') { break; }
            }
        }
        else if (choose == '5') {
            skidka();
            while (true) {
                system("cls");
                std::cout << "\nВаша корзина:" << "\n\n";
                for (size_t i = 0; i < 64; i++) {
                    if (corsina_name[i] != "") {
                        std::cout << i + 1 << ") " << corsina_name[i] << " | " << corsina_price[i] << " р/л | " << corsina_col[i] << " л\n";
                    }
                }
                std::cout << "\nТекущая сумма: " << sum << "\n";
                std::cout << "Текущая скидка: " << skid;
                std::cout << "\n\n1) При покупке 3л петрушевого чая, скидка 5% на них - ";
                if (five_petr == TRUE) { std::cout << "Активна\n"; }
                else { std::cout << "Неактивна\n"; }
                std::cout << "2) Если стоимость покупки превышает 3000 рублей, то скидка 13% на весь чек - ";
                if (trinad_proc == TRUE) { std::cout << "Активна\n"; }
                else { std::cout << "Неактивна\n"; }
                std::cout << "3) Каждый четвёртый литр лукового сока в подарок - Сейчас " << skid_luk << " литра бесплатно\n";
                std::cout << "\n\nИтог: " << (sum - skid) << "\n\n";
                std::cout << "\n1 - Оплатить";
                std::cout << "\n0 - Вернуться\n";
                std::cout << "\nВвод: ";
                std::getline(std::cin, input);
                choose = input[0];
                if (input.empty()) continue;
                if (choose == '0') { break; }
                else if (choose == '1') {
                    system("cls");
                    std::cout << "Чек оплачен:\n\n\n";
                    std::cout << "Сумма: " << sum;
                    std::cout << "\nСкидка: " << skid;
                    std::cout << "\n\nИтог: " << (sum - skid) << "\n\n";
                    system("pause");
                    break;
                }
            }
        }
        else if (choose == '0') {
            break;
        }
    }
    /*
    const int size = 4;
    std::string input;
    char choose = ' ';
    int mas[size]{};
    double ras[size]{};
    char gaz[size]{};

    FillArray(mas, size);
    FillArray(ras, size);
    FillArray(gaz, size);
    ShowArray(mas, size);
    ShowArray(ras, size);
    ShowArray(gaz, size);
    std::cout << "\n\n" << Factorial(5) << "\n";
    std::cout << Prois(3, 4) << "\n";
    std::cout << Delen(6, 2, 0);
    */
    /*
    const int col =    ;
    const int row = 3;
    int alex[row][col]{};
    for (size_t row_this = 0; row_this < row; row_this++) {                                              
        for (size_t i = 0; i < col; i++)
        {
            alex[row_this][i] = rand() % 10;
        }  
    }
    for (size_t row_this = 0; row_this < row; row_this++) {
        for (size_t i = 0; i < col; i++)
        {
            std::cout << "  " << alex[row_this][i];
        }
        std::cout << "\n";
    }

    */
    /*
    int ur = 0;
    char choose = ' ';
    ur = rand() % 10 + 1;
    int wait = 0;
    int maxhp = 25, maxhphard = 20, hp = 0;
    int randomNumber = 0;
    std::string input;
    while (true) {
        system("cls");
        std::cout << "\n\n\n\t\tИгра \"Угадай число\"\n\n\n";
        std::cout << "1 - Начать игру\n";
        std::cout << "2 - Настройки\n";
        std::cout << "0 - Выход\n";
        std::cout << "\nВвод: ";
        std::getline(std::cin, input);

        choose = input[0];

        if (choose == '1') {
            while (true) {
                system("cls");
                std::cout << "\n\n\n\t\tВыберите уровень сложности\n\n\n";
                std::cout << "1 - Легкий (1-500)\n";
                std::cout << "2 - Сложный (1-5000)\n";
                std::cout << "0 - Выход в главное меню\n";
                std::cout << "\nВвод: ";
                std::getline(std::cin, input);

                choose = input[0];

                if (choose == '1') {
                    randomNumber = rand() % 500 + 1;
                    hp = maxhp;
                    while (true) {
                        system("cls");
                        std::cout << "\nКоличество жизней: " << hp << "\n";
                        std::cout << "\nВведите число от 1 до 500: ";

                        std::getline(std::cin, input);

                        if (input.empty()) continue;

                        bool isNumber = true;
                        for (char c : input) {
                            if (!isdigit(c)) { isNumber = false; break; }
                        }
                        if (!isNumber) {
                            std::cout << "Это не число!\n";
                            std::cin.get();
                            continue;
                        }

                        int guess = std::stoi(input); // строка -> число

                        if (guess < 1 || guess > 500) {
                            std::cout << "Число должно быть от 1 до 500!\n";
                            std::cin.get();
                            continue;
                        }
                        if (guess == randomNumber) {
                            std::cout << "\nПоздравляю! Ты угадал число " << randomNumber << "!\n Нажмите enter чтобы продолжить... ";
                            std::cin.get();
                            break;
                        }
                        else if (guess < randomNumber) {
                            std::cout << "\nЗагаданное число" << " БОЛЬШЕ " << guess << "\n";
                            hp--;
                        }
                        else {
                            std::cout << "\nЗагаданное число"  << " МЕНЬШЕ " << guess << "\n";
                            hp--;
                        }

                        if (hp <= 0) {
                            std::cout << "\nТы проиграл! Было загадано: " << randomNumber << "\n";
                            std::cin.get();
                            break;
                        }

                        std::cout << "Нажмите Enter для продолжения...";
                        std::cin.get();
                    }
                }
                else if (choose == '2') {
                    randomNumber = rand() % 5000 + 1;
                    hp = maxhphard;
                    while (true) {
                        system("cls");
                        std::cout << "\nКоличество жизней: " << hp << "\n";
                        std::cout << "\nВведите число от 1 до 5000: ";

                        std::getline(std::cin, input);

                        if (input.empty()) continue;

                        bool isNumber = true;
                        for (char c : input) {
                            if (!isdigit(c)) { isNumber = false; break; }
                        }
                        if (!isNumber) {
                            std::cout << "Это не число!\n";
                            std::cin.get();
                            continue;
                        }

                        int guess = std::stoi(input); // строка -> число

                        if (guess < 1 || guess > 5000) {
                            std::cout << "Число должно быть от 1 до 5000!\n";
                            std::cin.get();
                            continue;
                        }
                        if (guess == randomNumber) {
                            std::cout << "\nПоздравляю! Ты угадал число " << randomNumber << "!\n Нажмите enter чтобы продолжить... ";
                            std::cin.get();
                            break;
                        }
                        else if (guess < randomNumber) {
                            std::cout << "\nЗагаданное число" << " БОЛЬШЕ " << guess << "\n";
                            hp--;
                        }
                        else {
                            std::cout << "\nЗагаданное число" << " МЕНЬШЕ " << guess << "\n";
                            hp--;
                        }

                        if (hp <= 0) {
                            std::cout << "\nТы проиграл! Было загадано: " << randomNumber << "\n";
                            std::cin.get();
                            break;
                        }

                        std::cout << "Нажмите Enter для продолжения...";
                        std::cin.get();
                    }
                }
                else if (choose == '0') {
                    break;
                }
            }
        }
        else if (choose == '2') {
            while (true) {
                system("cls");
                std::cout << "\n\n\n\t\tНастройки\n\n\n";
                std::cout << "1 - Изменить кол-во жизней в легком режиме\n";
                std::cout << "2 - Изменить кол-во жизней в сложном режиме\n";
                std::cout << "0 - Выход в главное меню\n";
                std::cout << "\nВвод: ";
                std::getline(std::cin, input);

                choose = input[0];

                if (choose == '1') {
                    while (true) {
                        system("cls");
                        std::cout << "\nВведите кол-во жизней для легкого режима" << "\nВвод: ";
                        std::cin >> wait;
                        if (wait < 0 || wait > 100) {
                            std::cout << "\nДопустимые лимиты от 1 до 100!";
                            Sleep(1500);
                        }
                        else {
                            std::cout << "Успешно\n";
                            Sleep(1000);
                            maxhp = wait;
                            break;
                        }
                    }
                }
                if (choose == '2') {
                    while (true) {
                        system("cls");
                        std::cout << "\nВведите кол-во жизней для сложного режима" << "\nВвод: ";
                        std::cin >> wait;
                        if (wait < 0 || wait > 100) {
                            std::cout << "\nДопустимые лимиты от 1 до 100!";
                            Sleep(1500);
                        }
                        else {
                            std::cout << "Успешно\n";
                            Sleep(1000);
                            maxhphard = wait;
                            break;
                        }
                    }
                }
                else if (choose == '0') {
                    break;
                }

            }
        }
        else if (choose == '0') {
            system("cls");
            std::cout << "\n\n\n\t\tСпасибо за игру!\n\n\n";
            break;
        }
        else {
            std::cout << "\nНекорректный ввод\n";
            Sleep(1500);
        }
    }
    */
    /*
    double rastoyanie = 0;
    double minut = 0;
    double skorost = 0;

    std::cout << "Сколько ехать в метрах? ";
    std::cin >> rastoyanie;
    std::cout << "За какое время нужно доехать в минутах? ";
    std::cin >> minut;
    skorost = ((rastoyanie / 1000) / (minut / 60));
    std::cout << "Вам нужно ехать со скоростью: " << skorost << " км/ч\n";

    double vr_chas_n = 0;
    double vr_min_n = 0;
    double vr_sec_n = 0;

    double vr_chas_k = 0;
    double vr_min_k = 0;
    double vr_sec_k = 0;

    double stoim = 0;

    std::cout << "\nВремя начала катания на скутере: \n";
    std::cout << "Час: ";
    std::cin >> vr_chas_n;
    std::cout << "Минута: ";
    std::cin >> vr_min_n;
    std::cout << "Секунда: ";
    std::cin >> vr_sec_n;

    std::cout << "\nВремя завершени катания на скутере: \n";
    std::cout << "Час: ";
    std::cin >> vr_chas_k;
    std::cout << "Минута: ";
    std::cin >> vr_min_k;
    std::cout << "Секунда: ";
    std::cin >> vr_sec_k;

    if (vr_chas_n > vr_chas_k) {
        stoim = (((24 - vr_chas_n) * 60 * 60) + (vr_chas_k * 60 * 60) + (vr_min_n * 60 + vr_min_k * 60) + (vr_sec_n + vr_sec_k)) / 60 * 2;
        std::cout << "\nСтоимость поездки: " << stoim << " гривн";
    }
    else if (vr_chas_n <= vr_chas_k) {
        stoim = (((vr_chas_k - vr_chas_n) * 60 * 60) + (vr_min_n * 60 + vr_min_k * 60) + (vr_sec_n + vr_sec_k)) / 60 * 2;
        std::cout << "\nСтоимость поездки: " << stoim << " гривн";
    }

    double rastoyan = 0;
    double rashod = 0;
    double cena1 = 0, cena2 = 0, cena3 = 0;

    std::cout << "\n\nВведите расстояние поездки (в км): ";
    std::cin >> rastoyan;

    std::cout << "Введите расход бензина на 100 км (в литрах): ";
    std::cin >> rashod;

    std::cout << "Введите стоимость 1 литра первого бензина: ";
    std::cin >> cena1;
    std::cout << "Введите стоимость 1 литра второго бензина: ";
    std::cin >> cena2;
    std::cout << "Введите стоимость 1 литра третьего бензина: ";
    std::cin >> cena3;

    double obshiy_rashod = (rastoyan / 100) * rashod;
    double stoimost1 = obshiy_rashod * cena1;
    double stoimost2 = obshiy_rashod * cena2;
    double stoimost3 = obshiy_rashod * cena3;

    std::cout << "\n--- Результаты ---\n";
    std::cout << "Расход топлива на поездку: " << obshiy_rashod << " л.\n\n";

    std::cout << "Стоимость на первом топливе: " << stoimost1 << " руб.\n";
    std::cout << "Стоимость на втором топливе: " << stoimost2 << " руб.\n";
    std::cout << "Стоимость на третьем топливе: " << stoimost3 << " руб.\n";
    */
    /*
    double i = 0;
    double sum = 0;
    int ch = 0;
    int n = 0;
    int th = 0;
    int th_prov = 0;

    std::cout << "Введите шестизначное число: ";
    std::cin >> n;
    double k = 0;
    int one = n / 1000;
    int two = n % 1000;
    int first = one % 1000 / 100;
    int second = one % 100 / 10;
    int three = one % 10;
    int four = two % 1000 / 100;
    int five = two % 100 / 10;
    int six = two % 10;
    if ((n / 100000) > 0 && n < 1000000) {
        std::cout << first << "\n" << second << "\n" << three << "\n";
        std::cout << four << "\n" << five << "\n" << six;
        std::cout << "\nПервая часть: " << one << "\n";
        std::cout << "Вторая часть: " << two << "\n";

        if ((six + five + four) == (first + second + three)) {
            std::cout << "\n\t<ПОЗДРАВЛЯЕМ>\n" << "Это счастливое число!!!\n\n";
        }
        else {
            std::cout << "\n\t<ОБИДНО>\n" << "Это несчастливое число(((\n\n";
        }

        system("pause");
    }
    else {
        std::cout << "\n\t<ОБИДНО>\n" << "   Вы ввели не шестизначное число(((\n\n";
    }

    std::cout << "Введите четырёхзначное число: ";
    std::cin >> ch;
    int one_ch = ch / 1000;
    int two_ch = ch % 1000 / 100;
    int three_ch = ch % 100 / 10;
    int four_ch = ch % 10;
    int ch_otvet = 0;
    if ((ch / 1000) > 0 && ch < 10000) {
        std::cout << "Первая часть: " << one_ch << "\n";
        std::cout << "Вторая часть: " << two_ch << "\n";
        std::cout << "Третья часть: " << three_ch << "\n";
        std::cout << "Четвёртая часть: " << four_ch << "\n";
        ch_otvet = (two_ch * 1000) + (one_ch * 100) + (four_ch * 10) + (three_ch);
        std::cout << "\nНовое четырёхзначное число: " << ch_otvet << "\n";
    }
    else {
        std::cout << "\n\t<ОБИДНО>\n" << "   Вы ввели не четырёхзначное число(((\n\n";
    }

    std::cout << "\nВведите семь целых чисел: \n";
    while (i < 7) {
        i++;
        std::cin >> th_prov;
        if (th_prov > th) {
            th = th_prov;
        }
    }
    std::cout << "\nМаксимальное из семи чисел: " << th;
    */

    /*do {
        system("cls");
        std::cout << "\tМЕНЮ:\n\n"
            << "1) Ларионов\n"
            << "2) Александр\n"
            << "3) Дмитриевич\n"
            << "\nВведите пункт: ";
        std::cin >> i;

    } while (i != 1 && i != 2 && i != 3);
    if (i == 1) {
        std::cout << "\n<\tЛарионов\t>\n";
        system("pause");
    }
    else if (i == 2) {
        std::cout << "\n<\tАлександр\t>\n";
        system("pause");
    }
    else {
        std::cout << "\n<\tДмитриевич\t>\n";
        system("pause");
    }*/

    /*while (true) {
        std::cout << "\nВведите число: ";
        std::cin >> i;
        if (i == 0) {
            std::cout << "Сумма: " << sum << "\n";
            break;
        }
        else {
            sum += i;
        }
    }*/

    /*while (i < 5) {
        std::cout << "I = " << i;
        i++;
        if (i == 3) {
            continue;
        }
        std::cout << " Uraaaa\n";
        system("pause");
    }*/

    return 0;
}

/*
double FillArray(double a[], int b) {
    for (size_t i = 0; i < b; i++)
    {
        a[i] = (static_cast<double>(rand()) / RAND_MAX) * 10.0;
        a[i] = std::round(a[i] * 10.0) / 10.0;

    }
    return 0;
}
char FillArray(char a[], int b) {
    for (size_t i = 0; i < b; i++)
    {
        a[i] = (char)(rand() % 26 + 97);
    }
    return ' ';
}
int FillArray(int a[], int b) {
    for (size_t i = 0; i < b; i++)
    {
        a[i] = rand() % 10;
    }
    return 0;
}
double ShowArray(double a[], int b) {
    std::cout << "\n";
    for (size_t i = 0; i < b; i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}
char ShowArray(char a[], int b) {
    std::cout << "\n";
    for (size_t i = 0; i < b; i++)
    {
        std::cout << a[i] << " ";
    }
    return ' ';
}
int ShowArray(int a[], int b) {
    std::cout << "\n";
    for (size_t i = 0; i < b; i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}
*/

