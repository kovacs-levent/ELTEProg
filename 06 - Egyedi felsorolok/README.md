# Csoportos felsorolók

Előző órán foglalkoztunk olyan felsorolókkal, ahol egy sorban helyezkednek el a rekord adatai, a sor szövegét streamként kezelve kell megkonstruálni a felsorolandó elemet.
Most olyan felsorolót is fogunk készíteni, ahol az egy felsorolandó rekordhoz tartozó adatok a fájlban akár több sorban is elhelyezkedhetnek. Az ilyen felsorolókat csoportos, vagy egyedi felsorolónak szoktuk hívni.

Meggondolható, hogy hogyan épülhetne fel egy ilyen fájl, ahol egy nagyobb objektumhoz több apróbb egységnyi adat tartozik, mondjuk soronként elhelyezkedve.
A sorokat már fel tudjuk dolgozni, most azt kellene, hogy valamilyen módon csoportosítsuk az adatokat. Erre a fájlformátumot kell szabályozni, hogy az algoritmusunk effektív legyen. Ha minden rekordhoz bárhol lehetne adat (valami ID alapján azonosítva), akkor mindig az egész fájlon végig kéne menni, hogy összegezzük az adatokat, és számon kéne tartani, hogy mi volt már amit felsoroltunk. Ez felesleges komplexitást idéz és pazarló az algoritmus.

Tegyük fel, hogy a fájl rendezett valamilyen azonosító alapján, amiből ki tudjuk szűrni, hogy mi mihez tartozik. Így tehát az egy rekordhoz tartozó adatok a fájlban egymás után helyezkednek el, és a következő ID megtalálásakor tudjuk, hogy már más rekord adatai jönnek.
A rendezettséget feltehetjük, ha a fájlunk mégse lenne rendezett, akkor rászabadíthatnánk egy rendező algoritmust, így rendezett fájlt kapunk. A rendezés műveletigénye sok lehet, de ezt elég egyszer megtenni, illetve a fájlt rendezetten is karban lehet tartani. Ezt mi a félévben nem fogjuk tanulni, alapból rendezett fájlokkal foglalkozunk.

Az alapötlet tehát, hogy a Next() műveletében a felsorolónak összegezzük a csoportosított adatokat úgy, hogyha a következő adat már más azonosítóval rendelkezik (vagy ha elértük a fájl végét), akkor leállunk.
Érezhetően a Next() művelet ezzel bonyolultabb lesz, kénytelenek leszünk programozási tételeket alkalmazni a Next() algoritmusaként, hogy az adatokat összegezzük.

Már láttuk a pufferelés alapötletét, jelen esetben is ezt kell alkalmazni, hogy el tudjuk dönteni mikor van vége egy csoportnak.
Emiatt 2 darab rekordot fogunk készíteni a felsoroló osztályába, ezeket általában akt-nak és next-nek nevezzük el. Az akt-ban fogunk összegezni a Next() függvényben, és ezt fogja visszaadni a Current() függvény.
A next rekordba fogunk olvasni, ebbe egy sornak az adatait beolvassuk, majd a Next()-ben az olvasás eredménye alapján változtatjuk az akt-ot.
Az elején inicializálni kell az akt-ot, hogy a megfelelő ID-t betápláljuk a rekordba, addig fogunk olvasni és összegezni, amíg a next-be olvasott ID megegyezik ezzel (vagy nem érünk a fájl végére).

Egy módosítást vagyunk még kénytelenek eszközölni a csoportos felsorolóknál. A beolvasás jellege miatt meg kell gondolni, hogy mi történik a felsorolás végén.
Amikor az utolsó csoportot kezdjük el előállítani (a Next()-el), akkor a felsoroló addig fog olvasni míg a fájl végére nem ér, ekkor ugye beállítjuk (a status sx-be pl.), hogy a fájl olvasása már sikertelen.
Ha meghagyjuk az eddigi End() függvényünket, vagyis return sx == abnorm;-ot, akkor az utolsó rekord nem lesz felsorolva. Ezért be kell vezetni egy extra logikai változót is, amiben számon tartjuk a felsorolás végét. Ez azért kell mert jelen esetben a fájl és a felsorolás vége nem ugyanaz az esemény.
Ezt a Next() elején kell checkolni, ha már a státuszunk abnorm, akkor az előzőleg felsorolt elem volt az utolsó (hisz a fájl végére értünk, mivel a fájl formátuma feltehető, hogy helyes), vagyis az isEnd-et beállíthatjuk igaz-ra. Ennek az értékét fogja visszaadni az End().

Ez általánosan az ötlet ami szerint az ilyen felsorolókat megvalósítjuk (az eddigiekre építve), a ZH-n a kiváló szinthet ilyen felsorolót kell készíteni.

# Órai feladat

Egy előző évi gépes ZH-t oldunk meg mindkét szinten, a megfelelt szintesre építjük a kiváló szint felsorolóját. Ez megtalálható [itt](https://github.com/kovacs-levent/ELTEProg/blob/master/06%20-%20Egyedi%20felsorolok/1.gzh_2018_%C5%91sz.pdf).
