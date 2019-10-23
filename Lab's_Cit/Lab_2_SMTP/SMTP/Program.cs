using System;
using System.Net.Sockets;
using System.IO;
using System.Net.Security;
//using System.Net.netstandard;

namespace SMTP
{
    class Program
    {
        static void Main(string[] args)
        {
            ////Console.WriteLine("Hello World!");

            //TcpClient tcpClient = new TcpClient();

            ////подключения по IP и по указанному номеру порта.

            //tcpClient.Connect("imap.mail.ru", 993);

            ////получение потока

            //NetworkStream networkStream = tcpClient.GetStream();

            ////поток для чтения

            //StreamReader clientStreamReader = new StreamReader(networkStream);

            ////поток для записи

            //StreamWriter clientStreamWriter = new StreamWriter(networkStream);

            //while (true)

            //{

            //    clientStreamReader.Read();
            
            //}
            string server = "smtp.mail.ru";

            TcpClient client = new TcpClient(server, 465);

            var stream = client.GetStream();

            var sslStream = new SslStream(stream);

            sslStream.AuthenticateAsClient(server);

            var writer = new StreamWriter(sslStream);

            var reader = new StreamReader(sslStream);

            writer.WriteLine("EHLO " + server);

            writer.Flush();

            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("MAIL FROM " + "stalkergta-99@mail.ru");

            writer.Flush();

            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("RCPT TO " + "stalkergta-99@mail.ru");

            writer.Flush();

            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("DATA");

            writer.Flush();

            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("RSET");

            writer.Flush();

            Console.WriteLine(reader.ReadLine());
        }
    }
}
