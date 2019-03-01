#include <iostream>

int main ()
{
    ///A try blokkban ak�rmilyen C++ k�d lehet, ha kiv�tel dob�dik, akkor a try-hoz tartoz� catch blokkra ugrik a vez�rl�s
    ///Sima p�lda a try-catch-re. A try blokkban kiv�telt dobunk
    try
    {
        throw 101;
        ///Ez alatt a ki�r�s m�r nem fog lefutni
        std::cout << "Nincs kivetel!";
    }
    catch (int e)
    {
        std::cerr << "Kivetelt dobtak. Kivetel szama: " << e << std::endl;
    }

    ///T�bbf�le kiv�telkezel� is tartozhat egy try blokkhoz, a kiv�tel t�pus�t�l f�gg, hogy melyik kezel�nek ad�dik �t az ir�ny�t�s
    try
    {
        //throw 22;
        //throw 'c';
        throw "exception";
    }
    catch (int param)
    {
        std::cout << "int kivetel";
    }
    catch (char param)
    {
        std::cout << "char kivetel";
    }
    catch (...)
    {
        ///Ez lenne az ugymond alap�rtelmezett kiv�tel, ha nincs speci�lis kiv�telkezel�je defini�lva a t�pusnak, akkor erre az �gra megy a catch
        std::cout << "alap kivetel";
    }
    ///Az is lehet, hogy a catch blokk nem kezeli le a dobott kiv�telt (vagy csak szimpl�n try blokkon k�v�l dobnak kiv�telt)
    ///Ekkor a C++ termin�lja a programot az std::terminate f�ggv�nnyel
    try
    {
        //throw 2;
    }
    catch(std::string s)
    {
        std::cout << "string error";
    }
    return 0;
}
