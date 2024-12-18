#include<vector>

class BST {
	public:
		BST();
		BST(const std::vector<int> values);
		~BST();
		BST(const BST* other);
		BST& operator=(const BST* other);
		//? Move?

		void print() const;
		void insert(const std::vector<int> values);
		void insert(const int value);
		void remove(const int value);
		std::vector<int> getVectorOfValues() const;	
		void rebalance();
		struct Node {
			int value;
			Node* left;
			Node* right;
		};


	private:
		Node* root;
		void printHelper(const Node* curr) const;
		void insertHelper(const int value, Node* curr);
		void removeHelper(const int value, Node* &curr);
		Node* extractMinNode(Node* &curr);
};
