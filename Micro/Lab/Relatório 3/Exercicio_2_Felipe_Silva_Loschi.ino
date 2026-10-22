void setup() {
  // put your setup code here, to run once:
  DDRD = 0b00000110;
  PORTD = 0b00000110;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD = 0b00000000;
  _delay_ms(500);
  PORTD = 0b00000010;
  _delay_ms(500);
  PORTD = 0b00000100;
  _delay_ms(500);
  PORTD = 0b00000110;
  _delay_ms(500);
}
