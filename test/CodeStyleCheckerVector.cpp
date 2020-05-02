// RUN: clang++ -Xclang -load -Xclang %shlibdir/libCodeStyleChecker%shlibext -Xclang -plugin -Xclang code-style-checker -c %s

#include <vector>

// There's no straightforward way to write a test for any STL header so that it
// works reliably across different platforms. Indeed - the expected output
// depends on the actual implementation of the header file.
//
// Instead, this test makes sure that this translation unit is processed
// successfully (i.e. the plugin does not crash).
