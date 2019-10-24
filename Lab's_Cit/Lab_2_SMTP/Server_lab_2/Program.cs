using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Net.Security;

namespace server_lab_2
{
    public class SynchronousSocketListener
    {
        // Incoming data from the client.  
        public static string data = null;
        public static void smtp()
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

            writer.WriteLine("cWFzbW9rZTEyM0BtYWlsLnJ1");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("aSR5YXNsUENBVDQy");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("MAIL FROM: qasmoke123@mail.ru");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("RCPT TO: stalkergta-99@mail.ru");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("DATA");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("test \r\n.");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());

            writer.WriteLine("QUIT");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());
        }
        public static void pop3()
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
      
            writer.WriteLine("QUIT");
            writer.Flush();
            Console.WriteLine(reader.ReadLine());
        }
        public static void StartListening()
        { 
            byte[] bytes = new Byte[1024];

            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress ipAddress = ipHostInfo.AddressList[0];
            IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 11000);

            Socket listener = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            //try
            //{
                listener.Bind(localEndPoint);
                listener.Listen(10);

                while (true)
                {
                    Console.WriteLine("Waiting for a connection...");
                    Socket handler = listener.Accept();
                    data = null;

                    // An incoming connection needs to be processed.  
                    while (true)
                    {
                        int bytesRec = handler.Receive(bytes);
                        data += Encoding.ASCII.GetString(bytes, 0, bytesRec);

                        if (data.IndexOf("<EOF>") > -1)
                        {
                            break;
                        }

                        int key = Convert.ToInt32(data);
                        if (key == 1)
                        {
                            smtp();
                        }
                        if(key == 2)
                        {
                            pop3();
                        }
                        // Show the data on the console.  
                        Console.WriteLine("Text received : {0}", data);

                        // Echo the data back to the client.  
                        byte[] msg = Encoding.ASCII.GetBytes(data);

                        handler.Send(msg);
                    }
        
                    handler.Shutdown(SocketShutdown.Both);
                    handler.Close();
                }

            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine(e.ToString());
            //}

            Console.WriteLine("\nPress ENTER to continue...");
            Console.Read();
        }

        public static int Main(String[] args)
        {
            StartListening();
            return 0;
        }
    }
}