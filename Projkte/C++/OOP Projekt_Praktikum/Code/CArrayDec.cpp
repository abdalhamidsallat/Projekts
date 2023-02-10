/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 07.05.2019
 *      Author: Abd Alhamid
 */

#include "CArrayDec.hpp"
#include "CEntry.hpp"
#include "CArray.hpp"
#include <string>
#include <vector>

CArrayDec::CArrayDec() :N(256) {
	// TODO Auto-generated constructor stub

	for(int i=0; i < 256; i++) {
			m_symbolTable[i].setSymbol(intToString(i));
		}
}

CArrayDec::~CArrayDec() {
	// TODO Auto-generated destructor stub
}

string CArrayDec::decode(const vector<unsigned int> &in) {

	// Ausgabe-String
	string SDecode;
	SDecode = "";

	string Sx,First,Last;

	//das erst Zeichen von der neuen Zeichenfolge
	First = "";

	// Last ist die alte Zeichenfolge
	Last = "";

	string i;

	vector<unsigned int>::const_iterator v;
	// ueberpruefe ob der Vector leer ist
if(in.empty()) {
	return "";
}
// falls der Vector nicht leer ist
else {
	// lese die Eintraege von dem Vector Schritt fue Schritt durch
    for(v=in.begin(); v != in.end(); v++){

    	// ueberpruefe ob die einraege kleiner als die Groesse von dem Dictionary
     if(*v < N) {

			i = m_symbolTable[*v].getSymbol();
            First = i[0];

            Sx = Last + First;

			// die alte Ausgabe plus den neuen Eintrag
			SDecode = SDecode + i;

			if(searchInTable(Sx) == (-1)) {      // Sx wurde in der Tabelle nicht gefunden

				// Sx zu dem Dictionary einfuegen
			m_symbolTable[N].setSymbol(Sx);
			// Der Dictionary wird vergroessert
			N++;
			}

			Last = i;

     }

     else {        // if(*v >= N)
    	    // die alte Ausgabe plus das letzte Element und das erste Zeichen von der neuen Zeichenfolge
			SDecode = SDecode + Last + First;

			// Last + First zu dem Dictionary einfuegen
			m_symbolTable[N].setSymbol(Last + First);
			N++;

			Last = Last + First;
		   } //else

} // for Schleife

	return SDecode;
}
}

int CArrayDec::searchInTable(const string& str){

   for(unsigned int i=0; i < N; i++) {

		if(str == m_symbolTable[i].getSymbol()) {
			return i;
		}
	}
   return -1;
}

























