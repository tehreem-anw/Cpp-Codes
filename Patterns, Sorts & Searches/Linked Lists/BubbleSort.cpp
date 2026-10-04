void bubbleSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool swapped = true;
    Node* lastPtr = nullptr; // Keeps track of the boundary of sorted nodes at the end

    while (swapped) {
        swapped = false; // Reset flag at the start of each pass
        Node* ptr1 = head;

        while (ptr1->next != lastPtr) {
            if (ptr1->val > ptr1->next->val) {
                // Swap the values of adjacent nodes
                int temp = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = temp;

                swapped = true; // Mark that a swap happened
            }
            ptr1 = ptr1->next;
        }
        // ptr1 is now at the end of the unsorted segment; shrink the boundary
        lastPtr = ptr1;
    }
}
