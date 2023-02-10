/*!\file CTrieEnc.cpp
 * \brief
 *
 *  Created on: 09.06.2019
 *      Author: Abd Alhamid Sallat
 */

#include "CTrieEnc.hpp"
#include "CKnot.hpp"
#include "CEntry.hpp"
#include <iostream>
#include "CArray.hpp"
#include "CEnc.hpp"
#include "CDoubleHashing.hpp"
#include "CForwardCounter.hpp"
#include "CLZW.hpp"

CTrieEnc::CTrieEnc() {
	// TODO Auto-generated constructor stub
	for(unsigned int i = 0; i < 256; i++) {

		// alle Wurzrlelemente werden mit (-1) initialisiert
		m_symbolTable[i].setParent(-1);
		m_symbolTable[i].setSymbol(intToString(i));
	}

}

CTrieEnc::~CTrieEnc() {
	// TODO Auto-generated destructor stub
}

vector<unsigned int> CTrieEnc::encode(const string & str) {

	int I,J;
	string::const_iterator i;
	vector<unsigned int> indexSend;
	CForwardCounter attemptCounter;

    CDoubleHashing& hash = CDoubleHashing::getInstance();

    unsigned int hashValue;
    unsigned int Hi;

	i = str.begin();

	I = charToInt(*i);

if(!str.empty()) {

		for(i = str.begin() + 1; i != str.end(); i++) {

			J = charToInt(*i);

			hashValue = hash.hash(I , J , LZW_DICT_SIZE , 0);
			Hi = hashValue;

			if((m_symbolTable[Hi].getParent() != I) || (charToInt(m_symbolTable[Hi].getSymbol()[0]) != J ) ) {

				int j = 1;
			do {

				if( (I == m_symbolTable[Hi].getParent()) && (J == charToInt(m_symbolTable[Hi].getSymbol()[0])) ) {

                    j = 0;
                    // der Knoten ist schon vorhanden
                    I = Hi;
                    continue;
				}

				if((m_symbolTable[Hi].getParent() == -2)) {

					m_symbolTable[Hi].setSymbol(intToString(J));
					m_symbolTable[Hi].setParent(I);

					j = 0;
					indexSend.push_back(I);

					I = J;

				}

				attemptCounter.count();
				Hi = hash.hash(I , J ,LZW_DICT_SIZE , attemptCounter.getValue());

				if(Hi == hashValue) {

					j = 0;

				}



			}
			while(j == 1); // for Schleife

//			continue;
		} // if Statement

			else {

				I = Hi;
//                continue;
			}
		}

		//Sende das letzte Zeichen
		indexSend.push_back(I);
		return indexSend;
}
}

















