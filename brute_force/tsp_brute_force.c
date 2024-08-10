#include "tools.h"
#include "float.h"

//
//  TSP - BRUTE-FORCE
//
// -> la structure "point" est définie dans "tools.h"
// -> tsp_main peut être testé dès les 3 premières fonctions codées
//

  double dist(point A, point B) {
  double a=A.x-B.x;
  double b=A.y-B.y;
  
  return sqrt(a*a+b*b);
}

double value(point *V, int n, int *P) {
  double distance= 0;

  for(int i=0;i < n-1; i++)
    distance=dist(V[P[i]],V[P[i+1]])+distance;

  //distance du retour
  distance += dist(V[P[n - 1]], V[P[0]]);
  return distance;
}

double tsp_brute_force(point *V, int n, int *Q) {
  int P[n];//pour stoquer les permutations
  //initialiser P a P[i]=i
  for(int i=0;i<n;i++)
      P[i]=i;

  //parcourir tous les permutations
  //une boucle ou on calcule tous les distances min

  double dmin=DBL_MAX;
  double d;
  do
  {
    d=value(V,n,P);
    if(d<dmin)
    {
      dmin=d;
      for(int i=0;i<n;i++)
       Q[i]=P[i]; //recopier P dans Q
    }
  } while (NextPermutation(P,n)&&running);
  

  return dmin;
}

void MaxPermutation(int *P, int n, int k) {
  int Q[n];

  //on recopie le prefix de P
  for(int i=0;i<k;i++)
   Q[i]=P[i];

  //on recopie les elements qui nous reste en P dans l'ordre inverse en Q
  int j=1;
  for(int i=k;i<n;i++)
  {
    Q[i]=P[n-j];
    j++;
  }
  
  //on recopie la permutation finale Q dans P
  for(int i=0;i<n;i++)
   P[i]=Q[i];

}

double value_opt(point *V, int n, int *P, double w) {
    double distance = 0;
    for (int i = 0; i < n - 1; i++) {
        distance += dist(V[P[i]], V[P[i + 1]]);
        if (distance > w)
            return -i-2;
    }
    // Ajouter la distance de retour
    distance += dist(V[P[n - 1]], V[P[0]]);
    return (distance <= w) ? distance : -n;
}

double tsp_brute_force_opt(point *V, int n, int *Q) {
    int P[n];//pour stoquer les permutations
    
  //initialiser P a P[i]=i
  for(int i=0;i<n;i++)
      P[i]=i;

  //parcourir juste les permutations qui ne depasse pas la dist opt deja trouve

  double dmin=DBL_MAX;
  do
  {
    //verifier si avec la configuration actuale on depasse dmin a partir d'une position (k)
    double k=value_opt(V,n,P,dmin);
    //si on depasse on saute les permutations avec cet prefix
    if(k<0)
     MaxPermutation(P,n,-k);

    //sinon on met a jour dmin et on recopie la permutation qui a donnee la nouvelle dist min
    else
    { 
      dmin=k;
      for(int i=0;i<n;i++)
       Q[i]=P[i]; //recopier P dans Q

    }
    
  } while (NextPermutation(P,n)&&running);
  
  return dmin;
}
