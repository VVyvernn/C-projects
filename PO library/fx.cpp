#include "movie.h"
#include "user.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

extern std::vector <movie> library;
extern std::vector <user> users;
extern vector <admin> admin1;
extern int current_user;
int movie_id = 1;


void movie::movie_type()
{
    int x;
    do
    {
        cout << "choose the driver type 1.CD 2.Blue Ray 3.DVD " << endl;
        cin >> x;
        switch(x)
        {
            case 1:
                type = 0;
                cout << "Driver type set to CD" << endl;
                break;

            case 2:
                type = 1;
                cout << "Driver type set to Blue Ray" << endl;
                break;

            case 3:
                type = 2;
                cout << "Driver type set to DVD" << endl;
                break;

            default:
                cout << "Wrong input" << endl;
                break;
        }


    }while(x > 3 || x < 0);
}

void movie::create()
{
    cout << "Add all the variables " << endl;
    cout << "Title \n: ";
    cin.ignore();
    getline(cin, title);
    // cin.ignore();
    cout << "Description \n: ";
    getline(cin, description);
    do{
        cout << "Year of release \n: ";
        //cin.ignore();
        cin >> yrofrelease;
    }while(yrofrelease < 1888 or yrofrelease > 2021);

    do{
    cout << "Number of copies \n: ";
    cin >> copies;
    if(copies == 0)
        cout << "There can't be 0 copies of a movie";
    }while(copies < 0);

    do{
    cout << "Number of available copies \n: ";
    cin >> avcopies;

        if(avcopies > copies)
        {
            cout << "There can't be more available copies than copies of the movie" << endl;
        }

    }while(avcopies > copies);

    movie_type();
    id = movie_id + 1;
    cout << "Id: " << movie_id << endl;
    movie_id++;

}
void movie::info() const
{
    cout << "*-------------------------------------------*" << endl;
    cout << "Title: " << title << endl;
    cout << "Description: "<< description << endl;
    cout << "Year of release: " << yrofrelease << endl;
    cout << "All copies: " << copies << endl;
    cout << "Available copies: " << avcopies << endl;
    cout << "Type: ";
    if(type == 0)
    {
        cout << "CD" << endl;
    }
    else if(type == 1)
    {
        cout << "Blue Ray" << endl;
    }
    else
    {
        cout << "DVD" << endl;
    }
    cout << id << endl;

}

void movie::info2() const
{
    cout <<"Title: " << title << " Id: " << id << " // ";
}

void movie::rent()
{
//    if(avcopies > 0)
//        avcopies = avcopies - 1;
//    else
//        cout << "No more copies are available" << endl;
        avcopies = avcopies - 1;
}
void movie::returnmovie()
{
    if(avcopies < copies)
        avcopies ++;
    else
        cout << "Can't return the movie" << endl;
}


int  movie::get_id()
{
    return id;
}


movie::movie()
{

}

void addmovie()
{
    movie k;
    k.create();
    library.push_back(k);
}

void addmovie2(std::string titl, std::string desc, int yror, int cop, int avcop, int tp, int idd)
{
    movie k(titl, desc, yror, cop, avcop, tp, idd);
    library.push_back(k);
}

void printmovies()
{
    for(auto & i : library)
    {
        i.info();
    }
}

void printmovies2(vector<movie> v)
{//for user.rentedmovies, and just printing movies
    //changed to info2 !!!!!
    int x = 1;
    for(auto & i : v)
    {
        i.info2();
        x++;
        if(x % 5 == 0)
            cout << "\n";
    }
}


int check_id()
{
    int max1 = library[0].id;
    for(auto & i : library)
       {
            if(max1 < i.id)
               max1 = i.id;
          }
       return max1;
}

