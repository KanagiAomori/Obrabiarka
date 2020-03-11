#include "project1.h"

Obrabiarka::Obrabiarka() {
    iloscCzasow = 0;
    zestawCzasow = nullptr;
    std::cout << "object constructed - Obrabiarka" << std::endl;
}

Obrabiarka::Obrabiarka(const Obrabiarka& kopia) {
    iloscCzasow = kopia.iloscCzasow;
    zestawCzasow = new Czas[kopia.iloscCzasow];
    for(int i = 0; i < iloscCzasow; i++) {
        memcpy(zestawCzasow, kopia.zestawCzasow, iloscCzasow * sizeof(Czas));
    }
    std::cout << "object constructed - Obrabiarka" << std::endl;
}

Obrabiarka::~Obrabiarka() {
    if(zestawCzasow != nullptr)
    delete[] zestawCzasow;
    std::cout << "object destructed - Obrabiarka" << std::endl;
}

void Obrabiarka::dodaj_czas(Czas& nowy) {
    iloscCzasow++;
    Czas* temp = new Czas[iloscCzasow];
    memcpy(temp, zestawCzasow, (iloscCzasow - 1) * sizeof(Czas));
    zestawCzasow = temp;
    zestawCzasow[iloscCzasow - 1].change_all(
        nowy.acces_godziny(),
        nowy.acces_minuty(),
        nowy.acces_sekundy()
    );
}

int Obrabiarka::acces_iloscCzasow() {
    return iloscCzasow;
}

// chyba złe
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


Obrabiarka& Obrabiarka::operator=(const Obrabiarka& obrabiarka2) {   // i tu też nie dokońca
    iloscCzasow = obrabiarka2.iloscCzasow;
    delete[] zestawCzasow;
    zestawCzasow = new Czas[iloscCzasow];
    memcpy(zestawCzasow, obrabiarka2.zestawCzasow, iloscCzasow * sizeof(Czas));
    return *this ;
}

Czas& Obrabiarka::operator[](int index) {
    return zestawCzasow[index];
}
