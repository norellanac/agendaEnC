#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct piloto
{
  char nombre[50];
  char nacionalidad[50];
  int puntos;
  int id;
};

int opcionMenu=0;
int noResgistroEditar=0;
char textoEntrada[50];
int cantidadRegistros=0;

void muestraPilotos (){
  FILE *archivoLeer;
  struct piloto leerEstructura;
  printf("\Registros guardados: \n");
  archivoLeer = fopen ("pilotos.dat", "r");
  if (archivoLeer == NULL)  {
    fprintf(stderr, "\nNo hay registros para leer, debe crear un piloto\n");
    exit (0);
  }

  while(fread(&leerEstructura, sizeof(struct piloto), 1, archivoLeer))
  printf ("Nombre:  %s nacionalidad:  %s, puntos: %d, , id: %d\n", leerEstructura.nombre,
  leerEstructura.nacionalidad, leerEstructura.puntos,  leerEstructura.id);
  fclose (archivoLeer);
}

void agregarPilotos (){
  FILE *archivoEscribir;
  archivoEscribir = fopen ("pilotos.dat", "a"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede abrir el archivo\n");
    exit (0);
  }
  struct piloto nuevoRegistro;// = {textoEntrada, textoEntrada, 33120413};
  printf("\nIngrese la informacion del nuevo piloto. \n");
  printf("\nIngrese nombre. \n");
  scanf("%s",nuevoRegistro.nombre);
  printf("\nIngreso.  %s \n", nuevoRegistro.nombre);
  printf("\nIngrese nacionalidad. \n");
  scanf("%s",nuevoRegistro.nacionalidad);
  printf("\nIngreso.  %s \n", nuevoRegistro.nacionalidad);
  printf("\nIngrese puntos. \n");
  scanf("%d",&nuevoRegistro.puntos);
  printf("\nIngreso.  %d \n", nuevoRegistro.puntos);
  printf("\nIngrese id. \n");
  scanf("%d",&nuevoRegistro.id);
  printf("\nIngreso.  %d \n", nuevoRegistro.id);

  // guardar estructura en el archivo
  fwrite (&nuevoRegistro, sizeof(struct piloto), 1, archivoEscribir);

  if(fwrite != 0)
  printf("Se guardo el contenido exitosamente!\n");
  else
  printf("error escribiendo en el archivo !\n");
  fclose (archivoEscribir);
}

void editarPilotos (){
  piloto *listadoRegistros = new piloto[50]; //vector que guardara todos los pilotos
  FILE *archivoEditar;
  struct piloto editarRegistro;
  archivoEditar = fopen ("pilotos.dat", "r");
  if (archivoEditar == NULL)
  {
    fprintf(stderr, "\nNo hay registros para leer, debe crear un piloto\n");
    exit (0);
  }

  while(fread(&editarRegistro, sizeof(struct piloto), 1, archivoEditar)){
    listadoRegistros[cantidadRegistros]=editarRegistro;
    cantidadRegistros++;
  }
  fclose (archivoEditar);
  for (int i = 0; i < cantidadRegistros; ++i){
    printf("\n Piloto No. %d, %s - punt: %d id: %d \n", i+1,  listadoRegistros[i].nombre , listadoRegistros[i].puntos, listadoRegistros[i].id);
  }
  printf ( "Ingrese el numero del piloto a editar: ");  scanf("%d", &noResgistroEditar);
  printf("\nIngrese la nueva informacion del piloto. \n");
  printf("\nIngrese nombre. \n");
  scanf("%s",listadoRegistros[noResgistroEditar-1].nombre);
  printf("\nIngreso.  %s \n", listadoRegistros[noResgistroEditar-1].nombre);
  printf("\nIngrese apellido. \n");
  scanf("%s",listadoRegistros[noResgistroEditar-1].nacionalidad);
  printf("\nIngreso.  %s \n", listadoRegistros[noResgistroEditar-1].nacionalidad);
  printf("\nIngrese puntos. \n");
  scanf("%d",&listadoRegistros[noResgistroEditar-1].puntos);
  printf("\nIngreso.  %d \n", listadoRegistros[noResgistroEditar-1].puntos);
  printf("\nIngrese id. \n");
  scanf("%d",&listadoRegistros[noResgistroEditar-1].id);
  printf("\nIngreso.  %d \n", listadoRegistros[noResgistroEditar-1].id);
  FILE *archivoEscribir;
  archivoEscribir = fopen ("pilotos.dat", "w"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede crear el archivo\n");
    exit (0);
  }

  for (int i = 0; i < cantidadRegistros; ++i){
    fwrite (&listadoRegistros[i], sizeof(struct piloto), 1, archivoEscribir);
    if(fwrite != 0)
    printf("Se guardo el contenido exitosamente!\n");
    else
    printf("error escribiendo en el archivo !\n");
  }

  fclose (archivoEscribir);
  muestraPilotos();
}

void menuInicial (){

  while (opcionMenu != 4) {
    printf ( "\n\nmenu\n\n");
    printf ( "1. Ver Pilotos.\n");
    printf ( "2. Agregar Piloto.\n");
    printf ( "3. Editar.\n");
    printf ( "4. Salir.\n");
    printf ( "Que opcion desea: ");  scanf("%d", &opcionMenu);
    switch(opcionMenu)
    {
      case 1:
      muestraPilotos();
      break;
      case 2:
      agregarPilotos();
      break;
      case 3:
      editarPilotos();
      break;
      case 4:
      break;
    }
  }

}


int main ()
{
  //crea el archivo si no existe
  FILE *archivoEscribir;
  archivoEscribir = fopen ("pilotos.dat", "a"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede crear el archivo\n");
    exit (0);
  }
  fclose (archivoEscribir);
  menuInicial();
  return 0;
}
