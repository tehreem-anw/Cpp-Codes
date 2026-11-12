#include<iostream>
using namespace std;

class Node{
    public:
    int ;
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

    void insert(int key){
        root = recursiveInsert(root, key);
    }

    Node* search(int key){
        return recursiveSearch(root, key);
    }

    void deleteNode(int key){
        root = deleteNodeHelper(root, key);
    }

    Node* findMin(){
        if(root == NULL) return NULL;
        Node* curr = root;
        while(curr->left != NULL){
            curr = curr->left;
        }
        return curr;
    }

    Node* findMax(){
        if(root == NULL) return NULL;
        Node* curr = root;
        while(curr->right != NULL){
            curr = curr->right;
        }
        return curr;
    }

    int height(){
        return calculateHeight(root);
    }

    Node* inorderSuccessor(int key){
        Node* target = search(key);
        if(target == NULL) return NULL;

        if(target->right != NULL){
            Node* curr = target->right;
            while(curr->left != NULL){
                curr = curr->left;
            }
            return curr;
        }

        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != target){
            if(target->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }

    Node* recursiveInsert(Node* r, int key){
        if(r == NULL){
            return new Node(key);
        }
        if(key < r->data){
            r->left = recursiveInsert(r->left, key);
        }
        else if(key > r->data){
            r->right = recursiveInsert(r->right, key);
        }
        else {
            cout << "Duplicates not allowed." << endl;
        }
        return r;
    }

    Node* recursiveSearch(Node* r, int key){
        if(r == NULL || r->data == key){
            return r;
        }
        if(key < r->data){
            return recursiveSearch(r->left, key);
        }
        return recursiveSearch(r->right, key);
    }

    int calculateHeight(Node* r){
        if(r == NULL){
            return -1;
        }
        int l = calculateHeight(r->left);
        int rt = calculateHeight(r->right);
        return 1 + (l > rt ? l : rt);
    }

    Node* deleteNodeHelper(Node* r, int v){
        if(r == NULL) return NULL;
        if(v < r->data){
            r->left = deleteNodeHelper(r->left, v);
        }
        else if(v > r->data){
            r->right = deleteNodeHelper(r->right, v);
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
            Node* curr = r->right;
            while(curr->left != NULL){
                curr = curr->left;
            }
            r->data = curr->data;
            r->right = deleteNodeHelper(r->right, curr->data);
        }
        return r;
    }
};

int main() {
    Tree bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(40);
    bst.insert(50);
    bst.insert(25);

    cout << "Min value: " << bst.findMin()->data << endl;
    cout << "Max value: " << bst.findMax()->data << endl;
    cout << "Height of tree: " << bst.height() << endl;

    Node* succ = bst.inorderSuccessor(25);
    cout << "Inorder successor of 25: " << succ->data << endl;

    bst.deleteNode(20);
    cout << "20 deleted." << endl;

    return 0;
}
