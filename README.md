# C++ base dev. container

## Simple repository with basic C++ development utilities:
- clang-tidy
- clang-format
- clangd (autocompletion)
- debugger
- cmake

## C++ dependenices included:
- gtest, gmock

To test this repository, simply open this folder in a dev. container using vscode extension. 
You should be able to compile, debug and test right away using the cmake extension.


To enable clang-tidy, simply use `cmake .. -DUSE_CLANG_TIDY=ON` on build folder or as configure argument in cmake extension. (... or change cmake cache manually).
