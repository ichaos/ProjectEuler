/*
 * A palindromic number reads the same both ways. The largest palindrome made from 
 * the product of two 2-digit numbers is 9009 = 91 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <vector>
/*
class Palidromic {
private:
    int n;
public:
    Palidromic();
    Palidromic(int n) {
        this->n = n;
    }
    
    static bool isPalidromic(int n) {
        std::vector<int> nums;
        while (n > 0) {
            nums.push_back(n % 10);
            n = n / 10;
        }
        // check if it's a palidromic
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[nums.size() - i - 1])
                return false;
        }
        return true;
    }
};
//*/