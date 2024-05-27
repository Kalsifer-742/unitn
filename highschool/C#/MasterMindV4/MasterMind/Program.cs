using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MasterMind
{
    class Program
    {
        static void Main(string[] args)
        {
            bool isInt;
            int codeLength;
            int attempts;
            do
            {
                Console.Write("Code length: ");
                isInt = int.TryParse(Console.ReadLine(), out codeLength);
            } while (!isInt);
            do
            {
                Console.Write("Attempts: ");
                isInt = int.TryParse(Console.ReadLine(), out attempts);
            } while (!isInt);

            GameLogic game = new GameLogic(codeLength);

            game.debugCode();

            game.colorsetPrint();

            game.Start(attempts);

            Console.ReadKey();
        }
    }
}
