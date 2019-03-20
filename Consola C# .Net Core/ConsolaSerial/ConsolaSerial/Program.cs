using System;
using System.IO.Ports;

namespace ConsolaSerial
{
    class Program
    {
        static SerialPort miPuertoSerie;
        static int velocidadPuertos = 115200;
        static string[] PuertosDisponibles;
        static int indicePuertos = 0;
        //=======================================================================

        public static void AbrePuerto(string numeroPuerto)
        {
            try
            {
                miPuertoSerie = new SerialPort(numeroPuerto);
                miPuertoSerie.BaudRate = velocidadPuertos;
                miPuertoSerie.Parity = Parity.None;
                miPuertoSerie.StopBits = StopBits.One;
                miPuertoSerie.DataBits = 8;
                miPuertoSerie.Handshake = Handshake.None;
                miPuertoSerie.RtsEnable = true;
                miPuertoSerie.ReadTimeout = 500;
                miPuertoSerie.WriteTimeout = 500;
                miPuertoSerie.Open();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error de Conexión: " + ex.Message);
            }
        }//Fin AbrePuerto ----------------------------------------

        public static void CierraPuerto()
        {
            try
            {
                if (miPuertoSerie.IsOpen) miPuertoSerie.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error cerrando Puerto " + ex.Message);
            }
        }//Fin CierraPuerto ----------------------------------------

        public void ObtienePuertosDisponibles()
        {
            PuertosDisponibles = SerialPort.GetPortNames();
        }//Fin ObtienePuertosDisponibles ----------------------------------------

        public int CantPuertosDisponibles()
        {
            return SerialPort.GetPortNames().Length;
        }//Fin ObtienePuertosDisponibles ----------------------------------------

        public static void LeePuerto()
        {
            try
            {
                //miPuertoSerie.Write("1\n");
                miPuertoSerie.DataReceived += new SerialDataReceivedEventHandler(Datos_Recibidos);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error de E/S: " + ex.Message);
            }
        }//Fin LeePuerto ----------------------------------------

        //=======================================================================

        public static void Datos_Recibidos(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            try
            {
                string laData = miPuertoSerie.ReadLine();
                laData = laData.Substring(0, laData.Length - 1);

                if (laData != String.Empty)
                {
                    Console.WriteLine(laData);
                }
                else
                {
                    Console.WriteLine("Error: No se recibieron datos");
                }
                CierraPuerto();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error de Conexión: " + ex.Message);
            }

        }//Fin Datos_Recibidos ----------------------------------------

        static void Main(string[] args)
        {
            AbrePuerto(PuertosDisponibles[indicePuertos]);
            LeePuerto();
        }
       
    }
}
