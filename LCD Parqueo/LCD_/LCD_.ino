// ---------------------------------PARA LCD-------------------------
// libreria para el manejo de LCD
#include <LiquidCrystal.h>

// asignamos los pines de salida del arduino
const int rs1 = 13, en1 = 12, d41 = 11, d51 = 10, d61 = 9, d71 = 8;
const int rs2 = 7, en2 = 6, d42 = 5, d52 = 4, d62 = 3, d72 = 2;
// inicializamos el objeto LCD
LiquidCrystal lcd(rs1, en1, d41, d51, d61, d71);
// la lcd2 solo es para fines de pruebas y poder ver las dos opciones
LiquidCrystal lcd2(rs2, en2, d42, d52, d62, d72);

// Creamos los array que utiliza la funicion createChar()
// Creamos los caracteres epeciales para el carro
byte carchar4[8]= {B00000,B00000,B01110,B11111,B11011,B11111,B01110,B00000};
byte carchar5[8]={B11111,B11111,B00011,B00011,B00011,B11111,B11111,B00000};
byte carchar7[8]={B11111,B11111,B00000,B00000,B11111,B11111,B11111,B00000};
byte carchar8[8]={B11111,B11111,B00000,B00000,B11111,B11111,B11111,B00000};
byte carchar9[8]={B11000,B11110,B00110,B00011,B01111,B01111,B01111,B01111};

// Creamos las flechas
byte arrowchar[8]={B00100, B01110, B11111, B01110, B01110,B01110,B00000,B00000};
byte arrowchar2[8]={B00100, B00110, B11111, B11111, B00110,B00100,B00000,B00000};
// Creamos la barra invertida
byte negchar[8]={ B00000,B10000,B11000,B01100,B00110,B00011,B00001,B00000};

int Parqueos_Disponibles = 1;
int Parqueos_Reservados = 8;
int Parqueos_Ocupados = 8;


unsigned long  TiempoAnterior;

// para los delay en intervalos usando millis
#define INTERVALO_MENSAJE1 5000
#define INTERVALO_MENSAJE2 7000
#define INTERVALO_MENSAJE3 11000
#define INTERVALO_MENSAJE4 15000
unsigned long tiempo_1 = 0;
unsigned long tiempo_2 = 0;
unsigned long tiempo_3 = 0;
unsigned long tiempo_4 = 0;




// --------------------------------------FIN PARA LCD ------------------------------
void setup() {
  //------------------------------------------SETUP LCD-----------------
  // indicamos el tamaño del display
  lcd2.begin(16,2);
    // inicializamos la pantalla indicando filas y columnas
  lcd.begin(16,2);
  // asignamos un numero a la funcion createChar seguido de el nombre de el array creado
  lcd2.createChar(2,arrowchar);
  lcd2.createChar(3,arrowchar2);
  lcd2.createChar(4,carchar4);
  lcd2.createChar(5,carchar5);
  lcd2.createChar(6,negchar);
  lcd2.createChar(7,carchar7);
  lcd2.createChar(8,carchar8);
  lcd2.createChar(9,carchar9);

 
  // Este es un nuevo caracter
  lcd.createChar(6,negchar);

  // Creamos las flechas
  lcd.createChar(2,arrowchar);
  lcd.createChar(3,arrowchar2);

 //Creamos las partes del carro 
  lcd.createChar(4,carchar4);
  lcd.createChar(5,carchar5);
  lcd.createChar(7,carchar7);
  lcd.createChar(8,carchar8);
  lcd.createChar(9,carchar9);


  TiempoAnterior = millis();
  
  //--------------------------------FIN SETUP LCD---------------------------------
  
}

