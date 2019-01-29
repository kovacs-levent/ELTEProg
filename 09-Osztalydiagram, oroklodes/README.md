# Öröklődés

Az objektumorientált programozási paradigmának egyik alapelve, hogy az objektumok lehetnek más objektumok részei.
Erre már láttunk példát, például a prioritásos sornál, az Elem objektumot tartalmazza a PrSor osztálya.
A fenti érezhetően tartalmazási kapcsolatot ír le, de az is lehet, hogy olyan kapcsolatot szeretnénk ami ennél közelibb.

Az órai feladat egy lényverseny a lemodellezése.
A játékszabályok megtalálhatóak a mappában, és érezhetően hasonló viselkedésűek a különböző lények, de csak az konkretizálja, hogy milyen fajtájú lényről beszélünk.
Olyasfajta modellt szeretnénk alkotni, ahol a lények viselkedését elég legyen általánosan leírni, a speciális viselkedést pedig külön osztályokban szeretnénk leírni, ami viszont az általános viselkedést is követi.
Az ilyesfajta feladatokra jó az öröklődés, a speciális lények mindegyike egy simán lény is, tehát ha a sima lényekre írunk egy osztályt, akkor azt a többi lény használhatná a speciális viselkedésének leírásához.
Ez azért jó, mert a verseny szimulációjának szempontjából nincs jelentősége annak, hogy a lény milyen típusú, a lényre kifejtett hatás az ami, speciális, a versenyhez nincs semmi köze.
Érezhetően azt szeretnénk elérni, hogy a versenybe ne kelljen foglalkozni a speciális dolgokkal, azt oldják meg az osztályok maguk.

Az öröklődéssel tehát megalkottunk 3 gyerekosztályt, melyek mind az általános lény osztályból származnak le.
Ez azt jelenti, hogy minden függvényét az adott osztálynak örökli, melynek több módja van. 4 féle öröklődést különböztetünk meg:
* public
* protected
* private
* virtual

Az első három érezhető lehet az osztályokkal való eddigi munkánkból, hogy mit jelent.
A public öröklődés nem változtat a láthatóságokon, a protected minden public láthatóságot protected-re változtat, a private pedig mindent private-ra állít.
A protected láthatóság pedig most már számít, a protected változóit egy osztálynak csakis a gyerekosztályai érik el, más nem.

A virtual öröklődés többszintű öröklődésnél érdekes, ez azt biztosítja, hogy ha egy osztály olyan osztályokból örököl melyek szintén gyerekosztályok, akkor csak egy másolatot kapjon a duplikált változókból (lehet, hogy a két osztálynak van ugyanolyan változója).
Mi nem fogunk vele foglalkozni.

A virtuális függvénye viszont a lények osztályban olyan függvény melyet nem definiálunk.
A C++ ha a függvény után = 0 szerepel (tehát pl. void f() = 0;), akkor ez a függvény absztrakt függvény, vagyis nincs definíciója, nem is akarunk neki adni (nem tudunk).
Az ilyen absztrakt függvényeket tartalmazó osztályokat nem lehet példányosítani, viszont a gyerekosztályokat szeretnénk, tehát az absztrakt függvénnyel kezdeni kell valamit.
Az absztrakt függvény ezért lesz virtuális, hogy a gyerekosztály felüldefiniálhassa (override) azt. Ha ez megvan, akkor a gyerekosztály már példányosítható.
