#include<iostream>
using namespace std;

#define SPACE 10

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Tree{
    public:
    Node* root;
    Tree(){
        root = NULL;
    }
    bool isEmpty(){
        return (root == NULL);
    }
    void insertNode(Node* newNode){
        if(isEmpty()){
            root = newNode;
            cout << "Node added as root." << endl;
            return;
        }
        else{
            Node* temp = root;
            while(temp != NULL){
                if(newNode->data == temp->data){
                    cout << "Duplicates not allowed." << endl;
                    return;
                }
                else if((newNode->data < temp->data) && (temp->left == NULL)){
                    temp->left = newNode;
                    cout << "Node added to left." << endl;
                    break;
                }
                else if(newNode->data < temp->data){
                    temp = temp->left;
                }
                else if((newNode->data > temp->data) && (temp->right == NULL)){
                    temp->right = newNode;
                    cout << "Node added to right." << endl;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
    Node* recursiveInsert(Node* r, Node* newNode){
        if(r == NULL){
            r = newNode;
            cout << "Inserted." << endl;
            return r;
        }
        if(newNode->data < r->data){
            r->left = recursiveInsert(r->left, newNode);
        }
        else if(newNode->data > r->data){
            r->right = recursiveInsert(r->right, newNode);
        }
        else{
            cout << "Duplicates not allowed." << endl;
            return r;
        }
        return r;
    }
    void print2D(Node* r, int space){
        if(r == NULL){
            return;
        }
        space += SPACE;
        print2D(r->right, space);
        cout << endl;
        for(int i = SPACE; i < space; i++){
            cout << " ";
        }
        cout << r->data << endl;
        print2D(r->left, space);
    }
    void printPreorder(Node* r){
        if(r == NULL){
            return;
        }
        cout << r->data << " ";
        printPreorder(r->left);
        printPreorder(r->right);
    }
    void printInorder(Node* r){
        if(r == NULL){
            return;
        }
        printInorder(r->left);
        cout << r->data << " ";
        printInorder(r->right);
    }
    void printPostorder(Node* r){
        if(r == NULL){
            return;
        }
        printPostorder(r->left);
        printPostorder(r->right);
        cout << r->data << " ";
    }
    Node* iterativeSearch(int val){
        if(root == NULL){
            return root;
        }
        Node* temp = root;
        while(temp != NULL){
            if(temp->data == val){
                return temp;
            }
            else if(val < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return NULL;
    }
    Node* recursiveSearch(Node* r, int val){
        if(r == NULL || r->data == val){
            return r;
        }
        else if(val < r->data){
            return recursiveSearch(r->left, val);
        }
        else{
            return recursiveSearch(r->right, val);
        }
    }
    int height(Node* root){
        if(root == NULL){
            return -1;
        }
        int l = height(root->left);
        int r= height(root->right);
        return 1 + (l > r ? l : r);
    }
    void printGivenLevel(Node* r, int level){
        if(r == NULL) return;
        else if(level == 0){
            cout << r->data << " ";
        }
        else{
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printLevelOrderBFS(Node* r){
        int h = height(r);
        for(int i = 0; i <= h; i++){
            printGivenLevel(r, i);
        }
    }
    Node* minValNode(Node* r){
        Node* curr = r;
        while(curr->left != NULL){
            curr = curr->left;
        }
        return curr;
    }
    Node* deleteNode(Node* r, int v){
        if(r == NULL) return NULL;
        else if(v < r->data){
            r->left = deleteNode(r->left, v);
        }
        else if(v > r->data){
            r->right = deleteNode(r->right, v);
        }
        else{
            if(r->left == NULL){
                Node* temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right == NULL){
                Node* temp = r->left;
                delete r;
                return temp;
            }
            else{
                Node* temp = minValNode(r->right);
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }
        return r;
    }
};

int main() {
    Tree bst;

    cout << "=== 1. INSERTION TEST ===" << endl;
    bst.root = bst.recursiveInsert(bst.root, new Node(50));
    bst.root = bst.recursiveInsert(bst.root, new Node(30));
    bst.root = bst.recursiveInsert(bst.root, new Node(70));
    bst.root = bst.recursiveInsert(bst.root, new Node(20));
    bst.root = bst.recursiveInsert(bst.root, new Node(40));
    bst.root = bst.recursiveInsert(bst.root, new Node(60));
    bst.root = bst.recursiveInsert(bst.root, new Node(80));

    // Test iterative insert
    bst.insertNode(new Node(25));

    cout << "\n=== 2. 2D TREE VISUALIZATION ===" << endl;
    bst.print2D(bst.root, 0);
    cout << endl;

    cout << "=== 3. TRAVERSAL TESTS ===" << endl;
    cout << "Preorder:   "; bst.printPreorder(bst.root); cout << endl;
    cout << "Inorder:    "; bst.printInorder(bst.root); cout << endl;
    cout << "Postorder:  "; bst.printPostorder(bst.root); cout << endl;
    cout << "Level Order: "; bst.printLevelOrderBFS(bst.root);

    cout << "\n=== 4. HEIGHT TEST ===" << endl;
    cout << "Height of tree: " << bst.height(bst.root) << endl;

    cout << "\n=== 5. SEARCH TESTS ===" << endl;
    Node* res1 = bst.iterativeSearch(40);
    cout << "Iterative search for 40: " << (res1 != NULL ? "Found" : "Not Found") << endl;

    Node* res2 = bst.recursiveSearch(bst.root, 99);
    cout << "Recursive search for 99: " << (res2 != NULL ? "Found" : "Not Found") << endl;

    cout << "\n=== 6. DELETION TEST ===" << endl;
    cout << "Deleting node 30 (has two children)..." << endl;
    bst.root = bst.deleteNode(bst.root, 30);

    cout << "Inorder after deleting 30: ";
    bst.printInorder(bst.root);
    cout << endl;

    cout << "\nFinal 2D Tree Structure:\n";
    bst.print2D(bst.root, 0);

    return 0;
}
