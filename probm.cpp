#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
const int PRIMARY_BASE = 137;
const int SECONDARY_BASE = 1319;
const int64 PRIMARY_MOD = 1000000007;
const int64 SECONDARY_MOD = 1000000009;

class StringProcessor {
private:
    int length;
    string input;
    vector<int64> primaryPrefix, secondaryPrefix;
    vector<int64> primaryPowers, secondaryPowers;
    
    void initializePrefixArrays() {
        primaryPrefix.resize(length + 1, 0);
        secondaryPrefix.resize(length + 1, 0);
        primaryPowers.resize(length + 1, 1);
        secondaryPowers.resize(length + 1, 1);
        
        for (int i = 1; i <= length; i++) {
            primaryPowers[i] = (primaryPowers[i - 1] * PRIMARY_BASE) % PRIMARY_MOD;
            secondaryPowers[i] = (secondaryPowers[i - 1] * SECONDARY_BASE) % SECONDARY_MOD;
        }
        
        for (int i = 0; i < length; i++) {
            int charValue = input[i] - 'a' + 1;
            primaryPrefix[i + 1] = (primaryPrefix[i] * PRIMARY_BASE + charValue) % PRIMARY_MOD;
            secondaryPrefix[i + 1] = (secondaryPrefix[i] * SECONDARY_BASE + charValue) % SECONDARY_MOD;
        }
    }
    
    pair<int64, int64> computeHash(int beginIndex, int endIndex) {
        int segmentLength = endIndex - beginIndex + 1;
        int64 hash1 = (primaryPrefix[endIndex + 1] - primaryPrefix[beginIndex] * 
                      primaryPowers[segmentLength] % PRIMARY_MOD + PRIMARY_MOD) % PRIMARY_MOD;
        int64 hash2 = (secondaryPrefix[endIndex + 1] - secondaryPrefix[beginIndex] * 
                      secondaryPowers[segmentLength] % SECONDARY_MOD + SECONDARY_MOD) % SECONDARY_MOD;
        return make_pair(hash1, hash2);
    }
    
public:
    StringProcessor(int n, const string& s) : length(n), input(s) {
        initializePrefixArrays();
    }
    
    int calculateMinimalPartition() {
        int left = 0, right = length - 1;
        int partitionCount = 0;
        
        while (left <= right) {
            if (left == right) {
                partitionCount++;
                break;
            }
            
            int maxPossibleLength = (right - left + 1) / 2;
            int currentLength = 1;
            bool foundMatch = false;
            
            while (currentLength <= maxPossibleLength) {
                auto leftHash = computeHash(left, left + currentLength - 1);
                auto rightHash = computeHash(right - currentLength + 1, right);
                
                if (leftHash == rightHash) {
                    foundMatch = true;
                    break;
                }
                currentLength++;
            }
            
            if (!foundMatch) {
                partitionCount++;
                break;
            }
            partitionCount += 2;
            left += currentLength;
            right -= currentLength;
        }
        
        return partitionCount;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    
    StringProcessor processor(n, s);
    int ans = processor.calculateMinimalPartition();
    cout << ans << "\n";
    
    return 0;
}