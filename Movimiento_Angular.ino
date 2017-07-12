void movimientoAngular(int x){

  if(variablePasada != x){
  digitalWrite(pm1_a,LOW);
  digitalWrite(pm2_a,LOW);
  digitalWrite(pm3_a,LOW);
  digitalWrite(pm1_r,LOW);
  digitalWrite(pm2_r,LOW);
  digitalWrite(pm3_r,LOW);
  v1=200;
  v2=200;
  v3=200;
  analogWrite(pm1v, v1);
  analogWrite(pm2v, v2);
  analogWrite(pm3v, v3);

  switch(x){
    case 1: //Adelante
      digitalWrite(pm3_r,HIGH);
      digitalWrite(pm1_a,HIGH);
      break;

      case 2: //Adelante a la izquierda
      digitalWrite(pm2_a,HIGH);
      digitalWrite(pm3_r,HIGH);
      break;

      case 3: //A la izquierda
      digitalWrite(pm1_a,LOW);
      digitalWrite(pm2_a,HIGH);
      digitalWrite(pm3_a,LOW);
      digitalWrite(pm1_r,HIGH);
      digitalWrite(pm2_r,LOW);
      digitalWrite(pm3_r,HIGH);
      break;

      case 4: //Atras a la izquierda
      digitalWrite(pm2_a,HIGH);
      digitalWrite(pm1_r,HIGH);
      break;

      case 5: //Atras
      digitalWrite(pm1_r,HIGH);
      digitalWrite(pm3_a,HIGH);
      break;

      case 6: //Atras a la derecha
      digitalWrite(pm3_a,HIGH);
      digitalWrite(pm2_r,HIGH);
      break;

      case 7: //Derecha
      digitalWrite(pm1_a,HIGH);
      digitalWrite(pm2_a,LOW);
      digitalWrite(pm3_a,HIGH);
      digitalWrite(pm1_r,LOW);
      digitalWrite(pm2_r,HIGH);
      digitalWrite(pm3_r,LOW);
      break;

      case 8: //Adelante a la derecha
      digitalWrite(pm1_a,HIGH);
      digitalWrite(pm2_r,HIGH);
      break;

      case 98: //Girar a la izquierda
      v1=200;
      v2=200;
      v3=200;
      analogWrite(pm1v, v1);
      analogWrite(pm2v, v2);
      analogWrite(pm3v, v3);
      digitalWrite(pm1_r,HIGH);
      digitalWrite(pm2_r,HIGH);
      digitalWrite(pm3_r,HIGH);
      break;

      case 99: //Girar a la derecha
      v1=200;
      v2=200;
      v3=200;
      analogWrite(pm1v, v1);
      analogWrite(pm2v, v2);
      analogWrite(pm3v, v3);
      digitalWrite(pm1_a,HIGH);
      digitalWrite(pm2_a,HIGH);
      digitalWrite(pm3_a,HIGH);
      break;
  }
    variablePasada = x;
  }
}
