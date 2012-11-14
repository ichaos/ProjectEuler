#include <iostream>

void findabc(void) {
    //b = (500 - a) * 1000 / (1000 - a)
    for (int i = 0; i < 500; i++) {
        if (((500 - i) * 1000) % (1000 - i) == 0)
            std::cout << i << "+" << (500 - i) * 1000 / (1000 - i) << std::endl;
    }
    return;
}
