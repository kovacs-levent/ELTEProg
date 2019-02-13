# Függvény paraméterek

A C++ lehetőséget ad arra, hogy tóbb módon adjuk át a paramétereket egy függvénynek.
Az alapértelmezett érték szerinti paraméterátadással már mindenki találkozott Programozáson, ez úgy adja át a paramétert, hogy bemásolja az értékét a paraméternek, hogy a függvény azt használja (vagyis egy új változót kap a függvény, melynek ugyanaz lesz az értéke, mint a híváskor adott változóé, literálé, stb.).
Új féle átadás a referencia szerinti paraméterátadás. A fő különbsége az érték szerintihez képest, hogy a külső hívásból kapott változóval dolgozunk.
Tehát ha a függvény módosítja a változót, akkor az eredeti változó is módosul, amivel hívtuk a függvényt.
Ezen kívül memóriakezelés szempontjából is van különbség, a referenciákból nem készül másolat, mint általában a sima paraméterekből.
Ez akkor jó, ha mondjuk valamilyen nagy méretű adatot (pl. egy vector-t) szeretnénk átadni a függvénynek, ahol a másolás költséges lehet.
Általában a függvény paraméterlistájában ilyen alakban kell megadni: <típusnév> &<változónév>.

Az átadáson kívül mást is befolyásolhatunk a paramétereinkben, nekünk a const lesz fontos. Const jelzővel ellátott változókat/paramétereket nem lehet módosítani, különben fordítási hibát kapunk (biztosíték arra, hogy nem lesz változás).
Ez azért fontos, mert egyes műveletek változtathatják a változó értékét (referenciák), mellékhatásokkal járhatnak (elég csak egy i++, inkrementálásra gondolni).
Az is előfordul, hogy a fentiek valamelyike úgy megy végbe, hogy nem számítunk rá, és a változás a program többi részének futását is befolyásolja.
Ajánlott tehát ahol csak lehet const-ot írni, általánosan programokban lévő bugok egy jó része abból következik, hogy változók nem vártan módusulnak.

## Megjegyzések

1. Lehet const referenciát is csinálni, ekkor egy olyan paramétert kapunk, mely nem másolódik, és nem is módosítható
2. Ha egy függvénynek referencia paramétere van, akkor a függvényhíváskor csakis olyan értéket adhatunk paraméternek, melynek van memóriacíme (általában a lényeg, hogy változók kell legyenek a paraméterek). 
Ez röviden annyit tesz, hogy csakis olyan értéket adhatunk híváskor paraméternek, mely valahol le van tárolva a memóriában, és adható neki érték.
Pl. A max_horpadas(9, 10, "input.txt"); hívás hibát dob, mert a 9 és a 10 úgynevezett számliterálok, nem változók, nincs memóriacímük, nem adhatunk nekik értéket

# Fájlkezelés
Szeretnénk, ha nem csak billentyűzetről, vagy a programba beleégetve tudnánk adatot átadni, hanem külön fájlból tudnánk beolvasni.
A C++-ban az inputstream-ek (és outputstream-ek) mögött megbújó felépítés miatt a filestream-ből való beolvasás hasonló a konzolból beolvasáshoz.
Az ifstream (és később ofstream) csatornáinkat hasonlóan kezelhetjük beolvasás és írás szempontjából mint a cin-t és a cout-ot.
Azonban fontos odafigyelni, hogy a bekérés körülményei megváltoztak, szükséges tehát extra feltételeket hozzáadni a beolvasáshoz (Mi van, ha nincs megadva, vagy nem tudjuk előre, hogy hány beolvasandó adatunk van?).

A fájl végét kell ellenőrizni (illetve egyéb formai követelményeket is lehetne még check-olni), ha vége a fájlnak, ne olvassunk többet.
A istream (inputstream) objektumoknak vannak különféle  fail(), eof(), stb. függvényeik, ezzel tudjuk ellenőrizni a stream állapotát.
A beolvasás többféle módon megvalósítható ezekkel, mi most egy fail()-al való változatot nézünk meg. A fenti állapotfüggvények logikai értékűek, és általában valamilyen állapotbit-et (flag) ellenőriznek.
A fenti fail() függvény pl. akkor igaz, hogyha valamilyen művelet hibával végződött Pl.: fájlt akarunk nyitni, de a fájl nem létezik, olvasni akarunk, de már nincs adat, olyan típusba akarunk olvasni amit a kapott adatból nem tudunk előállítani (pl. egy int-be szöveget olvasunk a streamből) stb.

