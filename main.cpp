#include "project1.h"
#include <string.h>

void textDisplay(const char* line);

int main(int argc, char** argv)
{
    textDisplay("Autor Projektu: Piotr Debski");
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
    textDisplay("dodanie tylko sekund");
    (o2+5).display();
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
    ob1.dodaj_czas(o5);
    textDisplay("wpisanie zestawienia");
    ob1.pokaz_cale_zestawienie();
    textDisplay("zsumowanie czasow w zestawieniu");
    ob1.zsumuj_wszystkie().display();

    textDisplay("pokazanie wybranego czasu czasu");
    ob1.pokaz_czas(3);  
    
    textDisplay("operator []");
    ob1.operator[](2).display();   
    textDisplay("Konstruktor kopiujacy Obrabirka"); // 4.1
    Obrabiarka ob2(ob1);    
    ob2.pokaz_cale_zestawienie();
    
    textDisplay("operator przyrownania");   //4.1 
    Obrabiarka ob3;
    ob3 = ob1;
    ob3.pokaz_cale_zestawienie();

    textDisplay("Menu");
    std::cout << "[1] utworz kopie n czasow\n" << "[2] utworz kopie  z zakresu czas\n\n";

    char sterowanie;    // zmienna do switch
    int ileCzasow;
    int g, m, s;
    Obrabiarka ob4, ob5;
    Czas zakres;
    std::cin >> sterowanie;
    switch(sterowanie)
    {
        case '1':
            textDisplay("tworzenie kopi za pomoca metody"); // 4.2
            std::cout << "podaj ilosc czasow" << std::endl;
            std::cin >> ileCzasow;
            ob4 = ob1.kopia(ileCzasow);
            ob4.pokaz_cale_zestawienie();
            break;
        case '2':
            textDisplay("tworzenie kopi z zakresem czasu"); // 4.3
            std::cout << "wpisz kolejno godziny, minuty, sekundy" << std::endl;
            std::cin >> g >> m >> s;
            zakres.change_all(g, m, s);
            ob5 = ob1.kopia_z_zakresem_czasu(zakres);
            std::cout << "caly czas zakres: ";
            zakres.display();
            std::cout << "caly czas ob5: ";
            ob5.zsumuj_wszystkie().display();
            std::cout << std::endl;
            ob5.pokaz_cale_zestawienie();
            break;
        default:
            std::cout << "zły wybór" << std::endl;
            break;
    }

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