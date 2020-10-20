#include <iostream>
#include "player_random.h"
#include "player_smart.h"
#include "game.h"
#include "PLAYER.h"
using namespace std;

//bool testCreatboardAndShowboard(Game game)
//{
//    game.creatBoard();
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            if (game.getBoard().value[i][j] != '#')
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//bool testMakestepZero(Game game)
//{
//    game.creatBoard();
//    if (game.makeStep<Zero>(rand() % 3, rand() % 3))
//    {
//        return true;
//        game.showBoard();
//    }
//    return false;
// }
//bool testMakestepX(Game game)
//{
//    game.creatBoard();
//    if (game.makeStep<Сross>(rand() % 3, rand() % 3))
//    {
//        return true;
//        game.showBoard();
//    }
//    return false;
//}

int enterCheckNumber(int min, int max) //Проверка и ввод числа
{
    int number=0;
    string str;
    cin >> str;
    while (str.size() > 1) 
      {
        cout << "Чиcло введено неверно!\nПопробуйте снова:";
        cin >> str;
      }

    number = stoi(str);

    while (!(number >= min && number <= max))
    {
        cout << "Чиcло введено неверно!\nПопробуйте снова:";
        cin >> number;
    }

    return number;
}

int main()
{
    /* cout << testCreatboardAndShowboard(game);
     cout << testMakestepZero(game);
     cout << testMakestepX(game);*/
    setlocale(LC_ALL, "ru");
    string first_player, second_player, answer;
    int count = 0;
    int x, y;
    
    cout << "Добро пожаловать в игру крестики нолики!" << endl << "Введите имя первого игрока(Нолики,игрок со случайными ходами): ";
    cin >> first_player;
    cout << endl;
    cout << "Введите имя второго игрока(Крестики, думайющий игрок): ";
    cin >> second_player;
    cout << endl << "Начало игры!" << endl;

    RandomPlayer player(first_player);
    SmartPlayer player2(second_player);
    Game game;
    
    Player* choose = &player;
    Player* choose2 = &player2;

    game.creatBoard();
    while (!game.PlayBoardIsEnd())
    {
        cout << "Хотите взять управление ходом крестики?(yes/no)" << endl;
        cin >> answer;
        if (answer == "yes" && !game.PlayBoardIsEnd())
        {
            cout << "Введите два значения(x,y): ";
            x = enterCheckNumber(0, 2);
            y = enterCheckNumber(0, 2);
            game.makeStep<Cross>(x, y);
            count++;
            cout << count << " Ход(крестики," << player2.getName() << ")" << endl;
            game.showBoard();
            game.serialize(Cross::getType());
            cout << endl;
        }
        else if (choose2->doStep(x, y, game) && answer == "no" && !game.PlayBoardIsEnd())
        {
            game.makeStep<Cross>(x, y);
            count++;
            cout << count << " Ход(крестики," << player2.getName() << ")" << endl;
            game.showBoard();
            game.serialize(Cross::getType());
            cout << endl;
        }
        else if (answer != "yes" || answer != "no")
        {
            cout << "Некорректный ответ!Пропуск хода!" << endl;
        }
        if (game.PlayBoardIsEnd())
        {
            break;
        }
        cout << "Хотите взять управление ходом ноликами?(yes/no)" << endl;
        cin >> answer;
        if (answer == "yes" && !game.PlayBoardIsEnd())
        {
            cout << "Введите два значения(x,y): ";
            x = enterCheckNumber(0, 2);
            y = enterCheckNumber(0, 2);
            game.makeStep<Zero>(x, y);
            count++;
            cout << count << " Ход(нолики," << player.getName() << ")" << endl;
            game.showBoard();
            game.serialize(Zero::getType());
            cout << endl;;
        }
        else if (choose->doStep(x, y, game) && answer == "no" && !game.PlayBoardIsEnd())
        {
            game.makeStep<Zero>(x, y);
            count++;
            cout << count << " Ход(нолики," << player.getName() << ")" << endl;
            game.showBoard();
            game.serialize(Zero::getType());
            cout << endl;
        }
        else if (answer != "yes" || answer != "no")
        {
            cout << "Некорректный ответ!Пропуск хода!" << endl;
        }
    }

    return 0;
}
