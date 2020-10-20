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
struct circuito
{
  char desc[50];
  char pais[50];
  int vueltas;
  char fecha[50];
};
struct equipo
{
  char nombre[50];
  int puntos;
  int id;
};

int opcionMenu=0;
int noResgistroEditar=0;
char textoEntrada[50];
int cantidadRegistros=0;

//*******PILOTOS***********
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

//*********PILOTOS*****************

//*******CIRCUITOS**************
void muestraCircuitos (){
  FILE *archivoLeer;
  struct circuito leerEstructura;
  printf("\Registros guardados: \n");
  archivoLeer = fopen ("circuitos.dat", "r");
  if (archivoLeer == NULL)  {
    fprintf(stderr, "\nNo hay registros para leer, debe crear un circuito\n");
    exit (0);
  }

  while(fread(&leerEstructura, sizeof(struct circuito), 1, archivoLeer))
  printf ("Nombre:  %s pais:  %s, vueltas: %d, , id: %s\n", leerEstructura.desc,
  leerEstructura.pais, leerEstructura.vueltas,  leerEstructura.fecha);
  fclose (archivoLeer);
}

void agregarCircuitos (){
  FILE *archivoEscribir;
  archivoEscribir = fopen ("circuitos.dat", "a"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede abrir el archivo\n");
    exit (0);
  }
  struct circuito nuevoRegistro;// = {textoEntrada, textoEntrada, 33120413};
  printf("\nIngrese la informacion del nuevo circuito. \n");
  printf("\nIngrese desc. \n");
  scanf("%s",nuevoRegistro.desc);
  printf("\nIngreso.  %s \n", nuevoRegistro.desc);
  printf("\nIngrese pais. \n");
  scanf("%s",nuevoRegistro.pais);
  printf("\nIngreso.  %s \n", nuevoRegistro.pais);
  printf("\nIngrese vueltas. \n");
  scanf("%d",&nuevoRegistro.vueltas);
  printf("\nIngreso.  %d \n", nuevoRegistro.vueltas);
  printf("\nIngrese fecha. \n");
  scanf("%s",nuevoRegistro.fecha);
  printf("\nIngreso.  %s \n", nuevoRegistro.fecha);

  // guardar estructura en el archivo
  fwrite (&nuevoRegistro, sizeof(struct circuito), 1, archivoEscribir);

  if(fwrite != 0)
  printf("Se guardo el contenido exitosamente!\n");
  else
  printf("error escribiendo en el archivo !\n");
  fclose (archivoEscribir);
}

void editarCircuito (){
  circuito *listadoRegistros = new circuito[50]; //vector que guardara todos los circuitos
  FILE *archivoEditar;
  struct circuito editarRegistro;
  archivoEditar = fopen ("circuitos.dat", "r");
  if (archivoEditar == NULL)
  {
    fprintf(stderr, "\nNo hay registros para leer, debe crear un circuito\n");
    exit (0);
  }

  while(fread(&editarRegistro, sizeof(struct circuito), 1, archivoEditar)){
    listadoRegistros[cantidadRegistros]=editarRegistro;
    cantidadRegistros++;
  }
  fclose (archivoEditar);
  for (int i = 0; i < cantidadRegistros; ++i){
    printf("\n circuito No. %d, %s - vueltas: %d fecha: %s \n", i+1,  listadoRegistros[i].desc , listadoRegistros[i].vueltas, listadoRegistros[i].fecha);
  }
  printf ( "Ingrese el numero del circuito a editar: ");  scanf("%d", &noResgistroEditar);
  printf("\nIngrese la nueva informacion del circuito. \n");
  printf("\nIngrese desc. \n");
  scanf("%s",listadoRegistros[noResgistroEditar-1].desc);
  printf("\nIngreso.  %s \n", listadoRegistros[noResgistroEditar-1].desc);
  printf("\nIngrese pais. \n");
  scanf("%s",listadoRegistros[noResgistroEditar-1].pais);
  printf("\nIngreso.  %s \n", listadoRegistros[noResgistroEditar-1].pais);
  printf("\nIngrese vueltas. \n");
  scanf("%d",&listadoRegistros[noResgistroEditar-1].vueltas);
  printf("\nIngreso.  %d \n", listadoRegistros[noResgistroEditar-1].vueltas);
  printf("\nIngrese fecha. \n");
  scanf("%s",listadoRegistros[noResgistroEditar-1].fecha);
  printf("\nIngreso.  %s \n", listadoRegistros[noResgistroEditar-1].fecha);
  FILE *archivoEscribir;
  archivoEscribir = fopen ("circuitos.dat", "w"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede crear el archivo\n");
    exit (0);
  }

  for (int i = 0; i < cantidadRegistros; ++i){
    fwrite (&listadoRegistros[i], sizeof(struct circuito), 1, archivoEscribir);
    if(fwrite != 0)
    printf("Se guardo el contenido exitosamente!\n");
    else
    printf("error escribiendo en el archivo !\n");
  }

  fclose (archivoEscribir);
  muestraCircuitos();
}
//*******CIRCUITOS**************

