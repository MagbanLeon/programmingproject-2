# Programming Project 2
**CS 219 - Computer Organization**

**Programming Project by Leon Magbanua**

# Information on Code
## How to run Code
Program executable should already be included in .ZIP file as **program2**. To run, simply type the command **./program2** to run. If executable is not present, type **gcc program.c -o program2** and follow with the command.

## Code Working Process
The code works by first detecting capabilities to read the text file. If able to, it will loop the following actions until the end of the text file:
1. The operation name, first operand, and second operand are all sent into variables within the program.

2. A function is then called that will compare the operation name against a cases of already established commands, (ADD, AND, ASR, LSR, LSL, NOT, ORR, SUB, XOR, and their variants with **S** at the), throwing out an error otherwise.

3. Once the operation is identified, the function will run that specfic case and that mathematicla operation associated with it (ex. identifying SUB or SUBS will perform subtraction between the two operands).

4. After the result is calculated, it is returned to a third operand responsible for holding results.  Then a function for displaying is called that displays the *operation*, *initial two operands*, and the *result* (in the case of the NOT operation, only the first operand and result are displayed).

5. Immediately following this initial display, a line of code checks the 4th letter of the operation name to determine if an **S** is present. If so, then a function is called to set the N and Z flags.

6. a final function for checking the N and Z flag is called. This is done by comparing the result to the value of 0. If the number is exactly