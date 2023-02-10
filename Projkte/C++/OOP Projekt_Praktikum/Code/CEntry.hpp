/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 15.05.2019
 *      Author: Abd Alhamid
 */

#ifndef CENTRY_HPP_
#define CENTRY_HPP_

#include <string>

using namespace std;

class CEntry {
public:
	CEntry();
	CEntry (string str);

	virtual ~CEntry();

	const string& getSymbol() const;

	void setSymbol(string str);

	static unsigned int getNumber();

private:
	string m_symbol;
	static unsigned int m_number;

};

#endif /* CENTRY_HPP_ */








