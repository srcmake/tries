// Copyright srcmake.com 2020.
#include <iostream>
#include <assert.h>
#include "trie.hpp"
using namespace std;
  
int main()  
	{
	cout << "Program started.\n";

	Trie trie;
	
	trie.Insert("apple");
	trie.Insert("banana");
	trie.Insert("apricot");

	assert(trie.Contains("apple") == true);
	assert(trie.Contains("app") == false);
	assert(trie.Contains("apricot") == true);

	assert(trie.Contains("bananas") == false);
	assert(trie.Contains("banana") == true);
	
	cout << "Program ended.\n";
	return 0;
	}