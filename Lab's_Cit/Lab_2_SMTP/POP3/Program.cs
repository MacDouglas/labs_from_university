using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.IO;
using System.Net.Security;

namespace POP3
{
    class Program
    {
        static void Main(string[] args)
        {
            string server = "pop.mail.ru";

            TcpClient client = new TcpClient(server, 995);

            var stream = client.GetStream();
            var sslStream = new SslStream(stream);

            sslStream.AuthenticateAsClient(server);

            var writer = new StreamWriter(sslStream);
            var reader = new StreamReader(sslStream);

            writer.WriteLine("USER qasmoke123");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("PASS i$yaslPCAT42");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("STAT");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("LIST 1");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            string key = Console.ReadLine();
            

            writer.WriteLine("TOP 1 10");
            writer.Flush();
            for (int i = 0; i < Convert.ToInt32(key); i++)
            {
                Console.WriteLine(reader.ReadLine());
            }
            //bool key = true;
            //string key1;
            //while (key)
            //{
            //    key1 = Console.ReadLine();
            //    if(key1 == "exit")
            //    {
            //        break;
            //    }
            //    writer.WriteLine(key1);
            //    writer.Flush();
            //    Console.WriteLine(reader.ReadLine());
            //}

            writer.WriteLine("QUIT");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());
        }
    }
}
