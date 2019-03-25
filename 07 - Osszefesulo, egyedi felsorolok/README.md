# Összefésülő felsoroló

Az összefésülés gyakori elv a programozás közben, akkor használjuk ezeket az úgynevezett merging algoritmusokat, amikor több input forrásunk van, de mindegyik adatára szükségünk van a helyes eredmény meghatározásához. Az összefésülő felsoroló hasonló elvvel működik, több inputfájlt kell egyszerre kezelnünk és ezek adatai alapján valamilyen eredményt kiszámolni.

Ez általában a mi esetünkben azt jelenti, hogy két fájlt olvasunk egyszerre, viszont valamilyen módon váltogatnunk kell, hogy éppen melyiket olvassuk, melyik éppen a felsorolandó elem. Az inputfájljaink rendezettek, hogy a műveletigény kevesebb és a működési elv egyszerűbb legyen. Ez megint csak nem olyan nagy elvárás, lehet rendezni a fájlokat az algoritmus előtt.

Az első kérdés, hogy mi alapján olvassunk. Mivel a fájljaink rendezettek, ezért nyilvánvalóan értelmes közöttük valamilyen rendezés, szóval megvizsgálhatjuk, hogy az olvasott elemek közül melyik a kisebb (az egyszerűség kedvéért két fájlból olvasunk). Ha pl. az első fájlban lévő adat kisebb, akkor tudjuk, hogy ilyen adat már nem lesz a 2. fájlban, szóval az elsőből olvasunk (a feladat szempontjából biztosan tudunk döntést hozni, hogy ezzel az elemmel mit kell tenni). Ha a két elem egyenlő, akkor mindkettőből olvasunk.

Az, hogy a fenti eseteknél az olvasáson túl milyen műveletet hajtunk végre, illetve, hogy mi a megállási feltétel az feladatfüggő, ilyenekre nézünk pár példát.

# Órai feladat

Két egyszerű feladatot oldunk meg, adott két rendezett inputfájl melyekben egész számok szerepelnek. A feladatok:

1. Készítsünk felsorolót, mely felsorolja a két inputfájlban lévő elemek unióját.

2. Készítsünk felsorolót, mely felsorolja a két inputfájlban lévő elemek metszetét.
