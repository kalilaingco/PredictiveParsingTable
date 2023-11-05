# PredictiveParsingTable
will either accept or reject a given string based on determined language using a predictive parsing table. Created for my compilers & languages class

Problem: Given the following CFG and the Predictive Parsing table. Write a program to trace
input strings (1) (i+i)*i$ ,(2) i*(i-i)$ , (3) i(i+i)$ . Show the content of the stack after each
match.

Grammar:
E -> E+T
E -> E-T
E -> T
T -> T*F
T -> T/F
T -> F
F -> i
F -> (E)

Predictive Parsing Table:
[E,i] = TQ
[E,(] = TQ
[Q,+] = +TQ
[Q,-] = -TQ
[Q,)] = lambda
[Q,$] = lambda/accepted
[T,i] = FR
[T,(] = FR
[R,+] = lambda
[R,-] = lambda
[R, *] = *FR
[R,/] = /FR
[R,)] = lambda
[R, $] = lambda/ accepted
[F,i] = i
[F, (] = (E)
