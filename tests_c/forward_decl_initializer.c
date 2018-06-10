struct foo { int a; };

struct foo xxx; /* = { 0 }; this will cause a warning. */

int a() {
  printf ("in a: %d\n", xxx.a);
  xxx.a = 12;
}

struct foo xxx = { 15 };

int main () {
  a();
  printf ("after a: %d\n", xxx.a);
}


