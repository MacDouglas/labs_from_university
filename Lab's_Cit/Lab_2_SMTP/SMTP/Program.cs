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
            string server = "smtp.mail.ru";

            TcpClient client = new TcpClient(server, 465);

            var stream = client.GetStream();
            var sslStream = new SslStream(stream);

            sslStream.AuthenticateAsClient(server);

            var writer = new StreamWriter(sslStream);
            var reader = new StreamReader(sslStream);

            writer.WriteLine("EHLO smtp.mail.ru");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());
            Console.WriteLine(reader.ReadLine());
            Console.WriteLine(reader.ReadLine());
            Console.WriteLine(reader.ReadLine());
            Console.WriteLine(reader.ReadLine());
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("AUTH LOGIN");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("bWlrZXdvbGY5OTEyMTAxQGdtYWlsLmNvbQ==");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("UWhVLXhUQy1CM1MtQkJq");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("MAIL FROM: mikewolf9912101@gmail.com");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("RCPT TO: qasmoke123@mail.ru");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("DATA");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            //writer.WriteLine("SUBJECT: test");
            //writer.Flush();
            //Console.WriteLine(reader.ReadLine());

            writer.WriteLine("test \r\n.");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("QUIT");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());
        }
    }
}
