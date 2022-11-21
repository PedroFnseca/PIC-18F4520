void main() {
  trisb.RB0 = 1;
  trisb.RB1 = 1;
  trisd.RD0 = 0;    
  adcon1 = 15;
  latd = 0;

  while(1){
     if(portb.RB0 == 0){
       latd.RD0 =~ latd.RD0;
     }
  }
}