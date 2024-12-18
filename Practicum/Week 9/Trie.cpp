#include<iostream>

struct TrieNode {
	TrieNode* children[26];
	bool isFinal = false;
	TrieNode() {
		for(int i = 0; i < 26; i++)
			this->children[i] = nullptr;	
	}
};

void printTrie(TrieNode* currNode, const std::string& currValue) {
	if(currNode == nullptr) return;
	if(currNode->isFinal) std::cout << currValue << std::endl;

	for(int i = 0; i < 26; i++) {
		if(currNode->children[i]) 
			printTrie(
				currNode->children[i], 
				currValue + (char)('a' + i)
			);
	}
}

void printTrie(TrieNode* start) {
	printTrie(start, "");
} 

void addWord(TrieNode* currNode, const char* word) {
	for(int i = 0; word[i] != '\0'; i++) {
		int currIndex = word[i] - 'a';
		if(!currNode->children[currIndex])
			currNode->children[currIndex] = new TrieNode;

		currNode = currNode->children[currIndex];
	}
	currNode->isFinal = true;
}

bool hasChildren(TreeNode* curr) {
	for(int i = 0; i < 26; i++) {
		if(curr->children[i])
			return true;
	}
	return false;
}

void removeWord(TrieNode* curr, const char* currWord, const char* wordToRemove) {
	if(currWord == wordToRemove) {
		curr->isFinal = false;
		if(!hasChildren(curr))
			delete curr;
		return;
	}

}

void removeWord(TrieNode* start, std::string word) {
	removeWord(start, "", word);
}

void deallocate(TrieNode* curr) {
	if(curr == nullptr) return;
	for(int i = 0; i < 26; i++)
		deallocate(curr->children[i]);

	delete[] curr;
}

int main() {
	TrieNode* start = new TrieNode;
	addWord(start, "asd");
	addWord(start, "add");
	addWord(start, "a");
	addWord(start, "bvcx");
	addWord(start, "asdasdasd");
	addWord(start, "assd");
	addWord(start, "assv");
	printTrie(start);
	
	remove("asd");
	remove("assd");

	deallocate(start);
	return 0;
}
