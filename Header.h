#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <cstdlib>

using std::setw;

struct tree{
    int id;
    int weight;
    tree *left, *right;
};

void swap(int *a,int *b);

void add(tree *&t,int x,int w);

tree* build();

void printpre(tree *t);

int search(tree *t,tree *&par,tree *&ptr,int x,int &l);

void Delete(tree *&t,int x);

void individual(tree *t,int w,int lev,int curlev);

void printin(tree *t,int n);

#endif // HEADER_H_INCLUDED
