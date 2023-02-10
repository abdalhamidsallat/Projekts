#include <iostream>
#include <vector>
#include <string>
#include "CArrayEnc.hpp"
#include "CArrayDec.hpp"
#include "CTrieEnc.hpp"
#include "CDoubleHashing.hpp"
#include "CTrieDec.hpp"

int main() {

//CArrayEnc* testEnc = new CArrayEnc;
//
//vector<unsigned int> encoded;
//
//encoded = testEnc -> encode("ccccccccccccccccccccc");
//
//vector<unsigned int>::const_iterator i;
//
//for(i = encoded.begin(); i != encoded.end(); i++) {
//
//  std::cout << *i << "\t";
//}
//
//  std::cout << std::endl;
//
//CArrayDec* testDec = new CArrayDec;
//
//string decoded;
//decoded = testDec -> decode (encoded);
//
//
//std::cout << decoded << std::endl;

	CTrieEnc* testTrieEnc = new CTrieEnc;

	vector<unsigned int> encoded;

	encoded = testTrieEnc -> encode("cccccccccc");

	vector<unsigned int>::const_iterator i;

	for(i = encoded.begin(); i != encoded.end(); i++) {

	  std::cout << *i << "\t";
	}

	std::cout << std::endl;

	CTrieDec* testTrieDec = new CTrieDec;

	string decoded;

	decoded = testTrieDec -> decode(encoded);

	std::cout << decoded << std::endl;

  return 0;
}


