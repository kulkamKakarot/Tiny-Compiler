/*  Global types and vars for Tiny Compiler must
    come before other include files */

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/*MAXRESERVED = the number of reserved words */
#define MAXRESERVED 8

typedef enum
    /* book-keeping tokens*/
    {ENDFILE,ERROR,
    //reserved words
    IF,THEN,ELSE,END,REPEAT,UNTIL,READ,WRITE,
    //multicharacter tokens
    ID,NUM,
    //special symbols
    ASSIGN,EQ,LT,PLUS,MINUS,TIMES,OVER,LPAREN,RPAREN,SEMI
    }TokenType;

extern FILE* source;    //source code text file
extern FILE* listing;   //listing output text file
extern FILE* code;      //code text file for TM simulator

extern int lineno;  //source line number for listing

//  SYNTAX TREE FOR PARSING

typedef enum {StmtK,ExpK} NodeKind;
typedef enum {IfK,RepeatK,AssignK,ReadK,WriteK} StmtKind;
typedef enum {OpK,ConstK,IdK} ExpKind;

// ExpType is used for type checking
typedef enum {Void,Integer,Boolean} ExpType;

#define MAXCHILDREN 3

typedef struct treeNode{
    struct treeNode* child[MAXCHILDREN];
    struct treeNode* sibling;
    int lineno;
    NodeKind nodeking;
    union {StmtKind stmt; ExpKind exp;} kind;
    union {TokenType op; int val; char* name;} attr;
    ExpType type; 
} TreeNode;

//  FLAGS FOR TRACING


extern int EchoSource;

extern int TraceScan;

extern int TraceParse;

extern int TraceAnalyze;

extern int TraceCode;


#endif