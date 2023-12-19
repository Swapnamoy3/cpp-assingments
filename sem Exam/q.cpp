#include <iostream>
 template <typename T>
 class Node {
 public:
     T data;
     Node* next;
  
     Node(T value) : data(value), next(nullptr) {}
 };
  
 template <typename T>
 class CircularLinkedList {
 private:
     Node<T>* head;
  
 public:
     CircularLinkedList() : head(nullptr) {}
  
     void insert(T value) {
         Node<T>* newNode = new Node<T>(value);
  
         if (!head) {
             head = newNode;
             head->next = head; // Point to itself for circularity
         } else {
             Node<T>* temp = head;
             while (temp->next != head) {
                 temp = temp->next;
             }
             temp->next = newNode;
             newNode->next = head;
         }
     }
  
     void remove(T value) {
         if (!head) {
             return;
         }
  
         Node<T>* temp = head;
         Node<T>* prev = nullptr;
  
         do {
             if (temp->data == value) {
                 if (temp == head) {
                     if (temp->next == head) {
                         delete temp;
                         head = nullptr;
                     } else {
                         Node<T>* lastNode = head;
                         while (lastNode->next != head) {
                             lastNode = lastNode->next;
                         }
                         lastNode->next = temp->next;
                         head = temp->next;
                         delete temp;
                     }
                 } else {
                     prev->next = temp->next;
                     delete temp;
                 }
                 return;
             }
             prev = temp;
             temp = temp->next;
         } while (temp != head);
     }
  
     bool search(T value) const {
         if (!head) {
             return false;
         }
  
         Node<T>* temp = head;
  
         do {
             if (temp->data == value) {
                 return true;
             }
             temp = temp->next;
         } while (temp != head);
  
         return false;
     }
  
     void reverse() {
         if (!head || head->next == head) {
             return; // List is empty or has only one element
         }
  
         Node<T>* current = head;
         Node<T>* prev = nullptr;
         Node<T>* next = nullptr;
  
         do {
             next = current->next;
             current->next = prev;
             prev = current;
             current = next;
         } while (current != head);
  
         head->next = prev;
         head = prev;
     }
  
     void display() const {
         if (!head) {
             return;
         }
  
         Node<T>* temp = head;
  
         do {
             std::cout << temp->data << " ";
             temp = temp->next;
         } while (temp != head);
  
         std::cout << std::endl;
     }
  
     ~CircularLinkedList() {
         if (!head) {
             return;
         }
  
         Node<T>* temp;
         Node<T>* current = head->next;
  
         while (current != head) {
             temp = current;
             current = current->next;
             delete temp;
         }
  
         delete head;
     }
 };
  
 int main() {
     CircularLinkedList<int> list;
  
     list.insert(1);
     list.insert(2);
     list.insert(3);
  
     std::cout << "Original List: ";
     list.display();
  
     list.remove(2);
     std::cout << "List after removing 2: ";
     list.display();
  
     list.reverse();
     std::cout << "Reversed List: ";
     list.display();
  
     return 0;
 }
