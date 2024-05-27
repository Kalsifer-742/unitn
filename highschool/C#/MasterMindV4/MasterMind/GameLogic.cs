using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using Pastel;

namespace MasterMind
{
    class GameLogic
    {
        private string[] code;
        static private string[] colors = {"Red", "Green", "Blue", "Yellow"};

        //constructor
        public GameLogic(int codeLength)
        {
            code = new string[codeLength];
            init();
        }

        //initialization
        private void init()
        {
            Random rng = new Random();
            for (int i = 0; i < code.Length; i++)
            {
                switch(rng.Next(0, colors.Length))
                {
                    case 0:
                        code[i] = colors[0];
                        break;
                    case 1:
                        code[i] = colors[1];
                        break;
                    case 2:
                        code[i] = colors[2];
                        break;
                    case 3:
                        code[i] = colors[3];
                        break;
                }
            }
        }
        public void colorsetPrint()
        {
            Console.Write("colors: ");
            for (int i = 0; i < colors.Length; i++)
            {
                Console.Write(colors[i].Pastel(Color.FromName(colors[i])) + " ");
            }
            Console.WriteLine();
        }

        //core
        public void Start(int attempts)
        {
            string[] attempt;
            string[] ret;

            for (int i = 0; i < attempts; i++)
            {
                do
                {
                    Console.WriteLine("Attempt n° " + (i + 1));
                    attempt = Console.ReadLine().Split();
                } while (attempt.Length != code.Length);

                ret = Check(attempt, out int win);

                Console.Write("CodeMaker: ");
                for (int j = 0; j < ret.Length; j++)
                {
                    if(ret[j] != null)
                    {
                        //Console.BackgroundColor = ret[j] == "Black" ? ConsoleColor.White : ConsoleColor.Black;
                        Console.Write(ret[j].Pastel(Color.FromName(ret[j] == "Black" ? "DarkGray" : "White"))); 
                        //Console.BackgroundColor = ConsoleColor.Black;
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();

                if(win == 1)
                {
                    Console.WriteLine("CodeBreaker has Won");
                    break;
                }
                else if(i == attempts - 1)
                {
                    Console.WriteLine("CodeMaker has Won");
                }
            }
        }
        private string[] Check(string[] attempt, out int win)
        {
            string[] codeCopy = new string[code.Length];
            string[] ret = new string[code.Length];
            win = 0;            

            for (int i = 0; i < code.Length; i++)
            {
                codeCopy[i] = code[i];
            }

            for (int i = 0; i < code.Length; i++)
            {
                if (attempt[i] == code[i])
                {
                    ret[i] = "Black";
                    win++;

                    codeCopy[i] = null;
                    attempt[i] = null;
                }
            }

            for (int i = 0; i < code.Length; i++)
            {
                if(attempt[i] != null && Array.IndexOf(codeCopy, attempt[i]) != -1)
                {
                    ret[i] = "White";
                }
            }

            if (win == code.Length)
            {
                win = 1;
            }
            else
            {
                win = 0;
            }
            Array.Sort(ret);
            return ret;
        }

        //extra
        public void debugCode()
        {
            Console.Write("DEBUG CodeMaker code: ");
            for (int i = 0; i < code.Length; i++)
            {
                Console.Write(code[i] + " ");
            }
            Console.WriteLine();
        }
    }
}
