void swap(int &a, int &b) {
    int c=a; a=b; b=c;
}

template <class T>
T gcf(T a, T b) {
    a = abs(a);
    b = abs(b);
    if (a<b) swap(a, b);
    while (b!=0) { a=a-b; if (a<b) swap(a, b); }
    return a;
}

template <class T> T lcm(T a, T b) {
    return (a/gcf(a, b))*b;
}