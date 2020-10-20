#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct contacto 
{ 
    char nombre[50]; 
    char apellidos[50]; 
    int telefono; 
}; 

int opcionMenu=0;
int noContactoEditar=0;
char textoEntrada[50];
int cantidadContactos=0;

void muestraContactos (){
    FILE *archivoLeer; 
    struct contacto leerContacto; 
    printf("\nContactos guardados: \n");  
    archivoLeer = fopen ("agenda.dat", "r"); 
    if (archivoLeer == NULL) 
    { 
        fprintf(stderr, "\nNo hay registros para leer, debe crear un contacto\n"); 
        exit (0); 
    } 

    
    while(fread(&leerContacto, sizeof(struct contacto), 1, archivoLeer)) 
        printf ("Nombre:  %s Apellidos:  %s, Telefono: %d\n", leerContacto.nombre, 
            leerContacto.apellidos, leerContacto.telefono);  
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
    struct contacto nuevoContactoT;// = {textoEntrada, textoEntrada, 33120413}; 
    printf("\nIngrese la informacion del nuevo contacto. \n");
    printf("\nIngrese nombre. \n");
    scanf("%s",nuevoContactoT.nombre);
    printf("\nIngresó.  %s \n", nuevoContactoT.nombre);
    printf("\nIngrese apellido. \n");
    scanf("%s",nuevoContactoT.apellidos);
    printf("\nIngresó.  %s \n", nuevoContactoT.apellidos);
    printf("\nIngrese telefono. \n");
    scanf("%d",&nuevoContactoT.telefono);
    printf("\nIngresó.  %d \n", nuevoContactoT.telefono);
    
    // write struct to file 
    fwrite (&nuevoContactoT, sizeof(struct contacto), 1, archivoEscribir); 
    
    if(fwrite != 0) 
        printf("Se guardo el contenido exitosamente!\n"); 
    else
        printf("error escribiendo en el archivo !\n");  
    fclose (archivoEscribir); 
}

void editarContactos (){
    contacto *listadoContactos = new contacto[50]; //vector que guardará todos los contactos
    FILE *archivoEditar; 
    struct contacto editarContacto;  
    archivoEditar = fopen ("agenda.dat", "r"); 
    if (archivoEditar == NULL) 
    { 
        fprintf(stderr, "\nNo hay registros para leer, debe crear un contacto\n"); 
        exit (0); 
    } 

    
    while(fread(&editarContacto, sizeof(struct contacto), 1, archivoEditar)){
       listadoContactos[cantidadContactos]=editarContacto;
       cantidadContactos++;
   } 
   fclose (archivoEditar); 
   for (int i = 0; i < cantidadContactos; ++i){
    printf("\n Contacto No. %d, %s - telefono: %d \n", i+1,  listadoContactos[i].nombre , listadoContactos[i].telefono);  
}
printf ( "Ingrese el numero del contacto a editar: ");  scanf("%d", &noContactoEditar);
printf("\nIngrese la nueva informacion del contacto. \n");
printf("\nIngrese nombre. \n");
scanf("%s",listadoContactos[noContactoEditar-1].nombre);
printf("\nIngresó.  %s \n", listadoContactos[noContactoEditar-1].nombre);
printf("\nIngrese apellido. \n");
scanf("%s",listadoContactos[noContactoEditar-1].apellidos);
printf("\nIngresó.  %s \n", listadoContactos[noContactoEditar-1].apellidos);
printf("\nIngrese telefono. \n");
scanf("%d",&listadoContactos[noContactoEditar-1].telefono);
printf("\nIngresó.  %d \n", listadoContactos[noContactoEditar-1].telefono);
FILE *archivoEscribir; 
    archivoEscribir = fopen ("agenda.dat", "w"); //abre el archivo para poder escribir y si no existe lo creea
    if (archivoEscribir == NULL) 
    { 
        fprintf(stderr, "\nNo se puede crear el archivo\n"); 
        exit (0); 
    } 
    
    

    for (int i = 0; i < cantidadContactos; ++i){
        fwrite (&listadoContactos[i], sizeof(struct contacto), 1, archivoEscribir); 
        
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