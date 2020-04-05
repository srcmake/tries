// Copyright srcmake.com 2020.
#include <iostream>
#include <unordered_map>

///////////////////////////////////////
class Trie
	{
	private:
		struct Node;
		Node* root;
		
	public:
		Trie();
		~Trie();
		void Insert(const std::string&);
		bool Contains(const std::string&);
		bool StartsWith(const std::string&);
	};
///////////////////////////////////////


///////////////////////////////////////
struct Trie::Node
	{
	char c;
	bool isEndOfWord;
	std::unordered_map<char, Node*> nextNodesMap;

	Node() 
		{
		isEndOfWord = false;
		}

	Node(const char& newChar)
		{
		c = newChar;
		isEndOfWord = false;
		}
	};
///////////////////////////////////////


///////////////////////////////////////
Trie::Trie()
	{
	std::cout << "Constructor called for trie.\n";
	root = new Node();
	}
///////////////////////////////////////


///////////////////////////////////////
Trie::~Trie()
	{
	std::cout << "Destructor called for trie.\n";
	// TODO: Delete all nodes.
	}
///////////////////////////////////////

///////////////////////////////////////
void Trie::Insert(const std::string& word)
	{
	//std::cout << "Inserting word " << word << std::endl;

	// Starting from the root, traverse/create nodes for each char in the string.
	Node* curr = root;
	for(int i = 0; i < word.length(); i++)
		{
		char c = word[i];

		// Check if this char has a node created for it yet.
		std::unordered_map<char, Node*>::const_iterator it = curr->nextNodesMap.find(c);
		
		// The node doesn't exist so create it.
		Node* node;
		if(it == curr->nextNodesMap.end())
			{
			node = new Node(c);
			curr->nextNodesMap[c] = node;
			}
		// The node does exist so make "node" point to it.
		else
			{
			node = curr->nextNodesMap[c];
			}
	
		// If this is the last character in the word, mark the node as the end of the word.
		if(i == word.length() - 1)
			{
			node->isEndOfWord = true;
			}

		// Update curr.
		curr = node;
		}

	//std::cout << "Finished inserting word " << word << std::endl;
	}
///////////////////////////////////////


///////////////////////////////////////
bool Trie::Contains(const std::string& word)
	{
	// Starting from the root, traverse/create nodes for each char in the string.
	Node* curr = root;
	for(int i = 0; i < word.length(); i++)
		{
		char c = word[i];

		// Check if this char has a node created for it yet.
		std::unordered_map<char, Node*>::const_iterator it = curr->nextNodesMap.find(c);
		
		// The node doesn't exist so this word wassn't inserted.
		Node* node;
		if(it == curr->nextNodesMap.end())
			{
			return false;
			}
		// The node does exist so make "node" point to it.
		else
			{
			node = curr->nextNodesMap[c];
			}
	
		// If this is the last character in the word, check if it's marked as the return of a word.
		if(i == word.length() - 1)
			{
			return node->isEndOfWord;
			}

		// Update curr.
		curr = node;
		}
	
	return false;
	}
///////////////////////////////////////


///////////////////////////////////////
bool Trie::StartsWith(const std::string&)
	{
	return false;
	}
///////////////////////////////////////