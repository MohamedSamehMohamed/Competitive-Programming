#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Treap{
	struct Node{
		T value;
		int priority, subSize;
		Node* left;
		Node* right;
		Node(T value, int priority, Node* left, Node* right)
		{
			this->value = value;
			this->priority = priority;
			this->left = left;
			this->right = right;
			subSize = 1; 
		}
	};
	int getRandomValue()
	{
		return rand() % MAX;
	}
	const int MAX = 1e9;
	Node* root;
	Node* nullNode;
	int steps;
	bool isNull(Node* node)
	{
		return node == nullNode; 
	}
	void recalc(Node* root)
	{
		if (isNull(root)) return;
		int subSizes = 0;
		if (root->left != nullNode)
			subSizes += root->left->subSize;
		if (root->right != nullNode)
			subSizes += root->right->subSize; 
		root->subSize = subSizes + 1; 
	}
	void rotateWithLeft(Node* root)
	{
		Node* leftNode = root->left; 
		Node* temp = leftNode->right; 
		leftNode->right = root;
		root->left = temp;
	}
	void rotateWithRight(Node* root)
	{
		Node* rightNode = root->right; 
		Node* temp = rightNode->left; 
		rightNode->left = root;
		root->right = temp;
	}
	void rotate(Node* root)
	{
		return;
		if (!isNull(root->left))
		{
			if (root->left->priority < root->priority)
			{
				rotateWithLeft(root);
			}
		}
		if (!isNull(root->right))
		{
			if (root->right->priority < root->priority)
			{
				rotateWithRight(root);
			}
		}
	}
	Node* insertHelper(Node* root, T value, int priority)
	{
		if(root == nullNode)
		{
			return root = new Node(value, priority, nullNode, nullNode);
		}
		if (value > root->value)
		{
			root->right = insertHelper(root->right, value, priority);
		}else if (value < root->value) 
		{
			root->left = insertHelper(root->left, value, priority);
		}
		rotate(root);
		recalc(root); 
		return root;
	}
	Node* removeHelper(Node* root, T value)
	{
		if (root == nullNode)
			return root;
		if (value == root->value)
		{
			Node* temp = merge(root->left, root->right);
			delete root; 
			return temp; 
		}else if (root->value < value)
		{
			root->right = removeHelper(root->right, value);
		}else 
		{
			root->left = removeHelper(root->left, value); 
		}
		recalc(root);
		return root; 
	}
	void findHelper(Node* root, T value)
	{
		if (root == nullNode)
		{
			steps = -1; 
			return; 
		}
		if (root->value == value)
			return;
		steps++;
		if (root->value < value)
			findHelper(root->right, value);
		else 
			findHelper(root->left, value);
	}
	void removeTree(Node* root)
	{
		if (root == nullptr)
			return; 
		removeTree(root->left);
		removeTree(root->right);
		delete root;
	}
	Node* merge(Node* root1, Node* root2)
	{
		if (root1 == nullNode)
			return root2;
		if (root2 == nullNode)
			return root1; 
		if (root1->priority < root2->priority)
		{
			if (root1->value < root2->value)
			{
				root1->right = merge(root1->right, root2); 
			}else 
			{
				root1->left = merge(root1->left, root2);
			}
			recalc(root1);
			return root1; 
		}else 
		{
			if (root2->value < root1->value)
			{
				root2->right = merge(root2->right, root1);	
			}else 
			{
				root2->left = merge(root2->left, root1);
			}
			recalc(root2);
			return root2; 
		}
	}
	int getSubSize(Node* node)
	{
		return node == nullNode? 0: node->subSize; 
	}
	void inorderHelper(Node* root)
	{
		if (root == nullNode)
				return; 
			inorderHelper(root->left);
			cout << root->value << " ";
			inorderHelper(root->right);
	}
	public:
		Treap()
		{
			nullNode = nullptr;
			root = nullNode;
		}
		Treap(int n)
		{
			nullNode = nullptr;
			root = nullNode; 
			vector<Node*> elements(n);
			for (int i = 0; i < n; i++)
			{
				elements[i] = nullNode;
				elements[i] = insertHelper(elements[i], i + 1, getRandomValue());
			}
			for (int i = 0; i < n; i++)
			{
				root = merge(root, elements[i]);
			}
		}
		~Treap()
		{
			removeTree(root);
		}
		void insert(T value)
		{
			root = insertHelper(root, value, getRandomValue());
		}
		void remove(T value)
		{
			removeHelper(root, value);
		}
		void find(T value)
		{
			steps = 0;
			findHelper(root, value);
			printf("number of steps: %d\n", steps);
		}
		vector<Node*> split(Node* root, int remInLeft)
		{
			if (remInLeft == 0)
			{
				return {nullNode, root};
			}
			vector<Node*> ret; 
			if (getSubSize(root->left) + 1 <= remInLeft)
			{
				ret = split(root->right, remInLeft - getSubSize(root->left) - 1);
				if (!isNull(root->right)) root->right = nullNode;
				ret[0] = merge(root, ret[0]);
			}else 
			{
				ret = split(root->left, remInLeft);
				root->left = nullNode;
				ret[1] = merge(ret[1], root);
			}
			recalc(ret[0]);
			recalc(ret[1]);
			return ret;
		}
		void inorder()
		{
			inorderHelper(root);
		}
		void testSplit(int i)
		{
			inorderHelper(root);
			cout << "\n";
			auto ret = split(root, i);
			for (int j = 0;j < 2; j++)
			{
				cout <<"Tree number : " << j + 1 <<"\n";
				inorderHelper(ret[j]);
				cout <<"\n";
			}
			root = merge(ret[0], ret[1]);
		}
		void bfsOrder()
		{
			queue<Node*> q;
			q.push(root);
			while(!q.empty())
			{
				int sz = q.size();
				while(sz--)
				{
					Node* cur = q.front();
					q.pop();
					cout << cur -> value << " ";
					if (!isNull(cur->left))
						q.push(cur -> left);
					if (!isNull(cur->right))
						q.push(cur -> right);
				}
			}
		}
		void solve(int a, int b, int n)
		{
			// [a, b-1], [b, n-1]
			auto ret = split(root, a);
			auto ret1 = split(ret[1], b - a);
			auto ret2 = split(ret1[1], min(n - b + 1, b - a));
			/*
			ret[0] | ret1[0] | ret2[0] | ret2[1]
			
			*/
			root = merge(ret[0], ret2[0]);
			root = merge(root, ret1[0]);
			root = merge(root, ret2[1]);
		}
};
int main()
{
	int n;
	scanf("%d", &n);
	Treap<int> treap(n);
	treap.bfsOrder();
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		if (a < b)
			treap.solve(a, b, n);
	}
	treap.bfsOrder();
}