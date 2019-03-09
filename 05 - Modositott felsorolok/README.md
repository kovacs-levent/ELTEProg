# Beolvasás fájlból

Érthetően az előző órai egyszerű példán túl nem csak ilyen lehet a beolvasás. Van, hogy egy adategységhez több mindent kell olvasni, és nem is tudjuk feltétlen, hogy mennyit.
Jelen órán olyan felsorolót fogunk megnézni, mely olyan fájlnak az adatait sorolja fel, ahol egy rekord egy sorban helyezkedik el, de az olvasott adatok több tagúak is lehetnek.

Ehhez először az kell, hogy a soronként tudjunk beolvasni. A sort általában textfile-okban a '\n', sortörést jelző speciális karakterrel szokás befejezni.
Ezt fogjuk kihasználni, de általánosítani is lehet, a C++-ban a getline függvény pontosan ezt csinálja. A getline paraméterei egy istream (inputstream), amiből olvasni szeretnénk, egy string amibe beolvasnánk az adatot, és egy opcionális, 3. paraméter is van. A 3. paraméter azt mondja meg, hogy mi legyen a delimiter karakter, addig fog tartani a stream olvasása, ameddig nem érünk egy delimiter karakterhez, vagy a stream végéhez (hiba esetén szintén befejeződik az olvasás). Ha nem adjuk meg ezt a paramétert, akkor az alapértelmezett delimiter a '\n'.

Tehát már a sort be tudjuk olvasni egy string-be. Jelen feladat példájával élve, a sorunk a következő alakú: <vevő neve> <vásárolt áruk sorozata>.
Az áruk olyan rekordok, amiben meg van adva a termék neve, és az ára (ez egymás után 2 adat). Nem tudjuk előre mennyit vett a vásárló, csak, hogy valamikor véget ér az árusorozat.

Erre segítségül kell hívnünk még egy stream-et, amivel egy string-ben tárolt szöveget tudunk kezelni adatfolyamként. Ezek az std::stringstream, std::istringstream, std::ostringstream.
A stringstream két irányú, a másik kettő értelemszerűen input és output streameket valósít meg. A stringstream-nek be kell adni a string-et mint adatfolyam, ezután ezt úgy fogja kezelni, mint bármelyik másik stream (whitespace-k mentén olvas, stb.).

Ügyelni kell stringstream-ek esetén a megfelelő betáplálásra, és főleg a két irányú változat esetén, hogy karbantartsuk a stream-et, ha nem egy menetben szeretnénk csak használni (egy menet ~ egyszer betáplálunk adatot, majd visszaolvassuk).

A stringstream-eket általában ilyen feladatokra használjuk, hogy valamilyen formátumú string-et átformázzunk úgy, hogy az nekünk kezelhető legyen.

# A módosított felsoroló

Nyilvánvalóan a felsoroló továbbra is meg tudja ezeket oldani, egyedül a Read() függvényünk lesz bonyolultabb, ami így már szintén egy programozási tételre hajaz. Jelen esetben összegezzük az árakat a számlán, hogy megkapjuk a végösszeget.

Fontos, hogy az áruk sorozatát ne tároljuk le vector-ba, vagy bármilyen más adatszerkezetbe. Minden feladat egyéni, de lehet belőle következtetni arra, hogy milyen adatot kell számolnunk a rekordhoz, így a nem kellő adatokkal ne foglalkozzunk. A beolvasás közben több adatnak kiszámolása párhuzamosítható, tehát ha más feladat van, akkor a Read() és a szamla rekord értelemszerű módosításaival érdemes megoldani a feladatot, mivel a vector-ok felpopulálása és lebontása költséges, és a fájlban már benne van az adat.

Ezeket az elveket általánosan is be kell tartani, értelmezzük a feladatot mielőtt nekilátunk az implementációnak.

# Órai feladat

Adott egy üzlet aznapi forgalma: számlák sorozata, ahol egy számlán szerepel a vásárló neve, az általa vásárolt termékek neve és ára. Elsőre feltesszük, hogy a vásárló neve, és az áruk neve egy szóból áll. Mennyi
az aznapi bevétel?

### Egyéb olvasmány/dokumentáció a fenti témakörökről

getline dokumentáció: http://www.cplusplus.com/reference/string/string/getline/

std::stringstream dokumentáció: http://www.cplusplus.com/reference/sstream/stringstream/
