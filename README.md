# AbstractVM

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What you need to run this project is C++11

### Installing

To install you'll have to clone the project to your local machine

Step 1: Clone the project
```
git clone https://github.com/amatshiye/Abstract_VM
```
Step 2: Go inside the cloned repo
```
cd Abstract_VM
```

Step 3: Compile the project
```
make
```

To recompile the project use this command:
```
make re
```

## Running the tests

There are two ways to test the program. Either you pass a file to the program or you use the default mode (STDIN) to test it.

### Testing using the default mode

To use the default mode follow these instructions:

Step 1: Run the program

```
./avm (With no arguments or else it will fail)
```

Step 2: Input instructions

for example:
```
push int8(100)
push int32(20)
dump
add
exit;; (Add the double semi-colon and press enter to execute your instructions)
```


### Testing using the file mode

To use the file mode follow these instructions:

Step 1: Create text file (You can use any editor you want)

```
touch test.txt (Creating a file using a terminal)
```

Step 2: Write the following instructions inside the text file

```
push int8(100)
push int32(20)
dump
add
exit (This time around you don't need the double semi-colon)
```

## Built With

* [Visual Studio Code](https://code.visualstudio.com/) - The Code editor
* [iTerm](https://www.iterm2.com/) - A cool terminal for MacOS

## Authors

* **Afrika Matshiye** - [Github](https://github.com/amatshiye)

## Acknowledgments

* **Yan Chernikov** - [YouTube](https://www.youtube.com/channel/UCQ-W1KE9EYfdxhL6S4twUNw)