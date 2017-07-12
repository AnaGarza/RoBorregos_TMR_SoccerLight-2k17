#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055();

//Son las velocidades que todos los motores ejerceran cuando vayan a moverse
int v1 = 200, v2 = 200, v3 = 200;

int xy;


//Los numeros de pines de los motores, la 'a' significa avanzar y la 'r' retroceder
int pm3_a = 42, pm3_r = 44,
    pm1_a = 26, pm1_r = 28,
    pm2_a = 30, pm2_r = 32;

//Los numeros de pines para ecribir las velocidades de los mototres.
int pm1v = 13, pm2v = 12, pm3v = 10;

//Bits de tsop nano-mega
int b0 = 51, b1 = 49 , b2 = 53;

//Bits de linea nano-mega
int l0 = 23, l1 = 25, inter = 18;
//Para el RGB
int pinR = 5, pinG = 6, pinB = 7;

int i, x, y = 0, mayor[3], mayorx = -1;
int duration;

int echo1 = 45; //frente
int echo2 = 48; //izquierda
int echo3 = 36; //atras
int echo4 = 24; //derecha


int trig1 = 47;  //frente
int trig2 = 46;  //izquierda
int trig3 = 34;  //atras
int trig4 = 22;  //derecha

int variablePasada = 0; //La lectura pasada de los tres bits para revisar si hubo un cambio de movimiento

imu::Vector<3> euler; //Declaracion del objeto para los angulos euler
int anguloPasado = 0, vc1 = v1, vc2 = v2, vc3 = v3;
bool regresando = false;
int direccion = 0;



double d;
int cm;

//Distancias
int izquierda, derecha, front, back;
bool cerca = true;

void setup() {
  Serial.begin(9600);

  pinMode(trig1, OUTPUT);                  //supersónico izquierda
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);                  //supersónico izquierda
  pinMode(trig4, OUTPUT);

  pinMode(echo1, INPUT);                  //supersónico izquierda
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);                  //supersónico izquierda
  pinMode(echo4, INPUT);

  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);

  pinMode(b0, INPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);

  pinMode(pm1v, OUTPUT);
  pinMode(pm2v, OUTPUT);
  pinMode(pm3v, OUTPUT);

  pinMode(pm1_a, OUTPUT);
  pinMode(pm1_r, OUTPUT);
  pinMode(pm2_a, OUTPUT);
  pinMode(pm2_r, OUTPUT);
  pinMode(pm3_a, OUTPUT);
  pinMode(pm3_r, OUTPUT);

  analogWrite(pm1v, v1);
  analogWrite(pm2v, v2);
  analogWrite(pm3v, v3);
  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);
  //movimientoAngular(0);//Para asegurarnos de que no se mueva

  //  //Para utilizar la brujula
  bno.setExtCrystalUse(true);

  //attachInterrupt(digitalPinToInterrupt(18), linea, RISING);

  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }
}

void loop() {
    euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    acomodoAngular(euler.x());
    anguloPasado = euler.x();
    findIt();
    pared();
}

int binario_decimal() {
  int valx = 0;
  if (digitalRead(b0) == HIGH)
    valx += 1;
  if (digitalRead(b1) == HIGH)
    valx += 2;
  if (digitalRead(b2) == HIGH)
    valx += 4;
  return valx;
}
