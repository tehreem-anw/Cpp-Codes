void sortInsertion(Node* &head){
    if(head == NULL || head->next == NULL){return;}
    Node* sorted = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* nextNode = curr->next;
        if(sorted == NULL || sorted->data > curr->data){
            curr->next = sorted;
            sorted = curr;
        }
        else{
            Node* temp = sorted;
            while(temp != NULL && temp->next->data < curr->data){
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = nextNode;
    }
    head = sorted;
}
