/*!\file CTrieEnc.hpp
 * \brief
 *
 *  Created on: 09.06.2019
 *      Author: Abd Alhamid Sallat
 */

#include "CEnc.hpp"
#include "CKnot.hpp"
#include "CDoubleHashing.hpp"
#include "CArray.hpp"
#include <string>
#include <vector>

#pragma once

/*!
 *
 */
class CTrieEnc  : public CEnc {
public:
	CTrieEnc();
    ~CTrieEnc();

    vector<unsigned int> encode(const string &);

private:
    // Membervariable mit Datentyp(CKnot) und Groee (LZW_DICT_SIZE)
    CArray<CKnot, LZW_DICT_SIZE> m_symbolTable;
};
