# Programming Project 2
**CS 219 - Computer Organization**

**Programming Project by Leon Magbanua**

# Information on Code
## How to run Code
Program executable should already be included in .ZIP file as **program2**. To run, simply type the command **./program2** to run. If executable is not present, type **gcc program.c -o program2** and follow with the command.

## Code Working Process
The code works by first detecting capabilities to read the text file. If able to, it will loop the following actions until the end of the text file:
1. The operation name, first operand, and second operand are all sent into variables within the program. The flags for Negative and Zero are also set to 0 by default.

2. A function is then called that will compare the operation name against a cases of already established commands, (ADD, AND, ASR, LSR, LSL, NOT, ORR, SUB, XOR, and their variants with **S** at the), throwing out an error otherwise.

3. Once the operation is identified, the function will run that specfic case and that mathematicla operation associated with it (ex. identifying SUB or SUBS will perform subtraction between the two operands).

4. After the result is calculated, it is returned to a third variable responsible for holding the result.  Then a function for displaying is called that displays the *operation*, *initial two operands*, and the *result* (in the case of the NOT operation, only the first operand and result are displayed).
```CMD op1 op2: result```

5. Immediately following this initial display, a line of code checks the 4th letter of the operation name to determine if an **S** is present. If so, then a function is called to manage the N and Z flags.

6. When called, a final function for checking the N and Z flag is performed. The flags are intially set to zero and checks are performed to set them to 1. This is done by comparing the result to the value of 0. If the number is exactly 0, then the Zero flag is set to 1. If the result is less than decimal 0 (i.e. leading with an MSB of 1), then the Negative flag is set to 1.

7. Once this function for checking flags is (or is NOT) performed, another display output  presents the flags as either updated or the same as the last set flag values (assuming not **S** was present to change the flags).
```
CMD op1 op2: result
N:<0/1> Z:<0/1>
```