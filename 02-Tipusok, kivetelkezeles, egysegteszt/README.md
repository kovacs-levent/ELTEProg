# Egységtesztelés

A típusok már tudjuk miért jók, de nagyon oda kell figyelni arra, hogy függvények helyesen működjenek, különben felborulhat a működés. Mivel az objektumaink összetettek, melyeknek elemeit több függvény módosíthatja egyszerre, ezért a nem várt működési problémák és mellékhatások bugokhoz vezethetnek.

Éppen ezért fontos a megfelelően kimerítő tesztelés. Nyilvánvalóan nem tudunk minden esetet lefedni általában, hiszen abból végtelen féle lehet. Ha azonban átgondoljuk milyen lehetőségek vannak a program futtatása során, mi a tipikus vagy szélsőséges eset, akkor ezekre teszteket készítve láthatjuk, hogy a programunk megbízható e.

Az egységtesztek (Unit test) pontosan erre jók. Egy egységteszt azt vizsgálja meg, hogy egy program egy adott bemenetre helyesen működik-e. Ha nem, akkor a teszten megbukott a program és nyilvánvalóan ki kell javítani. A félévben a C++-hoz keszített Catch keretrendszert fogjuk használni a tesztek készítéséhez, melyet a https://github.com/catchorg/Catch2 repon értek el.
