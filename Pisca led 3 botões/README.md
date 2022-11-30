# Pisca led 3 botões
> ### Este projeto tem como objetivo ter 3 botões que possuem funções diferentes sendo: iniciar, reset e parar.
> ### Quando o botão inciar for pressionado irá iniciar uma sequência de leds que irão acender um por um e desligar da mesma forma. O reset irá parar e apagar todos. E o parar deixara a sequência parada no ultimo led aceso.

<br>

### Componentes ✍🏻

- 1x PIC-18F4520
- 3x Botões
- 8x Leds
- 8x Resistores 220Ω
- 3x Resistores 10kΩ
- 1x Protoboard
- Alguns Jumpers

## Circuito 📌

![image](https://user-images.githubusercontent.com/97262778/203568628-e9330e08-968a-4b2a-a01b-1e456abbc167.png)

<br>

## Código 📚

> ### O código também pode ser encontrado [aqui](./PiscaLed3Botoes.c) com mais detalhes.

```c
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
```
