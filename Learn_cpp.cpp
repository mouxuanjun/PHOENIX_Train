#include <cstdio>

class Cubic {
    public:
    int length;
    int width;
    int height;

    void Init(int __length,int __width,int __height) {
        length = __length;
        width = __width;
        height = __height;
    }
    void PrintInfo() {
        printf("length:%d,width:%d,height:%d\n",length,width,height);
    }
};

class Cubic_Volume : public Cubic {
    public:
    int volume;

    void PrintInfo() {
        volume = length * width * height;
        printf("length:%d,width:%d,height:%d,volume;%d\n",length,width,height,volume);
    }
};

int main() {
    Cubic_Volume cubic1;
    cubic1.Init(3,4,5);
    cubic1.PrintInfo();
}
