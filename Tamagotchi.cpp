#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include <fstream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <limits>

using namespace std;

class Tamagotchi {
protected:
    struct Product {
        int num_dry_food;
        int num_hay;
        int num_carrot;
        int num_banana;
        int num_fish;
        int num_soap;
        int num_shampoo;
        int num_shower_gel;
        int num_soapy_washcloth;
    };

    string name, favorite, gender, favorite_food;
    int choice_menu;

    int money;
    Product product;

    int food_indicator, wash_indicator, love_indicator;
    time_t last_update_time;
    time_t last_love_update;

public:
    Tamagotchi()
        : name(""), favorite(""), gender(""), favorite_food(""),
        choice_menu(0), money(0), product{ 2, 0, 0, 0, 0, 2, 0, 1, 0 },
        food_indicator(100), wash_indicator(100), love_indicator(0),
        last_update_time(time(nullptr)), last_love_update(0) {}

    Tamagotchi(const string& petName, const string& petFavorite, const string& petGender, const string& petFood,
        int petChoiceMenu, int petMoney, const Product& petProduct, int petFoodIndicator, int petWashIndicator,
        int petLoveIndicator, time_t petLastUpdateTime, time_t petLastLoveUpdateTime)
        : name(petName), favorite(petFavorite), gender(petGender), favorite_food(petFood),
        choice_menu(petChoiceMenu), money(petMoney), product(petProduct), food_indicator(petFoodIndicator),
        wash_indicator(petWashIndicator), love_indicator(petLoveIndicator),
        last_update_time(petLastUpdateTime), last_love_update(petLastLoveUpdateTime) {}


    void setName(const string& petName) { name = petName; }
    void setFavorite(const string& petFavorite) { favorite = petFavorite; }
    void setGender(const string& petGender) { gender = petGender; }
    void setFood(const string& petFood) { favorite_food = petFood; }

    string getName() const { return name; }
    string getFavorite() const { return favorite; }
    string getGender() const { return gender; }
    string getFavoriteFood() const { return favorite_food; }

    int getChoiceMenu() const { return choice_menu; }
    int getMoney() const { return money; }
    int getFoodIndicator() const { return food_indicator; }
    int getWashIndicator() const { return wash_indicator; }
    int getLoveIndicator() const { return love_indicator; }
    time_t getLastUpdateTime() const { return last_update_time; }
    time_t getLastLoveUpdateTime() const { return last_love_update; }

    Product getProduct() const { return product; }

    void passport() const {
        cout << "===================================" << endl;
        cout << "              Паспорт              " << endl;
        cout << "===================================" << endl;
        cout << "Ваш улюбленець: " << favorite << endl;
        cout << "Ім'я: " << getName() << endl;
        cout << "Стать: " << getGender() << endl;
        cout << "Улюблена їжа: " << favorite_food << endl;
        cout << "===================================" << endl;
    }

    void shop() {
        int choice_shop = -1, choice_buy, choice_product;
        string buyer_choice;
        int price = 0;

        map<string, int> goods = {
            {"Сухий корм", 40}, {"Сіно", 20}, {"Морква", 100}, {"Банан", 80}, {"Риба", 90},
            {"Мило", 150}, {"Шампунь", 130}, {"Гель для душу", 120}, {"Намилена мочалка", 100}
        };

        cout << "============================================================\n";
        cout << "                          Магазин                           \n";
        cout << "============================================================\n";
        cout << R"(
        /'~~~~~~~\|/
       ,/'     ____ \
      |   ,,__/    '| \
     ,|_./___   ___ |  |
       |-(  .)-(.  )|,'
      (|  ~~~   ~~~   |)
       |     -'      |'
        \   ,____,   /
         \   --'   /
          |\______/|
         |\________/|
         \----------/
    )" << "\n";

        cout << "\nПривіт! Вітаю тебе у моєму магазині, обирай що подобається\n";

        do {
            cout << "\n[1] Відділ з їжою\n[2] Відділ миючих засобів\n[0] Повернутись назад\n";
            cout << "Введіть свій вибір: ";

            if (!(cin >> choice_shop)) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "\033[1;31mВведіть число!\033[0m\n";
                continue;
            }

            if (choice_shop == 0) {
                main_screen();
                return;
            }
            else if (choice_shop != 1 && choice_shop != 2) {
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m\n";
                continue;
            }

