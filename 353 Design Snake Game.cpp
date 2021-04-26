/*
Problem link: https://leetcode.com/problems/design-snake-game/
Solution Author: emotionless
Date: 26 April 2021

*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>


using namespace std;

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */



    SnakeGame(int width, int height, vector<vector<int>>& food) {
        n = height;
        m = width;
        foods = food;
        dir["U"] = {-1, 0};
        dir["R"] = {0, +1};
        dir["D"] = {1, 0};
        dir["L"] = {0, -1};
        q.push({0, 0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int di = dir[direction].first;
        int dj = dir[direction].second;
        x += di, y += dj;
        if (x < 0 || x >= n || y < 0 || y >= m) return -1;

        if (foodIndex < foods.size() && foods[foodIndex][0] == x && foods[foodIndex][1] == y) {
            foodIndex++;
        } else {
            auto frnt = q.front();
            q.pop();
            vis.erase(frnt);
        }
        if (vis.find({x, y}) != vis.end()) {
            return -1;
        }
        q.push({x, y});
        vis.insert({x, y});
        return q.size() - 1;
    }
private:
    queue<pair<int, int>> q;
    set<pair<int, int>> vis;
    vector<vector<int>> foods;
    int foodIndex = 0;
    unordered_map<string, pair<int, int>> dir;
    int x = 0, y = 0;
    int n, m;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

/*

Time complexity:
O(queries * log(queries)
Space complexity:
O(n*m)
*/
