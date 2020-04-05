# Trie

This repository contains a C++ class that implements a trie.

A Trie is a data structure that saves memory by efficiently storing sequences of characters in a way such that overlapping characters (in the same position) in the beginning of the sequence can share the same char in RAM. For example, "apple" and "apricot" are two distinct words, but they both share the initial sequence "ap". 

In addition to the memory efficiency, searching for sequences of characters using a trie data structure can be more time efficient than if the sequences (words) were stored separately.

A tutorial explaining how tries work and the 
process of building/updating/querying one can be found [here](https://www.srcmake.com/home/tries).

## File Structure

- Makefile contains the commands to build/run the codebase.
- src/trie.hpp contains a class definition for our Trie code, as well as code for the Trie methods.
- src/main.cpp contains some driver code to instantiate our Trie class and test that the methods work correctly.

## Deployment

The `Makefile` will compile the project with C++14 (the version was chosen arbitrarily,
we're not really using any special language features). 

On Linux/Mac, as long as you have GCC, the following command will compile and run the project.

```
make
```

## LICENSE

This code is licensed under the MIT License. 