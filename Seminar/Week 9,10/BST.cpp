#include "./BST.h"


void BST::print() const {
	printHelper(this->root);
}

void BST::printHelper(const Node* curr) const {

}

void BST::insert(const std::vector<int> values) {
	for(const int& value : values)
		insert(value);
}

void BST::insert(const int value) {
	insertHelper(value, this->root);
}

void BST::insertHelper(const int value, Node* curr) {

}

void BST::remove(const int value) {
	removeHelper(value, this->root);
}

void BST::removeHelper(const int value, Node* &curr) {

}

Node* BST::extractMinNode(Node* curr) {
	return curr;
}

std::vector<int> BST::getVectorOfValues() const {
	return std::vector<int>();
}

void BST::rebalance() {
}
