#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<pair<int, int>> candidate;
map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int gem_s = gems.size();
    if(gem_s == 1) return {1, 1};
    
    set<string> gem_set(gems.begin(), gems.end());
    int set_s = gem_set.size();
    
    int i, j;
    
    int map_s;
    int start = 0, end = 0; // 2 pointer
    int dist = 1e9;
    int right = 1, left = 1;
    while(1){
        map_s = m.size();
        
        if(map_s == set_s){
            if(end - start < dist){
                right = end;
                left = start;
                dist = end - start;
            }
            
            // start 증가
            m[gems[start]]--;
            if(m[gems[start]] == 0) m.erase(gems[start]);
            start++;
        }
        else{
            if(end == gem_s) break; // end에 접근하기 전에 검사 필요
            m[gems[end]]++;
            end++;
        }
    }
    
    answer.push_back(left+1);
    answer.push_back(right);
    
    return answer;
}