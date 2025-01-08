#include<fstream>
#include<iostream>

struct TrieNode {
	int value; 
	TrieNode* child[26];
	TrieNode() {
		value = -1;
		for(int i = 0; i < 26; i++) {
			child[i] = nullptr;
		}
	}
};

class Trie {
	public:
		Trie() {
			this->root = new TrieNode();
		}
	
		Trie(const Trie& other) = delete;		

		void addWord(std::string word, int value) {
			addWordHelper(this->root, word, value);
		}

		void print() {
			printHelper(this->root, "");
		}
		
		int getValue(std::string word) {
			return getValueHelper(this->root, word, 0);
		}
	private:
		TrieNode* root;
		void addWordHelper(TrieNode* root, std::string word, int value) {
			TrieNode* curr = root;
			for(char c : word) {
				if(curr->child[c - 'a'] == nullptr) {
					TrieNode* newNode = new TrieNode();	
					curr->child[c - 'a'] = newNode;	
				}
				curr = curr->child[c - 'a'];
			}
			curr->value = value;
		}

		void printHelper(TrieNode* curr, std::string currWord) {
			if(curr->value != -1)
				std::cout << currWord << " " << curr->value << std::endl;
			for(int i = 0; i < 26; i++) {
				if(curr->child[i] != nullptr) { 
					char currCharacter = i + 'a';
					printHelper(curr->child[i], currWord + currCharacter);
				}
			}
		}
		int getValueHelper(TrieNode* curr, std::string word, int currLength) {
			if(!curr)
				return -1;
			if(word.length() == currLength)
				return curr->value;

			return getValueHelper(curr->child[word[currLength] - 'a'], word, currLength + 1);	
	}
};

struct HeapNode {
	std::string value;		
};

class Heap{
	public:
		void push() {
		}
		Heap(const int K) {
			
		}
	private:
		HeapNode* root;
};

int main() {
	Trie trie;

	std::string fileName;
	std::cin >> fileName;
	
	std::ifstream dictFile(fileName + ".txt");

	if(!dictFile.is_open()) {
		std::cout << "file not found" << std::endl;
		return 1;
	}

	std::string dictLine;

	while(getline(dictFile, dictLine)) {
		size_t pos = dictLine.find(" ");
		std::string word = dictLine.substr(0, pos);
		int value = stoi(dictLine.substr(pos + 1, dictLine.length()));
		trie.addWord(word, value);
	}

	f.close();
	
//	trie.print();
	
	std::cin >> fileName;

	std::ifstream textFile(filename + ".txt");
	if(!.is_open()) {
		std::cout << "file not found" << std::endl;
		return 1;
	}
	return 0;
}
