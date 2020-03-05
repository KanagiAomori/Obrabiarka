#include "project1.h"

Obrabiarka::Obrabiarka() {
    iloscCzasow = 0;
    zestawCzasow = new Czas[iloscCzasow];
    std::cout << "object constructed - Obrabiarka" << std::endl;
}

Obrabiarka::Obrabiarka(const Obrabiarka& kopia) { // no nie dziala
    iloscCzasow = kopia.iloscCzasow;
    zestawCzasow = new Czas[kopia.iloscCzasow];
    for(int i = 0; i < iloscCzasow; i++) {
       zestawCzasow[i] = kopia.zestawCzasow[i];
       printf("%d : %d : %p : %p\n", iloscCzasow, i,  zestawCzasow[i], kopia.zestawCzasow[i]);
    }
    std::cout << "object constructed - Obrabiarka" << std::endl;
}

Obrabiarka::~Obrabiarka() {
    delete[] zestawCzasow;
    std::cout << "object destructed - Obrabiarka" << std::endl;
}

void Obrabiarka::dodaj_czas(Czas& nowy) {
    iloscCzasow++;
    zestawCzasow[iloscCzasow - 1].change_all(
        nowy.acces_godziny(),
        nowy.acces_minuty(),
        nowy.acces_sekundy());
}

int Obrabiarka::acces_iloscCzasow() {
    return iloscCzasow;
}

Czas* Obrabiarka::acces_zestawCzasow() {
    return zestawCzasow;
}

void Obrabiarka::zmien_czas(Czas& o1, int index) {
    zestawCzasow[index] = o1;
}

void Obrabiarka::pokaz_cale_zestawienie() {
    for (int i = 0; i < iloscCzasow; i++){
        std::cout << i + 1 << ": ";
        zestawCzasow[i].display();
    }
}

void Obrabiarka::pokaz_czas(int index) {
    if (index != 0){
        std::cout << index << ": ";
        zestawCzasow[index - 1].display();
    }
    else {
        std::cout << "error - przekronczono zakres" << std::endl;
    }
}

Czas Obrabiarka::zsumuj_wszystkie() {
    Czas suma;
    for (int i = 0; i < iloscCzasow; i++){
        suma += zestawCzasow[i];
    }
    return suma;
}


void Obrabiarka::operator=(const Obrabiarka& obrabiarka2) {   // i tu też nie dokońca
    iloscCzasow = obrabiarka2.iloscCzasow;
    for(int i = 0; i < obrabiarka2.iloscCzasow; i++)
        zestawCzasow[i] = obrabiarka2.zestawCzasow[i];
}

Czas& Obrabiarka::operator[](int index) {
    /*
    if (index >= iloscCzasow && index < 0) {
        std::cout << "scope-error" << std::endl;
        return ;
    }*/
    return zestawCzasow[index];
}