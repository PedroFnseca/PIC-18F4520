# Pisca led com botão 🤖
> ### Este projeto tem como objetivo acender e desligar um led com um botão.

<br>

### Componentes ✍🏻

- 1x PIC-18F4520
- 1x Led
- 1x Resistor 220Ω
- 1x Botão
- 1x Protoboard
- Alguns Jumpers

## Circuito 📌

<!-- Colocar imagem aqui depois -->

<br>

## Código 📚
> ### O código também pode ser encontrado [aqui](./PiscaLed.c)

```c
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
```

<br>