//*********EQUIPOS***************
void muestraEquipos (){
  FILE *archivoLeer;
  struct equipo leerEstructura;
  printf("\Registros guardados: \n");
  archivoLeer = fopen ("equipos.dat", "r");
  if (archivoLeer == NULL)  {
    fprintf(stderr, "\nNo hay registros para leer, debe crear un equipo\n");
    exit (0);
  }

  while(fread(&leerEstructura, sizeof(struct equipo), 1, archivoLeer))
  printf ("Equipo:  %s  puntos: %d, , id: %d\n", leerEstructura.nombre, leerEstructura.puntos,  leerEstructura.id);
  fclose (archivoLeer);
}

void agregarEquipos (){
  FILE *archivoEscribir;
  archivoEscribir = fopen ("equipos.dat", "a"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede abrir el archivo\n");
    exit (0);
  }
  struct equipo nuevoRegistro;// = {textoEntrada, textoEntrada, 33120413};
  printf("\nIngrese la informacion del nuevo equipo. \n");
  printf("\nIngrese nombre. \n");
  scanf("%s",nuevoRegistro.nombre);
  printf("\nIngreso.  %s \n", nuevoRegistro.nombre);
  printf("\nIngrese puntos. \n");
  scanf("%d",&nuevoRegistro.puntos);
  printf("\nIngreso.  %d \n", nuevoRegistro.puntos);
  printf("\nIngrese id. \n");
  scanf("%d",&nuevoRegistro.id);
  printf("\nIngreso.  %d \n", nuevoRegistro.id);

  // guardar estructura en el archivo
  fwrite (&nuevoRegistro, sizeof(struct equipo), 1, archivoEscribir);

  if(fwrite != 0)
  printf("Se guardo el contenido exitosamente!\n");
  else
  printf("error escribiendo en el archivo !\n");
  fclose (archivoEscribir);
}

void editarEquipos (){
  equipo *listadoRegistros = new equipo[50]; //vector que guardara todos los equipos
  FILE *archivoEditar;
  struct equipo editarRegistro;
  archivoEditar = fopen ("equipos.dat", "r");
  if (archivoEditar == NULL)
  {
    fprintf(stderr, "\nNo hay registros para leer, debe crear un equipo\n");
    exit (0);
  }

  while(fread(&editarRegistro, sizeof(struct equipo), 1, archivoEditar)){
    listadoRegistros[cantidadRegistros]=editarRegistro;
    cantidadRegistros++;
  }
  fclose (archivoEditar);
  for (int i = 0; i < cantidadRegistros; ++i){
    printf("\n Equipo No. %d, %s - puntos: %d id: %d \n", i+1,  listadoRegistros[i].nombre , listadoRegistros[i].puntos, listadoRegistros[i].id);
  }
  printf ( "Ingrese el numero del equipo a editar: ");  scanf("%d", &noResgistroEditar);
  printf("\nIngrese la nueva informacion del equipo. \n");
  printf("\nIngrese nombre. \n");
  scanf("%s",listadoRegistros[noResgistroEditar-1].nombre);
  printf("\nIngreso.  %s \n", listadoRegistros[noResgistroEditar-1].nombre);
  printf("\nIngrese puntos. \n");
  scanf("%d",&listadoRegistros[noResgistroEditar-1].puntos);
  printf("\nIngreso.  %d \n", listadoRegistros[noResgistroEditar-1].puntos);
  printf("\nIngrese id. \n");
  scanf("%d",&listadoRegistros[noResgistroEditar-1].id);
  printf("\nIngreso.  %d \n", listadoRegistros[noResgistroEditar-1].id);
  FILE *archivoEscribir;
  archivoEscribir = fopen ("equipos.dat", "w"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede crear el archivo\n");
    exit (0);
  }

  for (int i = 0; i < cantidadRegistros; ++i){
    fwrite (&listadoRegistros[i], sizeof(struct equipo), 1, archivoEscribir);
    if(fwrite != 0)
    printf("Se guardo el contenido exitosamente!\n");
    else
    printf("error escribiendo en el archivo !\n");
  }

  fclose (archivoEscribir);
  muestraEquipos();
}
//*********EQUIPOS***************
void menuInicial (){
  while (opcionMenu != 99) {//si ingres el valor 99 ya no se muestra el menu y finaliza el ciclo
    printf ( "\n\nmenu\n\n");
    printf ( "1. Pilotos VER.\n");
    printf ( "2. Pilotos AGREGAR.\n");
    printf ( "3. Pilotos EDITAR.\n");
    printf ( "4. Circuitos VER.\n");
    printf ( "5. Circuitos AGREGAR.\n");
    printf ( "6. Circuitos EDITAR.\n");
    printf ( "7. Equipos VER.\n");
    printf ( "8. Equipos AGREGAR.\n");
    printf ( "9. Equipos EDITAR.\n");
    printf ( "99. Salir.\n");
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
      muestraCircuitos();
      break;
      case 5:
      agregarCircuitos();
      break;
      case 6:
      editarCircuito();
      break;
      case 7:
      muestraEquipos();
      break;
      case 8:
      agregarEquipos();
      break;
      case 9:
      editarEquipos();
      case 99:
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

  //FILE *archivoEscribir;
  archivoEscribir = fopen ("circuitos.dat", "a"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede crear el archivo\n");
    exit (0);
  }
  fclose (archivoEscribir);


  archivoEscribir = fopen ("equipos.dat", "a"); //abre el archivo para poder escribir y si no existe lo creea
  if (archivoEscribir == NULL)
  {
    fprintf(stderr, "\nNo se puede crear el archivo\n");
    exit (0);
  }
  fclose (archivoEscribir);
  menuInicial();
  return 0;
}
