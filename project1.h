#include <iostream>
#include <vector>
#include <cstring>

class Czas 
{
    private:
        int godziny;
        int minuty;
        int sekundy;
    public:
        Czas(int Godziny, int Minuty, int Sekundy); // konstruktor i desktruktor
        Czas(int Minuty, int Sekundy);
        Czas(int Sekundy);
        Czas(void);
        Czas(Czas& kopia);
        ~Czas();
        int acces_godziny();    // akcesory
        int acces_minuty();
        int acces_sekundy();
        void change_godziny(int Godziny);
        void change_minuty(int Minuty);
        void change_sekundy(int Sekundy);
        void change_all(int Godziny, int Minuty, int Sekundy);
        void display(); // metody
        Czas& operator+(Czas _czas2);    //operatory
        Czas& operator=(Czas& _czas2);
        Czas& operator+=(Czas& _czas2);
        bool operator>(Czas& _czas2);
        bool operator==(Czas& _czas2);
};

class Obrabiarka
{
    private:
        int iloscCzasow;
        Czas* zestawCzasow = nullptr;
        //std::vector<Czas> zestawCzasow;
    public: 
        Obrabiarka();
        Obrabiarka(const Obrabiarka& kopia);
        ~Obrabiarka();
        void dodaj_czas(Czas& nowy);  // a)
        int acces_iloscCzasow();
        Czas* acces_zestawCzasow();
        void zmien_czas(Czas& o1, int index);
        void pokaz_cale_zestawienie(); // c)
        void pokaz_czas(int index);
        Czas zsumuj_wszystkie();    // b)
        void operator=(const Obrabiarka& obrabiarka2);
        Czas& operator[] (int x);
};