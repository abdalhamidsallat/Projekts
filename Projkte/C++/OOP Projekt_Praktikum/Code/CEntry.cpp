/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 07.05.2019
 *      Author: Abd Alhamid
 */

#include <iostream>
#include <string>
#include "CEntry.hpp"

unsigned int CEntry::m_number = 0;

CEntry::CEntry() : m_symbol(""){
	// TODO Auto-generated constructor stub
   m_number++;
}

CEntry::CEntry(string str) : m_symbol(str){
	// TODO Auto-generated constructor stub
   m_number++;
}

CEntry::~CEntry() {
	// TODO Auto-generated destructor stub
	m_number--;
}

string const& CEntry::getSymbol() const{

    // const string = string const
	return m_symbol;
}

void CEntry::setSymbol(string str){

	m_symbol = str;
}

unsigned int CEntry::getNumber () {

	return m_number;
}













