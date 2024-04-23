# QL-ram

Speed test for the QL ram.

Result on my Trump Card.

test function at 1020590		<- Function loaded high
main function at 1020794		<- Function loaded high

                      Speed
local var	199064	  L 342		<- Local variable loaded low
static var	1039030	H 267		<- Loaded high, faster
global var	1043126	H 267		<- Loaded high, faster

	Address   Speed
0	191284	L 343
1	185148	L 342
2	203212	L 342
<snip>
16	261020	L 289
17	265148	H 267
18	269276	H 266
19	273404	H 266
<snip>

So Memory >256k is 30% quicker (using my quick and dirty memory test)
