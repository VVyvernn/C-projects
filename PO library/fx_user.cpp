#include <string>
#include <vector>
#include "movie.h"
#include "user.h"
#include <iostream>

using namespace std;
extern vector <movie> library;
extern vector <user> users;
extern vector <admin> admin1;


int user_id = 1;
int current_id = 0;
int current_user = 0;
bool admin::a = 0;

user::user()
{
    cout << "Hi! What's your name? \n:" ;
    cin.ignore();
    getline(std::cin, name );
    cout << "All right, " << name << " let's get started!" << endl;
    id = user_id;
    user_id ++;
    rented_movies.clear();
}


void user::info() const
{
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    if( !rented_movies.empty())
    {
        cout << "List of movies you have in your library right now :" << endl;
        printmovies2(rented_movies);
    } else
        cout << "This user hasn't rented any movies yet" << endl;

}
void user::info2() const
{
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
}

void admin::info() const
{
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    if( !rented_movies.empty())
    {
        cout << "List of movies you have in your library right now :" << endl;
        printmovies2(rented_movies);
    } else
        cout << "This admin hasn't rented any movies yet" << endl;
    
}

void admin::info2() const
{
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Also as an Admin you have permissions to delete, add and edit both movies and other users" << endl;
}

void user::rent(int x)
{//need to change this, should be ok now
    if(library[x].avcopies > 0)
    {
        rented_movies.push_back(library[x]);
        library[x].rent();
        cout << "Movie rented!" << endl;
    } else
    {
        cout << "Couldn't rent the movie, there are no more available copies." << endl;
    }

}

void user::return_movie(int x) //int of MOVIE IN LIBRARY
{
    int c = 0;
    if(rented_movies.size() > 1)
    {
        for(auto & i : rented_movies) {
            if (i.id == x) {
                swap(rented_movies[x - 1], rented_movies[rented_movies.size() - 1]);
                rented_movies.pop_back();
                c++;
            }
        }
        if(c)
        {
            cout << "Movie returned" << endl;
            library[x-1].returnmovie();
        } else
        {
            cout << "Couldn't find the movie" << endl;
        }
    } else
    {
        rented_movies.pop_back();
        library[x-1].returnmovie();

    }


}

int user::get_id() {
    return id;
}

void fx(user a, admin b)
{
    cout << "Names: " << a.name << "//" << b.name << endl;
    cout << "Id's: " << a.id << "//" << b.id << endl;
}



void admin::rent(int x)
{
    if(library[x].avcopies > 0)
    {
        rented_movies.push_back(library[x]);
        library[x].rent();
        cout << "Movie rented!" << endl;
    } else
    {
        cout << "Couldn't rent the movie, there are no more available copies." << endl;
    }

}

void admin::return_movie(int x) //int of MOVIE IN LIBRARY
{

    int c = 0;
    if(rented_movies.size() > 1)
    {
        for(auto & i : rented_movies) {
            if (i.id == x) {
                swap(rented_movies[x - 1], rented_movies[rented_movies.size() - 1]);
                rented_movies.pop_back();
                c++;
            }
        }
        if(c)
        {
            cout << "Movie returned" << endl;
            library[x-1].returnmovie();
        } else
        {
            cout << "Couldn't find the movie" << endl;
        }
    } else
    {
        rented_movies.pop_back();
        library[x-1].returnmovie();
    }



}

admin::admin()
{

}

admin::admin(const admin &k)
{
    name = k.name;
    id = k.id;
    for(int i = 0; i < k.rented_movies.size(); i++)
    {
        rented_movies.push_back(k.rented_movies[i]);
    }
}



void add_user2(std::string nm, int idd)
{
    user x(nm, user_id);
    users.push_back(x);
}
void add_admin()
{
    string name;
    cout << "Ok lets get started with creating an Admin for our library" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    admin k(name, user_id);
    admin1.push_back(k);
    admin::a = true;
}
void print_users(vector<user> v, int y)
{

    if(y == 1)
    {
        for(auto & i : v)
        {
            i.info();
        }
    } else
    {
        int x = 1;
        for(auto & i : v)
        {
            i.info2();
            x++;
            if(x&4 == 0)
                cout << endl;
        }
    }

}

