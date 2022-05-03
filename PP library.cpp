#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;



struct film_struct
{
	int id, liczba_kopii, liczba_kopii_wyp, rok;
	string tytul, opis;
	string nosnik_filmu;
	
};

vector<film_struct> wektor;


void wczytaj_film(film_struct& film);
void wypisz_film(film_struct& film);
int wczytaj_nosnik(void);
void edytowanie(film_struct& film);
void czytanie(vector<film_struct> &wektor);
void wyszukaj_film(vector<film_struct> &wektor);
void wpisywanie(film_struct& film);
void wpisanie2(vector<film_struct> &wektor);
void wyczysc(void);
void menu(void);
bool sprawdz(int y);
void wypisz_id_tytul(film_struct& film);
bool wypozycz_film(vector<film_struct> &wektor);
void oddaj_film(vector<film_struct> &wektor);


int main()
{
	cout << "W wektorze nie ma zadnych filmow, trzeba na poczatku wczytac je z pliku txt, lub wpisac je manualnie!" << endl;
	char wyb;
	do{
	menu();	
	cout << "Czy chcesz kontynuowac ? t/n Po wyborze 't' powrocisz do menu." << endl;
	cin >> wyb;
	system("cls");
	}while(toupper(wyb) != 'N');	
}

void wczytaj_film(film_struct& film)
{

	int x;
	
	do
	{
		cout << "Id: ";
		cin >> film.id;
	}while(sprawdz(film.id));
	
	
	cin.ignore();
	do
	{
		cout << "Tytul: ";
		getline(cin, film.tytul);
	}while(film.tytul.length() > 256);

	do
	{
		cout << "Rok wydania: " << endl;
		cin >> film.rok;	
	}while(film.rok < 1888 || film.rok > 2022);


	cin.ignore();
	do
	{
		cout << "Krotki opis filmu: ";
		getline(cin, film.opis);
	}while(film.opis.length() > 1000);
	
	x = wczytaj_nosnik();
	if(x == 0)
	{
		film.nosnik_filmu = "VHS";	
	}
	if(x == 1)
	{
		film.nosnik_filmu = "DVD";
	}
	if(x == 2)
	{
		film.nosnik_filmu = "BlueRay";
	}
	
	do
	{
		cout << "Wpisz liczbe kopii: ";
		cin >> film.liczba_kopii;
	}while(film.liczba_kopii < 0);
	
	do
	{
		cout << "Liczba kopii wypozyczonych: ";
		cin >> film.liczba_kopii_wyp;
		if(film.liczba_kopii < film.liczba_kopii_wyp)
		cout << "Liczba wypozyczonych kopii jest wieksza od kopii filmu" << endl;	
	}while(film.liczba_kopii < film.liczba_kopii_wyp);
	wektor.push_back(film);


}

void wypisz_film(film_struct& film)
{
	cout << "*------------------------------*" << endl;
	cout << "Id: " << film.id << endl;
	cout << "Tytul: " << film.tytul << endl;
	cout << "Rok wydania: " << film.rok << endl;
	cout << "Opis filmu: " << film.opis << endl;
	cout << "Liczba kopii :" << film.liczba_kopii << "\nIlosc wypozyczonych kopii: " << film.liczba_kopii_wyp << endl;
	cout << "nosnik : " << film.nosnik_filmu << endl;
		
}

void wypisz_id_tytul(film_struct& film)
{
	cout << "Id: " << film.id << endl;
	cout << "Tytul: " << film.tytul << endl;
	cout << "Ilosc kopii mozliwych do wyporzyczenia :" << film.liczba_kopii - film.liczba_kopii_wyp << endl;
	cout << "Ilosc kopii wypozyczonych : " << film.liczba_kopii_wyp << endl;
}


void czytanie(vector<film_struct> &wektor)
{
	fstream file;
	file.open("filmy.txt", ios::in);
	if(file.good())
	{
		while(true)
		{
			if(file.eof())
			{
				break;
			}
			else 
			{
			film_struct film;
			file >> film.id;
			getline(file, film.tytul);
			file >> film.rok;
			getline(file, film.opis);
			getline(file, film.nosnik_filmu);
			file >> film.liczba_kopii;
			file >> film.liczba_kopii_wyp;
			wektor.push_back(film);	
			}
		
		}
	}
	else 
	{
		cout << "Jest problem z otworzeniem pliku txt";
	}
	
	
	wektor.pop_back();

}

