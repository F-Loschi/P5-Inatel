#define temperatura PD2
#define pressao PD4
#define nivel PD5
#define peso PB0
#define led PD0
int main(){
  DDRD = 0;//Todos entradas
  DDRD |= (1<<led);
  PORTD = 0;//Todos iniciam desligados
  DDRB = 0;//Todos como entrada
  while(1){
    PORTD &= ~(1 << led);
    //1. Nível alro com temperatura e pressão alta
    while((PIND&(1<<temperatura))&&(PIND&(1<<nivel))&&(PIND&(1<<pressao))){
      PORTD |= (1<<led);
    }
    //2.Nível baixo com temperatura alta e peso alto
    while((PIND&(1<<temperatura))&&!(PIND&(1<<nivel))&&(PIND&(1<<peso))){
      PORTD |= (1<<led);
    }
    //3. Nível baixo com temperatura baixa e pessão alta
    while(!(PIND&(1<<temperatura))&&!(PIND&(1<<nivel))&&(PIND&(1<<pressao))){
      PORTD |= (1<<led);
    }
    //4. Nível baixo com peso baixo e temperatura alta
    while((PIND&(1<<temperatura))&&!(PIND&(1<<nivel))&&!(PIND&(1<<peso))){
      PORTD |= (1<<led);
    }
  }
}
