#define led PC0
#define chave PD4

int main(){
  DDRC = 255; //Portal C como saída
  DDRD = 0; //Portal D como entrada
  TCCR0A = 0;
  TCCR0B |= (1<<CS02) | (1<<CS01) | (CS00);
  
  while(1){
    if(TCNT0 == 255){
      PORTC ^= 255;//Inverte o estado do led
      TCNT0 = 0;//Reinicia o contador
    }
  }
}