# Vector
A C++-ban megvalósítottak sokfajta úgynevezett Container típust osztályként a standard könyvtárba (osztályokról következő órán lesz szó), melyekből az egyik a vector (precízebben: std::vector, azaz az std (standard) névtérben lévő vector típus).
A tömb helyett ebben a félévben ezt fogjuk használni, a vector sokkal rugalmasabb a tömbnél, mérete dinamikusan nő (nem kell előre tudni, vagy bekérni a méretét a bemenetnek), viszont tárolása hasonló a tömbhöz (egymás után helyezkednek el az adatok, a \[\] operátorral és indexekkel hivatkozhatunk az elemekre).

A plusz újdonság, hogy mivel ez egy magasabb szinten megvalósított típus, ezért vannak külön függvényei melyeket használhatunk, ami a tömbnél nem elérhető. A vectornak például bármikor lekérdezhetjük a méretét egy egyszerű size() függvényhívással, míg a tömbnél ez nem olyan egyszerű, főleg ha át szeretnénk azt adni paraméternek (megoldható, de a méretet nem tudjuk egy egységbe tárolni a tömbbel). Az órai kódban még a push_back()-et használjuk, ez a vector végére behelyez egy új elemet. Általában ezt használjuk egy vector feltöltésére, mivel ez rugalmasabb. A tömböknél használt fix indexekkel való feltöltés kihasználta azt, hogy tudjuk mennyi adatunk van. 

Ezen kívül még rengeteg vector-ral használható osztályfüggvény és algoritmus van implementálva a C++ standard könyvtárában, a félév folyamán többel is meg fogunk ismerkedni.

# Osztályokról röviden
Az objektumorientált programozás egyik legsűrűbben használt eszköze az osztályok. Ezek olyan programkódok, melyek valamilyen objektumot valósítanak meg úgy, hogy az használható legyen a főprogramban, vagy akár kiterjeszthetőek legyenek további osztályok létrehozására. Egy osztálynak lehetnek adattagjai és tagfüggvényei, illetve az osztályt a nevével szokás azonosítani (több osztály esetén megköveteljük a név egyediségét, legalábbis egy névtéren belül). Az ilyen objektumoktól általában azt várjuk el, hogy egy logikailag jól elkülöníthető feladatot oldjanak meg a programban.

A C++-ban ezeket class-ként valósítjuk meg, ennek a konstrukciónak a viselkedését bővebben a félév folyamán fogjuk mélyebben is tanulni. A class-okat, hogy használni is tudjuk példányosítani kell, ekkor kapjuk egy példányát az objektumunknak. A példány önmagába foglalja az összes class-ban definiált adattagot, tagfüggvényt, és ezeket a példányon keresztül tudjuk használni. Több példányt is készíthetünk, ekkor értelemszerűen a különböző adattagok minden példányra külön-külön létrejönnek, és a tagfüggvények a példány saját adataival dolgoznak. 

Fontos megemlíteni, hogy az class-oknál előjön az adattagok és tagfüggvények láthatósága, C++-ban 3 féle láthatóságot különböztetünk meg: public, protected és private. A protected-ről a félév második felében fogunk részletesen tanulni. A public láthatóságú tagok az osztályban és a külső példányokon keresztül is elérhetőek, tehát ha példányosítjuk az objektumunk, akkor a publikus tagokon keresztül tudjuk ezt az objektumot ténylegesen használni kívülről. A private láthatóság azt jelenti, hogy az ilyen tagokat csak az osztályon belül érhetjük el, tehát csak az osztály tagfüggvényein keresztül lehet őket közvetlenül olvasni, módosítani. Pl. a jelenlegi kódban a Felszin objektumunk f példánya nem látja a vec és a filestream adattagjait az osztálynak (egyszer érdemes kipróbálni: mi a hibaüzenet, ha mégis megpróbáljuk ezeket az f-en keresztül elérni? Pl. ha ki akarjuk írni az f.vec egyik elemét?).

# Órai feladat
Legmagasabban fekvő horpadás keresése. Egy felszínen adott távolságonként mérték a tengerszint feletti magasságot.
Horpadásnak veszünk egy értéket, ha a körülötte (balra és jobbra) lévő magasságok nagyobbak ennél az értéknél.
A feltételes maximum keresés programozási tétellel oldjuk meg a feladatot.

### Egyéb olvasmány/dokumentáció a fenti témakörökről (csak annak akit érdekel)
Referencia paraméterek: https://www.learncpp.com/cpp-tutorial/73-passing-arguments-by-reference/

Const változók, paraméterek: http://duramecho.com/ComputerInformation/WhyHowCppConst.html

Az istreamek doksija: http://www.cplusplus.com/reference/istream/istream/

Az std::vector doksija: https://en.cppreference.com/w/cpp/container/vector
