#define ABS(x)  ((x>=0) ? (x) : (-x));

#define MAX(x,y) (x>y ? x : y);

#define COLOR( f, b) (cout << "\033[1;3"<< (f) \
<<";4"<< (b) <<'m' << flush)