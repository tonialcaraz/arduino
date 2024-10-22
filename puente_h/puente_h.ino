/*
 *  Taloselectronics
 *  soporte@taloselectronics.com 
 *  Rafael Lozano Rolón
*/

#define input_a 2
#define pwm 3
#define input_b 4

void setup()
{
    pinMode(input_a, OUTPUT);
    pinMode(input_b, OUTPUT);
    
}

void loop()
{
    //Giro a la derecha
    digitalWrite(input_a, HIGH);
    digitalWrite(input_b, LOW);

    //aumenta la velocidad hasta maximo 255
    for (int i = 0; i < 255; i++)
    {
        analogWrite(pwm, i);
        delay(20);
    }
    
    delay(500);

    //Disminuye velocidad
    for (int i = 255; i > 0; i--)
    {
        analogWrite(pwm, i);
        delay(20);
    }
    
    delay(500);

    //Giro a la izq
    digitalWrite(input_a, LOW);
    digitalWrite(input_b, HIGH);

    //aumenta la velocidad hasta maximo 255
    for (int i = 0; i < 255; i++)
    {
        analogWrite(pwm, i);
        delay(20);
    }
    
    delay(500);

    //Disminuye velocidad
    for (int i = 255; i > 0; i--)
    {
        analogWrite(pwm, i);
        delay(20);
    }
    //Esperar 1 segundo antes de volver a acelerar
    delay(500);
    
}
