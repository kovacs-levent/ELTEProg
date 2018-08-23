// Készítette: Nagy Gergely
// Dátum: 2018.03.07.
#include "matrix.h"
#include <iostream>

//A felsorolók műveleteinek megvalósítása
void SorfolytonosEnor::next(){
	++_akt.second;
	if(_akt.second >= _meret.second){
		++_akt.first;
		_akt.second = 0;
	}
}

void OszlopfolytonosEnor::next(){
	++_akt.first;
	if(_akt.first >= _meret.first){
		++_akt.second;
		_akt.first = 0;
	}
}

void CsigaEnor::first(){
	_akt = std::make_pair(0,0);
	_dir = Jobbra;
	_num = 0;
	for(int i = 0; i<4; ++i){
		_foglalt[i] = 0;
	}
	++_foglalt[Fel];
}


//Csigavonalú felsoroló next() művelete
//Működés elve:
// Mindig tároljuk, hogy milyen irányba kell lépni, és hogy melyik irányba hány
// sort/oszlopot jártunk már be. Ez alapján megadható, hogy mikor kell fordulni a
// felsorolás irányának.
void CsigaEnor::next(){
	++_num;
	switch(_dir){
		case Fel:{
			if(_akt.first - _foglalt[Fel] <= 0){
				++_akt.second;
				_dir = Jobbra;
				++_foglalt[Fel];
			}
			else{
				--_akt.first;
			}
			break;
		}
		case Le:{
			if(_akt.first + _foglalt[Le] >= _meret.first - 1){
				--_akt.second;
				_dir = Balra;
				++_foglalt[Le];
			}
			else{
				++_akt.first;
			}
			break;
		}
		case Jobbra:{
			if(_akt.second + _foglalt[Jobbra] >= _meret.second - 1){
				++_akt.first;
				_dir = Le;
				++_foglalt[Jobbra];
			}
			else{
				++_akt.second;
			}
			break;
		}
		case Balra:{
			if(_akt.second - _foglalt[Balra] <= 0){
				--_akt.first;
				_dir = Fel;
				++_foglalt[Balra];
			}
			else{
				--_akt.second;
			}
			break;
		}
	}
}

//Mátrix beolvasása, elvárt formátum:
// sorszám oszlopszám
// mátrix elemei
// Pl.:
// 3 4
// 1 2 3 4
// 9 8 7 6
// 0 1 0 1
std::istream& operator>>(std::istream& s,Matrix& m){
	s >> m._sor >> m._oszlop;
	m._v.resize(m._sor,std::vector<int>(m._oszlop));
	for(int i = 0; i<m._sor; ++i){
		for(int j = 0; j<m._oszlop; ++j){
			s >> m._v[i][j];
		}
	}
	return s;
}

//Mátrix kiírása, a beolvasással megegyező formátumban írja ki a mátrixot
std::ostream& operator<<(std::ostream& s,const Matrix& m){
	s << m._sor << " " << m._oszlop << std::endl;
	for(int i = 0; i<m._sor; ++i){
		for(int j = 0; j<m._oszlop; ++j){
			s << m._v[i][j];
			if(j < m._oszlop - 1) s << " ";
		}
		s << std::endl;
	}
	return s;
}