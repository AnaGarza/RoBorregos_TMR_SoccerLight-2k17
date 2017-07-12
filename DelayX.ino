////Crea un delay pero con instrucciones que se estan ejeutando
////(No lee de los tsops mientras hace esto para evtar ruidos)
void delayX(int t){
  unsigned long tx = millis();
  unsigned long ta = millis();
  while(tx-millis() < t && binario_decimal()!=0){
    euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  ajusteAngular(euler.x());
  acomodoAngular(euler.x());
  anguloPasado = euler.x();
    Serial.print(millis());Serial.print(" - ");Serial.print(tx);Serial.print(" = ");
    Serial.println(millis()-tx);
      ta=millis();
      if(ta-tx>t){
      break;
      }
   }
       // Serial.println("salio");
 if(millis()-tx>t){
    movimientoAngular(1);
 }
}

void delayY(int t){
  int tx = millis();
  while(tx-millis() < t){
  euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  ajusteAngular(euler.x());
  acomodoAngular(euler.x());
  anguloPasado = euler.x();
  if(tx-millis() < t)break;
  }
}

