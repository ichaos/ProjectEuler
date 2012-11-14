/* 
 * File:   p4.h
 * Author: cj
 *
 * Created on 2012年11月6日, 下午2:23
 */

#ifndef P4_H
#define	P4_H

#include <vector>

class Palidromic {
private:
    int n;
public:
    Palidromic();
    Palidromic(int n);
    
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
    
    /*
     * For p4,
     * isPalidromic costs 550ms
     * isPalidromicNum costs 87ms
     */
    static bool isPalidromicNum(int n) {
        int reversed = 0;
        int m = n;
        while (m > 0) {
            reversed = reversed * 10 + m % 10;
            m = m / 10;
        }
        if (reversed == n)
            return true;
        else return false;
    }
};



#endif	/* P4_H */

