#ifndef SERIALCOMM_H_
#define SERIALCOMM_H_

#include <Arduino.h>

class SerialComm
{
    public:
        void open(unsigned long buad);
        static SerialComm * getInstance();

        // Write functions and Read functions
        String read();
        template <typename T> void write(T msg) { Serial.print(msg); }
        template <typename T> void writeln(T msg) { Serial.println(msg); }

    private:
        SerialComm();
        static SerialComm * instance;
        unsigned long buad;
};

#endif