void color(char c){
  analogWrite(pinR,0);
  analogWrite(pinG,0);
  analogWrite(pinB,0);
  
  switch(c){
    case 'b':
      analogWrite(pinB, 254);
      break;
    case 'G':
      analogWrite(pinG,254);
      break;
    case 'g': //verde claro
      analogWrite(pinR, 30);
      analogWrite(pinG, 254);
      analogWrite(pinB, 20);
      break;
    case 'B':
      analogWrite(pinG,254);
      analogWrite(pinB, 254);
      analogWrite(pinR, 254);
      break;
    case 'r': //Rosa tenue
      analogWrite(pinR, 254);
      analogWrite(pinB, 254);
      break;
    case 'c':
      analogWrite(pinR, 154);
      analogWrite(pinB, 254);
      break;
    case 'P': //Piel
      analogWrite(pinR, 254);
      analogWrite(pinG, 80);
      analogWrite(pinB, 80);
      break;
    case 'R': //Rosa fuerte
      analogWrite(pinR, 254);
      analogWrite(pinB, 128);
      break;
  }
}
