CIRCUITS-PROJECT " CMP-FALL-2018 "
It is a CAD SIMULATOR FOR (AC-CIRCUITS)
========================================================================================================
Notes:
1-first you have to enter number of nodes including the reference node (ground)
2-to enter any element follow the following steps :
	- enter a character representing the element { "V or v" for voltage source - "L or l" for inductor - "C or c" for capacitor - "R or r" for resistor }
	- enter the nodes of the elements but you sholud enter the smaller node firs like {don't enter --> (V 3 0 ) but enter --> (V 0 3)}
	- after that enter the value of the element { for R in [ohm] and L in [H] and C in [F] }
	- incase of voltage source enter the phase after the value 
	- all the above inputs should be separated by spaces and every element in a single line with its numbers 
3-to stop the inputs and display the output enter q letter 
4-the value of the frequency ( w "omega" ) is 50 
5-the output will be diplayed in the form of : 
	-the current and the voltage between between every tow nodes of any element
========================================================================================================
sample input :
enter number of nodes: 4
V 0 1 10 30 
L 1 2 0.001
C 2 3 0.0001
R 0 3 10
q
---------------------------
sample output :
the voltage between nodes 0 1 is : 8.661 + 4.9977J
the current  between nodes 0 1 is : -0.0227713 + 0.0444576J 
the voltage between nodes 0 3 is : -0.227713 + 0.444576J 
the current  between nodes 0 3 is : -0.0227713 + 0.0444576J 
the voltage between nodes 1 2 is : -0.0022 + -0.0011J
the current  between nodes 1 2 is : -0.0227713 + 0.0444576J 
the voltage between nodes 2 3 is : 8.891 + 4.554J
the current  between nodes 2 3 is : -0.0227713 + 0.0444576J 