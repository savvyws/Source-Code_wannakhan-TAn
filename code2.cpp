#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

string compareString(string target, string mask)
{
    int maxLength = max(target.size(), mask.size());

    if (target.size() < maxLength)
    {
        target += string(maxLength - target.size(), ' ');
    }
    else if (mask.size() < maxLength)
    {
        mask += string(maxLength - mask.size(), ' ');
    }

    int asciiTarget;
    int asciiMask;
    string ans;

    for (int i = 0; i < maxLength; i++)
    {
        asciiTarget = int(target[i]);
        asciiMask = int(mask[i]);

        // case 1: Both characters are uppercase using ASCII Code
        if (65 <= asciiMask && asciiMask <= 90 && 65 <= asciiTarget && asciiTarget <= 90)
        {
            ans += target[i];
        }
        // case 2: Both characters are lowercase using ASCII Code
        else if (97 <= asciiMask && asciiMask <= 122 && 97 <= asciiTarget && asciiTarget <= 122)
        {
            ans += mask[i];
        }
        // case 3: One character is uppercase and the other is lowercase using ASCII Code
        else if ((97 <= asciiMask && asciiMask <= 122 && 65 <= asciiTarget && asciiTarget <= 90) ||
                 (65 <= asciiMask && asciiMask <= 90 && 97 <= asciiTarget && asciiTarget <= 122))
        {
            ans += '$';
        }
        // case 4: Otherwise
        else
        {
            ans += '#';
        }
    }
    return ans;
}

int main()
{
    string Target, Mask;
    cout << "Target: ";
    // handle input with space
    getline(cin, Target);
    cout << "Mask: ";
    getline(cin, Mask);

    string ans = compareString(Target, Mask);
    cout << ans;

    return 0;
}