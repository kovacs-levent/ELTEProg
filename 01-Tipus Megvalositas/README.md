# Típusok, típus megvalósítás

A típusok ismerete alapvetően szükséges ahhoz, hogy különféle programokat készítsen az ember. Ezekkel az eszközökkel összetett objektumokat, adatszerkezeteket írhatunk úgy, hogy azok különálló egységet alkossanak. Ezek az eszközök nagyban növelik a kód olvashatóságát, skálázhatóságát és újrafelhasználását, mely bármilyen méretű alkalmazás fejlesztése esetén kulcs tényező.

## A típusok megvalósítása C++-ban

Általában egy típus megvalósításánál a legjobb gyakorlat C++ esetén, hogy először egy header file-t írunk, melyben a típus és a hozzá tartozó adattagok, függvények deklarációját tesszük. A header fájlokat be include-olhatjuk bármilyen másik fájlba, mely annyit jelent, hogy a header tartalmát bemásoljuk a fájlba. A header fájlokba tehát a deklarációkat tesszük, amellyel a program tudtára adjuk, hogy ez a típus és a különböz adattagjai léteznek. Arról, hogy mit csinálnak ez nem ad információt, ezt ugyanis egy külön fordítási egységben célszerű megvalósítáni, vagyis itt definiáljuk a függvényeinket.

A külön fordítási egységek használata azért célszerű a gyakorlatban, mert ha a header file-okba írnánk a definíciókat, akkor minden egyes fordítás esetén az egész program lefordul. Gondoljunk bele, hogy van 20 darab fordítási egységünk, ami használ egy típust, ami a header file-ba van definiálva. Mind a 20 fordítási egység esetén a header tartalma is fordulni fog, holott eszünkbe se jutott módosítani, csak használni. A külön fordítási egységnél ez nem fordul elő, ha nem változtattunk rajta, akkor a használó programok nem fordítják újra feleslegesen a már meglévő kódot. 

Az is igaz, hogy ilyenkor kereszthivatkozások jönnek létre, amik relatíve lassúak. Azonban általában a program hatékonysága szempontjából ez elenyésző, ha pedig mégsem, akkor lehetséges fordítani úgy, hogy ezeket megszüntesse a fordító a binárisban ld.: Link Time Optimization.
