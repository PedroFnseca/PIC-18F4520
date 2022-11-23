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

void reset(){
  latd = 0;
}

void stop(){
  /*
    TODO: STOP
      Fazer a sequência parar na ultima porta quando este botão for pressionado.
      obs: Por enquanto a existência dessa função não se faz necessário.
 */
}

void start(){
  while(1){
    for(i = 0; i < 8; i++){
      aumenta();
      if(portb.RB1 == 1){
        return;
      } else if(portb.RB1 == 0){
        reset();
        return;
      }
    }

    for(i = 0; i < 8; i++){
      diminui();
      if(portb.RB1 == 1){
        return;
      } else if(portb.RB1 == 0){
        reset();
        return;
      }
    }
  }
}

void aumenta(){
  delay_ms(300);
  latd = latd >> 1;
  latd.RB7 =~ latd.RB7;
}

void diminui(){
  delay_ms(300);
  latd = latd << 1;
}

void main() {
  trisb.RB0 = 1;   // RESET
  trisb.RB1 = 1;   // STOP
  trisb.RB2 = 1;   // START

  adcon1 = 15;
  latd = 0;
  
  while(1){
     if(portb.RB2 == 0){
       start();
     }
  }
}
