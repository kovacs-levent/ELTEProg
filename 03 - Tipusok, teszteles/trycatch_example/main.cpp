#include <iostream>

int main ()
{
    ///A try blokkban akármilyen C++ kód lehet, ha kivétel dobódik, akkor a try-hoz tartozó catch blokkra ugrik a vezérlés
    ///Sima példa a try-catch-re. A try blokkban kivételt dobunk
    try
    {
        throw 101;
        ///Ez alatt a kiírás már nem fog lefutni
        std::cout << "Nincs kivetel!";
    }
    catch (int e)
    {
        std::cerr << "Kivetelt dobtak. Kivetel szama: " << e << std::endl;
    }

    ///Többféle kivételkezelõ is tartozhat egy try blokkhoz, a kivétel típusától függ, hogy melyik kezelõnek adódik át az irányítás
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
        ///Ez lenne az ugymond alapértelmezett kivétel, ha nincs speciális kivételkezelõje definiálva a típusnak, akkor erre az ágra megy a catch
        std::cout << "alap kivetel";
    }
    ///Az is lehet, hogy a catch blokk nem kezeli le a dobott kivételt (vagy csak szimplán try blokkon kívül dobnak kivételt)
    ///Ekkor a C++ terminálja a programot az std::terminate függvénnyel
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
