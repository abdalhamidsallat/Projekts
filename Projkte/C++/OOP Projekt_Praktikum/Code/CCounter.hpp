/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 07.05.2019
 *      Author: Abd Alhamid
 */

//! \file CCounter.hpp
#pragma once

class CCounter
{
public:

	CCounter();
	virtual ~CCounter();

	int getValue() const;
	void setValue(int value);

	virtual void count();

	bool operator<(const CCounter& other) const;

	bool operator>(const CCounter& other) const;

private:
	int m_value;    //Zaehlerzustand
};







