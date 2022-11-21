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