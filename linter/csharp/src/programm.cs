using System;

namespace LinterDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 1 + 1;

            int unused = 42;   // ❌ unused variable

            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine(" Hello C# "); // ❌ spacing issue
        }
    }
}
