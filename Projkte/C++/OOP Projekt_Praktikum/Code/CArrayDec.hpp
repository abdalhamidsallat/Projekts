/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 07.05.2019
 *      Author: Abd Alhamid
 */
#include "CDec.hpp"
#include "CEntry.hpp"
#include "CArray.hpp"

#pragma once

/*!
 *
 */
class CArrayDec : public CDec {
public:
	CArrayDec();
    ~CArrayDec();

    string decode(const vector<unsigned int> &in);
    int searchInTable(const string& str);

private:
    // Membervariable mit Datentyp(CEntry) und Gr��e (LZW_DICT_SIZE)
    CArray<CEntry,LZW_DICT_SIZE> m_symbolTable;
    unsigned int N;
};


