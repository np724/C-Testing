class GrowArray {
private:
	int* p;
	uint32_t size; // the number of elements used
	uint32_t capacity; // the amount of memory
	void checkGrow() {
	  if (size < capacity)
	    return;
	  
		// if the memory needs to grow, double in size
		//TODO: YOU IMPLEMENT THIS
	capacity *= 2;
        int* newP = new int[capacity];
        for (uint32_t i = 0; i < size; i++) {
            newP[i] = p[i];
        }
        delete[] p;
        p = newP;
	}
public:
	//write constructor, destructor
	// Constructor
    GrowArray(uint32_t initialCapacity) : size(0), capacity(initialCapacity) {
        p = new int[capacity];
    }

    // Destructor
    ~GrowArray() {
        delete[] p;
    }
	//copy constructor + 10%
GrowArray(const GrowArray& other) : size(other.size), capacity(other.capacity) {
        p = new int[capacity];
        for (uint32_t i = 0; i < size; i++) {
            p[i] = other.p[i];
        }
    }

    // Copy Assignment Operator
    GrowArray& operator=(const GrowArray& other) {
        if (this != &other) {
            delete[] p;
            size = other.size;
            capacity = other.capacity;
            p = new int[capacity];
            for (uint32_t i = 0; i < size; i++) {
                p[i] = other.p[i];
            }
        }
        return *this;
    }
	//double ended?  + 20% (SEE circularbuffer)
	void addEnd(int v) { //O(____________)
		checkGrow();
        	p[size++] = v;
	}

	void addStart(int v) { //O(____________)
		checkGrow();
        	for (uint32_t i = size; i > 0; i--) {
            		p[i] = p[i - 1];
        	}
        	p[0] = v;
        	size++;
	}
	void removeStart() { //O(____________)
		if (size == 0)
            		return;
        	for (uint32_t i = 0; i < size - 1; i++) {
            		p[i] = p[i + 1];
        	}
        s	ize--;
	}
	
	void removeEnd() { //O(____________)
		if (size == 0)
            		return;
        	size--;
	}
	uint32_t getSize() const { //O(____________)
		return size;
	}
	void removeEvens() {
        	uint32_t newSize = 0;
        	for (uint32_t i = 0; i < size; i++) {
            		if (p[i] % 2 != 0) {
                		p[newSize++] = p[i];
            		}
        	}
        	size = newSize;
    }
};

int main() {
	GrowArray a(5); // empty list, with 500 elements
	const int n = 10;
	for (int i = 0; i < n; i++)   //O(____________)
		a.addEnd(i); // really fast!

	for (int i = 0; i < n; i++)    //O(____________)
		a.addEnd(i); // every time you need to grow, double

	a.addStart(5);
	
	for (int i = 0; i < n/2; i++) //O(____________)
		a.removeEnd();

	for (int i = 0; i < n/2; i++)
		a.removeStart();

	
    a.removeEvens();
	
	cout << a << '\n';
}
