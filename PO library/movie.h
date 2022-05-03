#ifndef PROJEKT_BAZA_DANYCH_MOVIE_H
#define PROJEKT_BAZA_DANYCH_MOVIE_H

#include <string>
#include <vector>



extern int movie_id;

class movie
{
    // temp change to public to check if reading works
public:
    std::string title;
    std::string description;
    int yrofrelease;
    int copies;
    int avcopies;
    int type;
    int id;

public:
    movie();
    movie(std::string titl, std::string desc, int yror, int cop, int avcop, int tp, int idd): title(titl), description(desc), yrofrelease(yror), copies(cop), avcopies(avcop), type(tp), id(idd)
    {
        //this is only temporary i need to change it so id is taken from movie_id
    }
    void create();
    void movie_type();
    void rent();
    void returnmovie();
    void file_write() const;
    void info() const;
    void info2() const;
    int get_id();
    void edit();

};



void addmovie();
void addmovie2(std::string titl, std::string desc, int yror, int cop, int avcop, int tp, int idd);
void printmovies();
void printmovies2(std::vector<movie> v);
//int check_id(int id);
void write();
void clear();
void read();
void menu();

void search_menu(int y);
void search();


#endif //PROJEKT_BAZA_DANYCH_MOVIE_H
