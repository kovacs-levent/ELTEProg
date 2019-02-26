//K�sz�tette:    Veszpr�mi Anna
//D�tum:         2018.02.20.
//Men�rendszer header �llom�ny

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "priorsor.h"

class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void Sorba();
        void Sorbol();
        void Legnagyobb();
        void Urese();
        void KiirSor();
        void TerhelesTeszt();
        PrQueue Q;

};

#endif // MENU_H_INCLUDED