void search()
{
    int x;
    cout << "Ok what are you looking for in a movie? \n" << "1. Title, 2.Description, 3. Year of release, 4. Copies available, 5.Id" << endl;
    cout << "\t \t-------List of movies-------" << endl;
    printmovies2(library);
    cout << endl;
    cin >> x;
    switch(x)
    {
        case 1:
        {
            string tmp;
            int x = 0, c = 0;
            cout << "Please enter the title of the movie you are looking for: ";
            cin.ignore();
            getline(cin, tmp);
            for(auto & i : library)
            {
                x++;
                if(i.title == tmp)
                {
                    cout << "Found the movie! It's:  ";
                    i.info2();
                    search_menu(x);
                    c++;
                }
            }
            if(!c)
                cout << "Couldn't find the movie" << endl;
            break; // for now
        }

        case 2:
        {
            string tmp;
            int x, c=0;
            cout << "Please enter the description of the movie you are looking for: ";
            getline(cin, tmp);
            for(auto & i : library)
            {
                x++;
                if(i.description == tmp )
                {
                    cout << "Found the movie! It's: "  << endl;
                    i.info2();
                    search_menu(x);
                    c++;
                }
            }
            if(!c)
                cout << "Couldn't find the movie" << endl;

            break;
        }

        case 3:
        {
            int tmp, x, c = 0;
            cout << "yr tmp: ";
            cin >> tmp;
            for(auto & i : library)
            {
                x++;
                if(i.yrofrelease == tmp )
                {
                    cout << "Found the movie! It's: "  << endl;
                    i.info2();
                    search_menu(x);
                    c++;
                }
            }
            if(!c)
                cout << "Couldn't find the movie" << endl;
            break;
        }

        case 4:
        {
            int tmp, x, c = 0;
            cout << "Copies available: ";
            cin >> tmp;
            for(auto & i : library)
            {
                x++;
                if(i.copies == tmp )
                {
                    cout << "Found the movie! It's: "  << endl;
                    i.info2();
                    search_menu(x);
                    c++;
                }
            }
            if(!c)
                cout << "Couldn't find the movie" << endl;
            break;
        }

        case 5:
        {
            int tmp, x, c = 0;
            cout << "id tmp: ";
            cin >> tmp;
            for(auto & i : library)
            {
                x++;
                if(i.id == tmp)
                {
                    cout << "Found the movie! It's: "  << endl;
                    i.info2();
                    search_menu(x);
                    c++;
                }
            }
            if(!c)
                cout << "Couldn't find the movie" << endl;
            break;
        }

    }

}

void search_menu(int y)
{
    char k;
    do
    {
        int x;
        cout << "What would you like to do?\n" << "1.rent, 2.show information, 3.Return, 4.cancel\n: ";
        cin >> x;
        switch(x)
        {
            case 1:
            {

                if(admin::a == 0)
                {
                    //library[y-1].rent();
                    users[current_user].rent(y-1);//check if current user works

                } else
                {
                    //library[y-1].rent();
                    admin1[0].rent(y-1);
                }
                clear();
                write();
                break;
            }

            case 2:
            {
                cout <<"Information about this movie" << endl;
                library[y - 1].info();
                break;
            }

            case 3:
            {
                if(admin::a == 0)
                {
                    // library[y-1].returnmovie();
                    users[current_user].return_movie(y-1);
                } else
                {
                    //  library[y-1].returnmovie();
                    admin1[0].return_movie(y-1);
                }
                clear();
                write();
                break;
            }

            default:
            {
                break;
            }
        }
        cout << "To keep looking for movies enter y, otherwise you will go back to the menu" << endl;
        cin >> k;
    } while(k == 'y');



}

void movie::file_write() const
{
    ofstream file;
    file.open("database.txt", ios::out | ios::app);
    file << "/ " ;
    file << title << endl;
    file << description << endl;
    file << yrofrelease << endl << copies << endl << avcopies << endl << type << endl << id << endl;
    file.close();
}

