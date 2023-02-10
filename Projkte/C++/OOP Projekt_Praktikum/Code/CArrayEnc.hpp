#include "CEnc.hpp"
#include "CEntry.hpp"
#include "CArray.hpp"

#pragma once

/*!
 *
 */
class CArrayEnc  : public CEnc {
public:
	CArrayEnc();
    ~CArrayEnc();

    vector<unsigned int> encode(const string &);
    int searchInTable(const string& str);

private:
    // Membervariable mit Datentyp(CEntry) und Größe (LZW_DICT_SIZE)
    CArray<CEntry,LZW_DICT_SIZE> m_symbolTable;
    unsigned int N;
};
