// Készítette: Nagy Gergely
// Dátum: 2018.03.07.
// Feladat: Keressük meg egy mátrix első negatív elemét, többféle felsorolóval is!
// 		    Lehetséges felsorolók: sorfolytonos, oszlopfolytonos, csigavonalú, csak egy egészet felsoroló
#include <iostream>
#include "matrix.h"

using namespace std;

//Lineáris keresés, különböző felsorolókkal
//Figyeljük meg, hogy az in.txt-ben és az in2.txt-ben található
//mátrixokra melyik felsorolóval melyik elemet találjuk meg elsőnek!
void LinKerSorFolyt(Matrix& m){
	cout << "Linearis kereses sorfolytonos felsoroloval" << endl;
	SorfolytonosEnor sf(m.getSor(), m.getOszlop());
	bool l = false;
	pair<int,int> elem;
	sf.first();
	while(!l && !sf.end()){
		elem = sf.current();
		l = m(elem) < 0;
		sf.next();
	}
	if(!l){
		cout << "Nincs negativ elem\n\n";
	}
	else{
		cout << "Az elso negativ elem helye: " << elem.first << ". sor " << elem.second << ". oszlop\n\n";
	}
}

void LinKerOszlopFolyt(Matrix& m){
	cout << "Linearis kereses oszlopfolytonos felsoroloval" << endl;
	OszlopfolytonosEnor of(m.getSor(), m.getOszlop());
	bool l = false;
	pair<int,int> elem;
	of.first();
	while(!l && !of.end()){
		elem = of.current();
		l = m(elem) < 0;
		of.next();
	}
	if(!l){
		cout << "Nincs negativ elem\n\n";
	}
	else{
		cout << "Az elso negativ elem helye: " << elem.first << ". sor " << elem.second << ". oszlop\n\n";
	}
}

void LinKerMatrixIndex(Matrix& m){
	cout << "Linearis kereses indexek felsorolojaval" << endl;
	MatrixIndexEnor mi(m.getSor(), m.getOszlop());
	bool l = false;
	int elem;
	mi.first();
	while(!l && !mi.end()){
		elem = mi.current();
		l = m(elem / m.getOszlop(), elem % m.getOszlop()) < 0;
		mi.next();
	}
	if(!l){
		cout << "Nincs negativ elem\n\n";
	}
	else{
		cout << "Az elso negativ elem helye: " << elem / m.getOszlop() << ". sor " << elem % m.getOszlop() << ". oszlop\n\n"; 
	}
}

void LinKerCsiga(Matrix& m){
	cout << "Linearis kereses csigavonalu felsoroloval" << endl;
	CsigaEnor cs(m.getSor(), m.getOszlop());
	bool l = false;
	pair<int,int> elem;
	cs.first();
	while(!l && !cs.end()){
		elem = cs.current();
		l = m(elem) < 0;
		cs.next();
	}
	if(!l){
		cout << "Nincs negativ elem\n\n";
	}
	else{
		cout << "Az elso negativ elem helye: " << elem.first << ". sor " << elem.second << ". oszlop\n\n";
	}
}

int main(){
	Matrix  m;
	cout << "Adj meg egy matrixot (sorok szama, oszlopok szama, majd az elemek felsorolasa):" << endl;
	cin >> m;

	LinKerSorFolyt(m);
	LinKerOszlopFolyt(m);
	LinKerMatrixIndex(m);
	LinKerCsiga(m);

	return 0;
}