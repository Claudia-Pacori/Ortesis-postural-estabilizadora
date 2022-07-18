#include <Servo.h>
#include <Keypad.h>

const byte filas = 4; //Byte utiliza 8 bits
const byte columnas = 4; //Byte utiliza 8 bits
byte pinesFilas[]  = {9,8,7,6};
byte pinesColumnas[] = {5,4,3,2};
char teclas[4][4] = {{'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};

Keypad teclado1 = Keypad( makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);  

//Variable donde almacenaremos el valor del potenciometro
float valor;
const byte pinServo = 11;

Servo servoMotor;

void setup() {
  //Inicializamos la comunicación serial
  Serial.begin(9600);
  servoMotor.attach(pinServo);
  
  //Escribimos por el monitor serie mensaje de inicio
  Serial.println("Teclado 4x4 con Biblioteca Keypad");

}

void loop() {
  //Verifica si alguna tecla fue presionada
  char tecla_presionada = teclado1.getKey();
   
  switch(tecla_presionada){
     case '1': //De 0 a 60
       valor = 60;
       break;
     case '2': //De 0 a 90
       valor = 90;
       break;
     case '3': //De 0 a 100
       valor = 100;
       break;
     case '4': //De 0 a 110
       valor = 110;
       break;
     case '5': //De 0 a 120
       valor = 120;
       break;
     case '6': //De 0 a 130
       valor = 130;
       break;
     case '7': //De 0 a 140
       valor = 140;
       break;
     case '8': //De 0 a 150
       valor = 150;
       break;
     case '9': //De 0 a 160
       valor = 160;
       break;
     default:
       valor = 0;
       break;     
    }
  if(tecla_presionada){
    Serial.print("Tecla: ");
    Serial.println(tecla_presionada);
    Serial.print("Moviendo hasta este angulo: ");
    Serial.println(valor);}


  //Imprimimos por el monitor serie
  for(int i=0; i<=valor; i+=5){
    delay(100);
  	servoMotor.write(i);
  } 
  for(int i=valor; i>=0; i-=5){
    delay(100);
  	servoMotor.write(i);
  } 

}
