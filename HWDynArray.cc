#include <iostream>
#include <cstdint>
#include <unistd.h>
using namespace std;
class GrowArray
{
private:
  int *p;
  uint32_t size;				// the number of elements used
  uint32_t capacity;			// the amount of memory
  void checkGrow()
  {
	if(size < capacity)
	  return;
	capacity *= 2;
	int* temP = new int[capacity];
	for (uint32_t i = 0; i < size; i++)
		temP[i] = p[i];
	delete [] p;
	p = temP;
  }
public:
  // Constructor
GrowArray(uint32_t initialCapacity): size(0), capacity(initialCapacity) {
	p = new int[capacity];
  }

  // Destructor
  ~GrowArray() {
	delete [] p;
  }
  
  //copy constructor + 10%
  GrowArray(const GrowArray & orig): size(orig.size), capacity(orig.capacity) {
	p = new int[capacity];
	for(uint32_t i = 0; i < size; i++)
		p[i] = orig.p[i];
  }

  // Copy Assignment Operator
  GrowArray & operator= (const GrowArray & orig) {
	if(this != &orig)
	  {
		delete [] p;
		size = orig.size;
		capacity = orig.capacity;
		p = new int[capacity];
		for(uint32_t i = 0; i < size; i++)
			p[i] = orig.p[i];
	  }
	return *this;
  }
  
  void addEnd(int v) {	//O(1)
	checkGrow();
	p[size++] = v;
  }

  void addStart(int v) {  //O(n)
	checkGrow();
	for(uint32_t i = size; i > 0; i--)
		p[i] = p[i - 1];
	p[0] = v;
	size++;
  }
  
  void removeStart() { //O(n)
	if(size == 0)
	  return;
	for(uint32_t i = 0; i < size - 1; i++)
		p[i] = p[i + 1];
	size--;
  }

  void removeEnd () {  //O(1)
	if(size == 0)
	  return;
	size--;
  }
  
  uint32_t getSize() const {  //O(1)
	return size;
  }
  
  void removeEvens() {  //O(n)
	uint32_t newSize = 0;
	for(uint32_t i = 0; i < size; i++)
	  {
		if(p[i] % 2 != 0)
			p[newSize++] = p[i];
	  }
	size = newSize;
  }
  
 friend ostream & operator << (ostream & s, const GrowArray & list) {
	for (int i = 0; i < list.size; i++)
	  s << list.p[i] << ' ';
	return s;
  }
};

int main()
{
  GrowArray a(5);				// empty list, with 5 elements
  const int n = 10;
  for(int i = 0; i < n; i++)	//O(n)
	a.addEnd(i);				// really fast!

  for(int i = 0; i < n; i++)	//O(n)
	a.addEnd(i);				// every time you need to grow, double

  a.addStart(5);

  for(int i = 0; i < n / 2; i++)	//O(n)
	a.removeEnd();

  for(int i = 0; i < n / 2; i++)   //O(n^2)
	a.removeStart();

  a.removeEvens();

  std::cout << a << '\n';
  
  GrowArray c(0);
  c = a;
  std::cout << c << '\n';
}