void loop() {
  //-----------------------------------LOOP-------------------------

  if(Parqueos_Disponibles==0){
      if(millis()-TiempoAnterior >= 1000){
        TiempoAnterior = millis();
    // limpiamos la pantalla LCD
    lcd.clear();
  lcd.setCursor(6,1);
  lcd.write("[");
  lcd.setCursor(7,1);
  lcd.write("/");
  lcd.setCursor(8,1);
  lcd.write("_");
  lcd.setCursor(9,1);
  lcd.write(6);
  lcd.setCursor(10,1);
  lcd.write("]");
  lcd.setCursor(7,0);
  lcd.write(6);
  lcd.setCursor(8,0);
  lcd.write(8);
  lcd.setCursor(9,0);
  lcd.write("/");
  lcd.setCursor(13,1);
  lcd.write("X");
  lcd.setCursor(13,0);
  lcd.write("X");
  lcd.setCursor(3,1);
  lcd.write("X");
  lcd.setCursor(3,0);
  lcd.write("X");
  }
  if(millis()-TiempoAnterior >= 1000){
    TiempoAnterior = millis();
    lcd.clear();
  lcd.setCursor(5,0);
  lcd.write("PARQUEO");
  lcd.setCursor(6,1);
  lcd.write("LLENO");
   lcd.setCursor(13,1);
  lcd.write("X");
  lcd.setCursor(13,0);
  lcd.write("X");
  lcd.setCursor(3,1);
  lcd.write("X");
  lcd.setCursor(3,0);
  lcd.write("X");
   

  }
  
  
 

  }else{
     
      // son if para no utilizar delay ya que el delay pausa todo el codigo
      // por lo tanto se utilizaron los millies 
      if(millis() > tiempo_1 + INTERVALO_MENSAJE1){
        tiempo_1 = millis();
      lcd.setCursor(0,0);
      lcd.print("PARQUEOS ");
      lcd.setCursor(0,1);
      lcd.print("DISPONIBLES: ");
      lcd.print(Parqueos_Disponibles);
        
       
    }
   
    if(millis() > tiempo_2 + INTERVALO_MENSAJE2){
        tiempo_2 = millis();
        lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PARQUEOS ");
      lcd.setCursor(0,1);
      lcd.print("0CUPADOS: ");
      lcd.print(Parqueos_Ocupados);
        
       
    }
   
    if(millis() > tiempo_3 + INTERVALO_MENSAJE3){
        tiempo_3 = millis();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("PARQUEOS ");
        lcd.setCursor(0,1);
        lcd.print("RESERVADOS: ");
        lcd.print(Parqueos_Reservados);
        
     
    }
    if(millis() > tiempo_4 + INTERVALO_MENSAJE4){
        tiempo_4 = millis();
        // Este ciclo for es para el desplazamiento a la derecha 
      for(int i= 0; i<24;i++){
      // idicamos la posicion de el caracter en el display + i 
      // Como i va aumentando los caracteres se empiezan a desplazar
      lcd.setCursor(1+i,1);
      // Escribimos sobre la LCD
      lcd.write("[");
      lcd.setCursor(2+i,1);
      lcd.write(4);
      lcd.setCursor(3+i,1);
      lcd.write("_");
      lcd.setCursor(4+i,1);
      lcd.write(4);
      lcd.setCursor(5+i,1);
      lcd.write("]");
      lcd.setCursor(2+i,0);
      lcd.write("/");
      lcd.setCursor(3+i,0);
      lcd.write(8);
      lcd.setCursor(4+i,0);
      lcd.write(9);
      lcd.setCursor(7+i,1);
      lcd.write(3);
      lcd.setCursor(7+i,0);
      lcd.write(3);
      // Estas son las flechas
      lcd.setCursor(15,0);
      lcd.write(2);
      lcd.setCursor(15,1);
      lcd.write(2);
     
      lcd.setCursor(-9+i,0);
      lcd.write("AVANCE");
      
      lcd.setCursor(i,1);
      lcd.write(3);
      lcd.setCursor(i,0);
      lcd.write(3);
      delay(100);
      
      // leugo se borra 
    
      lcd.clear();
  
  
  }// fin del for
    }// fin del delay    
  
  }// fin de else
  // esta zona es apra fines de prueba y poder ver las dos animaciones 
// no colocar en la documentacion  
 if(millis()-TiempoAnterior >= 1000){
        TiempoAnterior = millis();
    // limpiamos la pantalla LCD
    lcd2.clear();
  lcd2.setCursor(6,1);
  lcd2.write("[");
  lcd2.setCursor(7,1);
  lcd2.write("/");
  lcd2.setCursor(8,1);
  lcd2.write("_");
  lcd2.setCursor(9,1);
  lcd2.write(6);
  lcd2.setCursor(10,1);
  lcd2.write("]");
  lcd2.setCursor(7,0);
  lcd2.write(6);
  lcd2.setCursor(8,0);
  lcd2.write(8);
  lcd2.setCursor(9,0);
  lcd2.write("/");
  lcd2.setCursor(13,1);
  lcd2.write("X");
  lcd2.setCursor(13,0);
  lcd2.write("X");
  lcd2.setCursor(3,1);
  lcd2.write("X");
  lcd2.setCursor(3,0);
  lcd2.write("X");
  }
  if(millis()-TiempoAnterior >= 1000){
    TiempoAnterior = millis();
    lcd2.clear();
  lcd2.setCursor(5,0);
  lcd2.write("PARQUEO");
  lcd2.setCursor(6,1);
  lcd2.write("LLENO");
   lcd2.setCursor(13,1);
  lcd2.write("X");
  lcd2.setCursor(13,0);
  lcd2.write("X");
  lcd2.setCursor(3,1);
  lcd2.write("X");
  lcd2.setCursor(3,0);
  lcd2.write("X");
   

  }
  

// ------------------------------FIN LOOP LCD--------------------------------
}
