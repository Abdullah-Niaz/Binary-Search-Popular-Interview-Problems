#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> anagramGroups;

    // Iterate over each string in the input list
    for (string s : strs)
    {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end()); // Sort the string
        anagramGroups[sortedStr].push_back(s);    // Group the original string with its anagrams
    }

    // Prepare the result vector by collecting all grouped anagrams
    vector<vector<string>> result;
    for (auto group : anagramGroups)
    {
        result.push_back(group.second);
    }

    return result;
}

int main()
{
    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = groupAnagrams(strs1);

    // Print the result
    for (const auto &group : result1)
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    // Test case 2
    vector<string> strs2 = {""};
    vector<vector<string>> result2 = groupAnagrams(strs2);

    for (const auto &group : result2)
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    // Test case 3
    vector<string> strs3 = {"a"};
    vector<vector<string>> result3 = groupAnagrams(strs3);

    for (const auto &group : result3)
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
