# Dinamikus tömbök

A rendes tömböt már mindenki ismeri, illetve a C++ vector-át is. A dinamikus tömbök az előbbire hasonlítanak, azzal a kivétellel, hogy a memóriafoglalásuk dinamikusan történik. Ez annyit jelent, hogy a programban meg kell mondanunk, hogy szeretnénk lefoglalni (ekkor az operációs rendszertől kérünk memóriát a heap memóriaterületen) memóriát. Az operációs rendszer eleget tesz ennek a kérésnek és ad nekünk memóriát, amit onnantól mi kezelünk. Ez azért jó mert néhol a rendes memóriafoglalás nem elég jó. Minden egyes függvényhívás után kapunk stack memóriát ahol tárolhatjuk az adatokat. Ez azonban csak addig elérhető, ameddig a függvényünk fut, amit itt létrehozunk annak a függvény után véget ér az élettartama.

A dinamikus memóriakezelés ezt a problémát kívánja megoldani, az adat amit a dinamikus változókban/tömbökben tárolunk annak az élettartama addig tart, amíg mi fel nem szabadítjuk a memóriát. Nagyon kell ügyelni erre tehát, hogy eltakarítsunk magunk után, különben memóriaszivárgás (memory leak) jöhet létre. Ez annyit tesz, hogy már nem elérhető memóriarész a heap-en nem lett felszabadítva.

## Használatuk

A használathoz először le kell foglalnunk a memóriaterületet. Ezt úgy tehetjük meg, hogy deklarálunk egy pointer változót, arra a típusra amit tárolni szeretnénk. A pointerek ugyanolyan változók mint a többi, csak a tartalmuk memóriacímet tárol. Pl. egy int pointert int* p; módon deklarálhatunk. Ennek adjuk majd át a heap-en letárolt adatunk memóriacímét. p = new int; (ekkor egy sima intet foglalunk le), vagy p = new int[5]; módon (ez egy 5 méretű int tömböt foglal nekünk a heap-en).

Ezzel úgy dolgozhatunk nagyjából ahogy eddig is, aztán a végén viszont fel kell szabadítani a memóriát. Ezt a delete p; vagy delete[] p; parancsokkal tehetjük meg. Az első a p által mutatott memóriaterületet törli, a második pedig a p által mutatott tömböt is. Értelemszerűen a cél az, hogy minden new-hoz tartozzon egy delete és minden new[]-hoz tartozzon egy delete[], amit a kódban úgy helyezünk el, hogy a delete csak akkor fusson, amikor már tényleg végeztünk a munkánkkal (általában a destruktorban fut ez le).
