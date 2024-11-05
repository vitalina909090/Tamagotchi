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
using namespace std;

class Information {
protected:
    struct Product {
        static int num_dry_food;
        static int num_hay;
        static int num_carrot;
        static int num_banana;
        static int num_fish;
        static int num_soap;
        static int num_shampoo;
        static int num_shower_gel;
        static int num_soapy_washcloth;
    };

    static string name;
    static string favorite;
    static string gender;
    static string favorite_food;
    static int choice_menu;
    static int money;
    static Product product;
    static int food_indicator;
    static int wash_indicator;
    static int love_indicator;

    static time_t last_update_time;
    static time_t last_love_update;

public:


    Information() {}
    //: name(""),
        //favorite(""),
        //gender(""),
        //favorite_food(""),
        /*choice_menu(1),*/
        //money(0),
        //product{ 2, 0, 0, 0, 0, 2, 0, 1, 0 },
        //food_indicator(100),
        //wash_indicator(100),
        //love_indicator(0),
        //last_update_time(time(nullptr)),
        //last_love_update(0)

    void setName(const string& petName) { name = petName; }
    void setFavorite(const string& petFavorite) { favorite = petFavorite; }
    void setGender(const string& petGender) { gender = petGender; }
    void setFood(const string& petFood) { favorite_food = petFood; }

    string getName() const { return name; }
    string getFavorite() const { return favorite; }
    string getGender() const { return gender; }
    string getFood() const { return favorite_food; }

    static void passport() {
        cout << "===================================" << endl;
        cout << "              Паспорт              " << endl;
        cout << "===================================" << endl;
        cout << "Ваш улюбленець: " << favorite << endl;
        cout << "Ім'я: " << name << endl;
        cout << "Стать: " << gender << endl;
        cout << "Улюблена їжа: " << favorite_food << endl;
        cout << "===================================" << endl;
    }   

};

