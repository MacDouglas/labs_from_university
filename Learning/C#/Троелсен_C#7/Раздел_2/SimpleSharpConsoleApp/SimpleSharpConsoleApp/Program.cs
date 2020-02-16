using System;


namespace SimpleSharpConsoleApp
{
    class Program
    {
        static void ShowEnvironmentDetails()
        {
            foreach (string drive in Environment.GetLogicalDrives())
                Console.WriteLine("Drive: {0}", drive);

            Console.WriteLine("OS: {0}", Environment.OSVersion);

            Console.WriteLine("Number of processors: {0}", Environment.ProcessorCount);

            Console.WriteLine(".NET Version: {0}", Environment.Version);
            Console.WriteLine("Is64BitOperatingSystem: {0}", Environment.Is64BitOperatingSystem);
        }
        static int Main(string[] args)
        {
            //for (int i = 0; i < args.Length; i++)
            //Console.WriteLine("Arg: {0}", args[i]);

            //foreach (string arg in args)
            //Console.WriteLine("Arg: {0}", arg);

            //string[] theArgs = Environment.GetCommandLineArgs();
            //foreach(string arg in theArgs)
            //    Console.WriteLine("Arg: {0}", arg);

            ShowEnvironmentDetails();

            Console.ReadLine();

            return -1;


            //Console.Title = "My Rocking App";
            //Console.ForegroundColor = ConsoleColor.Yellow;
            //Console.BackgroundColor = ConsoleColor.Blue;
            //Console.WriteLine("*********************************");
            //Console.WriteLine("**Welcome to my rocking app******");
            //Console.WriteLine("*********************************");
            ////Console.BackgroundColor = ConsoleColor.White;
            ////1 Ii Ll
            //SportCar Ford = new SportCar();
            //Ford.GetPetName();
            //Console.ReadKey();

            //MessageBox.Show("All done!")



        }
    }
}
