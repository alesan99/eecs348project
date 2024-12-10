# EECS 348 Fall 2024 Term Project

### Team: Math Olympiads

### Arithmetic Expression Evaluator

Goal: Develop an arithmetic expression evaluator using C++.

* Parse and evaluate expressions
* Handle multiple operators (+, -, *, /, **)
* Interpret parantheses to aid with grouping and precedence

## Building from Source

Ensure you have make (>=4.3) and your C++ compiler of choice installed. This project was designed with
g++ (>=11.4) in mind.

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