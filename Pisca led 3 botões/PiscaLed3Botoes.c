/*
  3 botões sendo START, STOP E RESET.
  - START: irá percorrer os leds de cima para baixo e voltar
  - STOP: irá parar no led da sequência
  - RESET: faz tudo parar e apaga todos os leds
*/

void reset(void);
void stop(void);
void start(void);
void aumenta(void);
void diminui(void);

int i;
const int delay = 50;

void reset(){
  latd = 0;
}

void start(){
  i = 0;
  while(1){
    for(i = 0; i < 8; i++){
      delay_ms(delay);
      aumenta();
      if(portb.RB1 == 0){
        return;
      } else if(portb.RB0 == 0){
        reset();
        return;
      }
    }

    for(i = 0; i < 8; i++){
      delay_ms(delay);
      diminui();
      if(portb.RB1 == 0){
        return;
      } else if(portb.RB0 == 0){
        reset();
        return;
      }
    }
  }
}

void aumenta(){
  delay_ms(delay);
  latd = latd >> 1;
  latd.RB7 =~ latd.RB7;
}

void diminui(){
  delay_ms(delay);
  latd = latd << 1;
}

void main() {
  trisb.RB0 = 1;   // RESET
  trisb.RB1 = 1;   // STOP
  trisb.RB2 = 1;   // START

  adcon1 = 15;
  trisd = 0;
  latd = 0;

  while(1){
     if(portb.RB2 == 0){
       start();
     }
     if(portb.RB0 == 0){
       latd = 0;
     }
  }
}
