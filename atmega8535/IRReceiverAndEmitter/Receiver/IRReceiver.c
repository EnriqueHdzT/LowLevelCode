/*******************************************************
This program was created by the
CodeWizardAVR V2.60 Evaluation
Automatic Program Generator
� Copyright 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : IRReceiver
Version :
Date    : 10/2/2024
Author  :
Company :
Comments:


Chip type               : ATmega8535
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 128
*******************************************************/

#include <mega8535.h>
#include <delay.h>

// Declare your global variables here

void main(void)
{
// Declare your local variables here
#define IRInput PINB .0

      bit IRPreviousState = 0;
      bit IRCurrentState = 0;

      bit motorLeftOut0 = 0;
      bit motorLeftOut1 = 0;
      bit motorRightOut0 = 0;
      bit motorRightOut1 = 0;

      unsigned char counter = 0x00;

      // Input/Output Ports initialization
      // Port A initialization
      // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=Out Bit2=Out Bit1=Out Bit0=Out
      DDRA = (0 << DDA7) | (0 << DDA6) | (0 << DDA5) | (0 << DDA4) | (1 << DDA3) | (1 << DDA2) | (1 << DDA1) | (1 << DDA0);
      // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=0 Bit2=0 Bit1=0 Bit0=0
      PORTA = (0 << PORTA7) | (0 << PORTA6) | (0 << PORTA5) | (0 << PORTA4) | (0 << PORTA3) | (0 << PORTA2) | (0 << PORTA1) | (0 << PORTA0);

      // Port B initialization
      // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
      DDRB = (0 << DDB7) | (0 << DDB6) | (0 << DDB5) | (0 << DDB4) | (0 << DDB3) | (0 << DDB2) | (0 << DDB1) | (0 << DDB0);
      // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=P
      PORTB = (0 << PORTB7) | (0 << PORTB6) | (0 << PORTB5) | (0 << PORTB4) | (0 << PORTB3) | (0 << PORTB2) | (0 << PORTB1) | (0 << PORTB0);

      // Port C initialization
      // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
      DDRC = (0 << DDC7) | (0 << DDC6) | (0 << DDC5) | (0 << DDC4) | (0 << DDC3) | (0 << DDC2) | (0 << DDC1) | (0 << DDC0);
      // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
      PORTC = (0 << PORTC7) | (0 << PORTC6) | (0 << PORTC5) | (0 << PORTC4) | (0 << PORTC3) | (0 << PORTC2) | (0 << PORTC1) | (0 << PORTC0);

      // Port D initialization
      // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
      DDRD = (0 << DDD7) | (0 << DDD6) | (0 << DDD5) | (0 << DDD4) | (0 << DDD3) | (0 << DDD2) | (0 << DDD1) | (0 << DDD0);
      // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
      PORTD = (0 << PORTD7) | (0 << PORTD6) | (0 << PORTD5) | (0 << PORTD4) | (0 << PORTD3) | (0 << PORTD2) | (0 << PORTD1) | (0 << PORTD0);

      // Timer/Counter 0 initialization
      // Clock source: System Clock
      // Clock value: Timer 0 Stopped
      // Mode: Normal top=0xFF
      // OC0 output: Disconnected
      TCCR0 = (0 << WGM00) | (0 << COM01) | (0 << COM00) | (0 << WGM01) | (0 << CS02) | (0 << CS01) | (0 << CS00);
      TCNT0 = 0x00;
      OCR0 = 0x00;

      // Timer/Counter 1 initialization
      // Clock source: System Clock
      // Clock value: Timer1 Stopped
      // Mode: Normal top=0xFFFF
      // OC1A output: Disconnected
      // OC1B output: Disconnected
      // Noise Canceler: Off
      // Input Capture on Falling Edge
      // Timer1 Overflow Interrupt: Off
      // Input Capture Interrupt: Off
      // Compare A Match Interrupt: Off
      // Compare B Match Interrupt: Off
      TCCR1A = (0 << COM1A1) | (0 << COM1A0) | (0 << COM1B1) | (0 << COM1B0) | (0 << WGM11) | (0 << WGM10);
      TCCR1B = (0 << ICNC1) | (0 << ICES1) | (0 << WGM13) | (0 << WGM12) | (0 << CS12) | (0 << CS11) | (0 << CS10);
      TCNT1H = 0x00;
      TCNT1L = 0x00;
      ICR1H = 0x00;
      ICR1L = 0x00;
      OCR1AH = 0x00;
      OCR1AL = 0x00;
      OCR1BH = 0x00;
      OCR1BL = 0x00;

      // Timer/Counter 2 initialization
      // Clock source: System Clock
      // Clock value: Timer2 Stopped
      // Mode: Normal top=0xFF
      // OC2 output: Disconnected
      ASSR = 0 << AS2;
      TCCR2 = (0 << WGM20) | (0 << COM21) | (0 << COM20) | (0 << WGM21) | (0 << CS22) | (0 << CS21) | (0 << CS20);
      TCNT2 = 0x00;
      OCR2 = 0x00;

      // Timer(s)/Counter(s) Interrupt(s) initialization
      TIMSK = (0 << OCIE2) | (0 << TOIE2) | (0 << TICIE1) | (0 << OCIE1A) | (0 << OCIE1B) | (0 << TOIE1) | (0 << OCIE0) | (0 << TOIE0);

      // External Interrupt(s) initialization
      // INT0: Off
      // INT1: Off
      // INT2: Off
      MCUCR = (0 << ISC11) | (0 << ISC10) | (0 << ISC01) | (0 << ISC00);
      MCUCSR = (0 << ISC2);

      // USART initialization
      // USART disabled
      UCSRB = (0 << RXCIE) | (0 << TXCIE) | (0 << UDRIE) | (0 << RXEN) | (0 << TXEN) | (0 << UCSZ2) | (0 << RXB8) | (0 << TXB8);

      // Analog Comparator initialization
      // Analog Comparator: Off
      ACSR = (1 << ACD) | (0 << ACBG) | (0 << ACO) | (0 << ACI) | (0 << ACIE) | (0 << ACIC) | (0 << ACIS1) | (0 << ACIS0);
      SFIOR = (0 << ACME);

      // ADC initialization
      // ADC disabled
      ADCSRA = (0 << ADEN) | (0 << ADSC) | (0 << ADATE) | (0 << ADIF) | (0 << ADIE) | (0 << ADPS2) | (0 << ADPS1) | (0 << ADPS0);

      // SPI initialization
      // SPI disabled
      SPCR = (0 << SPIE) | (0 << SPE) | (0 << DORD) | (0 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);

      // TWI initialization
      // TWI disabled
      TWCR = (0 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | (0 << TWEN) | (0 << TWIE);

      while (1)
      {
            IRCurrentState = (0 == IRInput) ? 0 : 1;

            if (((0 == IRCurrentState) && (1 == IRPreviousState)))
            {
                  switch (counter)
                  {
                  case 1:
                        motorLeftOut0 = 0;
                        motorLeftOut1 = 0;
                        motorRightOut0 = 0;
                        motorRightOut1 = 1;
                        break;
                  case 2:
                        motorLeftOut0 = 1;
                        motorLeftOut1 = 0;
                        motorRightOut0 = 1;
                        motorRightOut1 = 0;
                        break;
                  case 3:
                        motorLeftOut0 = 0;
                        motorLeftOut1 = 1;
                        motorRightOut0 = 0;
                        motorRightOut1 = 1;
                        break;
                  case 4:
                        motorLeftOut0 = 0;
                        motorLeftOut1 = 1;
                        motorRightOut0 = 0;
                        motorRightOut1 = 0;
                        break;
                  default:
                        motorLeftOut0 = 0;
                        motorLeftOut1 = 1;
                        motorRightOut0 = 0;
                        motorRightOut1 = 0;
                        break;
                  }
                  counter = 0;
            }
            if (((1 == IRCurrentState) && (0 == IRPreviousState)))
            {
                  delay_ms(25);
                  while (IRCurrentState == IRInput && counter < 5)
                  {
                        delay_ms(27);
                        counter++;
                  }
                  if (5 == counter)
                  {
                        motorLeftOut0 = 0;
                        motorLeftOut1 = 0;
                        motorRightOut0 = 0;
                        motorRightOut1 = 0;
                  }
            }

            if (0 == motorLeftOut0 && 0 == motorLeftOut1 && 0 == motorRightOut0 && 1 == motorRightOut1)
            {
                  PORTA = 0x01;
            }
            else if (1 == motorLeftOut0 && 0 == motorLeftOut1 && 1 == motorRightOut0 && 0 == motorRightOut1)
            {
                  PORTA = 0x0A;
            }
            else if (0 == motorLeftOut0 && 1 == motorLeftOut1 && 0 == motorRightOut0 && 1 == motorRightOut1)
            {
                  PORTA = 0x05;
            }
            else if (0 == motorLeftOut0 && 1 == motorLeftOut1 && 0 == motorRightOut0 && 0 == motorRightOut1)
            {
                  PORTA = 0x04;
            }
            else
            {
                  PORTA = 0x00;
            }

            IRPreviousState = IRCurrentState;
      }
}
