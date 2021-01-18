/*Find Smallest Letter Greater Than Target
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) return letters.front();
        int low = 0, high = letters.size() - 1,mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (target < letters[mid]) high = mid;
            else low = mid + 1;
        }
        return letters[low];
    }
};