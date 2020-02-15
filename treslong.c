#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* tab; 
    int n;
    int capa;
}treslong;

treslong* newNbr0(int capa)
{
    treslong* t = (treslong*)malloc(sizeof(treslong));
    t->n = 1;
    t->capa = capa;
    t->tab = (char*)malloc(t->capa * sizeof(char));
    t->tab[0] = 0;
    return t;
}

treslong* sum(treslong* a, treslong* b)
{
    if(a->n > b->n) return sum(b,a);
    
    treslong* r = newNbr0(b->n + 1);
    
    //affiche(r);
    
    int retenue = 0;
    int i;
    for(i=0; i<a->n; i++)
    {
        int x = a->tab[i] + b->tab[i] + retenue;
        r->tab[i] = x % 10;
        retenue = x / 10;
    }
    
    for(; i<b->n; i++)
    {
        int x = b->tab[i] + retenue;
        r->tab[i] = x % 10;
        retenue = x / 10;
    }
    
    if(retenue)
    {
        r->tab[i] = 1;
        i++;
    }
    
    r->n = i;
    
    return r;
}
