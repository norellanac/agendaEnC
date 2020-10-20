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
int noContactoEditar=0;
char textoEntrada[50];
int cantidadContactos=0;

void muestraContactos (){
    FILE *archivoLeer;
    struct piloto leerContacto;
    printf("\nContactos guardados: \n");
    archivoLeer = fopen ("agenda.dat", "r");
    if (archivoLeer == NULL)
    {
        fprintf(stderr, "\nNo hay registros para leer, debe crear un piloto\n");
        exit (0);
    }


    while(fread(&leerContacto, sizeof(struct piloto), 1, archivoLeer))
        printf ("Nombre:  %s Apellidos:  %s, puntos: %d, , id: %d\n", leerContacto.nombre,
            leerContacto.nacionalidad, leerContacto.puntos,  leerContacto.id);
    fclose (archivoLeer);
}

void agregarContactos (){
    FILE *archivoEscribir;
    archivoEscribir = fopen ("agenda.dat", "a"); //abre el archivo para poder escribir y si no existe lo creea
    if (archivoEscribir == NULL)
    {
        fprintf(stderr, "\nNo se puede abrir el archivo\n");
        exit (0);
    }
    struct piloto nuevoContactoT;// = {textoEntrada, textoEntrada, 33120413};
    printf("\nIngrese la informacion del nuevo piloto. \n");
    printf("\nIngrese nombre. \n");
    scanf("%s",nuevoContactoT.nombre);
    printf("\nIngreso.  %s \n", nuevoContactoT.nombre);
    printf("\nIngrese apellido. \n");
    scanf("%s",nuevoContactoT.nacionalidad);
    printf("\nIngreso.  %s \n", nuevoContactoT.nacionalidad);
    printf("\nIngrese telefono. \n");
    scanf("%d",&nuevoContactoT.puntos);
    printf("\nIngreso.  %d \n", nuevoContactoT.puntos);
    printf("\nIngrese telefono. \n");
    scanf("%d",&nuevoContactoT.id);
    printf("\nIngreso.  %d \n", nuevoContactoT.id);

    // write struct to file
    fwrite (&nuevoContactoT, sizeof(struct piloto), 1, archivoEscribir);

    if(fwrite != 0)
        printf("Se guardo el contenido exitosamente!\n");
    else
        printf("error escribiendo en el archivo !\n");
    fclose (archivoEscribir);
}

void editarContactos (){
    piloto *listadoContactos = new piloto[50]; //vector que guardar� todos los pilotos
    FILE *archivoEditar;
    struct piloto editarContacto;
    archivoEditar = fopen ("agenda.dat", "r");
    if (archivoEditar == NULL)
    {
        fprintf(stderr, "\nNo hay registros para leer, debe crear un piloto\n");
        exit (0);
    }


    while(fread(&editarContacto, sizeof(struct piloto), 1, archivoEditar)){
       listadoContactos[cantidadContactos]=editarContacto;
       cantidadContactos++;
   }
   fclose (archivoEditar);
   for (int i = 0; i < cantidadContactos; ++i){
    printf("\n Contacto No. %d, %s - punt: %d id: %d \n", i+1,  listadoContactos[i].nombre , listadoContactos[i].puntos, listadoContactos[i].id);
}
printf ( "Ingrese el numero del piloto a editar: ");  scanf("%d", &noContactoEditar);
printf("\nIngrese la nueva informacion del piloto. \n");
printf("\nIngrese nombre. \n");
scanf("%s",listadoContactos[noContactoEditar-1].nombre);
printf("\nIngres�.  %s \n", listadoContactos[noContactoEditar-1].nombre);
printf("\nIngrese apellido. \n");
scanf("%s",listadoContactos[noContactoEditar-1].nacionalidad);
printf("\nIngres�.  %s \n", listadoContactos[noContactoEditar-1].nacionalidad);
printf("\nIngrese puntos. \n");
scanf("%d",&listadoContactos[noContactoEditar-1].puntos);
printf("\nIngres�.  %d \n", listadoContactos[noContactoEditar-1].puntos);
printf("\nIngrese id. \n");
scanf("%d",&listadoContactos[noContactoEditar-1].id);
printf("\nIngres�.  %d \n", listadoContactos[noContactoEditar-1].id);
FILE *archivoEscribir;
    archivoEscribir = fopen ("agenda.dat", "w"); //abre el archivo para poder escribir y si no existe lo creea
    if (archivoEscribir == NULL)
    {
        fprintf(stderr, "\nNo se puede crear el archivo\n");
        exit (0);
    }



    for (int i = 0; i < cantidadContactos; ++i){
        fwrite (&listadoContactos[i], sizeof(struct piloto), 1, archivoEscribir);

        if(fwrite != 0)
            printf("Se guardo el contenido exitosamente!\n");
        else
            printf("error escribiendo en el archivo !\n");
    }

    fclose (archivoEscribir);
    muestraContactos();
}

void menuInicial (){

    while (opcionMenu != 4) {
     printf ( "\n\nmenu\n\n");
     printf ( "1. Ver Contactos.\n");
     printf ( "2. Agregar Contacto.\n");
     printf ( "3. Editar.\n");
     printf ( "4. Salir.\n");
     printf ( "Que opcion desea: ");  scanf("%d", &opcionMenu);
     switch(opcionMenu)
     {
        case 1:
        muestraContactos();
        break;
        case 2:
        agregarContactos();
        break;
        case 3:
        editarContactos();
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
    archivoEscribir = fopen ("agenda.dat", "a"); //abre el archivo para poder escribir y si no existe lo creea
    if (archivoEscribir == NULL)
    {
        fprintf(stderr, "\nNo se puede crear el archivo\n");
        exit (0);
    }
    fclose (archivoEscribir);
    menuInicial();
    return 0;
}
