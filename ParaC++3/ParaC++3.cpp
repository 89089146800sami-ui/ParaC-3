#include <iostream>
#include <Windows.h>
#include <string>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));



    /*
    const int col = 10;
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