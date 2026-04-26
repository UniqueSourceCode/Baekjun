#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> next_room;

long long find_room(long long x) {
    //if empty, return itself else compress paths
    if (next_room[x] == 0) {
        next_room[x] = x+1;
        return x;
    }
    long long ans = find_room(next_room[x]);
    next_room[x] = ans;
    return ans;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, int> hash;
    for (auto& x : room_number) {
        long long room = find_room(x);
        answer.push_back(room);
    }
    return answer;
}