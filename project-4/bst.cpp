#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>

template <typename T>
struct BSTNode {
    T key;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
    BSTNode* parent = nullptr;

    BSTNode(const T& k) : key(k) {}
};

template <typename T>
class BST {
public:
    using key_t = T;
    using Node = BSTNode<T>;

    BST() : root(nullptr) {}
    ~BST() { Clear(); }

    void Insert(const key_t k) {
        Node* z = new Node(k);
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;
            if (k == x->key) {
                delete z;
                return;
            } 
            else if (k < x->key) {
                x = x->left;
            } 
            else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            root = z;
        } 
        else if (k < y->key) {
            y->left = z;
        } 
        else {
            y->right = z;
        }
    }

    void Delete(const key_t k) {
        Node* z = Search(k);
        if (!z) return;

        if (!z->left) {
            Transplant(z, z->right);
        } 
        else if (!z->right) {
            Transplant(z, z->left);
        } 
        else {
            Node* y = Min(z->right);
            if (y->parent != z) {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        delete z;
    }

    Node* Search(const key_t k) const {
        Node* x = root;
        while (x != nullptr && k != x->key) {
            if (k < x->key) x = x->left;
            else x = x->right;
        }
        return x;
    }

    void Clear() {
        Clear(root);
        root = nullptr;
    }

    Node* Min() const {
        return Min(root);
    }

    Node* Max() const {
        return Max(root);
    }

    Node* Predecessor(const key_t k) const {
        Node* x = Search(k);
        if (!x) return nullptr;

        if (x->left) {
            return Max(x->left);
        }
        Node* y = x->parent;
        while (y && x == y->left) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    Node* Successor(const key_t k) const {
        Node* x = Search(k);
        if (!x) return nullptr;

        if (x->right) {
            return Min(x->right);
        }
        Node* y = x->parent;
        while (y && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

	void InOrderPrint(std::ostream& out) const {
		InOrderPrint(root, out);
		out << std::endl;
	}

    void PrintStructure(std::ostream& out) const {
		PrintStructure(root, 0, out);
	}

private:
    Node* root;

    void Clear(Node* node) {
        if (node) {
            Clear(node->left);
            Clear(node->right);
            delete node;
        }
    }

    Node* Min(Node* node) const {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    Node* Max(Node* node) const {
        if (!node) return nullptr;
        while (node->right) node = node->right;
        return node;
    }

    void Transplant(Node* u, Node* v) {
        if (!u->parent) {
            root = v;
        } 
        else if (u == u->parent->left) {
            u->parent->left = v;
        } 
        else {
            u->parent->right = v;
        }
        if (v) v->parent = u->parent;
    }

	void InOrderPrint(Node* node, std::ostream& out) const {
		if (!node) return;
		InOrderPrint(node->left, out);
		out << node->key << " ";
		InOrderPrint(node->right, out);
	}

	void PrintStructure(Node* node, int indent, std::ostream& out) const {
		if (node != nullptr) {
			if (node->right) {
				PrintStructure(node->right, indent + 4, out);
			}
			if (indent) {
				out << std::string(indent, ' ');
			}
			if (node->right) out << " /\n" << std::string(indent, ' ');
			out << node->key << "\n";
			if (node->left) {
				out << std::string(indent, ' ') << " \\\n";
				PrintStructure(node->left, indent + 4, out);
			}
		}
	}

};

void RunTest(int test_id) {
	std::string num = (test_id < 10 ? "0" : "") + std::to_string(test_id);
    std::string input_file = "sets/set_" + num + ".txt";
    std::string output_file = "outputs/set_" + num + "_output.txt";

    std::ifstream in(input_file);
    std::ofstream out(output_file);

    if (!in) {
        std::cerr << "Input file " << input_file << " not found.\n";
        return;
    }

    BST<int> tree;
    int key;
    std::vector<int> inserted;

    out << "=== TEST " << std::setw(2) << std::setfill('0') << test_id << " ===\n";
    out << "Inserting elements:\n";

    while (in >> key) {
        tree.Insert(key);
        inserted.push_back(key);
        out << key << " ";
    }

    out << "\n\nIn-order traversal:\n";
    tree.InOrderPrint(out);

    out << "\nTree structure:\n";
    tree.PrintStructure(out);

    out << "\nSearch results:\n";
    for (int i = 0; i < std::min(3, (int)inserted.size()); ++i) {
        auto node = tree.Search(inserted[i]);
        out << "Search(" << inserted[i] << "): " << (node ? "Found" : "Not found") << "\n";
    }

    auto min = tree.Min();
    if (min) out << "\nMinimum: " << min->key << "\n";

    auto max = tree.Max();
    if (max) out << "Maximum: " << max->key << "\n";

    if (!inserted.empty()) {
        int middle = inserted[inserted.size() / 2];
        auto pred = tree.Predecessor(middle);
        auto succ = tree.Successor(middle);
        out << "\nMiddle value: " << middle << "\n";
        out << "Predecessor: " << (pred ? std::to_string(pred->key) : "None") << "\n";
        out << "Successor: " << (succ ? std::to_string(succ->key) : "None") << "\n";
    }
	
    tree.Clear();

    out.close();
    in.close();
}

int main() {
    for (int i = 1; i <= 10; ++i) {
        RunTest(i);
    }

    return 0;
}