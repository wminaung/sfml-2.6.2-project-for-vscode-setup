// #include <iostream>
// using namespace std;

// template <typename T> class LinkedList {
// private:
//   //////////
//   class Node {
//   public:
//     Node *next;
//     T data;

//     Node(T data, Node *next = nullptr) {
//       this->data = data;
//       this->next = next;
//     }
//     ~Node() { delete this->next; }
//   };
//   //////////
//   Node *root;
//   int nrOfNodes;

// public:
//   LinkedList() {
//     this->root = nullptr;
//     this->nrOfNodes = 0;
//   }
//   ~LinkedList() { delete this->root; }

//   //
//   void insertEnd(T data) {
//     if (this->root == nullptr) {
//       // list is empty,
//       this->root = new Node(data);
//     } else {
//       Node *walker = this->root;
//       while (walker->next != nullptr) {
//         walker = walker->next;
//       }
//       walker->next = new Node(data);
//     }
//     this->nrOfNodes++;
//   }
//   T getAt(int index) {
//     //
//     if (this->root == nullptr) {
//       throw std::runtime_error("List is empty");
//     } else if (index < 0 || index >= this->nrOfNodes) {
//       throw std::runtime_error("Index out of bounds");
//     }

//     T data;
//     if (index == 0) {
//       data = this->root->data;
//     } else {
//       Node *walker = this->root;
//       for (size_t i = 0; i < index; i++) {
//         walker = walker->next;
//       }
//       data = walker->data;
//     }
//     cout << "getAt(" << index << ") = " << data << endl;

//     return data;
//   };

//   // void remove(T element) { cout << "remove(" << data << ")" << endl; }
// };

// int main() {

//   LinkedList<int> list1;
//   list1.insertEnd(1);
//   list1.insertEnd(2);
//   list1.insertEnd(3);
//   list1.getAt(0);
//   list1.getAt(1);
//   list1.getAt(2);
//   list1.getAt(3);

//   return 0;
//   //
// }
// /*
// g++ test.cpp && ./a.exe
// - or -
// g++ -O3 -march=native test.cpp && ./a.exe
// */
