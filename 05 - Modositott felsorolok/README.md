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

# Pufferelés

Előfordulhat, hogy egy fájlban egy adattag több tagból áll mint 1. Ez főként string-eknél jellemző, eddig feltettük, hogy a szöveges elemek amiket beolvasunk egyszavasak. Szeretnénk nagyobb rugalmasságot, speciális adatoknál (pl. név) meg akarjuk engedni, hogy több tagú is lehessen a string (de továbbra is legalább 1 szó), de nem szeretnénk extra delimiter karaktereket bevezetni a fájlba, ha nem muszáj. Ha az adatok formátuma engedi, akkor van lehetőségünk a fentire, de extra ötletre van szükségünk, a fix számú adat beolvasása nem elég.

A több szóból álló stringeket pufferelni (buffering) fogjuk. Ahhoz hogy ezt megtehessük olyan konvenció kell, amiben meg tudjuk határozni, hogy mikor legyen vége a pufferelésnek pl. ha tudjuk, hogy a többszavas string után egy szám jön, akkor addig kell pufferelni míg a számhoz nem értünk. Végiggondolva a pufferelést akkor vethetjük tehát be, ha: a fájl tartalmában nincs egymás után két változó számú szóból álló string, úgy, hogy a köztük lévő adattagok mind stringek. Ellenpélda pl. egy többszavas string, egyszavas string, többszavas string formátum, ekkor nem tudjuk kikövetkeztetni az első string végét, hiába fix hosszú a középső string.

Ha tehát szabályos a fájlunk, akkor tudunk felső korlátot mondani arra, hogy meddig kell olvasni, hogy eldönthessük a string végén vagyunk-e, mivel mindenképp lesz olyan adat ami nem szöveg. Tekintve az órai feladatot azt szeretnénk megoldani, hogy a név tetszőleges számú szóból állhasson. A név után egyszavas string-ek és int-ek jönnek egymás után páronként (termék, ár). Előre szeretnénk olvasni a fájlban, és közben felépíteni a név string-et az előreolvasás eredménye szerint. Ez is egy fajta pufferelés. Általánosan a pufferelés olyan módszer ahol adatot szeretnénk továbbítani két médium között (jelen esetben egy string változó és egy filestream között), de a küldés nem közvetlenül történik, hanem csak ideiglenes letárolás után (a letárolás célja sokféle lehet).

Nyilvánvalóan egy előreolvasás nem lesz elég, el tudjuk dönteni előbb utóbb, hogy véget ért a string, de nem tudjuk, hogy a hozzáfűzést mikor kell abbahagyni, csak amikor egy int-et olvasunk. Ekkor viszont az előző string már a termék volt és a számlázhoz tartozik, nem a névhez. Utólag lebonthatnánk ugyan a stringet és kinyerhetnénk az áru nevét, de ez nem túl elegáns és felesleges bonyolultságot idéz. Két pufferelő változó kell tehát, és a második puffer eredménye szerint folytatjuk a fűzést. Ha a 2. változó még string, akkor tudjuk, hogy az első puffer tartalma a név része, tehát hozzáfűzhetjük.

Hasonló logikával a fenti formátumú fájlokban mindig lehet megfelelő pufferelő algoritmust írni. Ennek a módszernek a másik korlátja a memória és a hibakezelés. Ha túl sokat kell pufferelni egy huzamban, akkor nem ússzuk meg delimiterek nélkül, illetve pufferelés közben nem lehet visszatérni ha hibás adatot kapunk, az összegyűjtott adat használhatatlan, el kell dobni.

# A módosított felsoroló

Nyilvánvalóan a felsoroló továbbra is meg tudja ezeket oldani, egyedül a Read() függvényünk lesz bonyolultabb, ami így már szintén egy programozási tételre hajaz. Jelen esetben összegezzük az árakat a számlán, hogy megkapjuk a végösszeget.

Fontos, hogy az áruk sorozatát ne tároljuk le vector-ba, vagy bármilyen más adatszerkezetbe. Minden feladat egyéni, de lehet belőle következtetni arra, hogy milyen adatot kell számolnunk a rekordhoz, így a nem kellő adatokkal ne foglalkozzunk. A beolvasás közben több adatnak kiszámolása párhuzamosítható, tehát ha más feladat van, akkor a Read() és a szamla rekord értelemszerű módosításaival érdemes megoldani a feladatot, mivel a vector-ok felpopulálása és lebontása költséges, és a fájlban már benne van az adat.

Ezeket az elveket általánosan is be kell tartani, értelmezzük a feladatot mielőtt nekilátunk az implementációnak.

# Órai feladat

Adott egy üzlet aznapi forgalma: számlák sorozata, ahol egy számlán szerepel a vásárló neve, az általa vásárolt termékek neve és ára. A vásárló neve tetszőleges szószámú string, és az áruk neve egy szóból áll. Mennyi az aznapi bevétel?

### Egyéb olvasmány/dokumentáció a fenti témakörökről

getline dokumentáció: http://www.cplusplus.com/reference/string/string/getline/

std::stringstream dokumentáció: http://www.cplusplus.com/reference/sstream/stringstream/
