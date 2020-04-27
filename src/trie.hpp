// Copyright srcmake.com 2020.
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
		bool PrefixExists(const std::string&);
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
	// Create the root of the tree.
	root = new Node();
	}
///////////////////////////////////////


///////////////////////////////////////
Trie::~Trie()
	{
	// TODO: Delete all nodes.
	}
///////////////////////////////////////

///////////////////////////////////////
void Trie::Insert(const std::string& word)
	{
	// Starting from the root, traverse/create nodes for each char in the string.
	Node* currNode = root;
	for(int i = 0; i < word.length(); i++)
		{
		char c = word[i];

		// Check if this char has a node created for it yet.
		std::unordered_map<char, Node*>::const_iterator it = currNode->nextNodesMap.find(c);
		
		// The node doesn't exist so create it.
		Node* nextNode;
		if(it == currNode->nextNodesMap.end())
			{
			nextNode = new Node(c);
			currNode->nextNodesMap[c] = nextNode;
			}
		// The node does exist so make "node" point to it.
		else
			{
			nextNode = currNode->nextNodesMap[c];
			}
	
		// Update currNode.
		currNode = nextNode;

		// If this is the last character in the word, mark the node as the end of the word.
		if(i == word.length() - 1)
			{
			currNode->isEndOfWord = true;
			}
		}
	}
///////////////////////////////////////


///////////////////////////////////////
bool Trie::Contains(const std::string& word)
	{
	// Starting from the root, traverse/create nodes for each char in the string.
	Node* currNode = root;
	for(int i = 0; i < word.length(); i++)
		{
		char c = word[i];

		// Check if this char has a node created for it yet.
		std::unordered_map<char, Node*>::const_iterator it = currNode->nextNodesMap.find(c);
		
		// The node doesn't exist so this word wasn't inserted.
		Node* nextNode;
		if(it == currNode->nextNodesMap.end())
			{
			return false;
			}
		// The node does exist so make "node" point to it.
		else
			{
			nextNode = currNode->nextNodesMap[c];
			}
	
		// Update currNode.
		currNode = nextNode;

		// If this is the last character in the word, check if it's marked as the return of a word.
		if(i == word.length() - 1)
			{
			return currNode->isEndOfWord;
			}
		}
	
	return false;
	}
///////////////////////////////////////


///////////////////////////////////////
bool Trie::PrefixExists(const std::string& prefix)
	{
	// Starting from the root, traverse/create nodes for each char in the string.
	Node* currNode = root;
	for(int i = 0; i < prefix.length(); i++)
		{
		char c = prefix[i];

		// Check if this char has a node created for it yet.
		std::unordered_map<char, Node*>::const_iterator it = currNode->nextNodesMap.find(c);
		
		// The node doesn't exist so this prefix wasn't inserted.
		Node* nextNode;
		if(it == currNode->nextNodesMap.end())
			{
			return false;
			}
		// The node does exist so make "node" point to it.
		else
			{
			nextNode = currNode->nextNodesMap[c];
			}
	
		// Update currNode.
		currNode = nextNode;

		// If this is the last character in the prefix, then this prefix did exist.
		if(i == prefix.length() - 1)
			{
			return true;
			}
		}
	
	return false;
	}
///////////////////////////////////////