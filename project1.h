#include <iostream>
#include <vector>
#include <cstring>
/*
struct allocatedMemory {
    uint32_t totalAlocated = 0;
    uint32_t totalFreed = 0;

    uint32_t currentUsage() { return totalAlocated - totalFreed; }
};
*/

class Czas 
{
    private:
        int godziny;
        int minuty;
        int sekundy;
    public:
        Czas(int Godziny = 0, int Minuty = 0, int Sekundy = 0); // wartości domyślne tylko w .h
        //Czas(int Minuty, int Sekundy);  // te konstruktory mogą być przez to niepotrzebne
        //Czas(int Sekundy);
        //Czas(void);
        Czas(const Czas& kopia);
        ~Czas();
        int acces_godziny();    // akcesory
        int acces_minuty();
        int acces_sekundy();
        void change_godziny(int Godziny);
        void change_minuty(int Minuty);
        void change_sekundy(int Sekundy);
        void change_all(int Godziny, int Minuty, int Sekundy);
        void display(); // metody
        Czas operator+(Czas& _czas2);    //operatory
        Czas operator+(int Sekundy);
        Czas& operator=(Czas& _czas2);
        Czas& operator+=(Czas& _czas2);
        bool operator>(Czas& _czas2);
        bool operator<=(Czas& _czas2);
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
        Obrabiarka(int IloscCzasow);
        Obrabiarka(const Obrabiarka& kopia);
        ~Obrabiarka();
        void dodaj_czas(Czas& nowy);  // a)
        int acces_iloscCzasow();
        Czas* acces_zestawCzasow();
        void zmien_czas(Czas& o1, int index);
        void pokaz_cale_zestawienie(); // c).
        void pokaz_czas(int index);
        Czas zsumuj_wszystkie();    // b)
        Obrabiarka kopia(int n);    // n - ilosc czasow do skopiowania
        Obrabiarka kopia_z_zakresem_czasu(Czas zakres);
        Obrabiarka& operator=(const Obrabiarka& obrabiarka2);
        Czas& operator[](int index);
};

class Pracownik
{
    private:
        Obrabiarka ob1;
    public:
        Pracownik();
        ~Pracownik();
};