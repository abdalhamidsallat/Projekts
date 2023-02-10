/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 09.05.2019
 *      Author: Abd Alhamid
 */

#include "CArrayEnc.hpp"
#include "CEntry.hpp"
#include "CArray.hpp"
#include <iostream>
#include <string>
#include <vector>

CArrayEnc::CArrayEnc() : N(256) {
	// TODO Auto-generated constructor stub
	// int to string for Schleife

	for(int i=0; i < 256; i++) {

				m_symbolTable[i].setSymbol(intToString(i));
			}

}

CArrayEnc::~CArrayEnc() {
	// TODO Auto-generated destructor stub
}

vector<unsigned int> CArrayEnc::encode(const string & str) {

	string S, Sx;
	int h = 0;
	int jj = 0;

	vector<unsigned int> indexSend;

	N = 256;

	string::const_iterator i;

	S = "";

	// Wenn das String leer ist, exit Programm
if(!str.empty()) {

	    for(i = str.begin(); i != str.end(); i++) {

		      Sx = S + *i;
		      h = 0;
		      jj = 0;

		      for(unsigned int j=0; j < N; j++) {

		      if(Sx == m_symbolTable[j].getSymbol()){
		    	  h = 1;
		    	  jj=j;
		    	  S = m_symbolTable[jj].getSymbol();
		      }
              }

		      if(h == 0){

		    	  indexSend.push_back(searchInTable(S));
		    	  m_symbolTable[N].setSymbol(Sx);
		    	  N ++;
		    	  S = *i;
		    	  }

	      }

	    indexSend.push_back(searchInTable(S));

	    	  return indexSend;
} // else

}  //die encode funktion

int CArrayEnc::searchInTable(const string& str) {

	for(unsigned int i=0; i < N; i++) {

		if(str == m_symbolTable[i].getSymbol()) {
			return i;
		}

	}
	return -1;
}











