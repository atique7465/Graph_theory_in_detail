#include <bits/stdc++.h>

using namespace std;

/**
 * Ref: https://www.youtube.com/watch?v=B2AJoQSZf4M&ab_channel=StableSort
 * Problem: https://leetcode.com/problems/erect-the-fence/
 * Time complexity : O(m*n). For every point on the hull we examine all the other points to determine the next point. Here n is number of input points and m is number of output or hull points (m \leq nm≤n).
 * Space complexity : O(m). List hull  grows upto size mm.
 */
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {

        set<vector<int>> hull; //set to avoid duplicates

        int leftMost = findLeftMost(trees); //find left most

        //Jarvis march
        int a = leftMost;
        bool leftMostCollinear = false;
        do {
            //choose candidate b
            int b = (a + 1) % trees.size(); //to ensure we started with a point other than point_a

            //get the rightMost point of point_a
            //if crossProduct < 0 it means points[i] is on right of current point_a -> point_b. Make point_i the next point.
            for (int i = 0; i < trees.size(); i++)
                if (relativePosition(trees[a], trees[i], trees[b]) < 0)
                    b = i;

            //if more than one points are on the rightmost, then insert all the collinear points in the set
            for (int i = 0; i < trees.size(); i++)
                if (i != a && i != b && relativePosition(trees[a], trees[i], trees[b]) == 0 &&
                    inBetween(trees[a], trees[i], trees[b])) {
                    hull.insert(trees[i]);
                    if (i == leftMost) leftMostCollinear = true;
                }

            if(leftMostCollinear) break;

            hull.insert(trees[b]);
            a = b;
        } while (a != leftMost);

        return vector<vector<int>>(hull.begin(), hull.end());
    }

    int findLeftMost(vector<vector<int>> &trees) {
        int leftMost = 0;
        for (int i = 0; i < trees.size(); i++) if (trees[i][0] < trees[leftMost][0]) leftMost = i;
        return leftMost;
    }

    int relativePosition(vector<int> &a, vector<int> &i, vector<int> &b) {
        return (b[0] - a[0]) * (i[1] - a[1]) - (b[1] - a[1]) * (i[0] - a[0]);
    }

    bool inBetween(vector<int> &a, vector<int> &i, vector<int> &b) {
        bool xIn = (i[0] >= a[0] && i[0] <= b[0]) || (i[0] <= a[0] && i[0] >= b[0]);
        bool yIn = (i[1] >= a[1] && i[1] <= b[1]) || (i[1] <= a[1] && i[1] >= b[1]);
        return xIn & yIn;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{0,  5},
                             {10, 0},
                             {10, 10},
                             {0,  10},
                             {0,  0}};
    vector<vector<int>> hull = s.outerTrees(v);
    return 0;
}