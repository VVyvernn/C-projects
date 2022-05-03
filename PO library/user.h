#ifndef PROJEKT_BAZA_DANYCH_USER_H
#define PROJEKT_BAZA_DANYCH_USER_H
#include <string>
#include <vector>
#include "movie.h"


extern int user_id;
extern int current_id;
extern int current_user;
extern bool if_admin;


class tmp
{
public:
    std::string name;
    int id;
    std::vector<movie> rented_movies;
    virtual void info() const ;
    virtual void info2() const ;
    virtual void rent(int x);
    virtual void return_movie(int x);
};

class admin; //for friend class

class user : public tmp
{
private:
    int id;
    friend void fx(user a, admin b);
public:

    user();
    user(std::string nm, int idd)
    {
       name = nm;
       id = idd;
       user_id++;
    }
    user (std::string tst)
    {
        name = tst;
        id = 2;
    }
    void info() const;
    void info2() const;
    void rent(int x);
    void return_movie(int x);
    int get_id();

};


class admin : public tmp
{
public:
    admin();
    static bool a;
    admin(std::string nm, int idd)
    {
        name = nm;
        id = idd;
        a = 1;
    }
    void info() const;
    void info2() const;
    void rent(int x);
    void return_movie(int x);
     admin(const admin& k);
    admin operator+ (const admin& k )
    {
        admin admin;
        admin.id = this ->id + k.id;
        admin.name = this ->name +k.name;
        std::vector<movie> temp;

        return admin;
    }
    admin operator+=(const admin& k)
    {
        admin admin;
        for(int i = 0; i < k.rented_movies.size(); i++)
        {
            this->rented_movies.push_back(k.rented_movies[i]);

        }
        return admin;
    }
    bool operator==(const admin& k)
    {
        return (this->name == k.name);

    }
    //friend class fx(user a, admin b);
};

void user_menu();
int find_user();
void add_user2(std::string nm, int idd);
void print_users(std::vector<user> v, int y);
void add_admin();
int check_id();


#endif //PROJEKT_BAZA_DANYCH_USER_H
