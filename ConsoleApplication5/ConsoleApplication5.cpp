#include <iostream>
#include "sodium.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "rsa.h"
#pragma warning(disable : 4996)
using namespace std;
#define MESSAGE (const unsigned char *) "test"
#define MESSAGE_LEN 4

int main()
{




    int opcion;
    bool repetir = true;

    do {
        //system("cls");

         // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1.Generacion" << endl;
        cout << "2.Cifrado" << endl;
        cout << "3.Descifrado" << endl;
        cout << "4.Firma" << endl;
        cout << "5.Verificar Firma" << endl;
        cout << "0. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;


     
        //unsigned char IDalice[142] = "alice@iteso.mx ";
        //unsigned char IDaliceSERVER[142] = "alice@iteso.mx";
        //unsigned char client_pk[crypto_kx_PUBLICKEYBYTES], client_sk[crypto_kx_SECRETKEYBYTES];
        //unsigned char client_rx[crypto_kx_SESSIONKEYBYTES], client_tx[crypto_kx_SESSIONKEYBYTES];
        //crypto_kx_keypair(client_pk, client_sk);

        //unsigned char server_pk[crypto_kx_PUBLICKEYBYTES], server_sk[crypto_kx_SECRETKEYBYTES];
        //unsigned char server_rx[crypto_kx_SESSIONKEYBYTES], server_tx[crypto_kx_SESSIONKEYBYTES];
        //crypto_kx_keypair(server_pk, server_sk);
        //unsigned char MACr[crypto_auth_hmacsha512_BYTES];
        //unsigned char MACserver[crypto_auth_hmacsha512_BYTES];
        //int result = crypto_auth_hmacsha512_verify(MACr, MACserver, crypto_auth_hmacsha512_BYTES, server_rx);
        switch (opcion) {
        case 1:
            // Lista de instrucciones de la opción 1                

            system("pause>nul"); // Pausa
            std::cout << "1: Generacion y Recuperacion de Claves\n";
            //std::cout << "Codigo para generar\n";
            {
                char cadena[100];
                bool band = true;
                long long int num;
                int opc, p, q;
                RSA T;
                //system("clear");
                while (band)
                {
                    cout << endl;
                    cout << "Cifrado RSA" << endl;
                    //cout << "******************************" << endl << endl;
                    cout << "1.- Generar p y q aleatorios. " << endl;
                    //cout << "2.- Ingresar p y q desde el teclado. " << endl;
                    cout << "3.- Salir del submenu. " << endl;
                    cin >> opc;
                    //string msj;
                    //cin >> msj;
                    switch (opc)
                    {
                    case 1:	T.generarPrimos();
                        T.generarClaves();
                        T.mostrar();
                        cout << "Ingrese el texto a cifrar: ";
                        getchar();
                        cin.getline(cadena, 100);
                        cout << "mensaje cifrado: " << T.cifrarTexto(cadena) << endl;

                        cout << "Ingrese el texto a descifrar: ";
                        cin.getline(cadena, 100);
                        cout << "mensaje descifrado: " << T.descifrarTexto(cadena) << endl;
                        break;

                    case 2:	do
                    {
                        cout << "Ingrese p: ";
                        cin >> p;
                        cout << "Ingrese q: ";
                        cin >> q;
                    } while (p == q);

                    T.insertarP(p);
                    T.insertarQ(q);

                    T.generarClaves();
                    T.mostrar();
                    cout << "Ingrese el texto a cifrar: ";
                   
                    getchar();
                    cin.getline(cadena, 100);
                    cout << "mensaje cifrado: " << T.cifrarTexto(cadena) << endl;

                    cout << "Ingrese el texto cifrado para descifrarlo: ";
                    cin.getline(cadena, 100);
                    cout << "mensaje descifrado: " << T.descifrarTexto(cadena) << endl;
                    break;
                    case 3: cout << endl << "Programa Finalizado. " << endl << endl;
                        band = false;
                        break;
                    default: cout << "Opcion Incorrecta. " << endl;
                    }
                }
                //return 0;
            }
            break;

        case 2:
            // Lista de instrucciones de la opción 2                

            system("pause>nul"); // Pausa
            std::cout << "2: Cifrado\n";
            {
                string text;
                string temp;
                string ruta;
                cout << "\nIngrese una ruta absoluta: ";
                cin >> ruta;
                ifstream fe(ruta);
                while (!fe.eof()) {
                    fe >> temp;
                    text += temp + " ";
                }
                fe.close();
                std::cout << "-Texto en Claro\n";
                cout << text << endl;
            
            //ifstream fe("C:/prueba/texto.txt");

            unsigned char cipher_string[128];
            strcpy((char*)(cipher_string), text.c_str());
            //const char* cipher_string = text.c_str();
            int lenght_text = strlen((char*)cipher_string);
            unsigned char* cipher_text = new unsigned char[lenght_text];
            unsigned char* descipher_text = new unsigned char[lenght_text];
            unsigned char key[crypto_stream_chacha20_KEYBYTES];
            unsigned char nonce[crypto_stream_chacha20_NONCEBYTES];

            crypto_secretbox_keygen(key);
            randombytes_buf(nonce, sizeof nonce);
            int errorCode = crypto_stream_chacha20_xor(cipher_text, cipher_string, lenght_text, nonce, key);
            std::cout << "-Texto Cifrado\n";
            for (int i = 0; i < lenght_text; i++) {
               
                std::cout << std::setfill('0') << std::setw(2) << std::hex << int(cipher_text[i]);
            }

            std::cout << std::endl;

            errorCode = crypto_stream_chacha20_xor(descipher_text, cipher_text, lenght_text, nonce, key);

            for (int j = 0; j < lenght_text - 1; j++) {
                //std::cout << std::setfill('0') << std::setw(2) << std::hex << int(descipher_text[j]);
            }
            //std::cout << std::endl;
            //std::cout << descipher_text;

            //return 0;
            }
            break;

        case 3:
            // Lista de instrucciones de la opción 3                

            system("pause>nul"); // Pausa 
            std::cout << "3: Descifrado\n";

            {
                string text;
                string temp;
                string ruta;
                cout << "\nIngrese una ruta absoluta: ";
                cin >> ruta;
                ifstream fe(ruta);
                while (!fe.eof()) {
                    fe >> temp;
                    text += temp + " ";
                }
                fe.close();
                std::cout << "-Texto Cifrado\n";
                


                unsigned char cipher_string[128];
                strcpy((char*)(cipher_string), text.c_str());
                //const char* cipher_string = text.c_str();
                int lenght_text = strlen((char*)cipher_string);
                unsigned char* cipher_text = new unsigned char[lenght_text];
                unsigned char* descipher_text = new unsigned char[lenght_text];
                unsigned char key[crypto_stream_chacha20_KEYBYTES];
                unsigned char nonce[crypto_stream_chacha20_NONCEBYTES];

                crypto_secretbox_keygen(key);
                randombytes_buf(nonce, sizeof nonce);
                int errorCode = crypto_stream_chacha20_xor(cipher_text, cipher_string, lenght_text, nonce, key);
                
                for (int i = 0; i < lenght_text; i++) {

                    //std::cout << std::setfill('0') << std::setw(2) << std::hex << int(cipher_text[i]);
                }
                
                std::cout << std::endl;

                errorCode = crypto_stream_chacha20_xor(descipher_text, cipher_text, lenght_text, nonce, key);

                for (int j = 0; j < lenght_text-1 ; j++) {
                    std::cout << std::setfill('0') << std::setw(2) << std::hex << int(descipher_text[j]);
                }
                
                std::cout << std::endl;
                std::cout << "-Texto Descifrado\n";
                std::cout << descipher_text;

                //return 0;
            }

            break;

        case 4:
            // Lista de instrucciones de la opción 4                

            system("pause>nul"); // Pausa  
            std::cout << "4: Firma\n";

            {

                if (sodium_init() == -1) {
                    return  1;
                }

                unsigned char client_pk[crypto_kx_PUBLICKEYBYTES], client_sk[crypto_kx_SECRETKEYBYTES];
                unsigned char client_rx[crypto_kx_SESSIONKEYBYTES], client_tx[crypto_kx_SESSIONKEYBYTES];
                crypto_kx_keypair(client_pk, client_sk);

                unsigned char server_pk[crypto_kx_PUBLICKEYBYTES], server_sk[crypto_kx_SECRETKEYBYTES];
                unsigned char server_rx[crypto_kx_SESSIONKEYBYTES], server_tx[crypto_kx_SESSIONKEYBYTES];
                crypto_kx_keypair(server_pk, server_sk);

                if (crypto_kx_client_session_keys(client_rx, client_tx, client_pk, client_sk, server_pk) != 0) {
                    exit(1);
                }

                if (crypto_kx_client_session_keys(server_rx, server_tx, server_pk, server_sk, client_pk) != 0) {
                    exit(1);
                }

                //BOB Calcula
                unsigned char reto[128];
                std::cout << std::setfill('0') << std::setw(2);
                std::cout.setf(std::ios::hex, std::ios::basefield);
                randombytes_buf(reto, sizeof(reto));
                for (int i = 0; i < 128; i++) {
                    //std::cout << std::hex << reto[i];
                    std::cout << (int)reto[i];
                }
                std::cout << std::endl;
                //BOB envía reto a ALICE
                //...

                //ALICE recibe y calcula la MAC
             
                unsigned char IDalice[142] = "alice@iteso.mx";
                for (int i = 14; i < 142; i++) {
                    IDalice[i] = reto[i - 14];
                }
                std::cout << "IDAlice---" << std::endl;
                for (int i = 0; i < 14; i++) {
                    std::cout << (char)IDalice[i];
                    std::cout << " ";
                }
                for (int i = 14; i < 142; i++) {
                    std::cout << (int)IDalice[i];
                }
                std::cout << std::endl;
                std::cout << "---" << std::endl;
                unsigned char MAC[crypto_auth_hmacsha512_BYTES];
                crypto_auth_hmacsha512(MAC, IDalice, 142, client_tx);
                //ALICE envia MAC a BOB

                //BOB verifica la MAC(r)
                unsigned char MACr[crypto_auth_hmacsha512_BYTES];
                unsigned char MACserver[crypto_auth_hmacsha512_BYTES];
                /*int result = crypto_auth_hmacsha512_verify(MACr, MAC, crypto_auth_hmacsha512_BYTES, server_rx);*/
                unsigned char IDaliceSERVER[142] = "alice@iteso.mx";
                for (int i = 14; i < 142; i++) {
                    IDalice[i] = reto[i - 14];
                }
                crypto_auth_hmacsha512(MACserver, IDaliceSERVER, 142, client_tx);
                int result = crypto_auth_hmacsha512_verify(MACr, MACserver, crypto_auth_hmacsha512_BYTES, server_rx);
                std::cout << "---" << std::endl;
                for (int i = 0; i < crypto_auth_hmacsha512_BYTES; i++) {
                    std::cout << (int)MAC[i];
                }
                std::cout << std::endl;
                std::cout << "---" << std::endl;
                for (int i = 0; i < crypto_auth_hmacsha512_BYTES; i++) {
                    std::cout << (int)MACserver[i];
                }
                std::cout << std::endl;
                std::cout << "---" << std::endl;

                std::cout << "resultado:" << result << std::endl;

            }
            break;

        case 5:
            // Lista de instrucciones de la opción 4   

            system("pause>nul"); // Pausa  
            std::cout << "5: Verificar Firma\n";

            if (sodium_init() == -1) {
                return  1;
            }

            std::cout << std::setfill('0') << std::setw(2);
            std::cout.setf(std::ios::hex, std::ios::basefield);

            unsigned char pk[crypto_sign_PUBLICKEYBYTES];
            unsigned char sk[crypto_sign_SECRETKEYBYTES];
            crypto_sign_keypair(pk, sk);

            unsigned char signed_message[crypto_sign_BYTES];
            unsigned long long signed_message_len;
            crypto_sign_detached(signed_message, &signed_message_len, MESSAGE, MESSAGE_LEN, sk);
            for (int i = 0; i < (crypto_sign_BYTES); i++) {
                std::cout << (int)signed_message[i];
            } std::cout << std::endl;

            if (crypto_sign_verify_detached(signed_message, MESSAGE, MESSAGE_LEN, pk)) {
                return 1;
            }
            else {
                std::cout << "Firma OK" << std::endl;
            }


            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

    return 0;


}




