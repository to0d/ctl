int foo(int x) {
    int* p1 = &x;
    int* p2 = &x;
    *p1 = 1;
    *p2 = 2;
    
    return x;
}

struct S1 { int i; long l; };

struct S2 { float f; double d; struct S1 s; };

int foo2(struct S1 *p1, struct S2 *p2) {
  p1->i = 1;
  p2->s.i = 2;
  return p1->i;
}