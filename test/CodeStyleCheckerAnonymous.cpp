// RUN: clang -cc1 -verify -load %shlibdir/libCodeStyleChecker%shlibext -plugin code-style-checker %s 2>&1

// 1. Verify that anonymous unions are not flagged as invalid (no name - nothing
// to check), but it's members names are indeed verified.

static union {
// expected-warning@+1 {{Type and variable names should start with upper-case letter}}
  int clangTutorBad;
  const char *ClangTutorOk;
};

// 2. Verify that anonymous function arguments not flagged as invalid (no name
// - nothing to check), but the function name's indeed checked.

void clangTutorFunc(void *);

// expected-warning@+1 {{Function names should start with lower-case letter}}
void ClangTutorFunc(void *);

// 3. Verify that anonymous bit-fields are not flagged as invalid (no name
// - nothing to check), but other fields' names are indeed checked.
struct ClangTutorStruct {
  unsigned short 
    // expected-warning@+1 {{Type and variable names should start with upper-case letter}}
    clangTutorBitFieldBad : 1,
    ClangTutorBitFieldOK  : 1,
                          : 1;
};
