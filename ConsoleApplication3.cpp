#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

// Хранение первоначальных стоимостей прокачки клика
struct CostClicks {
    int cost1 = 50, cost2 = 500, cost3 = 5000, cost4 = 50000, cost5 = 500000;
};
// Хранение всех переменных типа bool
struct Bools {
    bool running = true;
    bool earning = true;
    bool upgrading = true;
    bool terms = true;
    bool clothes = true;
    bool bank = true;
};
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 2);
    // Начальный баланс
    int bankbalance = 0;
    // Процентная ставка (1% за клик)
    double interestRate = 0.01;
    char action;
    bool classes21 = true;
    int termbuy;
    int percents = bankbalance * interestRate;
    static int mainclass = 1;
    static int mainterm = 1;
    static int termcost = 100;
    CostClicks costclicks;
    Bools bools;
    // Очистка консоли
    system("cls");
    int balance = 100;
    // Начальный баланс
    auto choice = 0;
    // первоначальный доход за клик
    int clickearn = 1;
    // Переменная для выбора что делать в кликере
    int clickchoice;
    // Переменная для выбора как прокачивать клик
    auto upgradeclick = 0;
    bool flag = true;
    while (bools.running) {
        // Приветствие
        cout << "Hello, this is our simulator of school life. Under you can see a list of opportunities, which you can select. Good luck!" << endl << endl;

        // Список возможностей
        cout << "Here are your options:" << endl;
        cout << "1. Earn some money" << endl;
        cout << "2. Learn new terms" << endl;
        cout << "3. Buy new clothes" << endl;
        cout << "4. Go to bank" << endl;
        cout << "5. End a school(do not come in if you are not in 11 class, you will die)" << endl;
        cout << "6. Exit" << endl;

        // Ввод пользователя
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            // Переход в режим заработка путем кликанья
        case 1:
            bools.earning = true;
            while (bools.earning) {
                cout << "1. Click to earn" << endl;
                cout << "2. Upgrade earn for click" << endl;
                cin >> clickchoice;
                if (cin.fail()) {
                    cout << "Wrong input" << endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    bools.earning = false;
                }
                switch (clickchoice) {
                    // Сам кликер для заработка
                case 1:
                    balance += clickearn;
                    system("cls");
                    cout << "Your balance " << balance << endl;
                    continue;
                    // Варианты как увеличить заработок с клика
                case 2:
                    bools.upgrading = true;
                    cout << "Here you have some variants to upgrade your click" << endl;
                    cout << endl;
                    cout << "1. Cost: " << costclicks.cost1 << " clicks, +1 per click" << endl;
                    cout << "2. Cost: " << costclicks.cost2 << " clicks, +3 per click" << endl;
                    cout << "3. Cost: " << costclicks.cost3 << " clicks, +7 per click" << endl;
                    cout << "4. Cost: " << costclicks.cost4 << " clicks, +20 per click" << endl;
                    cout << "5. Cost: " << costclicks.cost5 << " clicks, +100 per click" << endl;
                    cout << "6. Main menu" << endl;
                    cout << "What do you want to buy: ";
                    cin >> upgradeclick;
                    if (cin.fail()) {
                        cout << "Wrong input" << endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Write again: ";
                        cin >> upgradeclick;
                    }
                    // Функция для прокачки кликера
                    while (bools.upgrading) {
                        switch (upgradeclick)
                        {
                        case 1:
                            if (costclicks.cost1 >= balance) {
                                cout << "You do not have enough money" << endl;
                                bools.upgrading = false;
                                continue;
                            }
                            else {
                                clickearn += 1;
                                costclicks.cost1 += 50;
                                cout << "Now you can increase " << clickearn << " per click" << endl;
                                bools.upgrading = false;
                                continue;
                            }

                        case 2:
                            if (costclicks.cost2 >= balance) {
                                cout << "You do not have enough money" << endl;
                                bools.upgrading = false;
                                continue;
                            }
                            else {
                                clickearn += 3;
                                costclicks.cost2 += 500;
                                bools.upgrading = false;
                                continue;
                            }

                        case 3:
                            if (costclicks.cost3 >= balance) {
                                cout << "You do not have enough money" << endl;
                                bools.upgrading = false;
                                continue;
                            }
                            else {
                                clickearn += 7;
                                costclicks.cost3 += 5000;
                                bools.upgrading = false;
                                continue;
                            }

                        case 4:
                            if (costclicks.cost4 >= balance) {
                                cout << "You do not have enough money" << endl;
                                bools.upgrading = false;
                                continue;
                            }
                            else {
                                clickearn += 20;
                                costclicks.cost4 += 50000;
                                bools.upgrading = false;
                                continue;
                            }

                        case 5:
                            if (costclicks.cost5 >= balance) {
                                cout << "You do not have enough money" << endl;
                                bools.upgrading = false;
                                continue;
                            }
                            else {
                                clickearn += 100;
                                costclicks.cost5 += 500000;
                                bools.upgrading = false;
                                continue;
                            }

                        case 6:
                            bools.upgrading = false;
                            bools.earning = false;
                            flag = false;
                            continue;
                        }
                    }
                }
            }
        // Раздел с обучением
        case 2:
            flag = true;
            if (flag) {
                cout << "Here you can study new terms, you have 5 terms per one class. After ending all of this classes you can end this school." << endl;
                cout << "Under you can the the list of classes" << endl << endl;
                cout << "You need to complete " << mainterm << " term" << endl;
                cout << "It costs " << termcost << endl;
                cout << "1. Buy" << endl;
                cout << "2. Leave" << endl;
                cout << "Choose what you want to do: ";
                cin >> termbuy;
                if (cin.fail()) {
                    cout << "Wrong input" << endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Write again: ";
                    cin >> termbuy;
                }
                while (bools.terms) {
                    if (termbuy == 1) {
                        if (termcost > balance) {
                            cout << "You do not have enough money." << endl;
                        }
                        else {
                            bools.terms = true;
                            int randomcomplete = dis(gen);
                            if (randomcomplete == 1) {
                                cout << "You can complete this term!" << endl;
                                mainterm++;
                                termcost += 100;
                                balance -= termcost;
                                bools.terms = false;
                            }
                            else {
                                cout << "Sorry, you cannot pass the exam, please try again." << endl;
                                bools.terms = false;
                            }
                        }
                    }
                    else if (termbuy == 2) {
                        bools.terms = false;
                        flag = false;
                    }
                }
                if (mainterm == 5) {
                    mainclass++;
                    mainterm = 1;
                }
            }
            // Реализация случайной генерации числа, чтобы сдавать экзамены было не так просто
            
        // Раздел с одеждой
        case 3:
            flag = true;
            if (flag) {
                cout << "Here you can buy some new clothes to be more beautiful." << endl << endl;
                cout << "Brands:" << endl;
                cout << "1. Prada" << endl;
                cout << "2. Gucci" << endl;
                cout << "3. Stussy" << endl;
                cout << "4. Carharrt" << endl;
                cout << "5. Marcelo Miracles" << endl;
                cout << "6. Nike" << endl;
                cout << "7. Inventory" << endl;
                cout << "8. Main menu" << endl;
                while (bools.clothes) {
                    auto brand = 0;
                    vector <string> brands = { "Prada", "Gucci", "Stussy", "Carharrt", "Marcelo Miracles", "Nike" };
                    cout << "Write the number of a brend you want to buy, all of them cost 5000" << endl;
                    cin >> brand;
                    vector <string> inventory;
                    if (brand == 1, 2, 3, 4, 5, 6) {
                        if (balance >= 5000) {
                            cout << "Good choice, your cloth adds in your inventory" << endl;
                            balance -= 5000;
                            inventory.push_back(brands[brand - 1]);
                            bools.clothes = false;
                        }
                        else {
                            cout << "You do not have enough money." << endl;
                            bools.clothes = false;
                        }
                    }
                    else if (brand == 7) {
                        for (size_t i = 0; i < inventory.size(); ++i) {
                            std::cout << inventory[i] << " ";
                        }
                    }
                    else if (brand == 8) {
                        bools.clothes = false;
                        flag = false;
                    }
                    else if (cin.fail()) {
                        cout << "Wrong input" << endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        bools.clothes = false;
                    }
                }
            }
            
        // Банк
        case 4:
            if (flag) {
                int action;
                bools.bank = true;
                while (bools.bank) {
                    cout << "Choose your action: " << endl;
                    cout << "1. Contribute deposit" << endl;
                    cout << "2. Take off your money" << endl;
                    cout << "3. Click for earning percents" << endl;
                    cout << "4. Leave" << endl;
                    cout << "Your choose: ";
                    cin >> action;

                    switch (action) {
                        case 1:
                            cout << "Enter a sum you want to deposit" << endl;
                            int deposit;
                            cin >> deposit;
                            if (cin.fail() || deposit <= 0) {
                                cout << "Wrong input. Your sum must be > 0" << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                bools.bank = false;
                            }
                            bankbalance += deposit;
                            balance -= deposit;
                            cout << "Contributed: " << deposit << endl;
                            cout << "Current balance in bank: " << bankbalance << endl;
                            break;
                        case 2:
                            int remove;
                            cout << "Enter a sum to remove: ";
                            cin >> remove;
                            if (cin.fail() || remove <= 0) {
                                cout << "Wrong input. Your number must be > 0" << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                bools.bank = false;
                                flag = false;
                            }

                            if (remove > bankbalance) {
                                cout << "Wrong input, you do not have enough money in the bank" << endl;
                                bools.bank = false;
                                flag = false;
                            }
                            bankbalance -= remove;
                            balance += remove;
                            cout << "Removed: " << remove << endl;
                            cout << "Current balance: " << balance << endl;
                            break;
                        case 3:
                            cout << "You earn 1%" << endl;
                            bankbalance += percents;
                            break;
                            if (cin.fail()) {
                                cout << "Wrong input" << endl;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                        case 4:
                            bools.bank = false;
                            flag = false;
                            cin >> choice;
                            break;
                        }
                }
            }
        case 5:
            while (classes21) {
                if (flag) {
                    if (mainclass == 11) {
                        cout << "You finish school and win the game!!!" << endl;
                        bools.running = false;
                    }
                    else {
                        cout << "You need to have a 11 mainclass" << endl;
                        flag = false;
                        cin >> choice;
                        classes21 = false;
                    }
                }
            }
            
        case 6:
            bools.running = false;
        }
    }
    return 0;
}