class Screen: public Information {
public:
    void main_screen() {
        system("cls");
        cout << "\t\tГРА ТАМАГОЧІ" << endl;
        if (favorite == "Котик") {
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
        else if (favorite == "Мавпочка") {
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
        else if (favorite == "Зайчик") {
            //            cout << R"(
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
            /// l/ ,-~    \
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

        cout << "\t\tМеню\n[1] Паспорт улюбленця\n[2] Магазин\n[3] Міні ігри\n[4] Погодувати\n[5] Помити\n[6] Проявити турботу\n[7] Інвентар\n[8] Підказки\n[0] Вийти" << endl;
        cin >> choice_menu;
    }
};

class Inventory :public Information {
public:
    void show() const {
        bool availability_food = false, availability_wash = false;

        cout << "============================================================" << endl;
        cout << "                        Інвентар                            " << endl;
        cout << "============================================================" << endl;
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

    Product& getProduct() {
        return product;
    }
};

class Shop: public Information, public Screen {
public:
    void display() {
        int choice_shop, choice_buy;
        int choice_product;

        string buyer_choice;
        int price = 0;

        map<string, int> goods;
        goods["Сухий корм"] = 40;
        goods["Сіно"] = 20;
        goods["Морква"] = 100;
        goods["Банан"] = 80;
        goods["Риба"] = 90;
        goods["Мило"] = 150;
        goods["Шампунь"] = 130;
        goods["Гель для душу"] = 120;
        goods["Намилена мочалка"] = 100;

        cout << "============================================================" << endl;
        cout << "                          Магазин                           " << endl;
        cout << "============================================================" << endl;

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
        )" << endl;

        cout << "\nПривіт! Вітаю тебе у моєму магазині, обирай що подобається" << endl;

        do {
            cout << "\n[1] Відділ з їжою\n[2] Відділ миючих засобів\n[0] Повернутись назад" << endl;
            cin >> choice_shop;

            if (choice_shop == 0) {
                Screen::main_screen();
                return;
            }

            while (choice_shop == 1 || choice_shop == 2) {
                cout << "\nУ вас " << Information::money << " M" << endl;

                if (choice_shop == 1) {
                    cout << "Їжа для тваринок:" << endl;
                    cout << "[1] Сухий корм - " << goods["Сухий корм"] << " М" << endl;
                    cout << "[2] Сіно - " << goods["Сіно"] << " М" << endl;
                    cout << "[3] Морква - " << goods["Морква"] << " М" << endl;
                    cout << "[4] Банан - " << goods["Банан"] << " М" << endl;
                    cout << "[5] Риба - " << goods["Риба"] << " М" << endl;
                }
                else {
                    cout << "Миючі засоби:" << endl;
                    cout << "[1] Мило - " << goods["Мило"] << " М" << endl;
                    cout << "[2] Шампунь - " << goods["Шампунь"] << " М" << endl;
                    cout << "[3] Гель для душу - " << goods["Гель для душу"] << " М" << endl;
                    cout << "[4] Намилена мочалка - " << goods["Намилена мочалка"] << " М" << endl;
                }

                cout << "[0] Повернутись назад" << endl;
                cout << "Виберіть товар: ";
                cin >> choice_product;

                if (choice_product == 0) break;


                if (choice_shop == 1) {
                    switch (choice_product) {
                    case 1:
                        buyer_choice = "Сухий корм";
                        price = goods["Сухий корм"];
                        break;
                    case 2:
                        buyer_choice = "Сіно";
                        price = goods["Сіно"];
                        break;
                    case 3:
                        buyer_choice = "Морква";
                        price = goods["Морква"];
                        break;
                    case 4:
                        buyer_choice = "Банан";
                        price = goods["Банан"];
                        break;
                    case 5:
                        buyer_choice = "Риба";
                        price = goods["Риба"];
                        break;
                    default: cout << "Введіть число 1-5" << endl; continue;
                    }
                }
                else {
                    switch (choice_product) {
                    case 1:
                        buyer_choice = "Мило";
                        price = goods["Мило"];
                        break;
                    case 2:
                        buyer_choice = "Шампунь";
                        price = goods["Шампунь"];
                        break;
                    case 3:
                        buyer_choice = "Гель для душу";
                        price = goods["Гель для душу"];
                        break;
                    case 4:
                        buyer_choice = "Намилена мочалка";
                        price = goods["Намилена мочалка"];
                        break;
                    default:
                        cout << "Введіть число 1-4" << endl;
                        continue;
                    }
                }

                cout << "Ви вибрали: " << buyer_choice << " - " << price << " М" << endl;
                cout << "Купити? [1] Так [2] Ні: ";
                cin >> choice_buy;

                if (choice_buy == 1) {
                    if (Information::money < price) {
                        cout << "Недостатньо монет!" << endl;
                    }
                    else {
                        cout << "Дякуємо за покупку!" << endl;
                        Information::money -= price;
                        if (buyer_choice == "Сухий корм")  Information::product.num_dry_food++;
                        else if (buyer_choice == "Сіно") Information::product.num_hay++;
                        else if (buyer_choice == "Морква") Information::product.num_carrot++;
                        else if (buyer_choice == "Банан") Information::product.num_banana++;
                        else if (buyer_choice == "Риба") Information::product.num_fish++;
                        else if (buyer_choice == "Мило") Information::product.num_soap++;
                        else if (buyer_choice == "Шампунь") Information::product.num_shampoo++;
                        else if (buyer_choice == "Гель для душу") Information::product.num_shower_gel++;
                        else if (buyer_choice == "Намилена мочалка") Information::product.num_soapy_washcloth++;
                    }
                }
                else if (choice_buy == 2) {
                    cout << "Ви скасували покупку." << endl;
                }
                else {
                    cout << "Введіть число 1-2" << endl;
                }
            }
        } while (true);
    }
};

class MiniGames: public Information, public Screen {
public:
    void play() {
        int choice_game;

        //Змінні для гри "Камінь, ножиці, папір"
        srand(time(NULL));
        int player_points = 0, computer_points = 0, choice_more = 1;

        do {
            cout << "============================================================" << endl;
            cout << "                        Міні ігри                           " << endl;
            cout << "============================================================" << endl;

            cout << "Обери гру: \n[1] Камінь, ножиці, папір\n[0] Повернутись назад" << endl;
            cin >> choice_game;

            switch (choice_game) {
            case 1:
                do {
                    system("cls");
                    cout << "\t\t\033[36mКамінь, ножиці, папір!\033[0m" << endl;
                    player_points = 0;
                    computer_points = 0;

                    for (int i = 1; i <= 3; i++) {
                        int choice_player;
                        cout << "\nРаунд " << i << " із 3" << endl;
                        do {
                            cout << "Оберіть один з варіантів:\n[1] Камінь\n[2] Ножиці\n[3] Папір" << endl;
                            cin >> choice_player;

                            if (choice_player < 1 || choice_player > 3) {
                                cout << "Введіть число 1-3" << endl;
                            }
                        } while (choice_player < 1 || choice_player > 3);

                        int choice_computer = rand() % 3 + 1;

                        cout << "Ви обрали: "
                            << (choice_player == 1 ? "Камінь" : choice_player == 2 ? "Ножиці" : "Папір") << endl;
                        cout << "Комп'ютер обрав: "
                            << (choice_computer == 1 ? "Камінь" : choice_computer == 2 ? "Ножиці" : "Папір") << endl;

                        if (choice_player == choice_computer) {
                            cout << "Нічия!" << endl;
                        }
                        else {
                            if ((choice_player == 1 && choice_computer == 2) ||
                                (choice_player == 2 && choice_computer == 3) ||
                                (choice_player == 3 && choice_computer == 1)) {
                                if (choice_player == 1 && choice_computer == 2) { cout << "Камінь б'є Ножиці" << endl; }
                                else if (choice_player == 2 && choice_computer == 3) { cout << "Ножиці б'ють Папір" << endl; }
                                else if (choice_player == 3 && choice_computer == 1) { cout << "Папір обгортає Камінь" << endl; }
                                cout << "\033[1;32mВи виграли цей раунд!\033[0m" << endl;
                                player_points++;
                            }
                            else {
                                if (choice_computer == 1 && choice_player == 2) { cout << "Камінь б'є Ножиці" << endl; }
                                else if (choice_computer == 2 && choice_player == 3) { cout << "Ножиці б'ють Папір" << endl; }
                                else if (choice_computer == 3 && choice_player == 1) { cout << "Папір обгортає Камінь" << endl; }
                                cout << "\033[1;31mКомп'ютер виграв цей раунд!\033[0m" << endl;
                                computer_points++;
                            }
                        }
                    }

                    cout << "\nПідсумки гри:\nВаші очки: " << player_points << "\nОчки комп'ютера: " << computer_points << endl;

                    if (player_points > computer_points) {
                        cout << "\033[1;32mВітаємо! Ви перемогли! На вашому балансі +100М\033[0m" << endl;
                        Information::money = Information::money + 100;
                    }
                    else if (player_points < computer_points) {
                        cout << "\033[1;31mКомп'ютер переміг!\033[0m" << endl;
                    }
                    else {
                        cout << "Нічия!" << endl;
                    }

                    do {
                        cout << "Зіграємо ще? [1] Так [0] Ні" << endl;
                        cin >> choice_more;
                        if (choice_more < 0 || choice_more > 1) { cout << "Введіть число 0-1" << endl; }
                        if (choice_more == 0) { system("cls"); }
                    } while (choice_more < 0 || choice_more > 1);

                } while (choice_more != 0);

                break;

            case 0:
                Screen::main_screen();
                return;

            default:
                cout << "Введіть число 0-1" << endl;
                break;
            }
        } while (true);
    }
};

class Care: public Information, public Screen {
public:

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

            cout << "Показник ситості: " << Information::food_indicator << "%" << endl;
            cout << "[1] Погодувати\n[0] Повернутись назад " << endl;
            cin >> choice_feed;

            switch (choice_feed) {
            case 1:
                system("cls");
                cout << "\t\tЇжа в інвентарю: " << endl;

                if (Information::product.num_dry_food > 0) {
                    cout << "Сухий корм: " << Information::product.num_dry_food << endl;
                    availability = true;
                    availability_cat_food = true;
                }
                if (Information::product.num_hay > 0) {
                    cout << "Сіно: " << Information::product.num_hay << endl;
                    availability = true;
                    availability_hay = true;
                }
                if (Information::product.num_carrot > 0) {
                    cout << "Морква: " << Information::product.num_carrot << endl;
                    availability = true;
                    availability_carrot = true;
                }
                if (Information::product.num_banana > 0) {
                    cout << "Банан: " << Information::product.num_banana << endl;
                    availability = true;
                    availability_banana = true;
                }
                if (Information::product.num_fish > 0) {
                    cout << "Риба: " << Information::product.num_fish << endl;
                    availability = true;
                    availability_fish = true;
                }

                if (!availability) {
                    cout << "Інвентар з їжою пустий" << endl;
                    do {
                        cout << "[0] Повернутись назад " << endl;
                        cin >> choice_feed;
                        if (choice_feed != 0) {
                            cout << "Такої функції немає " << endl;
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
                cin >> choice_food;

                num = 1;

                if (choice_food == 0) break;

                if (Information::food_indicator >= 100) {
                    cout << Information::name << " ситий!" << endl;
                    cout << "Погодуйте його трохи пізніше" << endl;
                    do {
                        cout << "[0] Повернуться назад" << endl;
                        cin >> choice_feed;
                        if (choice_feed != 0) {
                            cout << "Такой функции нет" << endl;
                        }
                    } while (choice_feed != 0);
                }
                else {
                    if (availability_cat_food && choice_food == num++) {
                        name_choice_food = "сухий корм";
                        Information::product.num_dry_food--;
                    }
                    else if (availability_hay && choice_food == num++) {
                        name_choice_food = "сіно";
                        Information::product.num_hay--;
                    }
                    else if (availability_carrot && choice_food == num++) {
                        name_choice_food = "морква";
                        Information::product.num_carrot--;
                    }
                    else if (availability_banana && choice_food == num++) {
                        name_choice_food = "банан";
                        Information::product.num_banana--;
                    }
                    else if (availability_fish && choice_food == num++) {
                        name_choice_food = "риба";
                        Information::product.num_fish--;
                    }
                    else {
                        cout << "Неправильний вибір. Спробуйте ще раз." << endl;
                        break;
                    }

                    if (name_choice_food == Information::favorite_food) {
                        add_indicator = 15;
                    }
                    else {
                        add_indicator = 5;
                    }


                    Information::food_indicator += add_indicator;
                    if (Information::food_indicator > 100) { Information::food_indicator = 100; }

                    if (Information::favorite == "Котик") {
                        cout << R"(
                           .'\                
                          //  ;               
                         /'   |               
        .----..._    _../ |   \               
         \'---._ `.-'      `  .'              
          `.    '              `.             
            :            _,.    '.            
            |     ,_    (() '    |            
            ;   .'(().  '      _/__..-        
            \ _ '       __  _.-'--._          
            ,'.'...____'::-'  \     `'        
           / |   /         .---.              
     .-.  '  '  / ,---.   (     )             
    / /       ,' (     )---`-`-`-.._          
   : '       /  '-`-`-`..........--'\         
   ' :      /  /                     '.       
   :  \    |  .'         o             \      
    \  '  .' /          o       .       '     
     \  `.|  :      ,    : _o--'.\      |     
      `. /  '       ))    (   )  \>     |     
        ;   |      ((      \ /    \___  |     
        ;   |      _))      `'.-'. ,-'` '     
        |    `.   ((`            |/    /      
        \     ).  .))            '    .       
     ----`-'-'  `''.::.________:::mx'' ---
    )" << endl;
                    }
                    else if (Information::favorite == "Мавпочка") {
                        cout << R"(
                                    __,__ 
                            .--.  .-"     "-.  .--.
                           / .. \/  .-. .-.  \/ .. \
                          | |  '|  /   Y   \  |'  | |
                          | \   \  \ 0 | 0 /  /   / |
                           \ '- ,\.-"`` ``"-./, -' /
                            `'-' /_   ^ ^   _\ '-'`
                            .--'|  \._ _ _./  |'--.
                          /`    \   \.-.  /   /    `\
                         /       '._/  |-' _.'       \
                        /          ;  /--~'   |       \
                       /        .'/|.-\--.     \       \
                      /   .'-. /.-.;\  |\|'~'-.|\       \
                      \       `-./`|_\_/ `     `\'.      \
                       '.      ;     ___)        '.`;    /
                         '-.,_ ;     ___)          \/   /
                          \   ``'------'\       \   `  /
                           '.    \       '.      |   ;/_
                       ___>     '.       \_ _ _/   ,  '--.
                      .'   '.   .-~~~~~-. /     |--'`~~-.  \
                     // / .---'/  .-~~-._/ / / /---..__.'  /
                    ((_(_/    /  /      (_(_(_(---.__    .'
                               | |     _              `~~`
                               | |     \'.
                                \ '....' |
                                 '.,___.' 
                        )" << endl;
                    }
                    else if (Information::favorite == "Зайчик") {
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

                    cout << "Ви використали " << name_choice_food << "!" << endl;
                    cout << "Показник ситості тепер: " << Information::food_indicator << "%" << endl;


                    if (last_choice_feed != 0) {
                        do {
                            cout << "[0] Повернутись назад " << endl;
                            cin >> last_choice_feed;
                            if (last_choice_feed != 0) {
                                cout << "Такої функції немає " << endl;
                            }
                        } while (last_choice_feed != 0);
                        feed();
                    }
                }


                break;

            case 0:
                Screen::main_screen();
                return;

            default:
                cout << "Введіть число 0-1" << endl;
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

            cout << "Показник чистоти: " << Information::wash_indicator << "%" << endl;
            cout << "[1] Помити\n[0] Повернутись назад " << endl;
            cin >> choice_wash;

            switch (choice_wash) {
            case 1:
                system("cls");
                cout << "\t\tЗасоби для миття в інвентарі: " << endl;

                if (Information::product.num_soap > 0) {
                    cout << "Мило: " << Information::product.num_soap << endl;
                    availability = true;
                    availability_soap = true;
                }
                if (Information::product.num_shampoo > 0) {
                    cout << "Шампунь: " << Information::product.num_shampoo << endl;
                    availability = true;
                    availability_shampoo = true;
                }
                if (Information::product.num_shower_gel > 0) {
                    cout << "Гель для душу: " << Information::product.num_shower_gel << endl;
                    availability = true;
                    availability_shower_gel = true;
                }
                if (Information::product.num_soapy_washcloth > 0) {
                    cout << "Намилена мочалка: " << Information::product.num_soapy_washcloth << endl;
                    availability = true;
                    availability_soapy_washcloth = true;
                }

                if (!availability) {
                    cout << "Інвентар для миття порожній" << endl;
                    do {
                        cout << "[0] Повернутись назад " << endl;
                        cin >> choice_wash;
                        if (choice_wash != 0) {
                            cout << "Такої функції немає " << endl;
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
                cin >> choice_cleaning;

                num = 1;

                if (choice_cleaning == 0) break;

                if (Information::wash_indicator >= 100) {
                    cout << Information::name << " вже чистий!" << endl;
                    cout << "Помийте його пізніше" << endl;
                    do {
                        cout << "[0] Повернутись назад" << endl;
                        cin >> choice_wash;
                        if (choice_wash != 0) {
                            cout << "Такої функції немає" << endl;
                        }
                    } while (choice_wash != 0);
                }
                else {
                    if (availability_soap && choice_cleaning == num++) {
                        name_choice_cleaning = "мило";
                        Information::product.num_soap--;
                    }
                    else if (availability_shampoo && choice_cleaning == num++) {
                        name_choice_cleaning = "шампунь";
                        Information::product.num_shampoo--;
                    }
                    else if (availability_shower_gel && choice_cleaning == num++) {
                        name_choice_cleaning = "гель для душу";
                        Information::product.num_shower_gel--;
                    }
                    else if (availability_soapy_washcloth && choice_cleaning == num++) {
                        name_choice_cleaning = "намилена мочалка";
                        Information::product.num_soapy_washcloth--;
                    }
                    else {
                        cout << "Неправильний вибір. Спробуйте ще раз." << endl;
                        break;
                    }

                    add_indicator = 20;
                    Information::wash_indicator += add_indicator;
                    if (Information::wash_indicator > 100) { Information::wash_indicator = 100; }
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
                    cout << "Показник чистоти тепер: " << Information::wash_indicator << "%" << endl;

                    if (last_choice_wash != 0) {
                        do {
                            cout << "[0] Повернутись назад " << endl;
                            cin >> last_choice_wash;
                            if (last_choice_wash != 0) {
                                cout << "Такої функції немає" << endl;
                            }
                        } while (last_choice_wash != 0);
                        wash();
                    }
                }
                break;

            case 0:
                Screen::main_screen();
                return;

            default:
                cout << "Введіть число 0-1" << endl;
                break;
            }
        } while (last_choice_wash != 0);
    }

    void love() {
        time_t time_now = time(nullptr);

        int choise_love;
        system("cls");
        cout << "============================================================" << endl;
        cout << "                     Проявити турботу                       " << endl;
        cout << "============================================================" << endl;

        cout << "[1] Обійняти\n[2] Погладити\n[3] Пограти\n[0] Повернутись назад" << endl;
        cin >> choise_love;

        if (difftime(time_now, Information::last_love_update) >= 1800) {
            do {
                system("cls");
                int love_balance = Information::love_indicator / 20;

                cout << "Рівень відносин: ";
                for (int i = 0; i < love_balance; i++) {
                    cout << "\033[31m*\033[0m" << " ";
                }

                for (int i = 0; i < 5 - love_balance; i++) {
                    cout << "*" << " ";
                }
                cout << endl << endl;

                switch (choise_love) {
                case 1:
                    if (love_balance < 3) {
                        cout << "Ваш рівень відносин занадто низький" << endl;
                        if (choise_love != 0) {
                            do {
                                cout << "\n[0] Повернутись назад " << endl;
                                cin >> choise_love;
                                if (choise_love != 0) {
                                    cout << "Такої функції немає" << endl;
                                }
                            } while (choise_love != 0);
                            love();
                        }
                    }
                    else {
                        if (Information::favorite == "Котик") {
                            cout << Information::name << " мурчить у ваших обіймах" << endl;
                        }
                        else if (Information::favorite == "Мавпочка") {
                            cout << Information::name << " весело крутить хвостом у ваших обіймах" << endl;
                        }
                        else if (Information::favorite == "Зайчик") {
                            cout << Information::name << " задоволено махає вушками у ваших обіймах" << endl;
                        }
                        cout << "Ваш рівень відносин збільшується на 20!" << endl;
                        Information::love_indicator += 20;
                        Information::last_love_update = time_now;
                    }
                    break;
                case 2:
                    if (Information::favorite == "Котик") {
                        cout << Information::name << " задоволено муркоче" << endl;
                    }
                    else if (Information::favorite == "Мавпочка") {
                        cout << Information::name << " підставляє голову під вашу руку" << endl;
                    }
                    else if (Information::favorite == "Зайчик") {
                        cout << Information::name << " ворушить хвостиком" << endl;
                    }
                    cout << "Ваш рівень відносин збільшується на 10!" << endl;
                    Information::love_indicator += 10;
                    Information::last_love_update = time_now;
                    break;
                case 3:
                    if (Information::favorite == "Котик") {
                        cout << "Ви берете іграшку на мотузці" << endl;
                        cout << Information::name << " перегортається на спинку і зацікавлено перебирає лапами" << endl;
                    }
                    else if (Information::favorite == "Мавпочка") {
                        cout << "Ви кидаєте м'ячик" << endl;
                        cout << Information::name << " бігає за ним по всій кімнаті" << endl;
                    }
                    else if (Information::favorite == "Зайчик") {
                        cout << "Ви даєте іграшку у вигляді морквини" << endl;
                        cout << Information::name << " із задоволенням грається" << endl;
                    }
                    cout << "Ваш рівень відносин збільшується на 10!" << endl;
                    Information::love_indicator += 10;
                    Information::last_love_update = time_now;
                    break;
                case 0:
                    return;
                default:
                    cout << "Введіть число 0-3" << endl;
                    break;
                }

                if (Information::love_indicator > 100) {
                    Information::love_indicator = 100;
                }

                if (choise_love != 0) {
                    do {
                        cout << "\n[0] Повернутись назад " << endl;
                        cin >> choise_love;
                        if (choise_love != 0) {
                            cout << "Такої функції немає" << endl;
                        }
                    } while (choise_love != 0);
                    love();
                }
            } while (true);
        }
        else {
            system("cls");
            cout << "============================================================" << endl;
            cout << "                     Проявити турботу                       " << endl;
            cout << "============================================================" << endl;
            int choise_last_love = 1;
            cout << "Ви можете оновити рівень відносин лише раз на 30 хвилин." << endl;

            do {
                cout << "\n[0] Повернутись назад " << endl;
                cin >> choise_last_love;

                if (choise_last_love != 0) {
                    cout << "Такої функції немає" << endl;
                }
            } while (choise_last_love != 0);

            Screen::main_screen();
        }
    }

    void updating_indicators() {
        time_t time_now = time(nullptr);
        int time_difference = static_cast<int>(difftime(time_now, Information::last_update_time));

        int decrease_indicators = time_difference / 10;
        Information::food_indicator = max(0, Information::food_indicator - decrease_indicators);
        Information::wash_indicator = max(0, Information::wash_indicator - decrease_indicators);
        Information::last_update_time = time_now;
    }
};

class Tamagotchi : public Information, public Care, public Screen {
public:

    void help() {
        cout << "============================================================" << endl;
        cout << "                        Підказки                            " << endl;
        cout << "============================================================" << endl;
        cout << "1. Улюблена їжа відновлює більше голоду\n2. Обійми доступні тільки з 3 рівня відносин\n3. Підвищити рівень відносин можна тільки один раз у 30хв\n4. Кожні 100с віднімається одиниця ситості і чистоти\n5. Монети можна зароботи у міні іграх " << endl;
    }

    void save(const string& filename) const {
        ofstream file(filename);
        if (!file){
            cout << "Не вдалося зберегти файл";
        };
        if (file.is_open()) {
            file << Information::name << "\n"
                << Information::favorite << "\n"
                << Information::gender << "\n"
                << Information::favorite_food << "\n"
                << Information::choice_menu << "\n"
                << Information::money << "\n"
                << Information::product.num_dry_food << "\n"
                << Information::product.num_hay << "\n"
                << Information::product.num_carrot << "\n"
                << Information::product.num_banana << "\n"
                << Information::product.num_fish << "\n"
                << Information::product.num_soap << "\n"
                << Information::product.num_shampoo << "\n"
                << Information::product.num_shower_gel << "\n"
                << Information::product.num_soapy_washcloth << "\n"
                << Information::food_indicator << "\n"
                << Information::wash_indicator << "\n"
                << Information::love_indicator << "\n"
                << Information::last_update_time << "\n"
                << Information::last_love_update << "\n";

            file.close();
        }
    }

    static void load(const string& filename) {
        ifstream file(filename);
        if (!file) { 
            cout << "Не вдалося відкрити файл для читання."; 
        };
        if (file.is_open()) {
            getline(file, Information::name);
            getline(file, Information::favorite);
            getline(file, Information::gender);
            getline(file, Information::favorite_food);
            file >> Information::choice_menu >> Information::money
                >> Information::product.num_dry_food >> Information::product.num_hay >> Information::product.num_carrot
                >> Information::product.num_banana >> Information::product.num_fish
                >> Information::product.num_soap >> Information::product.num_shampoo
                >> Information::product.num_shower_gel >> Information::product.num_soapy_washcloth >>
                Information::food_indicator >> Information::wash_indicator
                >> Information::love_indicator
                >> Information::last_update_time >> Information::last_love_update;

            file.close();

            time_t time_now = time(nullptr);
            int time_difference = static_cast<int>(difftime(time_now, Information::last_update_time));

            int decrease_indicators = time_difference / 10;

            Information::food_indicator = max(0, Information::food_indicator - decrease_indicators);
            Information::wash_indicator = max(0, Information::wash_indicator - decrease_indicators);

            Information::last_update_time = time_now;
        }
    }
};

class Menu : public Information, public Shop, public MiniGames, public Care, public Inventory, public Tamagotchi, public Screen {
public:

    void menu() {
        do {
            switch (Information::choice_menu) {
            case 1:
                system("cls");
                Information::passport();
                cout << "\t\tМеню\n\033[34m\033[1m[1] Паспорт улюбленця\033[0m\n[2] Магазин\n[3] Міні ігри\n[4] Погодувати\n[5] Помити\n[6] Проявити турботу\n[7] Інвентар\n[8] Підказки\n[9] Повернутись на головний екран\n[0] Вийти" << endl;
                cin >> Information::choice_menu;
                break;
            case 2:
                system("cls");
                Shop::display();
                break;
            case 3:
                system("cls");
                MiniGames::play();
                break;
            case 4:
                system("cls");
                Care::feed();
                break;
            case 5:
                system("cls");
                Care::wash();
                break;
            case 6:
                system("cls");
                Care::love();
                break;
            case 7:
                system("cls");
                Inventory::show();
                cout << "\n\t\tМеню\n[1] Паспорт улюбленця\n[2] Магазин\n[3] Міні ігри\n[4] Погодувати\n[5] Помити\n[6] Проявити турботу\n\033[34m\033[1m[7] Інвентар\033[0m\n[8] Підказки\n[9] Повернутись на головний екран\n[0] Вийти" << endl;
                cin >> Information::choice_menu;
                break;
            case 8:
                system("cls");
                Tamagotchi::help();
                cout << "\n\t\tМеню\n[1] Паспорт улюбленця\n[2] Магазин\n[3] Міні ігри\n[4] Погодувати\n[5] Помити\n[6] Проявити турботу\n[7] Інвентар\n\033[34m\033[1m[8] Підказки\033[0m\n[9] Повернутись на головний екран\n[0] Вийти" << endl;
                cin >> Information::choice_menu;
                break;
            case 9:
                system("cls");
                Screen::main_screen();
                break;
            default:
                cout << "Введіть число 0-9" << endl;
            }
        } while (Information::choice_menu != 0);
    }
};

string Information::name = "";
string Information::favorite = "";
string Information::gender = "";
string Information::favorite_food = "";
int Information::choice_menu = 1;
int Information::money = 0;
int Information::food_indicator = 100;
int Information::wash_indicator = 100;
int Information::love_indicator = 0;
time_t Information::last_update_time = time(nullptr);
time_t Information::last_love_update = time(nullptr);

int Information::Product::num_dry_food = 2;
int Information::Product::num_hay = 0;
int Information::Product::num_carrot = 0;
int Information::Product::num_banana = 0;
int Information::Product::num_fish = 2;
int Information::Product::num_soap = 0;
int Information::Product::num_shampoo = 1;
int Information::Product::num_shower_gel = 0;
int Information::Product::num_soapy_washcloth = 0;

Information::Product Information::product;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu menu;
    Tamagotchi info;
    Information information;
    Screen screen;
    info.load("tamagotchi_save.txt");

    int favorite = 0, gender = 0;
    string name, favorite_food;

    if (information.getName().empty()) {
        cout << "\t\tГРА ТАМАГОЧІ\nЗаповніть анкету..." << endl;

        do {
            cout << "Оберіть улюбленця!\n[1] Котик\n[2] Мавпочка\n[3] Зайчик" << endl;
            cin >> favorite;

            switch (favorite) {
            case 1:
                cout << "Ви обрали КОТИКА! Попіклуйтесь про нього" << endl;
                information.setFavorite("Котик");
                information.setFood("Риба");
                break;
            case 2:
                cout << "Ви обрали МАВПОЧКУ! Попіклуйтесь про неї" << endl;
                information.setFavorite("Мавпочка");
                information.setFood("Банан");
                break;
            case 3:
                cout << "Ви обрали ЗАЙЧИКА! Попіклуйтесь про нього" << endl;
                information.setFavorite("Зайчик");
                information.setFood("Морква");
                break;
            default:
                cout << "Введіть число 1-3" << endl;
            }
        } while (favorite < 1 || favorite > 3);

        /*Sleep(2000);*/
        system("cls");
        cout << "\t\tГРА ТАМАГОЧІ\nЗаповніть анкету..." << endl;

        do {
            cout << "Оберіть стать\n[1] Хлопчик\n[2] Дівчинка" << endl;
            cin >> gender;
            switch (gender) {
            case 1:
                cout << "Записав!" << endl;
                information.setGender("Хлопчик");
                break;
            case 2:
                cout << "Записав!" << endl;
                information.setGender("Дівчинка");
                break;
            default:
                cout << "Введіть число 1-2" << endl;
            }
        } while (gender < 1 || gender > 2);

        /*Sleep(1500);*/
        system("cls");
        cout << "\t\tГРА ТАМАГОЧІ\nЗаповніть анкету..." << endl;

        cout << "Впишіть ім'я вашого улюбленця: " << endl;
        cin.ignore();
        getline(cin, name);
        information.setName(name);
        cout << "Яке гарне ім'я!" << endl;

        //Sleep(1500);
        //for (int i = 0; i < 2; i++) {
        //    system("cls");
        //    cout << "\t\tГРА ТАМАГОЧІ" << endl;
        //    cout << "Генерую вашого улюбленця";
        //    Sleep(500);
        //    for (int i = 0; i < 3; i++) {
        //        cout << ".";
        //        Sleep(500);
        //    }
        //}
        system("cls");

        info.save("tamagotchi_save.txt");
    }


    screen.main_screen();
    menu.menu();


    info.save("tamagotchi_save.txt");

    return 0;
}