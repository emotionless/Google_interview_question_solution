/*
Link: https://leetcode.com/discuss/interview-question/421787/

Given a hotel which has 10 floors [0-9] and each floor has 26 rooms [A-Z]. You are given a sequence of rooms, where + suggests room is booked, - room is freed. You have to find which room is booked maximum number of times.

You may assume that the list describe a correct sequence of bookings in chronological order; that is, only free rooms can be booked and only booked rooms can be freeed. All rooms are initially free. Note that this does not mean that all rooms have to be free at the end. In case, 2 rooms have been booked the same number of times, return the lexographically smaller room.

You may assume:

N (length of input) is an integer within the range [1, 600]
each element of array A is a string consisting of three characters: "+" or "-"; a digit "0"-"9"; and uppercase English letter "A" - "Z"
the sequence is correct. That is every booked room was previously free and every freed room was previously booked.
Example:

Input: ["+1A", "+3E", "-1A", "+4F", "+1A", "-3E"]
Output: "1A"
Explanation: 1A as it has been booked 2 times.

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <unordered_map>
#include <cstring>

using namespace std;

class HotelRoom {
public:
    HotelRoom(vector<string> _roomsToBook) {
        roomsToBook = _roomsToBook;
    }

    string getMostBookedRoom() {
        int bookedTimes[10][26];
        memset(bookedTimes, 0, sizeof bookedTimes);
        int ans = 0;
        int mx = 0;
        for(auto room : roomsToBook) {
            int i = room[1] - '0';
            int j = room[2] - 'A';
            if (room[0] == '+') {
                bookedTimes[i][j]++;
                if (bookedTimes[i][j] > mx) {
                    ans = 26*i + j;
                    mx = bookedTimes[i][j];
                } else if (bookedTimes[i][j] == mx) {
                    ans = min(ans, 26*i + j);
                }
            }
        }
        string res = "";
        res += (char)(ans/26 + '0');
        res += (char)(ans%26 + 'A');
        return res;
    }


private:
    vector<string> roomsToBook;
};

int main() {
    HotelRoom hr = HotelRoom(vector<string>({"+1A", "+3E", "-1A", "+4F", "+1A", "-3E"}));
    cout << hr.getMostBookedRoom() << endl;

    return 0;
}
