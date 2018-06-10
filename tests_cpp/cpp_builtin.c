#define do_stuff(a,b) { kfree(a); a = b; }

void bar() {
 {
  kfree(a);
  a = b;
 }
 kfree(a);
}

void foo() {
 do_stuff(a,b)
  kfree(a);
}
