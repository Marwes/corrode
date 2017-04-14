#include <string.h>

int main(int argc, char** argv)
{
    if (argc != 2)
        return 2;
    return argv[1][0];
}