void user_menu()
{
    char k;
    do
        {
            int x;
            cout << "Welcome to the user menu!" << endl;
            cout << "1.add new user, 2.change users, 3.delete user" << endl;
            cout << "4.add new movie, 5.edit movie, 6.delete movie" << endl;
            cout << "7.print all users and their movies" << endl;
            cin >> x;
            switch(x)
            {
                case 1: //add new user
                {
                    cout << "Adding new user" << endl;
                    user k;
                    users.push_back(k);
                    if(users.size() > 0)
                    {
                        char k;
                        cout << "Do you want to switch to the newly created user? (y/n) " << endl;
                        cin >> k;
                        if(k == 'y')
                        {
                            // swap(users[0], users[users.size()-1]);
                            current_user = users.size() - 1;
                            cout << "Current user is " << users[current_user].name << endl;
                            admin::a = false;   //admin1[0].a = false;
                            //cout << admin1[0].a << endl;
                        }
                    }
                    break;
                }

                case 2: //switch user
                {
                    int x, y = 0;
                    if(users.size() != 0)
                    {
                        cout << "Current user is " << users[current_user].name << endl;
                        cout << "Here is a lit of all the users" << endl;
                        print_users(users,0);
                        cout << endl << "If you want to switch users input the id number of the user you want to switch to: ";
                        cin >> x;
                        for(auto & i : users)
                        {
                            if(i.get_id() == x)
                                current_user = y;
                            y++;
                        }
                        //current_user = x;
                        //swap(users[0], users[x-1]);//dont know if worth it tbh
                        users[current_user].info2();
                        admin::a = false;
                        break;
                    } else
                    {
                        cout << "There are no users in the library." << endl;
                        break;
                    }

                }

                case 3: //delete user
                {
                    cout << "Here is a lit of all the users" << endl;
                    print_users(users,0);
                    int x, y=0;
                    cout << endl << "If you want to delete one of the users input their id number: ";
                    cin >> x;
                    for(auto & i : users)
                    {
                        if(i.get_id() == x)
                            swap(users[y], users[users.size() - 1]);
                        y++;
                    }
                    //swap(users[x-1], users[users.size() - 1]);
                    users.pop_back();
                    print_users(users, 0);
                    cout << "User deleted" << endl;
                    break;

                }

                case 4:
                {//add movie
                    movie k;
                    k.create();
                    library.push_back(k);
                    clear();
                    write();
                    break;
                }

                case 5:
                {// edit
                    int x;
                    printmovies();
                    cout << "Enter id number of the movie you want to edit" << endl;
                    cin >> x;
                    for(auto & i : library )
                    {
                        if(i.id == x)
                        {
                            i.edit();
                        }

                    }
                   // library[x].edit();
                    clear();
                    write();
                    break;
                }

                case 6:
                {//delete movie
                    cout << "Here is a lit of all the movies" << endl;
                    printmovies2(library);
                    int x, y=0;
                    cout << endl << "If you want to delete one of the movies input its id number: ";
                    cin >> x;
                    for(auto & i : library)
                    {
                        if(i.id == x)
                            swap(library[y], library[library.size()-1]);
                        y++;

                    }
                    //swap(library[x-1], library[library.size()-1]);
                    library.pop_back();
                    printmovies2(library);
                    cout << "Movie deleted" << endl;
                    clear();
                    write();
                    break;
                }

                case 7:
                {//users and their movies
                    print_users(users, 1);
                    cout << endl;
                    break;
                }

                case 8:
                {

                }

                default:
                    break;
            }
            cout << "To stay in user menu enter y, otherwise you will go back to menu" << endl;
            cin >> k;
    }while(k =='y');


}
//just so polymorphism can work
void tmp::info() const {}
void tmp::info2() const {}
void tmp::rent(int x) {}
void tmp::return_movie(int x) {}
