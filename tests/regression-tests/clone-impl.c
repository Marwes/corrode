struct Test
{
    int x[100];
};

int main()
{
    struct Test x = {};
    x.x[50] = 123;
    struct Test y = x;
    return y.x[50];
}
