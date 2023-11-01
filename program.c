//Programming Porject 2
//Author: Leon Magbanua
#include <stdio.h>
#include <string.h>

#define FILENAME "Programming-Project-2.txt"
#define ARRAY_MAX 20

//Function Declarations
signed int doMath(char operate[], signed int firstNum, signed int secondNum);
void nz(int* n, int* z, signed int result);
void display(char command[], signed int operandFirst, signed int operateSecond, signed int result, int* negative, int* zero);

//Main
int main(){
    FILE* dataFile;
    signed int operand1, operand2, operand3;
    int negative = 0, zero = 0;     //for intially setting N and Z
    char operation[ARRAY_MAX];
    dataFile = fopen(FILENAME, "r");

    //reads from file
    if (dataFile == NULL){
		printf("Issue opening file.\n");
	}else{
        while(fscanf(dataFile, "%s %X %X", operation, &operand1, &operand2) != EOF){
            operand3 = doMath(operation, operand1, operand2);
            display(operation, operand1, operand2, operand3, &negative, &zero);
        }
    }
    fclose(dataFile);

    return 0;
}

//Function Definitions
signed int doMath(char operate[], signed int firstNum, signed int secondNum){
    signed int result = 0x0;
    if((strcmp(operate, "ADD") == 0)||(strcmp(operate, "ADDS") == 0)) result = firstNum + secondNum;        //ADDing
    else if((strcmp(operate, "AND") == 0)||(strcmp(operate, "ANDS") == 0)) result = firstNum & secondNum;   //AND
    else if((strcmp(operate, "ASR") == 0)||(strcmp(operate, "ASRS") == 0)) result = firstNum >>= secondNum; //Arithmetic Shift Right
    else if((strcmp(operate, "LSR") == 0)||(strcmp(operate, "LSRS") == 0)) result = firstNum >> secondNum;  //Logical Shift Right
    else if((strcmp(operate, "LSL") == 0)||(strcmp(operate, "LSLS") == 0)) result = firstNum << secondNum;  //Logical Shift Left
    else if((strcmp(operate, "NOT") == 0)||(strcmp(operate, "NOTS") == 0)) result = ~firstNum;              //NOT
    else if((strcmp(operate, "ORR") == 0)||(strcmp(operate, "ORRS") == 0)) result = firstNum | secondNum;   //OR
    else if((strcmp(operate, "SUB") == 0)||(strcmp(operate, "SUBS") == 0)) result = firstNum - secondNum;   //SUBtracting
    else if((strcmp(operate, "XOR") == 0)||(strcmp(operate, "XORS") == 0)) result = firstNum ^ secondNum;   //eXclusive OR
    else printf("Error! \n");   //error
    
    return result;
}

void nz(int* n, int* z, signed int answer){
    *n = 0;
    *z = 0;
    if(answer < 0x0) *n = 1;    //if answer MSB = 1 aka negative
    if(answer == 0x0) *z = 1;   //if answer = 0
}

void display(char command[], signed int operandFirst, signed int operateSecond, signed int result, int* negative, int* zero){
    if((strcmp(command, "NOT") == 0)||(strcmp(command, "NOTS") == 0)) printf("%s 0x%08X: 0x%08X \n", command, operandFirst, result);    //in case of NOT
    else printf("%s 0x%08X 0x%08X: 0x%08X \n", command, operandFirst, operateSecond, result);   //any other operation

    if(command[3] == 'S') nz(negative, zero, result);   //if affecting flags
    printf("N: <%X> Z:<%X> \n", *negative, *zero);
}