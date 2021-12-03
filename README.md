# OS-assignment-2
 OS assignment for banker's algorithm

### 1.	First, find the NEED by Max – Allocation.
><7 5 3> - <0 1 0> = <7 4 3>
>
><3 2 2> - <2 0 0> = <1 2 2>
>
><9 0 2> - <3 0 2> = <6 0 0>
>
><2 2 2> - <2 1 1> = <0 1 1>
>
><4 3 3> - <0 0 2> = <4 3 1>

NEED = {{ 7, 4, 3},
	{1, 2, 2},
	{6, 0, 0},
	{0, 1, 1},
	{4, 3, 1}};

### 2.	Then, determine the Safe Sequence by Available + Allocation = New Available. If True, then the process is kept in safe sequence. If false, then the process must wait.

>NEED = {{ 7, 4, 3}, <= <3 3 2> = F
>
>	{1, 2, 2},   <= <5 3 2> = T 
>	
>	{6, 0, 0},   <= <5 3 2> = F
>	
>	{0, 1, 1},   <= <7 4 3> = T
>	
>	{4, 3, 1}};  <= <7 4 3> = T

P0 and P2 are false and need to be revisited with New Available:

>P0 <7 4 5> + <0 1 0> = <7 5 5>;	<7 4 3> <= <7 4 5> = T
>
>P2 <7 5 5> + <3 0 2> = <10 5 7>; <1 2 2> <= <10 5 7> = T

### 3.	The system is in safe state. The safe sequence is:

P1, P3, P4, P0, P2

When examined, P0 and P2 resulted in false, therefore are in wait until the end (P0 then P2).

# matrix.txt

The data file contains matrices from the given example:

>010200302211002
>
>753322902222433
>
>332
