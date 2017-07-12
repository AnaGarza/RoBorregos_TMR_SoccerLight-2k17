//Acomoda al robot de frente mientras esta caminando
int top=210;
int bottom=190;

void ajusteAngular(float d){
  if(d>2 && d<358){
  switch(direccion){
    case 1: 
      igualadorV(v1, v3, vc1, vc3, d, top, bottom);
      break;
    case 5: 
      igualadorV(v3, v1, vc3, vc1, d, top, bottom);
      break;
    case 2:
      igualadorV(v1, v2, vc1, vc2, d, top, bottom);
      break;
    case 6:
      igualadorV(v2, v1, vc2, vc1, d, top, bottom);
      break;
    case 4:
      igualadorV(v3, v2, vc3, vc2, d, top, bottom);
      break;
    case 8:
      igualadorV(v2, v3, vc2, vc3, d, top, bottom);
      break;
  }}
}

void igualadorV(int &vel1, int &vel2, int &velC1, int &velC2, float d, int vMax, int vMin){
  if(d >0.5 && d < 359.5){
      //Desviado a la derecha
    if(d <180){
      if(vel1<vMax){vel1+= (d/2); }
      else{ if(vel2>vMin)vel2-=(d/2); }

      if(d-anguloPasado <=0 && regresando==false){regresando=true; velC1=vel1; velC2=vel2;}
    }
      //Desviado a la izquierda
    if(d >180){
      if(vel2<vMax){vel2+=(360-d)/2; }
      else {if(vel1>vMin)vel1-= (360-d)/2; }

      if(anguloPasado-d <=0 && regresando==false){regresando=true; velC1=vel1; velC2=vel2;}
    }
    
    analogWrite(pm1v, v1);
    analogWrite(pm2v, v2);
    analogWrite(pm3v, v3);
  }
    else if(regresando==true){vel1=velC1; vel2=velC2; regresando=false;
    analogWrite(pm1v, v1);
    analogWrite(pm2v, v2);
    analogWrite(pm3v, v3);}
}
