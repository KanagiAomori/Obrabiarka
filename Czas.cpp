#include "project1.h"
bool is_int(int zmienna);

Czas::Czas(int Godziny, int Minuty, int Sekundy) {
    godziny = Godziny;
    minuty = Minuty;
    sekundy = Sekundy;
    std::cout << "object constructed - Czas" << std::endl;
}

Czas::Czas(int Minuty, int Sekundy) {
    minuty = Minuty;
    sekundy = Sekundy;
    godziny = 0;
    std::cout << "object constructed - Czas" << std::endl;
}

Czas::Czas(int Sekundy) {
    sekundy = Sekundy;
    minuty = 0;
    godziny = 0;
    std::cout << "object constructed - Czas" << std::endl;
}

Czas::Czas(void) {
    sekundy = 0;
    minuty = 0;
    godziny = 0;
    std::cout << "object constructed - Czas" << std::endl;    
}


Czas::Czas(Czas& kopia) {
    godziny = kopia.godziny;
    minuty = kopia.minuty;
    sekundy = kopia.sekundy;
    std::cout << "object constructed - Czas" << std::endl;
}

Czas::~Czas() {
    std::cout << "object destructed - Czas" << std::endl;
}

int Czas::acces_godziny() {
    return godziny;    
}

int Czas::acces_minuty() {
    return minuty;
}

int Czas::acces_sekundy() {
    return sekundy;
}

void Czas::change_godziny(int Godziny) {
    if (Godziny > 0)
        godziny = Godziny;
    else
        std::cout << "Podano zla wartosc dla godzin" << std::endl;
}

void Czas::change_minuty(int Minuty) {
    if(minuty > 0 && minuty < 60)
        minuty = Minuty;
    else
        std::cout << "Podano zla wartosc dla minut" << std::endl;
}

void Czas::change_sekundy(int Sekundy) {
    if(Sekundy > 0 && Sekundy <60)
        sekundy = Sekundy;
    else
        std::cout << "Podano zla wartosc dla sekund" << std::endl;
}

void Czas::change_all(int Godziny, int Minuty, int Sekundy) {
    if (Sekundy > 0 && Sekundy < 60 && Minuty > 0 && Minuty < 60 && Godziny > 0 ) {
        sekundy = Sekundy;
        minuty = Minuty;
        godziny = Godziny;
    }
    else {
        std::cout << "Podano zla wartosc dla ktoregos z parametrow" << std::endl;    
    }
}

Czas& Czas::operator+(Czas _czas2)    // funkcja operatora zwraca tymczasowy obiekt typu czas
{
    Czas& temp = _czas2;
    temp.godziny += godziny;
    temp.minuty += minuty;
    temp.sekundy += sekundy;
        if (temp.sekundy >= 60){
        temp.sekundy = temp.sekundy - 60;
        temp.minuty++;
    }
    if (temp.minuty > 60){
        temp.minuty = temp.minuty - 60;
        temp.godziny++;
    }
    return temp;
}

Czas& Czas::operator=(Czas& _czas2) { // cos do poprawy
    godziny = _czas2.godziny;
    minuty = _czas2.minuty;
    sekundy = _czas2.sekundy;
    return *this;    
}

Czas& Czas::operator+=(Czas& _czas2) {
    godziny += _czas2.godziny;
    minuty += _czas2.minuty;
    sekundy += _czas2.sekundy;
    if (sekundy >= 60){
        sekundy = sekundy - 60;
        minuty++;
    }
    if (minuty > 60){
        minuty = minuty - 60;
        godziny++;
    }
    return *this;
}

bool Czas::operator>(Czas& _czas2) {
    if(godziny > _czas2.godziny)
        return true;
    else if(minuty > _czas2.minuty)
        return true;
    else if(sekundy > _czas2.sekundy)
        return true;
    else
        return false;
}

bool Czas::operator==(Czas& _czas2) {
    if(godziny == _czas2.godziny && minuty == _czas2.minuty && sekundy == _czas2.sekundy)
        return true;
    else
        return false;
}

void Czas::display() {
    std::cout << "Sekundy: " << sekundy << " Minuty: " << minuty << " Godziny: " << godziny << std::endl;
}
