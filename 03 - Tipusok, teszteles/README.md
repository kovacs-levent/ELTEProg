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
