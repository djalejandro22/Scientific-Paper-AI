#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int N = 3;
struct Node {
    array<int, N*N> state;
    int g;  // cost so far
    int f;  // estimated total cost = g + h
};
// Manhattan distance heuristic for 3x3 puzzle
int manhattanDistance(const array<int,9>& state, const array<int,9>& goal) {
    int dist = 0;
    for(int i = 0; i < 9; ++i) {
        if(state[i] == 0) continue; // skip empty
        // find current row, col and goal row, col for tile
        int curr = state[i];
        // Goal position of tile 'curr' (1-8) is index curr-1 (0-indexed)
        int goalIndex = curr - 1;
        int curr_r = i / N, curr_c = i % N;
        int goal_r = goalIndex / N, goal_c = goalIndex % N;
        dist += abs(curr_r - goal_r) + abs(curr_c - goal_c);
    }
    return dist;
}
// Comparison for priority queue (min-heap by f value)
struct CompareF {
    bool operator()(const Node& a, const Node& b) const {
        return a.f > b.f;
    }
};
string stateKey(const array<int,9>& st) {
    // Convert state array to a string key for hashing
    string key;
    for(int tile : st) { key.push_back(char(tile + '0')); }
    return key;
}
bool aStarSolve(const array<int,9>& start, const array<int,9>& goal) {
    priority_queue<Node, vector<Node>, CompareF> openList;
    unordered_set<string> closed;  // visited states
    Node startNode { start, 0, manhattanDistance(start, goal) };
    openList.push(startNode);
    while(!openList.empty()) {
        Node node = openList.top();
        openList.pop();
        if(node.state == goal) {
            cout << "Solution found with cost = " << node.g << " moves.\n";
            return true;
        }
        string key = stateKey(node.state);
        if(closed.count(key)) continue;  // skip if already visited (better path found)
        closed.insert(key);
        // Locate the empty tile (0)
        int zeroIdx = find(node.state.begin(), node.state.end(), 0) - node.state.begin();
        int zr = zeroIdx / N, zc = zeroIdx % N;
        // Possible moves (up, down, left, right)
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for(int m = 0; m < 4; ++m) {
            int nr = zr + dr[m], nc = zc + dc[m];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue; // out of bounds
            // Swap empty with neighbor tile to generate new state
            int newIndex = nr * N + nc;
            Node child = node;
            swap(child.state[zeroIdx], child.state[newIndex]);
            child.g = node.g + 1;
            child.f = child.g + manhattanDistance(child.state, goal);
            string childKey = stateKey(child.state);
            if(!closed.count(childKey)) {
                openList.push(child);
            }
        }
    }
    return false; // no solution (shouldn't happen for solvable puzzle)
}
int main(){
    // Example start (worst-case) and goal states for 8-puzzle
    array<int,9> start = {8,6,7, 2,5,4, 3,0,1};
    array<int,9> goal  = {1,2,3, 4,5,6, 7,8,0};
    aStarSolve(start, goal);
}
