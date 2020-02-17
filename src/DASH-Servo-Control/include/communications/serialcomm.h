#ifndef SERIALCOMM_H_
#define SERIALCOMM_H_

#include <Arduino.h>

class SerialComm
{
    public:
        // Write functions and Read functions
        void open(unsigned long cbuad)
        {
            buad = cbuad;
            Serial.begin(cbuad);
        }
        static SerialComm * getInstance();

        

        String SerailComm::read()
        {
            return Serial.readString();
        }
        template <typename T> void write(T msg) { Serial.print(msg); }
        template <typename T> void writeln(T msg) { Serial.println(msg); }

    private:
        SerialComm();
        static SerialComm * instance;
        unsigned long buad;
};

#endif