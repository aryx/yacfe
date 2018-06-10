/*
On Tue, Jul 29, 2008 at 11:17:38PM +0400, Alexander Beregalov wrote:
> Hi
> 
> What is it a right way to fix these warnings?
> 
> smth function()
> {
> 	switch (var) {
> 	case one:
> 		return 1;
> 	default:
> 		BUG();
> 	}
> }
> 
> warning: control reaches end of non-void function

If BUG() would be normal function it could be marked as __attribute__((noreturn)).
But it's a macro defined differently depending on architecture and CONFIG_*.
Sometimes it calls panic() which is annotated properly and sometimes it calls
other code....

If you are brave, you could fix all implementations.
*/

int foo()
{
	int var = 2;
	switch (var) {
	case 1:
		return 1;
	default:
		BUG();
	}
}
