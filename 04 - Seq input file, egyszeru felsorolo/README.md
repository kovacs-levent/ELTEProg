# Fájlkezelés
Az input fájlok kezeléséről már volt szó az előző órákon, részletesebb leírás erről [itt](https://github.com/kovacs-levent/ELTEProg/tree/master/01%20-%20Intervallumos%20tetelek%2C%20C%2B%2B%20nyelvi%20alapok) található.

A fájlokat viszont jó lenne nem csak olvasni, hanem írni is. C++-ban a output file stream-re az std::ofstream-et fogjuk használni, ennek működése hasonló a konzolos std::cout-hoz, annyi a különbség, hogy az ofstream-nek meg kell nyitnia egy fájlt mielőtt írni tudnánk vele. A fájl megnyitása történhet konstruktorral, vagy az open tagfüggvénnyel. A megnyitás módját lehet szabályozni az in, out, binary, ate, app, trunc kapcsolókkal. Ezzel főként azt lehet szabályozni, hogy a már meglévő tartalmat felülírjuk, hozzáírunk stb. Az alapértelmezett megnyitás (out mód) a fájl tartalmát felülírja. Ez nekünk javarészt elég is lesz, a fájljainkat a félév során egy ofstream objektummal és egy algoritmussal megírjuk, ha az írandó fájlban volt adat, akkor nem kell megtartani, eldobhatjuk a régi tartalmat.

Megnyitás után a fájlba ugyanolyan módon tudunk írni mint az std::cout-ra, a << operátorral. Előző órán már láttuk, hogy kell felüldefiniálni a << operátort, és hogy hogyan lehet általánosan output streamekre megírni ezeket. Emiatt van az, hogy miután megkonstruáltuk az ofstream-ünket, utána már ugyanúgy használhatjuk mint a cout-ot.

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

# Órai feladat
Adottak kaktuszok egy szekvenciális input fájlban a következő tulajdonságaik vannak felsorolva: nevük, őshazájuk, viráguk színe, méretük. Implementáljuk a kaktuszokat tartalmazó szekvenciális input fájl felsorolóját, és oldjuk meg vele az alábbi feladatokat:
* Egy output fájlba válogassuk ki a mexikói kaktuszok információit
* Egy output fájlba írjuk bele a piros virágú kaktuszokat
* Adjuk meg, hogy melyik mexikói kaktusz a legnagyobb

### Egyéb olvasmány/dokumentáció a fenti témakörökről
Az ostream-ek doksija: http://www.cplusplus.com/reference/ostream/ostream/
