#define CHAVE1 PD1
#define CHAVE2 PD2
#define LED1 PC5
#define LED2 PC0

ISR(INT0_vect){
  PORTC &= ~(1<<LED1);
  for(unsigned char j=0;j<20;j++){
    PORTC |= (1<<LED2);
    _delay_ms(100);
    PORTC &= ~(1<<LED2);
    _delay_ms(100); 
  }
}

int main(){
  
  DDRD = 0;//Todos entradas
  DDRC |= (1<<LED1)|(1<<LED2);//Leds são saídas
  //PORTD |= (1<<CHAVE1)|(1<<CHAVE2);
  PORTC = 0;//Leds desligados
  EICRA = (1<<ISC00);//Interrupção na mudança de nível lógico
  EIMSK = (1<<INT0);//Habilita a INT0
  sei();//Liga o serviço geral de interrupção
  while(1){
    if(PIND & (1<<CHAVE1)){
      PORTC |= (1<<LED1);
      _delay_ms(5000);
      PORTC &= ~(1<<LED1);
      _delay_ms(5000); 
    }
  }
}