void movie::edit()
{
    int x;
    cout << "Which variable of the movie do you want to edit?" << endl;
    cout << "1.title, 2.description, 3.year of release\n4.number of copies, 5.available copies, 6. type" << endl;
    cin >> x;
    switch(x)
    {
        case 1:
        {
            string tmp;
            cout << "New title: ";
            cin.ignore();
            getline(cin, tmp);
            title = tmp;
            break;
        }

        case 2:
        {
            cout << "New description: ";
            getline(cin, description);
            break;
        }

        case 3:
        {
            do
            {
                cout << "New year of release: ";
                cin >> yrofrelease;
            }while(yrofrelease < 1888 or yrofrelease > 2021);
            break;
        }

        case 4:
        {
            do
            {
                cout << "New number of copies: ";
                cin >> copies;
                cout << endl;
                if(copies == 0)
                    cout << "There can't be 0 copies of a movie";
            }while(copies < 0);
            break;
        }

        case 5:
        {
            do
            {
                cout << "New number of available copies: ";
                cin >> avcopies;
                cout << endl;

                if(avcopies > copies)
                {
                    cout << "There can't be move available copies than copies of the movie" << endl;
                }

            }while(avcopies > copies);
            break;
        }

        case 6:
        {
            //movie_type();
            int x;
            cout << "choose the driver type 1.CD 2.Blue Ray 3.DVD " << endl;
            cin >> x;
            type = x - 1;
            break;
        }

        default:
            break;
    }
}




void read()
{//works finally, sort of
    fstream file;
    file.open("database.txt", ios::in);
    string kek;
    if(file.good())
    {
        while(file >> kek)
        {
            movie k;
            getline(file, k.title);
            k.title.erase(k.title.begin()); //remove buffer
            getline(file, k.description);
            file >> k.yrofrelease;
            file >> k.copies;
            file >> k.avcopies;
            file >> k.type;
            file >> k.id;

            library.push_back(k);
        }
    } else
    {
        cout << "file is not opening" << endl;
    }
    file.close();
}
void write()
{
    clear();
    for(auto i = library.begin(); i != library.end(); i++)
    {
        i->file_write();
    }
}

void clear()
{
    ofstream file;
    file.open("database.txt", ios::out);
    file.close();
}


void menu()
{//not ready like at all
    int z;
    cout << "What would you like to do?" << endl;
    cout << "1. print movies, 2.Look for movies, 3.change users \n4.access admin menu(only accessible to the Admin) \n5.current user 6. funkcje 7.exit" << endl;
    cin >> z;
    switch(z)
    {
        case 1:
            printmovies2(library);
            break;

        case 2:
            search();
            break;

        case 3:
        {
            int x;
            if(admin::a == false)
            {
                if(users.size() > 1)
                {
                    cout << "Current user is " << users[current_user].name << endl;
                    cout << "Here is a lit of all the users" << endl;
                    print_users(users,0);
                    cout << endl << "If you want to switch users input the id number of the user you want to switch to: ";
                    cin >> x;
                    //swap(users[0], users[x-1]);//dont know if worth it tbh
                    current_user = x - 1;
                    users[current_user].info2();
                    break;
                } else
                {
                    cout << "There are no other users to switch to." << endl;
                    break;
                }
            } else
            {
                cout << "Admin can switch users in users menu" << endl;
                break;
            }

        }

        case 4:
        {
            if(admin::a == true)
            {
                user_menu();
                break;
            }
            else
            {
                cout << "You are not an Admin, you dont have access to this feature" << endl;
                break;
            }

        }

        case 5:
        {
            tmp *ptr = new tmp;
            if(admin::a == 1)
            {
                ptr = &admin1[0];
                ptr -> info();
            } else
            {
                ptr = &users[current_user];
                ptr -> info();
            }

            break;
        }

        case 6:
        {

                admin k, c, b;
                 user czemu("jeden", 2);
                k.id = 2;
                k.name = "Pierwszy";
                k.rented_movies.push_back(library[3]);
                c.id = 3;
                c.name = "Drugi ";
                c.rented_movies.push_back(library[2]);
                b = c + k;
                // /////////////////////////////
                cout << "*---nazwa---*" << endl;
                b.info();
                cout << endl;
                b += k;
                b += c;
                cout << "*-----filmy-------*" << endl;
                b.info();
                cout << endl;
                cout << "*----Porownanie nazw----*" << endl;
                c.name = "Drugi Pierwszy";
                bool a = b == c;
                cout << a << endl;
                user kek("Nowy", 1);
                cout << "*----Konstruktor kopiujacy----*" << endl;
                admin d(c);
                d.info2();
                cout << "*-----friend fx------*" << endl;
                 fx(kek, c);
                cout << "*-------Wskazniki----*" << endl;
                tmp *j = new tmp;
                j = &k;
                j->info();
                cout << endl;
                j = &czemu;
                j->info();

        }
        default:
            break;
    }
}
