#include<fstream>
#include<iostream>
#include<map>

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

		~Trie() {
			free(this->root);
		}	

		Trie(const Trie& other) = delete;
		Trie &operator=(const Trie& other) = delete;
		

		void addWord(std::string word, const int value) {
			addWordHelper(this->root, word, value);
		}

		void print() const {
			printHelper(this->root, "");
		}
		
		int getValue(std::string word) const {
			return getValueHelper(this->root, word, 0);
		}
	private:
		TrieNode* root;
		
		void free(TrieNode* currNode) {
			if(currNode == nullptr) return;
			for(int i = 0; i < 26; i++) {
				free(currNode->child[i]);
			}
			delete currNode;
		}	

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

		void printHelper(TrieNode* curr, std::string currWord) const {
			if(curr->value != -1)
				std::cout << currWord << " " << curr->value << std::endl;
			for(int i = 0; i < 26; i++) {
				if(curr->child[i] != nullptr) { 
					char currCharacter = i + 'a';
					printHelper(curr->child[i], currWord + currCharacter);
				}
			}
		}
		int getValueHelper(TrieNode* curr, std::string word, int currLength) const {
			if(!curr)
				return -1;
			if(word.length() == currLength)
				return curr->value;

			return getValueHelper(curr->child[word[currLength] - 'a'], word, currLength + 1);	
	}
};

struct HeapNode {
	int value;
	std::string word;
};

class Heap{
	public:
		void push(const std::string word, const int value) {
		}
		Heap(const size_t maxNumberOfNodeChildren) {
			this->maxNumberOfNodeChildren = maxNumberOfNodeChildren;
		}

		size_t getSize() {
			return this->currSize;
		}
	private:
		size_t maxSize;
		size_t currSize;
		size_t maxNumberOfNodeChildren;
		HeapNode* arr;
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

	dictFile.close();
	
//	trie.print();
	
	std::cin >> fileName;

	std::ifstream textFile(fileName + ".txt");
	if(!textFile.is_open()) {
		std::cout << "file not found" << std::endl;
		return 1;
	}
	
	std::map<std::string, int> wordOccurances;	
	std::string word;
	while(textFile >> word) {
		if(wordOccurances[word])
			wordOccurances[word] += 1;
		else
			wordOccurances[word] = 1;
	}

	for(std::map<std::string, int>::iterator it = wordOccurances.begin();
		it != wordOccurances.end(); it++) {
		
	}
	
	return 0;
}
