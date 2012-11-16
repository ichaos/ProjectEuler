#include <fstream>
#include <iostream>
#include <string>

int findMaximum(char *fileName) {
    int matrix[20][20] = {};
    std::fstream f(fileName);
    //f.open(fileName, std::ios_base::in | std::ios_base::out);
    char linebuf[128] = {};//{'\0'};
    std::string line;
    int a = 0;
    int i = 0;
    int max = 0;
    if (f.is_open()) {
        
        //while (f.getline(linebuf, 128) == 0) {
        //while (!f.eof()) {
        //while (f.getline(linebuf, 128)) {
            //f >> linebuf;
            //f >> a;
            //f >> line;
            //std::cout <<line<<std::endl; //<< linebuf << a << std::endl;
            //std::cout <<linebuf<<std::endl;
            
        //}
        while (!f.eof()) {
            f >> matrix[i/20][i%20];
            
            std::cout << matrix[i/20][i%20] << " ";
            i++;
        }
        
        
        for (i = 0; i < 20; i++) {
            for (int j = 0; j < 17; j++) {
                //left <--> right
                a = matrix[i][j] * matrix[i][j + 1] * matrix[i][j + 2] * matrix[i][j + 3];
                if (max < a) {
                    max = a;
                    std::cout << max << " = " << std::endl;
                }
                //up <--> down
                a = matrix[j][i] * matrix[j + 1][i] * matrix[j + 2][i] * matrix[j + 3][i];
                if (max < a) {
                    max = a;
                    std::cout << max << " = " << matrix[j][i]<< "*" << matrix[j + 1][i] << "*" << matrix[j + 2][i] <<  "*" << matrix[j + 3][i] << std::endl;
                }
            }
        }
        
        //diagonal
        for (i = 0; i < 20; i++) {
            for (int j = 0; j < 20;j++) {
                if (i + 3 < 20 && j + 3 < 20) {
                    a = matrix[i][j] * matrix[i + 1][j + 1] * matrix[i + 2][j + 2] * matrix[i + 3][j + 3];
                    if (max < a) {
                        max = a;
                        std::cout << max << " = " << std::endl;
                    }
                } 
                if (i - 3 >= 0 && j + 3 < 20) {
                    a = matrix[i][j] * matrix[i - 1][j + 1] * matrix[i - 2][j + 2] * matrix[i - 3][j + 3];
                    if (max < a) {
                        max = a;
                        std::cout << max << " = " << std::endl;
                    }
                }
            }
        }
        std::cout << "over: " << max <<  std::endl;
    } else {
        std::cout << "Open file failed." << std::endl;
    }
    
    return max;
}
