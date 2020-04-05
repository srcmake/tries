#include <iostream>
#include <unordered_map>

///////////////////////////////////////
class Trie
	{
	private:
		struct Node;
		Node* head;
		
	public:
		Trie();
		~Trie();
		void Insert(const std::string&);
		bool Search(const std::string&);
		bool StartsWith(const std::string&);
	};
///////////////////////////////////////


///////////////////////////////////////
struct Trie::Node
	{
	char c;
	bool isEndOfWord;
	std::unordered_map<char, Node*> nextNodes;

	Node() { }

	Node(const char& newChar)
		{
		c = newChar;
		}
	};
///////////////////////////////////////


///////////////////////////////////////
Trie::Trie()
	{
	std::cout << "Constructor called for trie.\n";
	head = new Node();
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
void Trie::Insert(const std::string&)
	{
	
	}
///////////////////////////////////////


///////////////////////////////////////
bool Trie::Search(const std::string&)
	{
	return false;
	}
///////////////////////////////////////


///////////////////////////////////////
bool Trie::StartsWith(const std::string&)
	{
	return false;
	}
///////////////////////////////////////