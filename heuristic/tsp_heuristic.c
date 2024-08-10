#include "tools.h"
#include "tsp_brute_force.h"


//
//  TSP - HEURISTIQUES
//

void reverse(int *T, int p, int q) {
  // Renverse la partie T[p]...T[q] du tableau T avec p<q si
  // T={0,1,2,3,4,5,6} et p=2 et q=5, alors le nouveau tableau T sera
  // {0,1, 5,4,3,2, 6}.
  int z=0;
  for(int i=0;i<(q-p+1)/2;i++)
  {
    SWAP(T[p+i],T[q-i],z);
  }
   
 
  return;
}

double first_flip(point *V, int n, int *P) {
  // Renvoie le gain>0 du premier flip réalisable, tout en réalisant
  // le flip, et 0 s'il n'y en a pas.
  double gain=0.0;
  for(int i=0;i<n;i++)
   for(int j=i+2;j<n;j++)
     {
      gain=dist(V[P[i]],V[P[(i+1)%n]])+dist(V[P[j]],V[P[(j+1)%n]])-dist(V[P[i]],V[P[j]])-dist(V[P[(i+1)%n]],V[P[(j+1)%n]]);
      if(gain>0)
      {
       reverse(P,i+1,j);
       return gain;
     }
     }
     
  return 0.0;
}

double tsp_flip(point *V, int n, int *P) {
    //initialiser P
    for(int i = 0; i < n; i++) {
        P[i] = i;
    }

    //la longueur initale de la tournee
    double l = 0.0;
    for(int i = 0; i < n - 1; i++) {
        l += dist(V[P[i]], V[P[i+1]]);
    }

    //on essaye d'ameliorer la longueur
    double gain;
    do {
        gain = first_flip(V, n, P);
        if(gain > 0.0) {
            l -= gain; 
            drawTour(V, n, P); 
        }
    } while(gain > 0.0 && running);

    return l;
}


double tsp_greedy(point *V, int n, int *P) {
  // La fonction doit renvoyer la valeur de la tournée obtenue. Pensez
  // à initialiser P, par exemple à P[i]=i.

   //initialiser P
  for(int i=0;i<n;i++)
  {
    P[i]=i;
  }
  bool *add=malloc(n*sizeof(bool));
  for(int i=0;i<n;i++)
  {
    add[i]=false;
  }
  //calculer la longueur avec l'algo glouton
  double l=0.0;
  double d;
  int p_curent=0;
  add[p_curent]=true;
  int m=1,succ;
  
  while(m<n)
  {
    d=DBL_MAX;
    for(int i=1;i<n;i++)
    {
      //on verifie si la nouvelle distance est min et si la ville n'est pas deja dans le circuit
         if(dist(V[p_curent],V[i])<d&&add[i]==false)
        {
          d=dist(V[p_curent],V[i]);
          succ=i;
        }
       
    }
    //on mise a jour le tableau P avec la nouvelle ville
    P[m]=succ;
    //on mise a jour le status de la nouvelle ville parce qu'elle est dans le circuit
    add[succ]=true;
    //on incremente le no des ville dans le circuit
    m++;
    //on mise a jour la ville courante
    p_curent=succ;
    l+=d;
    drawTour(V,n,P);

  }
  return l;
}
