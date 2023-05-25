# optim_miniproprocessor
Optimizare Microprocesor
#TEAM
Dobre Maria-Adina
Chiorean Alexandru

#TITLE
Optimized Miniprocessor in C: Basic processor that decodes a bit string and executes it.

#NOTE:
EACH TASK CAN BE INDIVIDUAL

#DESCRIPTION
task1 - Decode Instructions

N represents the number of instructions to be executed, encoded in 3 bits. It is obtained by converting the most significant 3 bits from binary to decimal and adding 1. For example, 000 corresponds to 1 instruction, and 010 corresponds to 3 instructions. The maximum number of instructions is 8.
Op represents the code of an instruction and is encoded in 2 bits. Op can be +, -, *, or / according to the table below:
Code Operation
00 +
01 -
10 *
11 /

In the input bit string, the 3 bits representing the number of operations are followed by N*2 bits representing the operations to be executed.

Dim represents the size of an operand and is encoded in 4 bits. Dim is calculated similarly to N by converting the least significant 4 bits to decimal and adding 1. Thus, the size of operands can take values from the range [1, 16].
In this exercise, you will read an unsigned int number from standard input that contains the encoded instruction and decode it. Then, you will print N, the operators, and the size of operands, all separated by a space.

Example:
Input: 1675493376 → Output: 4 + - / * 16

Input: 2483421184 → Output: 5 * * + + + 13

task2 - Read Operands

Read the operands. Building upon the previous program, add a code section that interprets (N+1) operands from standard input. For this task, the size of operands (Dim) is a power of 2 from the range [1, 16]. The operands will be read as unsigned short numbers (16-bit size) from standard input. The number of operands to be read from the keyboard is decomposed into multiple unsigned shorts using the formula: ((N+1)*Dim)/16, adding +1 if there is a remainder. Thus, ((N+1)*Dim)/16 numbers will be read from the keyboard and decomposed into (N+1) operands.
Example:
For N = 3 and Dim = 4, using the instruction 1410859008, the output from Task 1 will be 3 * * + 4. According to the formula ((N+1)*Dim)/16, we will read a single unsigned short from the keyboard (((3+1)*4)/16 = 1). Let's assume we read 54999. Its binary value is: 1101 0110 1101 0111. In this case, the first operand will be 13, the second operand 6, the third operand 13, and the fourth operand 7.

If N = 4 and Dim = 8, using the instruction 1947074560, the output from Task 1 will be 4 * * + + 8. Therefore, we will read 3 unsigned shorts from the keyboard (((4+1)*8)/16 = 2.5). Let's assume we read 54998 (11010110 11010110), 64041 (11111010 00101001), and 42752 (10100111 00000000). In this case, the first operand will be 214, the second operand 214, the third operand 250, the fourth operand 41, and the fifth operand 167, followed by padding bits.
TASK 2

To solve this task, we need to execute instructions with both operators and operands. The result will be calculated in the order of the received operations, disregarding operator precedence (i.e., * does not have precedence over +).

Example:
If we have the operations + - * + and operands 1 2 3 4 5, the calculation would be 1 + 2 - 3 * 4 + 5 = 5 (1 + 2 = 3 - 3 = 0 * 4 = 0 + 5 = 5).

For this task, we will read the instruction and operands from the keyboard and display the result.

Example usage:
./task1
1410859008
3 * * + 4
Number of inputs = 1
Enter number: 54999
Operands: 13 6 13 7
Result: 1021
or

./task1
1947074560
4 * * + + 8
Number of inputs = 3
Enter number: 54998
64041
42752
Operands: 214 214 250 41 167 0 0 0 0 0
Result: 11449208

TASK 3

In this task, we will extend the implementation from Task 2 to execute instructions with operands of any size within the range [1, 16]. The operands will still be read from standard input as unsigned shorts, but an operand might span over 2 successive readings.

TASK 4

Implement operator precedence, so that * and / have equal precedence but higher precedence than + and -.

#INITIAL_PROJECT

TASK 1
For this task, we converted the unsigned int number to its binary form and stored it in a vector using repeated divisions by 2. Since we stored the remainders in the vector in the order of the divisions, the binary form of the given number is reversed. Therefore, we iterate over the vector in reverse order. The last 3 bits represent the number N, which is then converted to base 10. Next, we iterate over the bit vector, taking 2 bits at a time, and based on their values, we display the operation signs. The last 4 bits represent the operand size, and their value is also converted to base 10.

TASK 2
Using the solution from the previous task, we calculate how many additional numbers need to be read based on the given formula. Instead of displaying the operations, they are stored in a vector. Knowing that the operations are stored in 16 bits, we create another vector to store the binary codes of the input numbers. Thus, their values are concatenated, allowing us to access the desired number of bits for operands' dimensions. Although this task assumes operand sizes are powers of 2, making the 16-bit space flexible and intuitive, this solution can handle operands with arbitrary sizes (i.e., non-powers of 2) as well. The input numbers are converted to base 2 and then concatenated, using the dimension itself as the separator. Finally, the program divides the resulting vector into N+2 sections, each of length equal to the operand size. The first N+1 sections are converted to base 10 and stored in another vector, while the last section (if it exists) is ignored. Then, the program simultaneously iterates over the operations vector and the operands vector. At each operation, the next operand receives the result of the operation between it and the current operand, and the desired result is displayed at the end of the iteration.

TASK 3
Same code as Task 2, explained above.

TASK 4
Essentially, we have the same code as in the previous task, but unlike before, the final iteration over the two vectors is done twice. The first iteration eliminates the high-priority operations by replacing the current element with the result of the operation between it and the next element, shifting the following elements one position to the left. The second iteration is similar to the previous tasks, replacing the next element with the result of the operation between it and the current operand, and the desired result is displayed at the end of the iteration.

INEFFICIENCY
The above implementation is inefficient due to the complete lack of bit operations or dynamic allocation. Although it eventually yields the correct result, this solution is specific to a high school level and will be optimized.
#OPTIMIZATION

We will optimize the code by using bitwise operations. We will modularize the code by creating relevant functions and organizing them into separate folders named "src" and "checker". Additionally, we will create multiple files for better clarity. Instead of storing bits in vectors, we will utilize bitwise operations.

#TASK_MANAGEMENT

Maria:

Optimization using bits: Task 2 and Task 3.
Modularization: Task 2 and Task 3.

Alex:

Optimization using bits: Task 1 and Task 4.
Modularization: Task 1 and Task 4.

#GIT REPO

https://github.com/mariad765/optim_microprocessor
