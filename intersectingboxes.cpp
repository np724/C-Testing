/*
  Complexity Practice Assignment: Find overlapping boxes
  Complete the following code
  Read in a list of boxes expressed as x y w h
  x and y are the top-left corner of the box,
  w and h are its width and height
  Some boxes may intersect with others

  Display the ordinal position of each box which intersects
  with another and display the pair i,j
  Do not display the pair twice, thus is i intersects with j,
  do not also display j,i
*/
#include <iostream>
#include <vector>
using namespace std;
class Box {
  public:
    int x, y, w, h;
    Box(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
};

int main() {
  ifstream f("boxes.txt");
  vector<Box> boxes;
  boxes.reserve(100000); // preallocate room. If you are smart, do it based on the size of the file
  for (int x, y, w, h; f >> x >> y >> w >> h;) {
    boxes.emplace_back(x, y, w, h); // create a list of all boxes
  }
  uint64_t intersecting = 0;

    for (uint32_t i = 0; i < boxes.size(); i++) {
        for (uint32_t j = i + 1; j < boxes.size(); j++) {
            if (boxes[i].x + boxes[i].w > boxes[j].x && boxes[i].y - boxes[i].h < boxes[j].y && boxes[i].x < boxes[j].x + boxes[j].w && boxes[i].y > boxes[j].y - boxes[j].h) {
                cout << "Boxes " << i + 1 << " and " << j + 1 << " intersect" << endl;
                intersecting++;
            }
        }
    }

    cout << "intersecting boxes: " << intersecting << endl;
    return 0;
}
