#include <iostream>
using namespace std;

class DoubleLinkedList {
private:
	class Node {
	public:
		Node* next;
		Node* prev;
		int val;
	};

	Node* head;
	Node* tail;
public:
	DoubleLinkedList() : head(nullptr), tail(nullptr) {
	}
	
	// Destructor to free allocated memory
	~DoubleLinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	void addStart(int v) {
		Node* newNode = new Node;
		newNode->val = v;
		newNode->prev = nullptr;
		newNode->next = head;
		if (head != nullptr)
			head->prev = newNode;
		head = newNode;
		if (tail == nullptr)
			tail = head;
	}

	void addEnd(int v) {
		Node* newNode = new Node;
		newNode->val = v;
		newNode->next = nullptr;
		newNode->prev = tail;
		if (tail != nullptr)
			tail->next = newNode;
		tail = newNode;
		if (head == nullptr)
			head = tail;
	}

	void removeStart() {
		if (head != nullptr) {
			Node* temp = head;
			head = head->next;
			if (head != nullptr)
				head->prev = nullptr;
			delete temp;
			if (head == nullptr)
				tail = nullptr;
		}
	}

	void removeEnd() {
		if (tail != nullptr) {
			Node* temp = tail;
			tail = tail->prev;
			if (tail != nullptr)
				tail->next = nullptr;
			delete temp;
			if (tail == nullptr)
				head = nullptr;
		}
	}

	void insert(int pos, int v) {
		Node* newNode = new Node;
		newNode->val = v;

		if (pos <= 0) {
			addStart(v);
			return;
		}

		Node* current = head;
		for (int i = 0; current != nullptr && i < pos - 1; ++i) {
			current = current->next;
		}

		if (current == nullptr) {
			cout << "Position out of bounds.\n";
			return;
		}

		newNode->next = current->next;
		newNode->prev = current;
		if (current->next != nullptr)
			current->next->prev = newNode;
		current->next = newNode;

		if (newNode->next == nullptr)
			tail = newNode;
	}

	friend ostream& operator <<(ostream& s, const DoubleLinkedList& list) {
		typename DoubleLinkedList::Node* current = list.head;
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
    cin >> n;
	for (int i = 0; i < n; i++)
		a.addStart(i);
	for (int i = 0; i < n; i++)
		a.addEnd(i);
	for (int i = 0; i < 3*n/2; i++)
		a.removeStart();
	
	for (int i = 0; i < n/2 - 5; i++)
		a.removeEnd();

	cout << a << '\n';
	for (int i = 0; i < 10; i++)
		a.insert(1, i);
	cout << a << '\n';

	return 0;
}
