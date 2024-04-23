# DSA-programming-activity

## Prerequisites

Make sure GCC is installed. Version GCC 11.4.0 or later is recommended.

## Compilation and Execution

### Linear Search

1. Navigate to the directory `team09_AE2`. Copy your driver file to `team09_AE2` and compile the files with GCC
```
gcc driver.c cset_ls.c
```

2. run the executable with the following command to test its functions
```
.\a.exe
```

### Hash-Table

1. Navigate to the directory `team09_AE2`. Copy your driver file to `team09_AE2` and compile the files with GCC
```
gcc driver.c cset.c
```

2. run the executable with the following command to test its functions
```
.\a.exe
```

## Usage

The APIs implements a data structure `CodeSet`, which allows users to store distinct codes (assumed to be positive integers not larger than 9*10^18) and make sure there are no duplicates. It supports the following functions:
`cset_init`: initializes an empty CodeSet.
`cset_destroy`: destroy the CodeSet and free its memory.
`cset_insert`: insert the given code into CodeSet.
`cset_remove`: remove the given code if it is present in the CodeSet.
`cset_find`: returns true if the given code is present in the CodeSet.

The capacity of the data structure is 10^6.
