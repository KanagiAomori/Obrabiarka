#include "project1.h"
#include <string.h>

void textDisplay(const char* line);

int main(int argc, char** argv)
{
    textDisplay("Test klasy Czas");
    Czas o1(5, 4, 3);
    o1.display();
    textDisplay("zmiana godziny");
    o1.change_godziny(10);
    o1.display();
    textDisplay("minuty in o1: ");
    std::cout << o1.acces_minuty() << std::endl;
    textDisplay("dodanie o1 i o2");
    Czas o2(1, 1, 1);
    (o1+o2).display();
    textDisplay("porownania o1 > o2 i o1 == o2");
    o1.display();
    o2.display();
    std::cout<< (o1>o2) << std::endl;
    std::cout << (o1==o2) << std::endl;
    
    std::cout << std::endl << "Test klasy Obrabiarka" << std::endl << std::endl;
    Czas o3(1, 59, 50);
    Czas o4;
    //o4 = o1;
    o4.operator=(o1);
    Czas o5(o3);    // konstr kopiujacy.
    textDisplay("tworzenie obrabiarki i zestawu czasow");
    Obrabiarka ob1;
    ob1.dodaj_czas(o1);
    ob1.dodaj_czas(o2);
    ob1.dodaj_czas(o3);
    ob1.dodaj_czas(o4);
    ob1.dodaj_czas(o5);

    textDisplay("wpisanie zestawienia");
    ob1.pokaz_cale_zestawienie();

    textDisplay("zsumowanie czasow w zestawieniu");
    ob1.zsumuj_wszystkie().display();

    textDisplay("pokazanie wybranego czasu czasu");
    ob1.pokaz_czas(3);  
    
    textDisplay("Konstruktor kopiujacy Obrabirka");
    Obrabiarka ob2(ob1);    // tu sie zaczyna psuc
    ob2.pokaz_cale_zestawienie();
    
    textDisplay("operator przyrownania");    
    Obrabiarka ob3;
    ob3 = ob1;
    ob3.pokaz_cale_zestawienie();

    return 0;
}

void textDisplay(const char* line)
{
    int i = 0;
    printf("||");
    for(i = 0; i < (strlen(line) + 2); i++)
        printf("-");
    printf("||\n");
    printf("|| %s ||\n||", line);
    for(i = 0; i < (strlen(line) + 2); i++)
        printf("-");
    printf("||\n");
}