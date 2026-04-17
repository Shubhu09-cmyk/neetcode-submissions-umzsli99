class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //greedy math approach 

        /*
        unordered_map<char,int> freq;
⚠️ Interview Note:
Since tasks are only 'A' → 'Z', a fixed array is faster and cleaner.
✅ Better Version:
vector<int> freq(26, 0);
for (char c : tasks) {
    freq[c - 'A']++;
}
👉 This improves:
Space → truly O(1)
Speed → no hashing
*/
        unordered_map<char,int> freq;
        for(char& c : tasks){ //calculate frequency
            freq[c]++;
        }
        //calc max freq
        int maxFreq=0;
        for( auto& c : freq){
            maxFreq=max(maxFreq,c.second);
        }
        //calc maxCount
        int maxCount=0;
        for(auto& c : freq){
            if(maxFreq==c.second){
                maxCount++;
            }
        }
        //apply formula
        int result=(maxFreq-1)*(n+1)+maxCount;
        return max((int)tasks.size(),result);
        /*
        tasks.size() → size_t (unsigned, usually 64-bit)
result → int (signed, usually 32-bit)
🧨 What C++ does internally
Before calling max, both arguments must be the same type.
👉 So C++ implicitly converts result → size_t

❗ Why is that dangerous?
If result were ever negative, it would become a huge positive number due to unsigned conversion.
Example:
int result = -1;
size_t x = result;  // becomes VERY large number (like 2^64 - 1)
Now:
max(tasks.size(), result)
might return a completely incorrect huge value.
🤔 “But in THIS problem, result is never negative…”
Correct. In Task Scheduler, your formula guarantees:
(maxFreq - 1) * (n + 1) + maxCount ≥ 1
👉 So practically:
No bug will occur here
Your code will pass all tests
💡 Then why do interviewers care?
Because they’re testing:
Your understanding of C++ type system
Your attention to edge-case safety
Writing robust, warning-free code
✅ Proper Fix
return max((int)tasks.size(), result);
Now both are int → no implicit conversion
🧠 Alternative (Even cleaner)
You can also do:
return max(static_cast<int>(tasks.size()), result);
👉 Preferred in modern C++ interviews
🎯 Interview One-Liner
If asked:
“Any issues with this line?”
You say:
“Yes, tasks.size() is size_t and result is int, so implicit conversion can occur. I’d cast to int to avoid signed/unsigned mismatch.”
🏁 Bottom Line
❌ Not a runtime bug here
⚠️ But bad practice / warning-prone
✅ Fix is simple and expected in interviews
If you want, I can show you a case where this actually breaks real code—that’s where it really clicks.

*/
    }
};