            while (choice_shop == 1 || choice_shop == 2) {
                cout << "\nУ вас " << money << " M\n";

                if (choice_shop == 1) {
                    cout << "Їжа для тваринок:\n";
                    cout << "[1] Сухий корм - " << goods["Сухий корм"] << " M\n";
                    cout << "[2] Сіно - " << goods["Сіно"] << " M\n";
                    cout << "[3] Морква - " << goods["Морква"] << " M\n";
                    cout << "[4] Банан - " << goods["Банан"] << " M\n";
                    cout << "[5] Риба - " << goods["Риба"] << " M\n";
                }
                else {
                    cout << "Миючі засоби:\n";
                    cout << "[1] Мило - " << goods["Мило"] << " M\n";
                    cout << "[2] Шампунь - " << goods["Шампунь"] << " M\n";
                    cout << "[3] Гель для душу - " << goods["Гель для душу"] << " M\n";
                    cout << "[4] Намилена мочалка - " << goods["Намилена мочалка"] << " M\n";
                }

                cout << "[0] Повернутись назад\n";
                cout << "Виберіть товар: ";
                if (!(cin >> choice_product)) {
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << "\033[1;31mТакої позиції немає\033[0m\n";
                    continue;
                }

                if (choice_product == 0) break;

                try {
                    if (choice_shop == 1) {
                        switch (choice_product) {
                        case 1: buyer_choice = "Сухий корм"; price = goods["Сухий корм"]; break;
                        case 2: buyer_choice = "Сіно"; price = goods["Сіно"]; break;
                        case 3: buyer_choice = "Морква"; price = goods["Морква"]; break;
                        case 4: buyer_choice = "Банан"; price = goods["Банан"]; break;
                        case 5: buyer_choice = "Риба"; price = goods["Риба"]; break;
                        default: throw ("\033[1;31mТакої позиції немає\033[0m");
                        }
                    }
                    else {
                        switch (choice_product) {
                        case 1: buyer_choice = "Мило"; price = goods["Мило"]; break;
                        case 2: buyer_choice = "Шампунь"; price = goods["Шампунь"]; break;
                        case 3: buyer_choice = "Гель для душу"; price = goods["Гель для душу"]; break;
                        case 4: buyer_choice = "Намилена мочалка"; price = goods["Намилена мочалка"]; break;
                        default: throw ("\033[1;31mТакої позиції немає\033[0m");
                        }
                    }
                }
                catch (const char* error) {
                    cout << "\033[1;31m" << error << "\033[0m" << endl;
                    continue;
                }

                cout << "Ви вибрали: " << buyer_choice << " - " << price << " M\n";
                cout << "Купити? [1] Так [2] Ні: ";
                if (!(cin >> choice_buy) || (choice_buy != 1 && choice_buy != 2)) {
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m\n";
                    continue;
                }

                if (choice_buy == 1) {
                    if (money < price) {
                        cout << "Недостатньо монет!\n";
                    }
                    else {
                        cout << "Дякуємо за покупку!\n";
                        money -= price;
                        if (buyer_choice == "Сухий корм") product.num_dry_food++;
                        else if (buyer_choice == "Сіно") product.num_hay++;
                        else if (buyer_choice == "Морква") product.num_carrot++;
                        else if (buyer_choice == "Банан") product.num_banana++;
                        else if (buyer_choice == "Риба") product.num_fish++;
                        else if (buyer_choice == "Мило") product.num_soap++;
                        else if (buyer_choice == "Шампунь") product.num_shampoo++;
                        else if (buyer_choice == "Гель для душу") product.num_shower_gel++;
                        else if (buyer_choice == "Намилена мочалка") product.num_soapy_washcloth++;
                    }
                }
                else {
                    cout << "Ви скасували покупку\n";
                }
            }
        } while (true);
    }

    void mini_games() {
        int choice_game;
        srand(time(NULL));

        do {
            int player_points = 0, computer_points = 0, choice_more = 1;
            system("cls");
            cout << "============================================================\n";
            cout << "                        Міні ігри                           \n";
            cout << "============================================================\n";

            cout << "Обери гру: \n[1] Камінь, ножиці, папір\n[2] Хрестики-Нулики\n[0] Повернутись назад\n";
            cout << "Ваш вибір: ";

            while (!(cin >> choice_game) || choice_game < 0 || choice_game > 2) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
            }

            switch (choice_game) {
            case 1:
                do {
                    system("cls");
                    cout << "\t\t\033[36mКамінь, ножиці, папір!\033[0m\n";
                    player_points = 0;
                    computer_points = 0;

                    for (int i = 1; i <= 3; i++) {
                        int choice_player;
                        cout << "\nРаунд " << i << " із 3\n";
                        do {
                            cout << "Оберіть один з варіантів:\n[1] Камінь\n[2] Ножиці\n[3] Папір\n";
                            cout << "Ваш вибір: ";

                            if (!(cin >> choice_player) || choice_player < 1 || choice_player > 3) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "\033[1;31mВведіть число 1-3!\033[0m\n";
                            }
                            else {
                                break;
                            }
                        } while (true);

                        int choice_computer = rand() % 3 + 1;

                        cout << "Ви обрали: "
                            << (choice_player == 1 ? "Камінь" : choice_player == 2 ? "Ножиці" : "Папір") << endl;
                        cout << "Комп'ютер обрав: "
                            << (choice_computer == 1 ? "Камінь" : choice_computer == 2 ? "Ножиці" : "Папір") << endl;

                        if (choice_player == choice_computer) {
                            cout << "Нічия!\n";
                        }
                        else if ((choice_player == 1 && choice_computer == 2) ||
                            (choice_player == 2 && choice_computer == 3) ||
                            (choice_player == 3 && choice_computer == 1)) {
                            cout << "\033[1;32mВи виграли цей раунд!\033[0m\n";
                            player_points++;
                        }
                        else {
                            cout << "\033[1;31mКомп'ютер виграв цей раунд!\033[0m\n";
                            computer_points++;
                        }
                    }

                    cout << "\nПідсумки гри:\nВаші очки: " << player_points
                        << "\nОчки комп'ютера: " << computer_points << endl;

                    if (player_points > computer_points) {
                        cout << "\033[1;32mВітаємо! Ви перемогли! На вашому балансі +100M\033[0m\n";
                        money += 100;
                    }
                    else if (player_points < computer_points) {
                        cout << "\033[1;31mКомп'ютер переміг!\033[0m\n";
                    }
                    else {
                        cout << "Нічия!\n";
                    }

                    do {
                        cout << "Зіграємо ще? [1] Так [0] Ні\n";
                        cout << "Ваш вибір: ";

                        if (!(cin >> choice_more) || choice_more < 0 || choice_more > 1) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m\n";
                        }
                        else {
                            break;
                        }
                    } while (true);

                } while (choice_more != 0);
                break;
            case 2:
                do {
                    system("cls");
                    cout << "\t\t\033[36mХрестики-Нулики\033[0m" << endl;

                    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
                    char player_symbol, computer_symbol;
                    int moves = 0, turn = 1;

                    do {
                        cout << "Оберіть символ:\n[1] Хрестик (X)\n[2] Нолик (O)\n";
                        int choice_symbol;
                        cin >> choice_symbol;

                        if (cin.fail() || choice_symbol < 1 || choice_symbol > 2) {
                            cout << "\033[1;31mНевірний вибір! Спробуйте ще раз.\033[0m\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        else {
                            player_symbol = (choice_symbol == 1) ? 'X' : 'O';
                            computer_symbol = (choice_symbol == 1) ? 'O' : 'X';
                            break;
                        }
                    } while (true);

                    while (true) {
                        cout << "\nПоле:\n";
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 3; j++) {
                                cout << " " << board[i][j];
                                if (j < 2) cout << " |";
                            }
                            cout << endl;
                            if (i < 2) cout << "---|---|---\n";
                        }

                        char whose_move = (turn % 2 == 1) ? player_symbol : computer_symbol;

                        if (whose_move == player_symbol) {
                            int choice_move;
                            bool valid_move = false;

                            do {
                                cout << "\nВаш хід! Оберіть номер поля: ";
                                cin >> choice_move;

                                if (cin.fail() || choice_move < 1 || choice_move > 9) {
                                    cout << "\033[1;31mНевірний хід! Введіть число від 1 до 9.\033[0m\n";
                                    cin.clear();
                                    cin.ignore(10000, '\n');
                                }
                                else {
                                    for (int i = 0; i < 3; i++) {
                                        for (int j = 0; j < 3; j++) {
                                            if (board[i][j] == '0' + choice_move) {
                                                board[i][j] = whose_move;
                                                valid_move = true;
                                                break;
                                            }
                                        }
                                        if (valid_move) break;
                                    }
                                    if (!valid_move) {
                                        cout << "\033[1;31mЦе поле вже зайняте! Спробуйте інше.\033[0m\n";
                                    }
                                }
                            } while (!valid_move);
                        }
                        else {
                            cout << "\nХід комп'ютера...\n";
                            bool right_move = false;
                            while (!right_move) {
                                int choice_computer = rand() % 9 + 1;
                                for (int i = 0; i < 3; i++) {
                                    for (int j = 0; j < 3; j++) {
                                        if (board[i][j] == '0' + choice_computer) {
                                            board[i][j] = whose_move;
                                            right_move = true;
                                            break;
                                        }
                                    }
                                    if (right_move) break;
                                }
                            }
                        }

                        moves++;
                        bool win = false;
                        for (int i = 0; i < 3; i++) {
                            if ((board[i][0] == whose_move && board[i][1] == whose_move && board[i][2] == whose_move) ||
                                (board[0][i] == whose_move && board[1][i] == whose_move && board[2][i] == whose_move)) {
                                win = true;
                                break;
                            }
                        }
                        if (!win && ((board[0][0] == whose_move && board[1][1] == whose_move && board[2][2] == whose_move) ||
                            (board[0][2] == whose_move && board[1][1] == whose_move && board[2][0] == whose_move))) {
                            win = true;
                        }

                        if (win) {
                            cout << "\n" << (whose_move == player_symbol ? "\033[1;32mВітаємо! Ви перемогли! На вашому балансі +100М\033[0m" : "\033[1;31mКомп'ютер переміг!\033[0m") << endl;
                            if (whose_move == player_symbol) {
                                money = money + 100;
                            }
                            break;
                        }

                        if (moves == 9) {
                            cout << "\nНічия! Поле заповнене" << endl;
                            break;
                        }

                        turn++;
                    }

                    do {
                        cout << "Зіграємо ще? [1] Так [0] Ні" << endl;
                        cin >> choice_more;

                        if (cin.fail() || choice_more < 0 || choice_more > 1) {
                            cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    } while (cin.fail() || choice_more < 0 || choice_more > 1);

                } while (choice_more != 0);

                break;

            case 0:
                main_screen();
                return;

            default:
                cout << "\033[1;31mНеправильний вибір!\033[0m\n";
            }
        } while (true);
    }

    virtual void feed_img() {}
    void feed() {
        int choice_feed;
        int last_choice_feed = 1;

        bool availability = false;
        bool availability_cat_food = false;
        bool availability_hay = false;
        bool availability_carrot = false;
        bool availability_banana = false;
        bool availability_fish = false;

        int num = 1;
        int choice_food;
        string name_choice_food;
        int add_indicator = 0;

        do {
            updating_indicators();
            system("cls");
            cout << "============================================================" << endl;
            cout << "                   Погодувати улюбленця                     " << endl;
            cout << "============================================================" << endl;

            cout << "Показник ситості: " << food_indicator << "%" << endl;
            cout << "[1] Погодувати\n[0] Повернутись назад " << endl;

            while (!(cin >> choice_feed) || choice_feed < 0 || choice_feed > 1) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
            }

            switch (choice_feed) {
            case 1:
                system("cls");
                cout << "\t\tЇжа в інвентарю: " << endl;

                if (product.num_dry_food > 0) {
                    cout << "Сухий корм: " << product.num_dry_food << endl;
                    availability = true;
                    availability_cat_food = true;
                }
                if (product.num_hay > 0) {
                    cout << "Сіно: " << product.num_hay << endl;
                    availability = true;
                    availability_hay = true;
                }
                if (product.num_carrot > 0) {
                    cout << "Морква: " << product.num_carrot << endl;
                    availability = true;
                    availability_carrot = true;
                }
                if (product.num_banana > 0) {
                    cout << "Банан: " << product.num_banana << endl;
                    availability = true;
                    availability_banana = true;
                }
                if (product.num_fish > 0) {
                    cout << "Риба: " << product.num_fish << endl;
                    availability = true;
                    availability_fish = true;
                }

                if (!availability) {
                    cout << "Інвентар з їжою пустий" << endl;
                    do {
                        cout << "[0] Повернутись назад " << endl;
                        while (!(cin >> choice_feed) || choice_feed != 0) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                        }
                    } while (choice_feed != 0);
                    break;
                }

                cout << "Оберіть чим годувати:" << endl;
                if (availability_cat_food) {
                    cout << "[" << num++ << "] Сухий корм" << endl;
                }
                if (availability_hay) {
                    cout << "[" << num++ << "] Сіно" << endl;
                }
                if (availability_carrot) {
                    cout << "[" << num++ << "] Морква" << endl;
                }
                if (availability_banana) {
                    cout << "[" << num++ << "] Банан" << endl;
                }
                if (availability_fish) {
                    cout << "[" << num++ << "] Риба" << endl;
                }
                cout << "[0] Повернутись назад " << endl;

                while (!(cin >> choice_food) || choice_food < 0 || choice_food > num - 1) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
                }

                num = 1;

                if (choice_food == 0) break;

                if (food_indicator >= 100) {
                    cout << "Улюбленець ситий!" << endl;
                    cout << "Погодуйте його трохи пізніше" << endl;
                    do {
                        cout << "[0] Повернутись назад" << endl;
                        while (!(cin >> choice_feed) || choice_feed != 0) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                        }
                    } while (choice_feed != 0);
                }
                else {
                    if (availability_cat_food && choice_food == num++) {
                        name_choice_food = "сухий корм";
                        product.num_dry_food--;
                    }
                    else if (availability_hay && choice_food == num++) {
                        name_choice_food = "сіно";
                        product.num_hay--;
                    }
                    else if (availability_carrot && choice_food == num++) {
                        name_choice_food = "морква";
                        product.num_carrot--;
                    }
                    else if (availability_banana && choice_food == num++) {
                        name_choice_food = "банан";
                        product.num_banana--;
                    }
                    else if (availability_fish && choice_food == num++) {
                        name_choice_food = "риба";
                        product.num_fish--;
                    }
                    else {
                        cout << "\033[1;31mНеправильний вибір. Спробуйте ще раз\033[0m" << endl;
                        break;
                    }

                    if (name_choice_food == favorite_food) {
                        add_indicator = 30;
                    }
                    else {
                        add_indicator = 20;
                    }

                    food_indicator += add_indicator;
                    if (food_indicator > 100) { food_indicator = 100; }

                    this->feed_img();

                    cout << "Ви використали " << name_choice_food << "!" << endl;
                    cout << "Показник ситості тепер: " << food_indicator << "%" << endl;

                    if (last_choice_feed != 0) {
                        do {
                            cout << "[0] Повернутись назад " << endl;
                            while (!(cin >> last_choice_feed) || last_choice_feed != 0) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                            }
                        } while (last_choice_feed != 0);
                        feed();
                    }
                }
                break;

            case 0:
                main_screen();
                return;

            default:
                cout << "\033[1;31mОберіть один із запропонованих пунктів\033[0m" << endl;
                break;
            }
        } while (last_choice_feed != 0);
    }

    void wash() {
        updating_indicators();
        int choice_wash;
        int last_choice_wash = 1;

        bool availability = false;
        bool availability_soap = false;
        bool availability_shampoo = false;
        bool availability_shower_gel = false;
        bool availability_soapy_washcloth = false;

        int num = 1;
        int choice_cleaning;
        string name_choice_cleaning;
        int add_indicator = 0;

        do {
            system("cls");
            cout << "============================================================" << endl;
            cout << "                   Помити улюбленця                         " << endl;
            cout << "============================================================" << endl;

            cout << "Показник чистоти: " << wash_indicator << "%" << endl;
            cout << "[1] Помити\n[0] Повернутись назад " << endl;

            while (!(cin >> choice_wash) || choice_wash < 0 || choice_wash > 1) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
            }

            switch (choice_wash) {
            case 1:
                system("cls");
                cout << "\t\tЗасоби для миття в інвентарі: " << endl;

                if (product.num_soap > 0) {
                    cout << "Мило: " << product.num_soap << endl;
                    availability = true;
                    availability_soap = true;
                }
                if (product.num_shampoo > 0) {
                    cout << "Шампунь: " << product.num_shampoo << endl;
                    availability = true;
                    availability_shampoo = true;
                }
                if (product.num_shower_gel > 0) {
                    cout << "Гель для душу: " << product.num_shower_gel << endl;
                    availability = true;
                    availability_shower_gel = true;
                }
                if (product.num_soapy_washcloth > 0) {
                    cout << "Намилена мочалка: " << product.num_soapy_washcloth << endl;
                    availability = true;
                    availability_soapy_washcloth = true;
                }

                if (!availability) {
                    cout << "Інвентар для миття порожній" << endl;
                    do {
                        cout << "[0] Повернутись назад " << endl;
                        while (!(cin >> choice_wash) || choice_wash != 0) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                        }
                    } while (choice_wash != 0);
                    break;
                }

                cout << "Оберіть, чим мити улюбленця:" << endl;
                if (availability_soap) {
                    cout << "[" << num++ << "] Мило" << endl;
                }
                if (availability_shampoo) {
                    cout << "[" << num++ << "] Шампунь" << endl;
                }
                if (availability_shower_gel) {
                    cout << "[" << num++ << "] Гель для душу" << endl;
                }
                if (availability_soapy_washcloth) {
                    cout << "[" << num++ << "] Намилена мочалка" << endl;
                }
                cout << "[0] Повернутись назад " << endl;

                while (!(cin >> choice_cleaning) || choice_cleaning < 0 || choice_cleaning >= num) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
                }

                num = 1;

                if (choice_cleaning == 0) break;

                if (wash_indicator >= 100) {
                    cout << "Улюбленець вже чистий!" << endl;
                    cout << "Помийте його пізніше" << endl;
                    cout << "[0] Повернутись назад " << endl;
                    do {
                        while (!(cin >> choice_wash) || choice_wash != 0) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                        }
                    } while (choice_wash != 0);
                    break;
                }

                else {
                    if (availability_soap && choice_cleaning == num++) {
                        name_choice_cleaning = "мило";
                        product.num_soap--;
                    }
                    else if (availability_shampoo && choice_cleaning == num++) {
                        name_choice_cleaning = "шампунь";
                        product.num_shampoo--;
                    }
                    else if (availability_shower_gel && choice_cleaning == num++) {
                        name_choice_cleaning = "гель для душу";
                        product.num_shower_gel--;
                    }
                    else if (availability_soapy_washcloth && choice_cleaning == num++) {
                        name_choice_cleaning = "намилена мочалка";
                        product.num_soapy_washcloth--;
                    }
                    else {
                        cout << "Неправильний вибір. Спробуйте ще раз." << endl;
                        break;
                    }

                    add_indicator = 20;
                    wash_indicator += add_indicator;
                    if (wash_indicator > 100) { wash_indicator = 100; }
                    cout << R"(
o    .   _     . 
          .     (_)         o
   o                      _       o
  _    o     O      .   o  (_)   .
 (_)             o   O             _
 o        o        ,_ ,  o   o    (_)
  . O     O    O       o      .  ,        o
     o8o 8OOo o8OoOo OOo8Oo8 O88Oo
    o8o8O OoOO Ooo8OoOoOo o8OOo8Oo||     O
   Oo(""o8"""""""""""""""8oo""""""")
  _   \'                  '   /'   o
 (_)    \                       /    _   .
      O  \           _         /    (_)
o   .     -. .----<(o)_--. .-'
   --------(_/------(_<_/--\_)--------
)";

                    cout << "\nВи використали " << name_choice_cleaning << "!" << endl;
                    cout << "Показник чистоти тепер: " << wash_indicator << "%" << endl;
                }
                if (last_choice_wash != 0) {
                    do {
                        cout << "[0] Повернутись назад " << endl;
                        while (!(cin >> last_choice_wash) || last_choice_wash != 0) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                        }
                        if (last_choice_wash != 0) {
                            cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                        }
                    } while (last_choice_wash != 0);
                    wash();
                }
                break;

            case 0:
                main_screen();
                return;

            default:
                cout << "\033[1;31mОберіть один із запропонованих пунктів\033[0m" << endl;
                break;
            }
        } while (last_choice_wash != 0);
    }

    virtual void love_txt1() {}
    virtual void love_txt2() {}
    virtual void love_txt3() {}
    void love() {
        time_t time_now = time(nullptr);

        int choice_love;
        system("cls");
        cout << "============================================================" << endl;
        cout << "                     Проявити турботу                       " << endl;
        cout << "============================================================" << endl;

        cout << "[1] Обійняти\n[2] Погладити\n[3] Пограти\n[0] Повернутись назад" << endl;

        while (!(cin >> choice_love) || choice_love < 0 || choice_love > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
        }

        if (choice_love == 0) {
            main_screen();
            return;
        }

        if (difftime(time_now, last_love_update) >= 1800) {
            do {
                system("cls");
                int love_balance = love_indicator / 20;

                cout << "Рівень відносин: ";
                for (int i = 0; i < love_balance; i++) {
                    cout << "\033[31m*\033[0m" << " ";
                }
                for (int i = 0; i < 5 - love_balance; i++) {
                    cout << "*" << " ";
                }
                cout << endl << endl;

                switch (choice_love) {
                case 1:
                    if (love_balance < 3) {
                        cout << "Ваш рівень відносин занадто низький" << endl;
                    }
                    else {
                        love_txt1();
                        cout << "Ваш рівень відносин збільшується на 20!" << endl;
                        love_indicator += 20;
                        last_love_update = time_now;
                    }
                    break;
                case 2:
                    love_txt2();
                    cout << "Ваш рівень відносин збільшується на 10!" << endl;
                    love_indicator += 10;
                    last_love_update = time_now;
                    break;
                case 3:
                    love_txt3();
                    cout << "Ваш рівень відносин збільшується на 10!" << endl;
                    love_indicator += 10;
                    last_love_update = time_now;
                    break;
                default:
                    cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
                }

                love_indicator = min(love_indicator, 100);

                cout << "\n[0] Повернутись назад " << endl;
                while (!(cin >> choice_love) || choice_love != 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                }

                if (choice_love == 0) {
                    return;
                }
            } while (true);
        }
        else {
            system("cls");
            cout << "============================================================" << endl;
            cout << "                     Проявити турботу                       " << endl;
            cout << "============================================================" << endl;
            cout << "Ви можете оновити рівень відносин лише раз на 30 хвилин." << endl;

            int choice_last_love;
            do {
                cout << "\n[0] Повернутись назад " << endl;
                while (!(cin >> choice_last_love) || choice_last_love != 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\033[1;31mВведіть 0 для повернення!\033[0m" << endl;
                }
            } while (choice_last_love != 0);

            main_screen();
        }
    }


    void inventory() const {
        bool availability_food = false, availability_wash = false;

        cout << "============================================================" << endl;
        cout << "                        Інвентар                            " << endl;
        cout << "============================================================" << endl;
        cout << "\t\tГроші: " << endl;
        cout << "У вас " << money << " M\n";

        cout << "\t\tЇжа: " << endl;

        if (product.num_dry_food > 0) {
            cout << "Сухий корм: " << product.num_dry_food << endl;
            availability_food = true;
        }
        if (product.num_hay > 0) {
            cout << "Сіно: " << product.num_hay << endl;
            availability_food = true;
        }
        if (product.num_carrot > 0) {
            cout << "Морква: " << product.num_carrot << endl;
            availability_food = true;
        }
        if (product.num_banana > 0) {
            cout << "Банан: " << product.num_banana << endl;
            availability_food = true;
        }
        if (product.num_fish > 0) {
            cout << "Риба: " << product.num_fish << endl;
            availability_food = true;
        }
        if (!availability_food) {
            cout << "Інвентар з їжою пустий" << endl;
        }

        cout << "\tЗасоби для миття: " << endl;

        if (product.num_soap > 0) {
            cout << "Мило: " << product.num_soap << endl;
            availability_wash = true;
        }
        if (product.num_shampoo > 0) {
            cout << "Шампунь: " << product.num_shampoo << endl;
            availability_wash = true;
        }
        if (product.num_shower_gel > 0) {
            cout << "Гель для душу: " << product.num_shower_gel << endl;
            availability_wash = true;
        }
        if (product.num_soapy_washcloth > 0) {
            cout << "Намилена мочалка: " << product.num_soapy_washcloth << endl;
            availability_wash = true;
        }

        if (!availability_wash) {
            cout << "Інвентар для миття порожній" << endl;
        }
    }

    void help() {
        cout << "============================================================" << endl;
        cout << "                        Підказки                            " << endl;
        cout << "============================================================" << endl;
        cout << "1. Улюблена їжа відновлює більше голоду\n2. Обійми доступні тільки з 3 рівня відносин\n3. Підвищити рівень відносин можна тільки один раз у 30хв\n4. Кожні 100с віднімається одиниця ситості і чистоти\n5. Монети можна заробити у міні іграх " << endl;
    }

    virtual void main_img(){}
    void main_screen() {
        system("cls");
        cout << "\t\tГРА ТАМАГОЧІ" << endl;
        main_img();
        cout << "\t\tМеню\n[1] Паспорт улюбленця\n[2] Магазин\n[3] Міні ігри\n[4] Погодувати\n[5] Помити\n[6] Проявити турботу\n[7] Інвентар\n[8] Підказки\n[0] Вийти" << endl;

        while (!(cin >> choice_menu) || choice_menu < 0 || choice_menu > 8) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
        }
    }

    void menu() {
        do {
            switch (choice_menu) {
            case 1:
                system("cls");
                passport();
                cout << "\t\tМеню\n\033[34m\033[1m[1] Паспорт улюбленця\033[0m\n[2] Магазин\n[3] Міні ігри\n[4] Погодувати\n[5] Помити\n[6] Проявити турботу\n[7] Інвентар\n[8] Підказки\n[9] Повернутись на головний екран\n[0] Вийти" << endl;
                while (!(cin >> choice_menu) || choice_menu < 0 || choice_menu > 9) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
                }
                break;

            case 2:
                system("cls");
                shop();
                break;

            case 3:
                system("cls");
                mini_games();
                break;

            case 4:
                system("cls");
                feed();
                break;

            case 5:
                system("cls");
                wash();
                break;

            case 6:
                system("cls");
                love();
                break;

            case 7:
                system("cls");
                inventory();
                cout << "\n\t\tМеню\n[1] Паспорт улюбленця\n[2] Магазин\n[3] Міні ігри\n[4] Погодувати\n[5] Помити\n[6] Проявити турботу\n\033[34m\033[1m[7] Інвентар\033[0m\n[8] Підказки\n[9] Повернутись на головний екран\n[0] Вийти" << endl;
                while (!(cin >> choice_menu) || choice_menu < 0 || choice_menu > 9) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
                }
                break;

            case 8:
                system("cls");
                help();
                cout << "\n\t\tМеню\n[1] Паспорт улюбленця\n[2] Магазин\n[3] Міні ігри\n[4] Погодувати\n[5] Помити\n[6] Проявити турботу\n[7] Інвентар\n\033[34m\033[1m[8] Підказки\033[0m\n[9] Повернутись на головний екран\n[0] Вийти" << endl;
                while (!(cin >> choice_menu) || choice_menu < 0 || choice_menu > 9) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
                }
                break;

            case 9:
                system("cls");
                main_screen();
                break;

            default:
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
            }
        } while (choice_menu != 0);
    }


    void save(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            file << name << "\n"
                << favorite << "\n"
                << gender << "\n"
                << favorite_food << "\n"
                << choice_menu << "\n"
                << money << "\n"
                << product.num_dry_food << "\n"
                << product.num_hay << "\n"
                << product.num_carrot << "\n"
                << product.num_banana << "\n"
                << product.num_fish << "\n"
                << product.num_soap << "\n"
                << product.num_shampoo << "\n"
                << product.num_shower_gel << "\n"
                << product.num_soapy_washcloth << "\n"
                << food_indicator << "\n"
                << wash_indicator << "\n"
                << love_indicator << "\n"
                << last_update_time << "\n"
                << last_love_update << "\n";

            file.close();
        }
    }

    void load(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            getline(file, name);
            getline(file, favorite);
            getline(file, gender);
            getline(file, favorite_food);
            file >> choice_menu >> money
                >> product.num_dry_food >> product.num_hay >> product.num_carrot
                >> product.num_banana >> product.num_fish
                >> product.num_soap >> product.num_shampoo
                >> product.num_shower_gel >> product.num_soapy_washcloth
                >> food_indicator >> wash_indicator
                >> love_indicator
                >> last_update_time >> last_love_update;

            file.close();

            // Преобразуем время в количество секунд с момента последнего обновления
            time_t time_now = time(nullptr);
            int time_difference = static_cast<int>(difftime(time_now, last_update_time));

            int decrease_indicators = time_difference / 100;

            food_indicator = max(0, food_indicator - decrease_indicators);
            wash_indicator = max(0, wash_indicator - decrease_indicators);

            last_update_time = time_now;
        }
    }

    void updating_indicators() {
        time_t time_now = time(nullptr);
        int time_difference = static_cast<int>(difftime(time_now, last_update_time));

        int decrease_indicators = time_difference / 100;
        food_indicator = max(0, food_indicator - decrease_indicators);
        wash_indicator = max(0, wash_indicator - decrease_indicators);
        last_update_time = time_now;
    }

};

class Cat : public Tamagotchi {
public:
    Cat(const string& petName, const string& petFavorite, const string& petGender, const string& petFood,
        int petChoiceMenu, int petMoney, const Product& petProduct, int petFoodIndicator, int petWashIndicator,
        int petLoveIndicator, time_t petLastUpdateTime, time_t petLastLoveUpdateTime)
        : Tamagotchi(petName, "Котик", petGender, "риба", petChoiceMenu, petMoney, petProduct, petFoodIndicator,
            petWashIndicator, petLoveIndicator, petLastUpdateTime, petLastLoveUpdateTime) {}

    void feed_img() override {
        cout << "                           .'\\                " << endl;
        cout << "                          //  ;               " << endl;
        cout << "                         /'   |               " << endl;
        cout << "        .----..._    _../ |   \\               " << endl;
        cout << "         \\'---._ `.-'      `  .'              " << endl;
        cout << "          `.    '              `.             " << endl;
        cout << "            :            _,.    '.           " << endl;
        cout << "            |     ,_    (() '    |           " << endl;
        cout << "            ;   .'(().  '      _/__..-       " << endl;
        cout << "            \\ _ '       __  _.-'--._         " << endl;
        cout << "            ,'.'...____'::-'  \\     `'       " << endl;
        cout << "           / |   /         .---.              " << endl;
        cout << "     .-.  '  '  / ,---.   (     )             " << endl;
        cout << "    / /       ,' (     )---`-`-`-.._         " << endl;
        cout << "   : '       /  '-`-`-`..........--'\\        " << endl;
        cout << "   ' :      /  /                     '.      " << endl;
        cout << "   :  \\    |  .'         o             \\     " << endl;
        cout << "    \\  '  .' /          o               '    " << endl;
        cout << "     \\  `.|  :      ,    : \033[36m _o--'.\\ \033[0m     |    " << endl;
        cout << "      `. /  '       ))    \033[36m(   )  \\> \033[0m     |    " << endl;
        cout << "        ;   |      ((      \033[36m\\ /    \\___\033[0m   |    " << endl;
        cout << "        ;   |      _))      \033[36m`'.-'. ,-'`\033[0m  '   " << endl;
        cout << "        |    `.   ((`            \033[36m|/\033[0m     /         " << endl;
        cout << "        \\     ).  .))            \033[36m'\033[0m    .      " << endl;
        cout << "     ----`-'-'  `''.::.________:::'' ---   " << endl;
    }
    void love_txt1() { cout << name << " мурчить у ваших обіймах" << endl;}
    void love_txt2() { cout << name << " задоволено муркоче" << endl; }
    void love_txt3() {
        cout << "Ви берете іграшку на мотузці" << endl;
        cout << name << " перегортається на спинку і зацікавлено перебирає лапами" << endl;
    }
    void main_img() override{
        //cout << "   /\\_____/\\" << endl;
//cout << "  /  o   o  \\" << endl;
//cout << " ( ==  ^  == )" << endl;
//cout << "  )         (" << endl;
//cout << " (           )" << endl;
//cout << " ( (  )   (  ) )" << endl;
//cout << "(__(__)___(__)__)" << endl;

//cout << "      |\\      _,,,---,,_" << endl;
//cout << "ZZZzz /,`.-'`'    -.  ;-;;,_" << endl;
//cout << "     |,4-  ) )-,_. ,\\ (  `'-'" << endl;
//cout << "    '---''(_/--'  `-\\_)" << endl;


//cout << "           __..--''``---....___   _..._    __" << endl;
//cout << " /// //_.-'    .-/\";  `        ``<._  ``.''_ `. / // /" << endl;
//cout << "///_.-' _..--.'_    \\                    `( ) ) // //" << endl;
//cout << "/ (_..-' // (< _     ;_..__               ; `' / ///" << endl;
//cout << " / // // //  `-._,_)' // / ``--...____..-' /// / //" << endl;

//cout << "                   _ |\\_" << endl;
//cout << "                   \\` ..\\" << endl;
//cout << "              __,.-\" =__Y=" << endl;
//cout << "            .\"        )" << endl;
//cout << "      _    /   ,    \\/\\_" << endl;
//cout << "     ((____|    )_-\\ \\_-`" << endl;
//cout << "  `-----'`-----` `--`" << endl;

//cout << "  ,-.       _,---._ __  / \\" << endl;
//cout << " /  )    .-'       `./ /   \\" << endl;
//cout << "(  (   ,'            `/    /|" << endl;
//cout << " \\  `-\"             '\\   / |" << endl;
//cout << "  `.              ,  \\ \\ /  |" << endl;
//cout << "   /`.          ,'-`----Y   |" << endl;
//cout << "  (            ;        |   '" << endl;
//cout << "  |  ,-.    ,-'         |  /" << endl;
//cout << "  |  | (   |        hjw | /" << endl;
//cout << "  )  |  \\  `.___________|/" << endl;
//cout << "  `--'   `--'" << endl;


        cout << "       _                        " << endl;
        cout << "       \\`*-.                    " << endl;
        cout << "        )  _`-.                 " << endl;
        cout << "       .  : `. .                 " << endl;
        cout << "       : _   '  \\               " << endl;
        cout << "       ; *` _.   `*-._           " << endl;
        cout << "       `-.-'          `-.        " << endl;
        cout << "         ;       `       `.      " << endl;
        cout << "         :.       .        \\     " << endl;
        cout << "         . \\  .   :   .-'   .    " << endl;
        cout << "         '  `+.;  ;  '      :    " << endl;
        cout << "         :  '  |    ;       ;-.  " << endl;
        cout << "         ; '   : :`-:     _.`* ;  " << endl;
        cout << "      .*' /  .*' ; .*`- +'  `*'   " << endl;
        cout << "      `*-*   `*-*  `*-*'          " << endl;

        //cout << "       ," << endl;
        //cout << "       \\`-._           __" << endl;
        //cout << "        \\\\  `-..____,.'  `." << endl;
        //cout << "         :`.         /    \\`." << endl;
        //cout << "         :  )       :      : \\" << endl;
        //cout << "          ;'        '   ;  |  :" << endl;
        //cout << "          )..      .. .:.`.;  :" << endl;
        //cout << "         /::...  .:::...   ` ;" << endl;
        //cout << "         ; _ '    __        /:\\" << endl;
        //cout << "         `:o>   /\\o_>      ;:. `." << endl;
        //cout << "        `-`.__ ;   __..--- /:.   \\" << endl;
        //cout << "        === \\_/   ;=====_.':.     ;" << endl;
        //cout << "         ,/'`--'...`--....        ;" << endl;
        //cout << "              ;                    ;" << endl;
        //cout << "            .'                      ;" << endl;
        //cout << "          .'                        ;" << endl;
        //cout << "        .'     ..     ,      .       ;" << endl;
        //cout << "       :       ::..  /      ;::.     |" << endl;
        //cout << "      /      `.;::.  |       ;:..    ;" << endl;
        //cout << "     :         |:.   :       ;:.    ;" << endl;
        //cout << "     :         ::     ;:..   |.    ;" << endl;
        //cout << "      :       :;      :::....|     |" << endl;
        //cout << "      /\\     ,/ \\      ;:::::;     ;" << endl;
        //cout << "    .:. \\:..|    :     ; '.--|     ;" << endl;
        //cout << "   ::.  :''  `-.,,;     ;'   ;     ;" << endl;
        //cout << ".-'. _.'\\      / `;      \\__,:      \\" << endl;
        //cout << "`---'    `----'   ;      /    \\,.,,,/" << endl;
    }
};
class Monkey : public Tamagotchi {
public:
    Monkey(const string& petName, const string& petFavorite, const string& petGender, const string& petFood,
        int petChoiceMenu, int petMoney, const Product& petProduct, int petFoodIndicator, int petWashIndicator,
        int petLoveIndicator, time_t petLastUpdateTime, time_t petLastLoveUpdateTime)
        : Tamagotchi(petName, "Мавпочка", petGender, "банан", petChoiceMenu, petMoney, petProduct, petFoodIndicator,
            petWashIndicator, petLoveIndicator, petLastUpdateTime, petLastLoveUpdateTime) {}
    void feed_img() override {
        cout << "                    __,__ " << endl;
        cout << "            .--.  .-\"     \"-.  .--." << endl;
        cout << "           / .. \\/  .-. .-.  \\/ .. \\" << endl;
        cout << "          | |  '|  /   Y   \\  |'  | |" << endl;
        cout << "          | \\   \\  \\ 0 | 0 /  /   / |" << endl;
        cout << "           \\ '- ,\\.-\"`` ``\"-.\\/,-' /" << endl;
        cout << "            `'-' /_   ^ ^   _\\ '-'`" << endl;
        cout << "            .--'|  \\._ _ _./  |'--." << endl;
        cout << "          /`    \\   \\\033[33m.-.\033[0m  /   /    `\\ " << endl;
        cout << "         /       '._\033[33m/  |\033[0m-' _.'       \\" << endl;
        cout << "        /          \033[33m;  /\033[0m--~'   |       \\" << endl;
        cout << "       /        \033[33m.'/|.-\\\033[0m--.     \\       \\" << endl;
        cout << "      /   .'-. \033[33m/.-.;\\  |\\|\033[0m'~'-.|\\       \\" << endl;
        cout << "      \\       `-./`\033[33m|_\\_/\033[0m `     `\\'.      \\" << endl;
        cout << "       '.      ;     ___)        '.`;    /" << endl;
        cout << "         '-.,_ ;     ___)          \\/   /" << endl;
        cout << "          \\   ``'------'\\       \\   `  /" << endl;
        cout << "           '.    \\       '.      |   ;/_" << endl;
        cout << "       ___>     '.       \\_ _ _/   ,  '--." << endl;
        cout << "      .'   '.   .-~~~~~-. /     |--'`~~-.  \\" << endl;
        cout << "     // / .---'/  .-~~-._/ / / /---..__.'  /" << endl;
        cout << "    ((_(_/    /  /      (_(_(_(---.__    .'" << endl;
        cout << "             | |     _              `~~`" << endl;
        cout << "              | |     \\'." << endl;
        cout << "               \\ '....' |" << endl;
        cout << "                '.,___.' " << endl;

    }

    virtual void love_txt1() { cout << name << " весело крутить хвостом у ваших обіймах" << endl; }
    virtual void love_txt2() { cout << name << " підставляє голову під вашу руку" << endl; }
    virtual void love_txt3() {
        cout << "Ви кидаєте м'ячик" << endl;
        cout << name << " бігає за ним по всій кімнаті" << endl;
    }
    void main_img() override{
    cout << R"(
               .-"""-.
             _/-=-.   \
            (_|a a/   |_ 
             / "  \   ,_)
        _    \`=' /__/
       / \_  .;--'  `-.
       \___)//      ,  \
        \ \/;        \  \
         \_.|         | |
          .-\ '     _/_/
        .'  _;.    (_  \
       /  .'   `\   \\_/
      |_ /       |  |\\
     /  _)       /  / ||
    /  /       _/  /  //
    \_/       ( `-/  ||
              /  /   \\ .-.
              \_/     \'-/ 
                       `"`
    )" << endl;

    //
    //            cout << R"(
    //                __,__ 
    //        .--.  .-"     "-.  .--.
    //       / .. \/  .-. .-.  \/ .. \
            //      | |  '|  /   Y   \  |'  | |
            //      | \   \  \ 0 | 0 /  /   / |
            //       \ '- ,\.-"`` ``"-./, -' /
            //        `'-' /_   ^ ^   _\ '-'`
            //        .--'|  \._ _ _./  |'--.
            //      /`    \   \.-.  /   /    `\
            //     /       '._/  |-' _.'       \
            //    /          ;  /--~'   |       \
            //   /        .'/|.-\--.     \       \
            //  /   .'-. /.-.;\  |\|'~'-.|\       \
            //  \       `-./`|_\_/ `     `\'.      \
            //   '.      ;     ___)        '.`;    /
            //     '-.,_ ;     ___)          \/   /
            //      \   ``'------'\       \   `  /
            //       '.    \       '.      |   ;/_
            //   ___>     '.       \_ _ _/   ,  '--.
            //  .'   '.   .-~~~~~-. /     |--'`~~-.  \
            // // / .---'/  .-~~-._/ / / /---..__.'  /
            //((_(_/    /  /      (_(_(_(---.__    .'
            //           | |     _              `~~`
            //           | |     \'.
            //            \ '....' |
            //             '.,___.' 
            //    )" << endl;
    }
};
class Rabbit : public Tamagotchi {
public:
    Rabbit(const string& petName, const string& petFavorite, const string& petGender, const string& petFood,
        int petChoiceMenu, int petMoney, const Product& petProduct, int petFoodIndicator, int petWashIndicator,
        int petLoveIndicator, time_t petLastUpdateTime, time_t petLastLoveUpdateTime)
        : Tamagotchi(petName, "Зайчик", petGender, "морква", petChoiceMenu, petMoney, petProduct, petFoodIndicator,
            petWashIndicator, petLoveIndicator, petLastUpdateTime, petLastLoveUpdateTime) {}
    void feed_img() override {
        cout << "       /|      __ " << endl;
        cout << "      / |   ,-~ /" << endl;
        cout << "     Y :|  //  /" << endl;
        cout << "     | jj /( .^" << endl;
        cout << "     >-\"~\"-v\"" << endl;
        cout << "    /       Y" << endl;
        cout << "   jo  o    |" << endl;
        cout << "  ( ~T~     j" << endl;
        cout << "   >._-' _./" << endl;
        cout << "  /   \033[32m\\/_\033[0m  |" << endl;
        cout << " _/  \033[32m_/\033[0m     l       " << endl;
        cout << " /  \033[38;5;214m(,;)\033[0m ,-~ \\" << endl;
        cout << " |  \033[38;5;214m(,.)\033[0m   .- \\" << endl;
        cout << " |\\/\033[38;5;214m(,/\033[0m\\/  /   Y" << endl;
        cout << " Y  \033[38;5;214m|/\033[0m     /   Y" << endl;
        cout << " l       I     !" << endl;
        cout << " ]\\      _\\    /\"\\ " << endl;
        cout << "(\" ~----( ~   Y.  )" << endl;
    }

