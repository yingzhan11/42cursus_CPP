#include <iostream>
#include "Array.hpp"

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main() {
    try {
        std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;
	
        std::cout << BLUE << "\n----------Int Test----------\n\n" << WHITE;
        std::cout << BLUE << "\n---Default Array---\n\n" << WHITE;
        Array<int> testDefault;
        std::cout << "testDefault size: " << testDefault.size() << std::endl;

        std::cout << BLUE << "\n---N Elements Array---\n\n" << WHITE;
        unsigned int n = 6;
        Array<int> testA(n);
        std::cout << "testA size: " << testA.size() << std::endl;
        std::cout << "testA array: ";
        for (unsigned int i = 0; i < testA.size(); i++)
            std::cout << testA[i] << " ";

        std::cout << "\n\nChange elements in array testA" << std::endl;
        for (unsigned int i = 0; i < testA.size(); i++)
            testA[i] = (i + 5) * i;
        std::cout << "testA array after changing: ";
        for (unsigned int i = 0; i < testA.size(); i++)
            std::cout << testA[i] << " ";

        std::cout << BLUE << "\n\n---Copy Array---\n\n" << WHITE;
        Array<int> testB(testA);
        testDefault = testB;

        std::cout << "testB use copy constructor to copy from testA" << std::endl;
        std::cout << "testB size: " << testB.size() << std::endl;
        std::cout << "testB array: ";
        for (unsigned int i = 0; i < testB.size(); i++)
            std::cout << testB[i] << " ";
        std::cout << "\n\ntestDefault use copy operator to copy form testB" << std::endl;
        std::cout << "testDefault size: " << testDefault.size() << std::endl;
        std::cout << "testDefault array: ";
        for (unsigned int i = 0; i < testDefault.size(); i++)
            std::cout << testDefault[i] << " ";

        std::cout << "\n\nChange elements in array testB and testDefault" << std::endl;
        for (unsigned int i = 0; i < testB.size(); i++)
            testB[i] *= 2;
        for (unsigned int i = 0; i < testDefault.size(); i++)
            testDefault[i] /= 2;

        std::cout << "testA array after changing: ";
        for (unsigned int i = 0; i < testA.size(); i++)
            std::cout << testA[i] << " ";
        std::cout << "\ntestB array after changing: ";
        for (unsigned int i = 0; i < testB.size(); i++)
            std::cout << testB[i] << " ";
        std::cout << "\ntestDefault array after changing: ";
        for (unsigned int i = 0; i < testDefault.size(); i++)
            std::cout << testDefault[i] << " ";
        
        // std::cout << BLUE << "\n\n---Out of range test---\n\n" << WHITE;
        // std::cout << testB[testB.size() + 1];

        std::cout << BLUE << "\n\n----------Double Test----------\n\n" << WHITE;
        Array<double> testC(5);
        for (unsigned int i = 0; i < testC.size(); i++)
            testC[i] = 4.2f * (i + 1);
        std::cout << "testC array after changing: ";
        for (unsigned int i = 0; i < testC.size(); i++)
            std::cout << testC[i] << " ";

        std::cout << BLUE << "\n\n----------String Test----------\n\n" << WHITE;
        Array<std::string> testD(3);
        testD[0] = "cpp";
        testD[1] = "module 07";
        testD[2] = "ex02";
        std::cout << "string array testD: ";
        for (unsigned int i = 0; i < testD.size(); i++)
            std::cout << testD[i] << " ";
    
        std::cout << BLUE << "\n\n----------Testing Done----------\n\n" << WHITE;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
	return (0);
}
