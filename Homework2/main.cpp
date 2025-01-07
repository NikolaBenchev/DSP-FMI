#include<fstream>
#include<iostream>

struct Node {
	bool isFinal;
	Node* children[26];
};

class Trie {
	public:
		void addWord(std::string word) {
			addWordHelper(this->root, word);
		}
	private:
		Node* root;
		void addWordHelper(Node* root, std::string word) {
			Node* curr = root;
			for(char c : word) {
				if(curr->children[c - 'a'] == nullptr) {
					Node* newNode = new Node();	
					curr->children[c - 'a'] = newNode;	
				}
				curr = curr->children[c - 'a'];
			}
			curr->isFinal = true;
		}
};

int main() {
	std::string fileName;
	std::cin >> fileName;
	
	std::ifstream f(fileName + ".txt");

	if(!f.is_open()) {
		std::cout << "file not found" << std::endl;
		return 1;
	}

	std::string s;

	while(getline(f, s)) {
			
		std::cout << s << std::endl;
	}
	f.close();	
	return 0;
}