int wczytaj_nosnik(void)
{

	int y;
	do
	{
		cout << "Wybierz nosnik VHS = 0, DVD = 1, BlueRay = 2: ";
		cin >> y;
	}while(y != 0 && y != 1 && y != 2);
	
	return y;
}

void edytowanie(film_struct& film)
{
	int x;
	int y;
	cout << " Jakie dane filmu chcesz zmienic? " << endl;
	cout << "1 = Id filmu\n2 = Tytul\n3 = Data wydania\n4 = Opis\n5 = Liczba kopii\n6 = Liczba wypozyczonych kopii\n7 = Nosnik filmu\n8 = Anuluj" << endl;
	cin >> x;
	switch(x)
	{
		case 1:
		cout << "Wpisz nowe Id: ";
		cin >> film.id;
		break;
		
		case 2:
		cout << "Wpisz nowy tytul: ";
		cin.ignore();
		getline(cin, film.tytul);
		break;
		
		case 3:
		do
		{
			cout << "Zmien rok wydania: ";
			cin >> film.rok;
			cout << endl;	
		}while(film.rok < 1888 && film.rok > 2021);
		break;
		
		case 4:
		cout << "Zmien opis: ";
		cin.ignore();
		getline(cin, film.opis);
		break;
		
		case 5:
		do
		{
			cout << "Zmien liczbe kopii: ";
			cin >> film.liczba_kopii;
		}while(film.liczba_kopii < 0);
		break;
		
		case 6:
		do{
			cout << "Zmien liczbe wypozyczonych kopii: ";
			cin >> film.liczba_kopii_wyp;
			cout << endl;
			if(film.liczba_kopii > film.liczba_kopii_wyp)
			cout << "Liczba wypozyczonych kopii jest wieksza od kopii filmu" << endl;
		}while(film.liczba_kopii_wyp > film.liczba_kopii);
		break;
		
		case 7:
		cout << "Zmien nosnik: ";
		y = wczytaj_nosnik();
		
		if(y == 0)
		{
			film.nosnik_filmu = "VHS";	
		}
		if(y == 1)
		{
			film.nosnik_filmu = "DVD";
		}
		if(y == 2)
		{
			film.nosnik_filmu = "BlueRay";
		}
		break;
		
		case 8:
		cout << "Anuluje edytowanie" << endl;
		break;
	}
}

void wyszukaj_film(vector<film_struct> &wektor)
{
	int id, j = 0;
	cout << "podaj ID filmu aby go wyszukac: ";
	cin >> id;
	for(vector<film_struct>::iterator i = wektor.begin(); i < wektor.end(); i++, j++)
	{
		if(i -> id == id)
		{
			system("cls");
			cout << "znalazlem " << i -> tytul << endl ;
			wypisz_film(wektor[j]);
			edytowanie(wektor[j]);
			system("cls");
			cout << "Zmieniony film" << endl;
			wypisz_film(wektor[j]);
			break; 
		}	
	}
}

void oddaj_film(vector<film_struct> &wektor)
{
	int id;
	cout << "podaj ID filmu ktory oddajesz: ";
	cin >> id;
	for(vector<film_struct>::iterator i = wektor.begin(); i < wektor.end(); i++)
	{
		if(i -> id == id)
		{
			system("cls");
			cout << "znalazlem" << i -> tytul << endl;
			if(i -> liczba_kopii_wyp > 0)
			{
				cout << "Oddajesz film " << i -> tytul << endl;
				i -> liczba_kopii_wyp--;
				break;
			}
			else
			{
				cout << "Nie mozna oddac filmu, nie ma kopii wypozyczonych." << endl;
			}
			break; 
		}
			
	}
	
}

