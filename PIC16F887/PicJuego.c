void SonidoInicio() {
    Sound_Play(440, 120); Delay_ms(50);
    Sound_Play(523, 120); Delay_ms(50);
    Sound_Play(659, 120); Delay_ms(50);
    Sound_Play(880, 100); Delay_ms(30);
    Sound_Play(1046, 180); Delay_ms(100);
}

void SonidoVictoria() {
    Sound_Play(784, 150); Delay_ms(50);
    Sound_Play(880, 150); Delay_ms(50);
    Sound_Play(988, 200); Delay_ms(50);
    Sound_Play(1046, 300); Delay_ms(100);
    Sound_Play(1318, 200); Delay_ms(200);
}

void SonidoDerrota() {
    Sound_Play(988, 100); Delay_ms(50);
    Sound_Play(784, 100); Delay_ms(50);
    Sound_Play(523, 100); Delay_ms(50);
    Sound_Play(349, 150); Delay_ms(50);
    Sound_Play(196, 300); Delay_ms(100);
}

void main() {

    ANSEL  = 0;
    ANSELH = 0;
    C1ON_bit = 0;
    C2ON_bit = 0;

    OPTION_REG.F7 = 0;
    TRISB.F0 = 1;
    TRISB.F1 = 1;


    Sound_Init(&PORTC, 3);

    while (1) {
        unsigned char valor = (PORTB & 0b00000011);

        switch (valor) {
            case 0b01: SonidoVictoria(); break;
            case 0b11: SonidoInicio(); break;
            case 0b10: SonidoDerrota(); break;
        }

        Delay_ms(10);
}
}
