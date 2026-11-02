#include<iostream>
using namespace std;

class CompleteTree{
    static const int max = 100;
    int arr[max];
    int size;

    int parent(int i) const{return (i - 1) / 2;}
    int left(int i) const{return 2 * i + 1;}
    int right(int i) const{return 2 * i + 2;}

    void preorder(int i) const{
        if(i >= size) return;
        cout << arr[i] << " ";
        preorder(left(i));
        preorder(right(i));
    }

    void inorder(int i) const{
        if(i >= size) return;
        inorder(left(i));
        cout << arr[i] << " ";
        inorder(right(i));
    }

    void postorder(int i) const{
        if(i >= size) return;
        postorder(left(i));
        postorder(right(i));
        cout << arr[i] << " ";
    }

    public:
    CompleteTree(){
        size = 0;
    }

    bool isEmpty() const{return size == 0;}
    bool isFull() const{return size == max;}
    int getSize() const{return size;}

    bool insert(int val){
        if(isFull()){
            cout << "Tree is full." << endl;
            return false;
        }
        arr[size++] = val;
        return true;
    }

    int search(int val) const{
        for(int i = 0; i < size; i++){
            if(arr[i] == val){
                return i;
            }
        }
        return -1;
    }

    bool remove(int val){
        int idx = search(val);
        if(idx == -1){
            cout << "Value not found." << endl;
            return false;
        }
        arr[idx] = arr[size - 1];
        size--;
        return true;
    }

    int height() const{
        if(isEmpty()) return -1;
        int h = 0, n = size;
        while(n > 1){
            n /= 2;
            h++;
        }
        return h;
    }

    void preorder() const  { preorder(0); cout << "\n"; }
    void inorder() const   { inorder(0); cout << "\n"; }
    void postorder() const { postorder(0); cout << "\n"; }

    void levelorder() const{
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void displayNodes() const {
        if (isEmpty()) { cout << "Tree is empty.\n"; return; }
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << " | Value " << arr[i];
            if (i == 0) cout << " | Parent: none";
            else        cout << " | Parent: " << arr[parent(i)];

            if (left(i) < size)  cout << " | Left: " << arr[left(i)];
            else                 cout << " | Left: none";

            if (right(i) < size) cout << " | Right: " << arr[right(i)];
            else                 cout << " | Right: none";
            cout << "\n";
        }
    }

    // Draw the tree sideways (right subtree on top)
    void drawTree(int i = 0, int depth = 0) const {
        if (i >= size) return;
        drawTree(right(i), depth + 1);
        for (int d = 0; d < depth; d++) cout << "    ";
        cout << arr[i] << "\n";
        drawTree(left(i), depth + 1);
    }
};

int main() {
    CompleteTree tree;

    cout << "=== Testing Complete Binary Tree ===\n\n";

    // 1. Insert values
    cout << "Inserting 10, 20, 30, 40, 50, 60...\n";
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);

    // 2. Level Order
    cout << "Level order: ";
    tree.levelorder();

    // 3. Traversals
    cout << "Preorder:    ";
    tree.preorder();
    cout << "Inorder:     ";
    tree.inorder();
    cout << "Postorder:   ";
    tree.postorder();

    // 4. Size and Height
    cout << "Tree Size: " << tree.getSize() << " | Height: " << tree.height() << "\n";

    // 5. Node Relationships
    cout << "\n--- Node Relationships ---\n";
    tree.displayNodes();

    // 6. Search Test
    int searchVal = 40;
    int foundIdx = tree.search(searchVal);
    cout << "\nSearching for " << searchVal << ": " 
         << (foundIdx != -1 ? "Found at index " + to_string(foundIdx) : "Not found") << "\n";

    // 7. Removal Test
    cout << "\nRemoving 20 (replaces with last element 60)...\n";
    tree.remove(20);
    cout << "Level order after removal: ";
    tree.levelorder();

    // 8. Visual Tree Drawing
    cout << "\n--- Visualizing Tree Structure ---\n";
    tree.drawTree();

    return 0;
}
