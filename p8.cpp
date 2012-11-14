#include <fstream>
#include <iostream>

int greatest(char *file) {
    int a[5];
    int b[5];
    int index = 0;
    int tmp;
    int greatest = 0;
    char c;
    
    std::fstream f;
    f.open(file, std::ios::in | std::ios::out);
    
    if (f.is_open()) {
        //f >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        for (int i = 0; i < 5; i++) {
            f >> c;
            a[i] = c - '0';
            std::cout << a[i] << std::endl;
        }            
        greatest = a[0] * a[1] * a[2] * a[3] * a[4];
        
        while (f >> c) {
            
            tmp = c - '0';
            if (tmp == 0) {
                for (int i = 0; i < 5; i++) {
                        if (f >> c)
                                b[i] = c - '0';
                }
                tmp = b[0] * b[1] * b[2] * b[3] * b[4];
                if (tmp > greatest)
                    greatest = tmp;
                for (int i = 0; i < 5; i++)
                    a[i] = b[i];
                //a = b;
                index = 0;
            } else {
            a[index] = tmp;
            index = ((index + 1) % 5);
            //index++;
            /*
                    if (tmp > a[index]) {
                a[index++] = tmp;
                tmp = a[0] * a[1] * a[2] * a[3] * a[4];
                if (tmp > greatest) {
                    greatest = tmp;
                }                
            //} else 
                */
            //a[index++] = tmp;
                tmp = a[0] * a[1] * a[2] * a[3] * a[4];
                if (tmp > greatest) {
                    greatest = tmp;
                } 
            }         
        }
    }
    std::cout << greatest << std::endl;     
    return greatest;
}