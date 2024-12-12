# EECS 348 Fall 2024 Term Project

[![Compilation](https://github.com/alesan99/eecs348project/actions/workflows/makefile.yml/badge.svg)](https://github.com/alesan99/eecs348project/actions/workflows/makefile.yml)
[![Tests](https://github.com/alesan99/eecs348project/actions/workflows/run_tests.yml/badge.svg)](https://github.com/alesan99/eecs348project/actions/workflows/run_tests.yml)

### Team: Math Olympiads

### Arithmetic Expression Evaluator

Goal: Develop an arithmetic expression evaluator using C++.

* Parse and evaluate expressions
* Handle multiple operators (+, -, *, /, ^)
* Interpret parentheses to aid with grouping and precedence

## Building from Source

Ensure you have make (>=4.3) and your C++ compiler of choice installed. This project was designed with
g++ (>=11.4) in mind.
If not using g++, be sure to edit the Makefile to point to your compiler of choice.

Once your build environment is set up:

```shell
make setup && make release
./bin/AEE_release
```

## Repository Structure

```
eecs348project
  -artifacts
    (Contains each project artifact in PDF format)
  -notes
    (Contains meeting notes and notes template)
  Makefile
  -src
    (Contains source and header files)