/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 18.05.2019
 *      Author: Abd Alhamid
 */
#include "CEntry.hpp"

#ifndef CKNOT_HPP_
#define CKNOT_HPP_

/*!
 *
 */
class CKnot : public CEntry {
public:
	CKnot();
	virtual ~CKnot();
	int getParent() const;
	void setParent(int parent);
private:
	int m_parent;
};

#endif /* CKNOT_HPP_ */

