bool wypozycz_film(vector<film_struct> &wektor)
{
	int id;
	cout << "podaj ID filmu ktory chcesz wypozyczyc: ";
	cin >> id;
	for(vector<film_struct>::iterator i = wektor.begin(); i < wektor.end(); i++)
	{
		if(i -> id == id)
		{
			system("cls");
			cout << "znalazlem" << i -> tytul << endl;
			if(i -> liczba_kopii > i ->liczba_kopii_wyp)
			{
				cout << "Wypozyczyles/las film " << i -> tytul << endl;
				i -> liczba_kopii_wyp ++;
				return true;
			}
			else
			{
				cout << "Niestety nie mozna wypozyczyc." << endl;
				return false;
			}
			break; 
		}
			
	}
	
	return false;		
}

bool sprawdz( int y)
{
	for(vector<film_struct>::iterator i = wektor.begin(); i < wektor.end(); i++)
	{
		if(i -> id == y)
		{
			cout << "Id juz istnieje podaj inne" << endl;
			if(y < 0)
			cout << "Id nie moze byc mniejsze od zera" << endl;
			
			return true; 
		}	
	}
	return false;
	
}
void wyczysc(void)
{
	ofstream file;
	file.open("filmy.txt", ios::out);
	file.close();
}
void wpisywanie(film_struct &film)
{
	
	ofstream file;
	file.open("filmy.txt", ios::out | ios::app );
	file  << film.id << ' ' << film.tytul << endl << film.rok << ' ' << film.opis << endl << film.nosnik_filmu << endl << film.liczba_kopii << endl << film.liczba_kopii_wyp << endl;		
	file.close();

}

void wpisanie2(vector<film_struct> &wektor)
{
	for(int i = 0; i < wektor.size(); i++)
	{
		wpisywanie(wektor[i]);
	}	
}
void menu(void)
{
	int x;
	cout <<"Jestes w menu wypozyczalni filmow, co chcial/chcialabys zrobic?" << endl;
	cout << "1. Ewidencja filmow \n2. Wypozycz film \n3. Dodaj film \n4. Edytuj film \n5. Wczytaj baze filmow z pliku \n6. Oddaj film \n7. Wyjdz" << endl;
	cin >> x;
	switch(x)
	{
		case 1:
			{
				system("cls");
				cout << "Zbior filmow" << endl;
				for(int i = 0; i < wektor.size(); i++)
				{
					wypisz_film(wektor[i]);
				}
				break;
			}
		
		case 2:
			{
				system("cls");
				bool x;
				char wyb;
				cout << "Filmy do wyboru " << endl;
				
				for(int i = 0; i < wektor.size(); i++)
				{
					wypisz_id_tytul(wektor[i]);	
				}
				
				cout << "Czy chcesz wypozyczyc film? t/n" << endl;
				cin >> wyb;
				
				if(toupper(wyb) == 'T')
				{
						do
					{
						x = wypozycz_film(wektor);
					}while(!x);
				
					wyczysc();
					wpisanie2(wektor);
					break;
				}
				else 
				{
					break;
				}
			
			}
			
		case 3:
			{
				char wyb;
				system("cls");
				cout << "Czy chcesz dodac nowy film? t/n" << endl;
				cin >> wyb;
			
				if(toupper(wyb) == 'T')
				{
					film_struct film;
					cout << "Dodawanie filmu" << endl;
					wczytaj_film(film);
					wyczysc();
					wpisanie2(wektor);
					break;
				}
				else 
				{
					break;
				}
			}
			
		case 4:
			{
				system("cls");
				for(int i = 0; i < wektor.size(); i++)
				{
					wypisz_id_tytul(wektor[i]);	
				}
				wyszukaj_film(wektor);
				wyczysc();
				wpisanie2(wektor);
				
				break;
			}
			
		case 5:
			{
				system("cls");
				wektor.clear();
				cout << "Wczytano dane z pliku txt" << endl;
				czytanie(wektor);
				break;
			}
			
		case 6:
			{
				char wyb;
				system("cls");
				cout << "Czy chcesz oddac film? t/n" << endl;
				cin >> wyb;
			
				if(toupper(wyb) == 'T')
				{
						for(int i = 0; i < wektor.size(); i++)
					{
						wypisz_id_tytul(wektor[i]);	
					}
					oddaj_film(wektor);
					wyczysc();
					wpisanie2(wektor);
				break;	
				}
				else
				{
					break;
				}
			
			
			}
			
		case 7:
			{
				system("cls");
				break;
			}
	}
	
}
