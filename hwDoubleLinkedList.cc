#include <iostream>
using namespace std;

class DoubleLinkedList {
private:
	class Node {
	public:
		Node* next;
		Node* prev;
		int val;
		Node(int v, Node* n = nullptr, Node* p = nullptr) : val(v), next(n), prev(p) {}
	};

	Node* head;
	Node* tail;
public:
	DoubleLinkedList() : head(nullptr), tail(nullptr) {
	}
	
	// Destructor to free allocated memory
	~DoubleLinkedList() {
		Node* temp;
        	for (Node* p = head; p != nullptr; p = temp) {
            		temp = p->next;
            		delete p;
        	}
	}

	void addStart(int v) {
		    head = new Node(v, head);
       	 	if (head->next != nullptr)
           		head->next->prev = head;
        	else
            		tail = head;
	}

	void addEnd(int v) {
		if (head == nullptr) {
            		head = new Node(v);
            		tail = head;
        	} 
		else {
            		Node* newNode = new Node(v, nullptr, tail);
            		tail->next = newNode;
            		tail = newNode;
        	}
	}

	void removeStart() {
		Node* temp = head;
        	int v = temp->val;
        	head = head->next;
        	if (head != nullptr)
            		head->prev = nullptr;
        	else
            		tail = nullptr;
        	delete temp;
	}

	void removeEnd() {
		Node* temp = tail;
        	tail = tail->prev;
        	if (tail != nullptr)
            		tail->next = nullptr;
        	else
            		head = nullptr;
        	delete temp;
	}

	void insert(int pos, int v) {
		if (pos <= 0) {
            		addStart(v);
            		return;
        	}

        	Node* current = head;
        	for (int i = 0; current != nullptr && i < pos; ++i)
            		current = current->next;

        	Node* newNode = new Node(v, current, current->prev);
        	current->prev->next = newNode;
        	current->prev = newNode;
	}

	friend ostream& operator <<(ostream& s, const DoubleLinkedList& list) {
		Node* current = list.head;
		while (current != nullptr) {
			s << current->val << " ";
			current = current->next;
		}
		return s;
	}
};

int main() {
	DoubleLinkedList a;
	uint32_t n;
    cout << "Enter an integer: ";
    cin >> n;  // 10
	for (int i = 0; i < n; i++)
		a.addStart(i);   // 9 8 7 6 5 4 3 2 1 0
	for (int i = 0; i < n; i++)
		a.addEnd(i);     // 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
	for (int i = 0; i < 3*n/2; i++)
		a.removeStart(); // 5 6 7 8 9
	
	for (int i = 0; i < n/2 - 5; i++)
		a.removeEnd();  // 5 6 7 8 9

	cout << a << '\n';
	for (int i = 0; i < 10; i++)
		a.insert(1, i); // 5 9 8 7 6 5 4 3 2 1 0 6 7 8 9
	cout << a << '\n';

	return 0;
}
