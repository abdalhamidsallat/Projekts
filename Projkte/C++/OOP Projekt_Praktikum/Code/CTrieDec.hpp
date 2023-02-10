/*!\file CTrieDec.hpp
 * \brief
 *
 *  Created on: 13.06.2019
 *      Author: Abd Alhamid Sallat
 */

#pragma once

#include "CDec.hpp"
#include "CKnot.hpp"
#include "CDoubleHashing.hpp"
#include "CArray.hpp"
#include <string>
#include <vector>

class CTrieDec : public CDec {
public:
	CTrieDec();
	virtual ~CTrieDec();

	string decode(const vector<unsigned int> &in);

private:
    // Membervariable mit Datentyp(CKnot) und Groee (LZW_DICT_SIZE)
    CArray<CKnot, LZW_DICT_SIZE> m_symbolTable;
    vector<unsigned int> N;

    int searchInN(unsigned int);
    string deriveFromTable(unsigned int);
};

/* CTRIEDEC_HPP_ */
