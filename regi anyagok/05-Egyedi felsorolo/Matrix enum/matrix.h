// Készítette: Nagy Gergely
// Dátum: 2018.03.07.
#ifndef MATRIX_H
#define MATRIX_H

#include <utility>
#include <vector>
#include <iostream>

//Mátrix osztály a mátrixok tárolására
//Megvalósítás:
// 		vector<vector<int>>-ben tárolva az elemek
// 		beolvasó és kiíró operátorok
// 		oszlop és sor darabszámát lekérdező függvényeg
// 		() operátor az elemek lekérdezésére (kaphat két int-et, vagy egy párt is)
struct Matrix{
public:
	int operator()(int sor, int oszlop) const{
		return _v[sor][oszlop];
	}
	int operator()(std::pair<int,int> p) const{
		return _v[p.first][p.second];
	}
	int getSor() const {return _sor;}
	int getOszlop() const {return _oszlop;}
	friend std::istream& operator>>(std::istream& s,Matrix& m);
	friend std::ostream& operator<<(std::ostream& s,const Matrix& m);
private:
	std::vector< std::vector<int> > _v;
	int _sor;
	int _oszlop;
};

//Sorfolytonos felsoroló  megvalósítása
class SorfolytonosEnor{
public:
	SorfolytonosEnor(int sor, int oszlop):_meret(sor,oszlop){}

	//Felsoroló műveletek
	void first(){_akt = std::make_pair(0,0);}
	void next();
	std::pair<int,int> current() const {return _akt;}
	bool end() const {return _akt.first >= _meret.first;} //Akkor ér véget a felsorolás, ha a sor index megegyezik a mérettel (0-tól indexelés miatt!)

private:
	std::pair<int,int> _akt;
	std::pair<int,int> _meret;
};

//Oszlopfolytonos felsoroló  megvalósítása
class OszlopfolytonosEnor{
public:
	OszlopfolytonosEnor(int sor, int oszlop):_meret(sor,oszlop){}

	//Felsoroló műveletek
	void first(){_akt = std::make_pair(0,0);}
	void next();
	std::pair<int,int> current() const {return _akt;}
	bool end() const {return _akt.second >= _meret.second;} //Akkor ér véget a felsorolás, ha a sor index megegyezik a mérettel (0-tól indexelés miatt!)

private:
	std::pair<int,int> _akt;
	std::pair<int,int> _meret;
};

//Csak indexet felsoroló  megvalósítása
//A felsoroló 0-tól sor*oszlopszámig sorolja fel az indexeket,
//Ezek a felsoroló használata során alakíthatók vissza a mátrix indexeivé
class MatrixIndexEnor{
public:
	MatrixIndexEnor(int sor, int oszlop):_max(sor*oszlop){}

	//Felsoroló műveletek
	void first(){_akt = 0;}
	void next(){++_akt;}
	int current() const {return _akt;}
	bool end() const {return _akt >= _max;}
private:
	int _max;
	int _akt;
};

//Csigavonalú felsoroló megvalósítása
//A bal felső (0,0) sarokból kívülről befelé,
//óramutatóval megegyezően sorolja fel a mátrix elemeit
class CsigaEnor{
public:
	CsigaEnor(int sor, int oszlop):_meret(sor,oszlop){}

	//Felsoroló műveletek
	void first();
	void next();
	std::pair<int,int> current() const {return _akt;}
	bool end() const {return _num >= _meret.first*_meret.second;}
private:
	enum Direction{Jobbra,Le,Balra,Fel};
	Direction _dir;
	int _foglalt[4];
	std::pair<int,int> _akt;
	std::pair<int,int> _meret;
	int _num;
	
};

#endif