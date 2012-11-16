/* 
 * File:   main.cpp
 * Author: cj
 *
 * Created on 2012年11月6日, 下午2:10
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "p4.h"

using namespace std;

/*
 * A palindromic number reads the same both ways. The largest palindrome made from 
 * the product of two 2-digit numbers is 9009 = 91 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * 
 * Consider the digits of P – let them be x, y and z. P must be at least 6 digits long since the
 * palindrome 111111 = 143×777 – the product of two 3-digit integers. Since P is palindromic:
 * P=100000x + 10000y * 1000z * 100z * 10y * x
 * P=100001x * 10010y * 1100z
 * P=11(9091x * 910y * 100z)
 * 
 * Since 11 is prime, at least one of the integers a or b must have a factor of 11.
 * So if a is not divisible by 11 then we know b must be.
 */
int findPalidromic(int low, int high) {
    int max = 0;
    int maxi = 0;
    int p = 0;
    for (int i = high; i >= low; i--) {
        for (int j = i; j >= low; j--) {
            p = i * j;
            if (Palidromic::isPalidromicNum(p) && max < p) {               
                    max = p;
                    maxi = i;                             
            }
        }
    }
    if (max > 0)
        cout << maxi << " * " << max / maxi << " = " << max << endl;                
    return 0;
}

int findPalidromic() {
    int max = 0;
    int maxi = 0;
    int db = 1;
    int p = 0;
    for (int i = 999; i >= 100; i--) {
        if (i % 11 != 0) {
            db = 11;            
        }
        for (int j = i - (i % db); j >= 100; j = j - db) {
            p = i * j;
            if (Palidromic::isPalidromicNum(p) && max < p) {               
                    max = p;
                    maxi = i;                             
            }        
        }            
    }
    if (max > 0)
        cout << maxi << " * " << max / maxi << " = " << max << endl;                
    return 0;
}

/*
 * p5: 2520 is the smallest number that can be divided by each of the numbers 
 * from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by 
 * all of the numbers from 1 to 20?
 * 2520 * 11 * 13 * 17 * 19 * 2 = 232792560
 */

/*
 * p6: By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 * 
 * Some useful facts:
 *  1 is not a prime.
 * All primes except 2 are odd.
 * All primes greater than 3 can be written in the form  6k+/-1.
 * Any number n can have only one primefactor greater than n .
 * The consequence for primality testing of a number n is: if we cannot find a number f less than 
 * or equal  n that divides n then n is prime: the only primefactor of n is n itself
 * 
 * 338ms
 */
int findithPrime(int i) {
    if (i <= 0)
        return -1;
    std::vector<int> primes;
    primes.push_back(2);
    int s = 1;
    int prime = 3;
    bool find = true;
    while (s < i) {
       while (1) {
           find = true;
           for (int n = 0; n < s; n++) {
               if (prime % primes[n] == 0) {
                   find = false;
                   break;
               }
           }
           if (find) {
               primes.push_back(prime);
               prime += 1;
               s++;
               break;
           }
           prime += 1;
       } 
    }
    return primes[i - 1];
}

bool isPrime(int num) {
    int sqrt = std::sqrt(num);
    for (int i = 2; i <= sqrt; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int sumOfPrimes(int up) {
    std::vector<int> primes;
    std::vector<int> sums;
    primes.push_back(2);
    //int s = 1;
    int prime = 3;
    //int sum = 2;
    uint64_t sum = 2;
    bool find = true;
    while (prime < up) {
       //while (1) {
           find = true;
           /*
           for (int n = 0; n < s; n++) {
               if (prime % primes[n] == 0) {
                   find = false;
                   break;
               }
           }
           */
           find = isPrime(prime);
           if (find) {
               //primes.push_back(prime);
               if (sum + prime > sum)
                  sum += prime;
               else {
                   sums.push_back(sum);
                   sum = prime;
               }
               //prime += 2;
               //s++;
               //break;
           }
           prime += 1; 
    }
    for (int i = 0; i < sums.size(); i++) {
        std::cout << sums[i] << std::endl;
    }
    printf("==0x%lx==, ==%llu==", sum, sum);
    return sum;
}

//p8
extern int greatest(char *file);
void testp8() {
    char *filename = "./nums.txt";
    int result = greatest(filename);
    std::cout << result << "+++" << std::endl;
}
extern void findabc(void);
extern int findMaximum(char *fileName);
void test(int idx) {
    switch(idx) {
        case 8:
            testp8();
            break;
        case 9:
            //testp9(); break;
            findabc(); break;
        case 10:
            sumOfPrimes(2000000); break;
            //std::cout << std::ios_base::hex << sumOfPrimes(2000000) <<std::endl; break;
        case 11:
            findMaximum("./numtrix.txt");
        default:
            break;
    };
}
/*
 * 
 */
int main(int argc, char** argv) {
    //p4
    //cout << Palidromic::isPalidromicNum(9009) << endl;
    //findPalidromic(100, 999);
    //findPalidromic();
    
    //p5
    //for (int i = 1; i < 11; i++)
    //    cout << findithPrime(i) << "\t";
    //cout << endl;
    //cout << "the 10001th prime is " << findithPrime(10001) << endl;
    test(11);
    return 0;
}

