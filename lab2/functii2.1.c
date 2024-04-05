# include <stdio.h>
# include <stdlib.h>
# include <string.h>
typedef struct{
  int nota;
  char nume[30];
}Student;

int conditie(const void *e1, const void *e2){
  Student *elem1=(Student *)e1;
  Student *elem2=(Student *)e2;
  if (elem1->nota>elem2->nota) return -1;
  if (elem1->nota==elem2->nota){
    
    if (strcmp(elem1->nume,elem2->nume)<0)
      return -1;
    if (strcmp(elem1->nume,elem2->nume)>0)
      return 1;
  

    return 0;
}
  return 1;
}
int main(void){
  int n;
  scanf("%d", &n);
  Student s[n];
  for (int i=0; i<n; i++){
    scanf("%s %d", s[i].nume, &s[i].nota);

  }
  qsort(s,n,sizeof(Student),conditie);
  for (int i=0; i<n; i++){
    printf("%s %d\n", s[i].nume, s[i].nota);
  }
  
  return 0;
}
