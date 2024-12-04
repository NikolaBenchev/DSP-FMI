#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

struct Node {
	int value;
	Node* left;
	Node* right;
};

std::vector<int> treeToVector(
		Node* root, 
		std::vector<int> result, 
		std::queue<Node*> q
		) {
	if(!root)
		return result;
	result.push_back(root->value);
	q.push(root->left);
	q.push(root->right);
	while(!q.empty()) {
		Node* nextNode = q.front();
		q.pop();
		result = treeToVector(nextNode, result, q);
	}
	return result;
}

std::vector<int> treeToVector(Node* root) {
	return treeToVector(root, std::vector<int>{}, std::queue<Node*>{});
}
int getNumberOfChildNodes(Node* root) {
	if(!root)
		return 0;
	return 1 + getNumberOfChildNodes(root->left) + 
		getNumberOfChildNodes(root->right);
}
bool isBalanced(Node* root) {
	int numberOfLeftChildren = getNumberOfChildNodes(root->left),
	numberOfRightChildren = getNumberOfChildNodes(root->right);
	return fabs(numberOfLeftChildren - numberOfRightChildren) <= 1;
}


bool isBinaryTree(Node* root) {
	if(!root)
		return true;
	if(root->left) {
		if(root->value <= root->left->value)
			return false;
	}
	if(root->right) {
		if(root->value >= root->right->value)
			return false;
	}
	return isBinaryTree(root->left) && isBinaryTree(root->right);
}

int main() {
	Node* root = new Node{
		8, 
			new Node{
				3,
				new Node{
					1,
					nullptr,
					nullptr
				},
				new Node{
					6,
					new Node{
						4,
						nullptr,
						nullptr
					},
					new Node{
						7,
						nullptr,
						nullptr
					}
				}
			},
			new Node{
				10,
				nullptr,
				new Node{
					14,
					new Node{
						13,
						nullptr,
						nullptr
					},
					nullptr
				}
			}
	};
	Node* balancedTest = new Node{
		1,
			new Node{
				2,
				nullptr,
				nullptr
			},
			new Node{
				3,
				nullptr,
				new Node{
					4,
					nullptr,
					nullptr
				}
			}
	};

	std::cout << isBinaryTree(root) << std::endl;
	std::cout << isBalanced(root) << std::endl;
	std::cout << isBalanced(balancedTest) << std::endl;
	std::vector<int> v = treeToVector(root);

	for(int a : v) {
		std::cout << a << std::endl;
	}
	return 0;
}
