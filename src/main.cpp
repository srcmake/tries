// Copyright srcmake.com 2020.
#include <iostream>
#include "trie.hpp"
using namespace std;
  
int main()  
	{
	cout << "Program started.\n";

	Trie trie;
	trie.Insert("apple");
	trie.Insert("banana");
	trie.Insert("apricot");
	
	cout << "Program ended.\n";
	return 0;
	}