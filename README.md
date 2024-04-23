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

The APIs implement a data structure `CodeSet`, which allows users to store distinct codes (assumed to be positive integers smaller than 2^63) and make sure there are no duplicates. They support the following functions:
`cset_init`: initializes an empty CodeSet.
`cset_destroy`: deletes the CodeSet and free its memory.
`cset_insert`: inserts the given code into the CodeSet.
`cset_remove`: removes the given code if it is present in the CodeSet.
`cset_find`: returns true if the given code is present in the CodeSet.

The data structure can hold a maximum of 10^6 codes.
