int b;
void findIt(){
 b=binario_decimal();
    switch(b){
    case 0:
     color('P');
     movimientoAngular(1);
        delay(100);
//        while(binario_decimal()==0){
//          centrar();
//          euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
//          acomodoAngular(euler.x());
//          anguloPasado = euler.x();
//        }
    break;
    case 1:
      movimientoAngular(6);
      delay(75);
      movimientoAngular(4);
      delay(175);

    color('B');
    break;
    case 2:
      movimientoAngular(5);
      delay(100);
    color('g');
    break;
    case 3:
      if(distancia(2)>51){
        movimientoAngular(4);
        delay(100);
      }else{
        movimientoAngular(6);
        delay(100);
      }
    color('R');
    break;
    case 4:
      movimientoAngular(5);
      delay(100);
      color('b');
    break;
    case 5:
      color('c');
      movimientoAngular(4);
      delay(75);
      movimientoAngular(6);
      delay(175);
    break;
    default:
      if(distancia(3)>50){
        movimientoAngular(5);
      }else{
        movimientoAngular(1);
      }
      color('<');
  }
}
