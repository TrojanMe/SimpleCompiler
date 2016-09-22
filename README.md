# Simple Compiler


![N|Solid](https://raw.githubusercontent.com/fsharp/FSharp.Compiler.Service/master/misc/logo.png)

###	1. Introduction

The purpose of this course is to construct a very simple compiler. In the first step to do so, there is an implementation of symbol-table. 
A symbol-table is a data structure maintained by compilers in order to store information about the occurrence of various entities such as identifiers, objects, function names etc. Information of different entities may include type, value, scope etc. At the first phase,a symbol-table based on hashing where collision is resolved by chaining is constructed. Figure 1 illustrates a sample symbol table.

![N|Solid](http://i.imgur.com/cjlRGQm.png)

### 2. Tasks

Following two classes are implemented:

- SymbolInfo: This class contains the information regarding a symbol faced in the source program. In the first step ,it is limited to only two members. One is for the Name of the symbol and other is the Type of the symbol. This class may extend as we progress to develop the compiler.
- SymbolTable: This class implements the hash table. Array of pointers and a hashFunction are used. 
  
Then the following four functions are implemented : 

*	Insert: Insert into symbol table if already not inserted.
*	Look up: Search the hash table for particular symbol.
*	Delete: Delete an entry from the symbol table.
*	Print: Print the whole symbol table in the console.


![N|Solid](http://i.imgur.com/IoIRsir.png)	


### 3. Input

Each line of the input starts with a code letter indicating the operation to perform. The letters are among ’I’, ’L’, ’D’ and ’P’. ’I’ stands for insert which is followed by two space with separated strings where the first one is symbol name and the second one is symbol type. As you might already guessed symbol name will be the key of the record to be stored in the symbol-table. ’L’ means lookup which is followed by a string containing the symbol to be looked up in the table. ’D’ stands for delete which is also followed by a string to be deleted. At last, ’P’ stands for printing the symbol table. (Reference - Table 1)

### 4. Important Notes

This instructions listed below were followed while implementing the task as instructed :

*	Implemented using C++ programming language
*	Hard coding was avoided
*	'Dynamic memory allocation' was used
*	Input was taken from file (input.txt) 

### ** Extras :

The main problem statement for the "symbolTable task" can be found on this link - https://goo.gl/Nz1Avu 




