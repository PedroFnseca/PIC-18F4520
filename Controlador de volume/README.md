# Controlador de Volume 🤖
> ### Este projeto tem como objetivo controlar o volume de algo a partir de dois botões e 8 leds simulando um volume de 0 a 100%.

<br> 

### Componentes ✍🏻

- 1x PIC-18F4520
- 2x Botões
- 8x Leds
- 8x Resistores 220Ω
- 2x Resistores 10kΩ
- 1x Protoboard
- Alguns Jumpers

## Circuito 📌

![image](https://user-images.githubusercontent.com/97262778/203568941-9026627b-c26b-47c7-bf11-46883ca26022.png)

<br>

## Código 📚
> ### O código também pode ser encontrado [aqui](./ControladorVolume.c)

```c
void main() {
  trisb.RB0 = 1;
  trisb.RB1 = 1;
  trisd = 0;
  portd = 0;
  latd = 0;
  adcon1 = 15;

  while (1)
  {
    // Encrementa o volume
    if (portb.RB0 == 1)
    {
      delay_ms(300);
      latd = latd >> 1;
      latd.RB7 =~ latd.RB7;
    }

    // Decrementa o volume
    if (portb.RB1 == 1)
    {
      latd = latd << 1;
    }
  }
}
```
