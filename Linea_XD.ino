void linea(){
  int valx=0;
  if(digitalRead(l0)==HIGH)
  valx+=1;
  if(digitalRead(l1)==HIGH)
  valx+=2;

  switch(valx){
    case 0:
      //movimientoAngular(6);
      color('R');
    break;
    case 1:
      //movimientoAngular(5);
      color('G');
    break;
    case 2:
      //movimientoAngular(2);
      color('B');
    break;
    case 3:
      //movimientoAngular(6);
      color('b');
    break;
  }

  for(int x=0; x<32; x++) delayMicroseconds(32000U);
  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);
}

