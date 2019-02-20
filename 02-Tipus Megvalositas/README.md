# Típusok, típus megvalósítás

A típusok ismerete alapvetően szükséges ahhoz, hogy különféle programokat készítsen az ember. Ezekkel az eszközökkel összetett objektumokat, adatszerkezeteket írhatunk úgy, hogy azok különálló egységet alkossanak. Ezek az eszközök nagyban növelik a kód olvashatóságát, skálázhatóságát és újrafelhasználását, mely bármilyen méretű alkalmazás fejlesztése esetén kulcs tényező.

## A típusok megvalósítása C++-ban

Általában egy típus megvalósításánál a legjobb gyakorlat C++ esetén, hogy először egy header file-t írunk, melyben a típus és a hozzá tartozó adattagok, függvények deklarációját tesszük egy osztályba vagy structba. A kettő között csak az alapértelmezett láthatóság a különbség, erről később lent. A header fájlokat be include-olhatjuk bármilyen másik fájlba, mely annyit jelent, hogy a header tartalmát bemásoljuk a fájlba. A header fájlokba tehát a deklarációkat tesszük, amellyel a program tudtára adjuk, hogy ez a típus és a különböz adattagjai léteznek. Arról, hogy mit csinálnak ez nem ad információt, ezt ugyanis egy külön fordítási egységben célszerű megvalósítáni, vagyis itt definiáljuk a függvényeinket.

A külön fordítási egységek használata azért célszerű a gyakorlatban, mert ha a header file-okba írnánk a definíciókat, akkor minden egyes fordítás esetén az egész program lefordul. Gondoljunk bele, hogy van 20 darab fordítási egységünk, ami használ egy típust, ami a header file-ba van definiálva. Mind a 20 fordítási egység esetén a header tartalma is fordulni fog, holott eszünkbe se jutott módosítani, csak használni. A külön fordítási egységnél ez nem fordul elő, ha nem változtattunk rajta, akkor a használó programok nem fordítják újra feleslegesen a már meglévő kódot. 

Az is igaz, hogy ilyenkor kereszthivatkozások jönnek létre, amik relatíve lassúak. Azonban általában a program hatékonysága szempontjából ez elenyésző, ha pedig mégsem, akkor lehetséges fordítani úgy, hogy ezeket megszüntesse a fordító a binárisban ld.: Link Time Optimization.

A típusok megvalósításának több lépése van, először is írnunk kell inicializációs függvényeket, amik beállítják a kívánt helyzetbe az osztályunkat a munka előtt. Ezeket a konstruktorok segítségével tehetjük meg, ezek akkor futnak le, amikor az típusunk példányosítjuk a programban. Konstruktorból akárhányat írhatunk, lehetnek paraméterei is, és a létrehozáskor ezek egyikét kell meghívnunk.

A konstruktor tehát speciális eljárás, ennek pedig egy kitüntetett típusa a copy (másoló) konstruktor. Ez olyan konstruktor ami a típusnak, amit konstruálunk éppen, egy példányát kapja meg paraméternek. Általában azzal a céllal, hogy annak a példánynak az állapotát másolja le az új példány is.

A harmadik speciális eljárásunk a destruktor. Ez akkor fut le, amikor a példányunk élettartama véget ér. A destuktorban tehát eltakarítani érdemes magunk után, ez később lesz majd fontos. A C++ fordító van olyan rendes, hogy mind konstruktorból, copy konstruktorból és destruktorból is szolgáltat egy alapértelmezettet, ezek minden adattagra a default konstruktort, copy konstruktort vagy destruktort futtatják le.

Mint fent említve volt fent, a típusokat osztályként vagy structként érdemes megvalósítani. Általában a kényelmesség miatt a struct-okkal egyszerű adatstruktúrákat valósítunk meg, minden mást class-al. A láthatóság a különbség csak, alapértelmezetten a structban minden public, a classban minden private.

Háromféle láthatóság van a C++-ban, a public láthatósággal olyan adattagokat/függvényeket/eljárásokat ruházunk fel, amelyeket kívülről, a példányosított objektumokon keresztül is el kell tudnunk érni. Általában adattagokat ritkán ruházzuk fel public-al (ha nem egyszerű adatszerkezetekkel dolgozunk, amiket structba írunk), a függvényeken, eljárásokon keresztül kezeljük az objektumainkat.

A protected láthatóság az öröklődésnél lesz fontos, ld. 08/09-es órától.

A private láthatósággal azt ruházzuk fel, amit csakis a típuson belül, a típus saját eljárásai, függvényei érhetnek el (általában azért indokolt ez, hogy megelőzzük a nem célszerű működést azzal, hogy csak kontrolláltan módosulnak az adattagjaink az eljárásokon keresztül).

# Órai feladat

## Pont

Valósítsuk meg a pont típust, mely a síkbeli koordináta-rendszer pontjainak a kezelésére lesz alkalmas! Implementáljuk a következő műveleteket:
- A pont koordinátáinak megváltoztatása
- A pont koordinátáinak lekérdezése valamint kiírása
- Pontok összeadása, kivonása egymásból, +/- operátorral is

## Kör

Valósítsuk meg a kör típusát, amely használja a pont típust! Implementáljuk a következő műveleteket: 
- A kör adatainak kiírása
- A kör területének kiszámolása
- Adott pontnak a középponttól mért távolságának kiszámolása
- Annak eldöntése, hogy egy adott pont rajta van-e a körön
- Kör skálázása skalárral (sugár megszorzása számmal), * operátorral is, mindkét oldalról (kör\*szám, és szám\*kör is elfogadott)

### Gyakorló feladat

Hozzuk létre a másodfokú polinomok típusát. Implementáljuk a következő műveleteket:
- Helyettesítési érték kiszámítása
- Polinomok összeadása
- Polinom szorzása számmal

### Egyéb olvasmány/dokumentáció a fenti témakörökről
Osztályok: http://www.cplusplus.com/doc/tutorial/classes/

Több forrásfájlról és a header fájlokról: http://www.cplusplus.com/forum/articles/10627/
