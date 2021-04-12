/* Utility functions  for the TINY compiler */

#ifndef _UTIL_H_
#define _UTIL_H_

/* Procedure printToken prints a token
and its lexeme to the listing file
*/
void printToken( TokenType, const char*);

/*Function newStmtNode creates a new statement
node for syntax tree construction
*/
TreeNode * newStmtNode( StmtKind);

/* Funtion newExpNode creates new expression
node for syntax tree construction
*/
TreeNode * newExpNode( ExpKind);

/* Function copyString allocates and make
a new copy of existing string
*/
char * copyString(char *);

/* procedure printTree prints a syntax tree to the
listing file using identation to indicate subtrees
*/
void printTree( TreeNode *);

#endif