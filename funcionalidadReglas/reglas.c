#include <stdio.h>

void reglas() {
  FILE *reglas = fopen("reglas.txt", "r");
  
  if(!reglas){
    printf("No he podido abrir el archivo");
    return 1;
  }
  char buffer[2433];
  do{
    if(fgets(buffer, 2433, reglas)){
    printf("%s", buffer);
  }
  }while(!feof(reglas));
  
  fclose(reglas);
}