# Programming Project 2
**CS 219 - Computer Organization**

**Programming Project by Leon Magbanua**

# Information on Code
## How to run Code
Program executable should already be included in .ZIP file as **program2**. To run, simply type the command **./program2** to run. If executable is not present, type **gcc program.c -o program2** and follow with the command.

## Code Working Process
The code works by first detecting capabilities to read the text file. If able to, it will loop the following actions until the end of the text file:
1. The operation name, first operand, and second operand are all sent into variables within the program.

2. A function is then called that, based on the operation name, will perform the respective math between the operands and return it into a separate third variable.

3. Once the result is calculated, a function for displaying is called that displays the *operation*, *initial two operands*, and the *result*.

4. Immediately following this initial display, a final function for checking overflow is called. This is done by comparing the operands to the result. Addition (unsigned at least) assumes that the result will be greater than the operands. Hence **if the result is identified to be less than the initial operands**, overflow is declared and displayed.

