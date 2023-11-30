template <typename T>
struct Node {
	T data;       // actual data of the node
	Node* next;   // pointer to next node
	Node(T value): data(value), next(nullptr) {} // constructor
};

template <typename T>
class SinglyLinkedList {
	private:
	Node<T>* head;

	public:
	SinglyLinkedList(): head(nullptr) {} // constructor

	~SinglyLinkedList() { // iterate through the list and delete each node
		Node<T>* current = head;
		while (current != nullptr) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}

	void insert(T value) { // insert at begin
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
	}
};