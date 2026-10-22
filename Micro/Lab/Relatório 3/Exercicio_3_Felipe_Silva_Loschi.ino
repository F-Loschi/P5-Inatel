void setup() {
  // put your setup code here, to run once:
  DDRD = 0b00001110;
  PORTD = 0b10001110;
}

void loop() {
  // put your main code here, to run repeatedly:
  //Ele já está dentro de um loop, então agora é só fazer a lógica
  if(!(PIND & 0b10000000){//Começa entrando aqui em 01
    PORTD = 0b00000001;//Setando pra ele ir para 10
    _delay_ms(500);//Delay para o próximo
  }
  if(!(PIND & 0b10000000){
    PORTD = 0b00000001;//Setando pra ele ir para 00
    _delay_ms(500);//Delay para o próximo
  }
  if(!(PIND & 0b10000000){
    PORTD = 0b00000001;//Setando pra ele voltar para 01
    _delay_ms(500);//Delay para o próximo
  }
}
