#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    static int count;  

public:
    
    String() {
        str = new char[81];  
        str[0] = '\0';  
        count++;
    }

    String(size_t size) {
        str = new char[size + 1];  
        str[0] = '\0';  
        count++;
    }

    String(const char* input) {
        size_t len = strlen(input);
        str = new char[len + 1];  
        strcpy(str, input);
        count++;
    }

    ~String() {
        delete[] str;  
        count--;
    }

    void input() {
        std::cout << "Enter string: ";
        std::cin.getline(str, 81);  
    }

    void output() const {
        std::cout << "String: " << str << std::endl;
    }

    static int getCount() {
        return count;
    }
};

int String::count = 0;

int main() {
    String s1;  
    String s2(100);  
    String s3("Hello, world!");  

    s1.input();
    s1.output();

    s2.input();
    s2.output();

    s3.output();

    std::cout << "Number of String objects: " << String::getCount() << std::endl;

    return 0;
}
