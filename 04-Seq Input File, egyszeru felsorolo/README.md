# Egyszerű felsoroló

A felsorolók (más néven: enumerator, iterator) olyan objektumok, melyek valamilyen adatszerkezetet (pl. tömb, vektor, fájl, gráf stb.) járnak be/dolgoznak fel anélkül, hogy az adatszerkezet elemeit újra letárolnánk. Mondhatni, bejárjuk az adatszerkezetet. A félév során fájlokat bejáró felsorolókkal fogunk foglalkozni, hogy kiemeljük a letárolás nélküli működést.

Egyszerű felsorolóknak nevezzük az olyan objektumokat, melyek szimplán csak bejárják a fájlt, a bejárt adatokon nem végeznek nagy módosítást. Más néven nevezetes felsorolónak nevezzük őket, pl. a szekvenciális input fájl felsorolója ilyen. A szekvenciális input fájl olyan szerkezetű fájl, melyben egymás után kövekteznek a felsorolandó adatok.

A felsorolókat programozási tételekkel karöltve fogjuk használni, minden feladatot ezek segítségével kell megoldani. Ezek egyszerű feladatokat megoldó algoritmusokat jelentenek, és ilyen jellegű feladatokat fogunk megoldani a félév folyamán is. A programozási tételek struktogramjai megtalálhatóak a fenti pdf-ben. Ezek az algoritmusok elég univerzálisak, minden helyesen megírt felsorolóra működnek.

A felsorolóinknak négyféle műveletet kell tudniuk elvégezni helyesen, hogy működőképesek legyenek az algoritmusainkkal. Ezek a:
* First() - Ez a művelet inicializálja a felsorolónk. Ez a metódus csak egyszer kell végrehajtódjon, hogy a megfelelő kezdőállapotba hozza az objektumunkat a további munkához és előállítja az első vizsgálandó elemet.
* Next() - Ezzel fogjuk léptetni a bejárást, amikor meghívjuk, akkor a következő vizsgálandó elemet kell beállítani a felsorolóban, a későbbiekben előfordul majd, hogy a vizsgálandó elemet ugyancsak programozási tételekkel kell előállítani, de van, hogy elég csak visszaadni az éppen fájlban lévő elemet
* Current() - Sima lekérdező függvény, az éppen felsorolt objektumot kell visszatérési értékként visszaadnia.
* End() - A felsorolás állapotát vizsgáló függvény, ez azt mondja meg, hogy a felsoroló végzett-e már a felsorolandó fájllal. Visszatérési értéke egy logikai érték kell legyen, ami akkor igaz, ha a felsoroló minden felsorolandó objektummal végzett.

Tehát láthatjuk, hogy az implementáció során ennek a négy metódusnak a megírása a fő feladat. Ennek keretében használhatunk segédmetódusokat is, hogy elkerüljük a kódismétlést és egyszerűbbé tegyük a debugolást, de arra is ügyeljünk, hogy ezt csak indokolt esetben tegyük meg. Ne írjunk felesleges függvényeket olyan műveletekre melyek logikailag nem feltétlenül különülnek el, vagy a kódban nincs indokolt szerepe (pl. csak egyszer fordul elő).
