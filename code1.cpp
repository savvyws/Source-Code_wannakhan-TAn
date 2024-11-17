#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string &str, char delimiter)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

// Function to convert the date format
string getDate(string s)
{
    string ans;
    unordered_map<string, int> monthMap = {
        {"january", 1}, {"february", 2}, {"march", 3}, {"april", 4}, {"may", 5}, {"june", 6}, {"july", 7}, {"august", 8}, {"september", 9}, {"october", 10}, {"november", 11}, {"ecember", 12}};

    vector<string> tokens = split(s, ' ');
    // make sure the input string is in the same format as the monthMap
    for (int i = 0; i < tokens[1].size(); i++)
    {
        tokens[1][i] = tolower(tokens[1][i]);
    }

    string year = to_string(stoi(tokens[2]) + 543);
    ans = tokens[0] + '/' + to_string(monthMap[tokens[1]]) + '/' + year;
    return ans;
}

int main()
{
    string date;
    cout << "Enter day month year: ";

    getline(cin, date);
    string ans = getDate(date);
    cout << ans;
    return 0;
}