    virtual void love_txt1() { cout << name << " задоволено махає вушками у ваших обіймах" << endl; }
    virtual void love_txt2() { cout << name << " ворушить хвостиком" << endl; }
    virtual void love_txt3() {
        cout << "Ви даєте іграшку у вигляді морквини" << endl;
        cout << name << " із задоволенням грається" << endl;
    }
    void main_img() override {
            //        cout << R"(
            //         , 
            //        /|      __
            //       / |   ,-~ /
            //      Y :|  //  /
            //      | jj /( .^
            //      >-"~"-v"
            //     /       Y
            //    jo  o    |
            //   ( ~T~     j
            //    >._-' _./
            //   /   "~"  |
            //  Y     _,  |
            // /| ;-"~ _  l
            // l/ ,-~    \
            //\//\/      .- \
            // Y        /    Y
            // l       I     !
            // ]\      _\    /"\
            //(" ~----( ~   Y.  )
            //    )" << endl;

        cout << R"(
                     /\    .-"/
                    /  ; .'  .' 
                   :   :/  .'   
                    \  ;-.'     
       .--"""--..__/     `.    
     .'           .'    `o  \   
    /                    `   ;  
   :                  \      :  
 .-;        -.         `.__.-'  
:  ;          \     ,   ;       
'._:           ;   :   (        
    \/  .__    ;    \   `-.     
     ;     "-,/_.--"`-..__)    
     '""--.._:
    )" << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int favorite = 0, gender = 0;
    string name;

    Tamagotchi* pet = new Tamagotchi();
    pet->load("tamagotchi_save.txt");
    Sleep(1500);

    if (pet->getName().empty()) {
        cout << "\t\tГРА ТАМАГОЧІ\nЗаповніть анкету..." << endl;

        do {
            cout << "Оберіть улюбленця!\n[1] Котик\n[2] Мавпочка\n[3] Зайчик" << endl;

            while (!(cin >> favorite) || favorite < 1 || favorite > 3) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
            }

            switch (favorite) {
            case 1:
                cout << "Ви обрали КОТИКА! Попіклуйтесь про нього" << endl;
                pet = new Cat(pet->getName(), pet->getFavorite(), pet->getGender(), pet->getFavoriteFood(), pet->getChoiceMenu(),
                    pet->getMoney(), pet->getProduct(), pet->getFoodIndicator(), pet->getWashIndicator(),
                    pet->getLoveIndicator(), pet->getLastUpdateTime(), pet->getLastLoveUpdateTime());
                break;
            case 2:
                cout << "Ви обрали МАВПОЧКУ! Попіклуйтесь про неї" << endl;
                pet = new Monkey(pet->getName(), pet->getFavorite(), pet->getGender(), pet->getFavoriteFood(), pet->getChoiceMenu(),
                    pet->getMoney(), pet->getProduct(), pet->getFoodIndicator(), pet->getWashIndicator(),
                    pet->getLoveIndicator(), pet->getLastUpdateTime(), pet->getLastLoveUpdateTime());
                break;
            case 3:
                cout << "Ви обрали ЗАЙЧИКА! Попіклуйтесь про нього" << endl;
                pet = new Rabbit(pet->getName(), pet->getFavorite(), pet->getGender(), pet->getFavoriteFood(), pet->getChoiceMenu(),
                    pet->getMoney(), pet->getProduct(), pet->getFoodIndicator(), pet->getWashIndicator(),
                    pet->getLoveIndicator(), pet->getLastUpdateTime(), pet->getLastLoveUpdateTime());
                break;
            default:
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
            }
        } while (favorite < 1 || favorite > 3 );

        Sleep(2000);

        system("cls");
        cout << "\t\tГРА ТАМАГОЧІ\nЗаповніть анкету..." << endl;

        do {
            cout << "Оберіть стать\n[1] Хлопчик\n[2] Дівчинка" << endl;

            while (!(cin >> gender) || gender < 1 || gender > 2) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
            }

            switch (gender) {
            case 1:
                cout << "Записав!" << endl;
                pet->setGender("Хлопчик");
                break;
            case 2:
                cout << "Записав!" << endl;
                pet->setGender("Дівчинка");
                break;
            default:
                cout << "\033[1;31mОберіть один із запропонованих пунктів!\033[0m" << endl;
            }
        } while (gender < 1 || gender > 2);

        Sleep(1500);

        system("cls");
        cout << "\t\tГРА ТАМАГОЧІ\nЗаповніть анкету..." << endl;

        cout << "Впишіть ім'я вашого улюбленця: " << endl;
        cin.ignore();
        getline(cin, name);
        pet->setName(name);
        cout << "Яке гарне ім'я!" << endl;

        Sleep(1500);

        for (int i = 0; i < 2; i++) {
            system("cls");
            cout << "\t\tГРА ТАМАГОЧІ" << endl;
            cout << "Генерую вашого улюбленця";
            Sleep(500);
            for (int i = 0; i < 3; i++) {
                cout << ".";
                Sleep(500);
            }
        }
        system("cls");

        pet->save("tamagotchi_save.txt");
    }
    else {
        if (pet->getFavorite() == "Котик") {
            pet = new Cat(pet->getName(), pet->getFavorite(), pet->getGender(), pet->getFavoriteFood(), pet->getChoiceMenu(),
                pet->getMoney(), pet->getProduct(), pet->getFoodIndicator(), pet->getWashIndicator(),
                pet->getLoveIndicator(), pet->getLastUpdateTime(), pet->getLastLoveUpdateTime());
        }
        else if (pet->getFavorite() == "Мавпочка") {
            pet = new Monkey(pet->getName(), pet->getFavorite(), pet->getGender(), pet->getFavoriteFood(), pet->getChoiceMenu(),
                pet->getMoney(), pet->getProduct(), pet->getFoodIndicator(), pet->getWashIndicator(),
                pet->getLoveIndicator(), pet->getLastUpdateTime(), pet->getLastLoveUpdateTime());
        }
        else if (pet->getFavorite() == "Зайчик") {
            pet = new Rabbit(pet->getName(), pet->getFavorite(), pet->getGender(), pet->getFavoriteFood(), pet->getChoiceMenu(),
                pet->getMoney(), pet->getProduct(), pet->getFoodIndicator(), pet->getWashIndicator(),
                pet->getLoveIndicator(), pet->getLastUpdateTime(), pet->getLastLoveUpdateTime());
        }
    }

    pet->main_screen();
    pet->menu();

    pet->save("tamagotchi_save.txt");

    delete pet;
    return 0;
}

