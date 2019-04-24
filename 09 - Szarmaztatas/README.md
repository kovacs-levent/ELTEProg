# Öröklődés

Az objektumorientált programozási paradigmának egyik alapelve, hogy az objektumok lehetnek más objektumok részei.
Erre már láttunk példát, például a prioritásos sornál, az Elem objektumot tartalmazza a PrSor osztálya.
A fenti érezhetően tartalmazási kapcsolatot ír le, de az is lehet, hogy olyan kapcsolatot szeretnénk ami ennél közelibb.

Az órai feladat egy fájlrendszer megvalósítása, ahol fájlok és könyvtárok lehetnek a bejegyzések. Egy fájlban adat van (string), egy könyvtárban pedig tartalmazhat bejegyzéseket (bejegyzések sorozata). A fájlrendszer szintén bejegyzéseket tartalmaz, bejegyzések sorozatát.
Olyasfajta modellt szeretnénk alkotni, ahol a bejegyzések viselkedését elég legyen általánosan leírni, a speciális viselkedést pedig külön osztályokban szeretnénk leírni, ami viszont az általános viselkedést is követi.
Az ilyesfajta feladatokra jó az öröklődés, a speciális bejegyzések (fájl, könyvtár) mindegyike egy bejegyzés is, tehát ha a sima entry-re írunk egy osztályt, akkor azt a fájl és könyvtár osztály használhatná azt a speciális viselkedésének leírásához.
Ez azért jó, mert a fájlrendszer szempontjából nincs jelentősége annak, hogy a bejegyzés milyen típusú, a bejegyzésekre kifejtett hatás ugyanaz (pl. törlésnél).
Azt szeretnénk elérni, hogy a fájlrendszerbe ne kelljen foglalkozni a speciális dolgokkal, azt oldják meg az osztályok maguk.

Az öröklődéssel tehát megalkottunk 2 gyerekosztályt, melyek mind az általános bejegyzés osztályból származnak le.
Ez azt jelenti, hogy minden függvényét az adott osztálynak örökli, melynek több módja van. 4 féle öröklődést különböztetünk meg:
* public
* protected
* private
* virtual

A public öröklődés nem változtat a láthatóságokon, a protected minden public láthatóságot protected-re változtat, a private pedig mindent private-ra állít.
A protected láthatóságú adattagjait és függvényeit egy osztálynak csakis a gyerekosztályai érik el.

A virtual öröklődés többszintű öröklődésnél érdekes, ez azt biztosítja, hogy ha egy osztály olyan osztályokból örököl melyek szintén gyerekosztályok, akkor csak egy másolatot kapjon a duplikált változókból (lehet, hogy a két osztálynak van ugyanolyan változója).
Mi nem fogunk vele foglalkozni.

Virtual függvények viszont fontosak, az általános függvényeket felül fogják definiálni (override) a gyerekosztályok, ezt jelenti a virtual, ez egy felüldefiniálható függvény. Az Entry osztály tartalmaz egy getSize() függvényt, mely visszaadja a bejegyzés méretét. Ez fájl esetén az adat méretét jelenti, könyvtár esetén a könyvtárban lévő bejegyzések méretének összessége. Az Entry-nél viszont magában nincs specifikálva, hogy mi a getSize(), ezért ezt absztrakt függvényként definiáljuk.
A C++-ban ha a függvény után = 0 szerepel (tehát pl. void f() = 0;), akkor ez a függvény absztrakt függvény, vagyis nincs definíciója, nem is akarunk neki adni (nem tudunk).
Az ilyen absztrakt függvényeket tartalmazó osztályokat nem lehet példányosítani, viszont a gyerekosztályokat szeretnénk, tehát az absztrakt függvénnyel kezdeni kell valamit (hiszen ezt megörökli a gyerekosztály).
Az absztrakt függvény ezért lesz virtuális, hogy a gyerekosztály felüldefiniálhassa (override) azt. Ha ez megvan, akkor a gyerekosztály már példányosítható.

Olyan függvény létrehozása is lehetséges, mely virtuális, de nem absztrakt. Erre van egy rövid példa a mappában.

# Órai feladat
Egy számítógépes fájlrendszerben a fájlokat könyvtárakba szervezzük. Minden könyvtár
tetszőleges számú fájlt vagy könyvtárat tartalmazhat. A fájlrendszerben a fájlok lehetnek
közvetlen a fájlrendszerhez kötve (gyökér), vagy valamelyik könyvtárban is
elhelyezkedhetnek. Mennyi tárhelyet foglal egy adott könyvtár?
