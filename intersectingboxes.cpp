#include <iostream>
#include <vector>
#include <fstream>
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

    // Iterate through the boxes
    for (uint32_t i = 0; i < boxes.size(); i++) {
        for (uint32_t j = i + 1; j < boxes.size(); j++) {
            // Check for intersection
            if (boxes[i].x < boxes[j].x + boxes[j].w &&
                boxes[i].x + boxes[i].w > boxes[j].x &&
                boxes[i].y < boxes[j].y + boxes[j].h &&
                boxes[i].y + boxes[i].h > boxes[j].y) {
                // Boxes i and j intersect
                cout << "Boxes " << i + 1 << " and " << j + 1 << " intersect" << endl;
                intersecting++;
            }
        }
    }

    cout << "Total intersecting pairs: " << intersecting << endl;
    return 0;
}
