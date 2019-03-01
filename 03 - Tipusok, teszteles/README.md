# Tesztelés

Az osztályokat valamilyen rendszer szerint (általában a feladat specifikációja alapján) készítjük el úgy, hogy a műveletek egymással szinkronban a szabályos működést eredményezzék.
Az eddigiek alapján a kis méretű kódokat le tudtuk kimerítően tesztelni úgy, hogy néhányszor kipróbáltuk a működését (konzolra kiírva, esetleg fájlba írva).
Érezhetően a fenti módszer nagy méretű kódbázisnál egy nagyon nehéz feladat, illetve nem hibabiztos (az ember hibázhat az ellenőrzés közben).

A különféle programok fejlesztésekor léterjövő kódbázist szeretnénk olyan eszközökkel tesztelni, mely képes az osztályokat egységesen, illetve külön-külön a metódusait is tesztelni.
Azt is elvárjuk, hogy az eredmény ellenőrzése programszintű legyen, tehát a működés helyességének ellenőrzését is a számítógép végzi.
Ez a tesztelési szint amit unit testing-nek vagyis egységtesztelésnek hívunk és nagy horderejű, hiszen ez biztosítja az objektumaink különálló működését.
Ez a legelső tesztelés ami általában megtörténik, hiszen a nagyobb rendszerek felépítéséhez szükségesek a megfelelően működő alapkódok.

Az egységteszteléskor a program objektumait egy kontrollált környezetben, fix bemenetekre teszteljük, hogy a várt eredményt kapjuk-e.
Ezek lesznek az egységtesztek.
A teszt kódjában elvégzünk műveleteket az objektumon és megnézzük közben (javarészt többször), hogy a kívánt eredményt kaptuk-e.
Egy ilyen teszt folyamán többször csinálunk check-eket, hogy szabályos-e a működés.
Egy ilyen check egy egyszerű logikai értékű kifejezés eredményét vizsgálja.
Ha check kifejezés igaz, akkor a program sikeres, ha hamis, akkor megbukott a teszten.

Az nyilvánvaló cél az, hogy az összes felállított teszteseten átmenjen a program, különben valahol bug van a kódban.
A C++ kódok teszteléséhez a Catch keretrendszert fogjuk használni, mely elérhető a https://github.com/catchorg/Catch2 repon.

# Kivételkezelés
A programok tervezése közben megállapítjuk a műveletekről, hogy milyen bemenetre, vagy milyen körülmények között kell annak ténylegesen jó eredményt adni. Pl.: Az intervallumos maximum kiválasztás progtétel csak nem üres intervallumon működik, üreseken nem elvárt, hogy egy maximális elemet visszakapjunk. Azonban ezeknek a megvalósított eljárásoknak a meghívását nem tudjuk korlátozni, a fenti példával: előfordulhat, hogy valaki egy egész számokat tartalmazó vektorokra megvalósított maxkert meghívja egy üres vektorra. Az is lehet, hogy memóriakezelési hiba adódik, az operációs rendszer nem enged valamilyen műveletet stb. Az eddigi programokban szimplán kiléptünk, ha hiba adódott, de ez a fajta hibakezelés nem igazán felhasználóbarát. Nem minden hiba ugyanolyan mértékű, nem kell kilőni minden esetben a programot, a kivételes eseteket le lehetne kezelni.

A C++-ban a fenti kivételkezelést try-catch blokkokkal, illetve throw utasításokkal valósítjuk meg. A try-blokka helyezett kódra figyeljük a kivételeket, ha bármilyen jellegű kivételt dob a kód, akkor a vezérlés átkerül a catch-blokkhoz (kivételkezelő). Ha nem adódik hiba, akkor a program normálisan fut tovább, a kivételkezelő kódját nem hajtja végre. A kivételeket a throw utasítással dobjuk ez bármilyen kifejezést kaphat paraméternek throw \<kif\>; alakban írjuk le, és ekkor a kifejezés értéke lesz a hibajelzés. A catch blokkban megmondhatjuk, hogy milyen típusú kivételeket szeretnénk lekezelni és minden típusra külön kódot tudunk végrehajtani.
  
A fentiekre pár példát feltöltöttem a mappába.

### Egyéb olvasmány, dokumentáció a fenti témakörökről
Egységtesztelésről: http://softwaretestingfundamentals.com/unit-testing/

Kivételkezelésről: http://www.cplusplus.com/doc/tutorial/exceptions/
