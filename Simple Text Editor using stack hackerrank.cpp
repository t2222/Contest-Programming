/*
link: https://www.hackerrank.com/challenges/simple-text-editor/problem

undo:

	1. store all operation sequences in stack,
	2. store all deleted texts in stack,

deletion:
	
	1. store deleted string in stack for retrieval,
	2. access top of stack, edit text and push it again. if top of stack string size exceeds then get the next top,
	3.

write:
	
	1. push to stack,

print:

	1. top of stack,
*/