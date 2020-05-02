  bool isPowerOfTwo(long long int x)
    {
        // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
        return (x && !(x & (x - 1)));
    }

    int main()
    {
        cout<<isPowerOfTwo(4)<<endl;
        cout<<isPowerOfTwo(23)<<endl;
        return 0;
    }
