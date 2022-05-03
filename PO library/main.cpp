#include <iostream>
#include "movie.h"
#include <string>
#include <vector>
#include "user.h"

using namespace std;

vector <movie> library;
vector <user> users;
vector <admin> admin1;
void test();
void test2();
void test3();


int main()
{
    test3();
}

void test()
{//renting
    char k;
    add_user2("test", user_id);
    read();

    printmovies2(library);

    do
    {
        menu();
        cout << "Enter a to end the program" << endl;
        cin >> k;
        users[0].info();
        cout << endl;
    }while (k != 'a');
}

void test2()
{//general, switching users
    char k;
    add_admin();
    add_user2("test", user_id);
    add_user2("tes2", user_id);
    add_user2("tes4", user_id);
    read();
   // cout << user_id << endl;
    do
    {
        system("cls");
        menu();
        cout << "To stay in the program enter a" << endl;
       // cin.ignore();
        cin >> k;
    }while (k == 'a');

}

void test3()
{//editing
    read();
    movie_id = check_id();
    char k;
    add_admin();

    do
    {
        menu();
        cout << "Enter a to end the program" << endl;

        cin >> k;
    }while (k != 'a');

}