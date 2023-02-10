/*!\file CTrieDec.cpp
 * \brief
 *
 *  Created on: 13.06.2019
 *      Author: Abd Alhamid Sallat
 */

#include "CTrieDec.hpp"
#include "CKnot.hpp"
#include "CEntry.hpp"
#include <iostream>
#include "CArray.hpp"
#include "CDec.hpp"
#include "CDoubleHashing.hpp"
#include "CForwardCounter.hpp"
#include "CLZW.hpp"
#include <string>

CTrieDec::CTrieDec() {
	// TODO Auto-generated constructor stub
	for(unsigned int i = 0; i < 256; i++) {

		// alle Wurzrlelemente werden mit (-1) initialisiert
		m_symbolTable[i].setParent(-1);
		m_symbolTable[i].setSymbol(intToString(i));

		N.push_back(i);
	}

}

CTrieDec::~CTrieDec() {
	// TODO Auto-generated destructor stub
}

string CTrieDec::decode(const vector<unsigned int> &in) {

string SDecode;

int I , J , II;

CDoubleHashing& Hash = CDoubleHashing::getInstance();
CForwardCounter attemptCounter;

unsigned int hashValue;
unsigned int Hi;

vector<unsigned int>:: const_iterator v;
v = in.begin();

if(in.empty()) {
	return "";
}
else {
	I = *v;
    SDecode = intToString(*v);
    II = I;

for(v = in.begin() + 1; v != in.end(); v++) {

	if(searchInN(*v) == 1) {

//        J = charToInt(m_symbolTable[*v].getSymbol()[0]);
		int a = *v;
		while(m_symbolTable[a].getParent() != -1) {
			a = m_symbolTable[a].getParent();
		}

		J = charToInt(m_symbolTable[a].getSymbol()[0]);

        II = *v;
		// die alte Ausgabe plus den neuen Eintrag
		SDecode = SDecode + deriveFromTable(*v);

		hashValue = Hash.hash(I , J , LZW_DICT_SIZE , 0);
		Hi = hashValue;

		if((m_symbolTable[Hi].getParent() != I) || (charToInt(m_symbolTable[Hi].getSymbol()[0]) != J ) ) {

		for(int j=1; j < LZW_DICT_SIZE; j++) {

			if( (I == m_symbolTable[Hi].getParent()) && (J == charToInt(m_symbolTable[Hi].getSymbol()[0])) ) {

//                j = LZW_DICT_SIZE;

                // der Knoten ist schon vorhanden
                I = *v;
                continue;
			}

			if((m_symbolTable[Hi].getParent() == -2)) {

				m_symbolTable[Hi].setSymbol(intToString(J));
				m_symbolTable[Hi].setParent(I);

//				std::cout << Hi << std::endl;
				j = LZW_DICT_SIZE;
				N.push_back(Hi);
//				I = Hi;

			}

			Hi = Hash.hash(I , J , LZW_DICT_SIZE , j);
			attemptCounter.count();
		} // for Schleife

        I = *v;

	   }// if Statement SECOND
		else {
			I = *v;
			continue;
	   } // else

	} // if Statement FIRST

	if(searchInN(*v) == 0) { // if(*v nicht vorhanden in der Tabelle)

		int a = II;
		while(m_symbolTable[a].getParent() != -1) {
			a = m_symbolTable[a].getParent();
		}

		J = charToInt(m_symbolTable[a].getSymbol()[0]);

		m_symbolTable[*v].setSymbol(intToString(J));
		m_symbolTable[*v].setParent(II);

		N.push_back(*v);
		SDecode = SDecode + deriveFromTable(*v);

		II = *v;
		I = *v;

	} // else

} // for Schleife
     return SDecode;

} // else (not empty)

} // decode funktion

int CTrieDec::searchInN(unsigned int indexIn) {

	vector<unsigned int>::const_iterator i;

	for(i = N.begin(); i != N.end(); i++) {
       if(indexIn == *i) {
    	   return 1;
       }
	}
	return 0;
}

string CTrieDec::deriveFromTable(unsigned int position) {

	string temp = "";

if(m_symbolTable[position].getParent() == -1) {

	temp = m_symbolTable[position].getSymbol();
	return temp;
}
else {

	temp = m_symbolTable[position].getSymbol();
	return deriveFromTable(m_symbolTable[position].getParent()) + temp;

}

}















