#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Room {
	public:
		vector<Room*> keys;  // Rooms you can visit from this room
		int milkTea;         // milk tea in the room
		int roomNumber;      // Unique room number
};

// Approach: DFS Traversal
// Time Complexity: O(N + E) where N is the total number of rooms and E is the total number of keys
// Space Complexity: O(N) We will store the room number of N rooms in a set

int totalAmountOfMilkTea(Room* start){
    int milkTeaCollected = 0;
    if (start == NULL) return milkTeaCollected;
    // Set used to keep track of rooms visited. Insert/find operations cost constant time complexity
    unordered_set<int> roomsVisited;
    // Stack used to iteratively perform Depth First Search
    stack<Room*> s;
    s.push(start);
    //Mark start Room as visited
    roomsVisited.insert(start->roomNumber);
    Room* current = NULL;
    // Perform DFS
    while(!s.empty()) {
        // Get the room at the top of the stack
        current = s.top();
        // Pop room from the stack
        s.pop();
        // Collect the milk tea
        milkTeaCollected += current->milkTea;
        // Iterate over the rooms that can be accessed from the current room
        for(Room* roomToVisit : current->keys){
            //  If the room to visit has not been visited
            if (roomsVisited.find(roomToVisit->roomNumber) == roomsVisited.end()){
                // Add it to the set of visited rooms
                roomsVisited.insert(roomToVisit->roomNumber);
                // Push it into the stack
                s.push(roomToVisit);
            }
        }
    }
    // Return the total amount of milk tea collected
    return milkTeaCollected;
}