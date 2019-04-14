
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ATLProject2Lib;

namespace client
{
    class CSharpEventSink : _ITestEvents
    {
        public void Notify(string str)
        {
            Console.Write("\n  -- Notification -- {0}", str);
        }
    }
    class CsClient
    {
        static void Main(string[] args)
        {
            Console.Write("\n  C# Client AutoTest for COM Project");
            Console.Write("\n ===========================\n");
            string reg = "(S)(.*)";       
            string regforname = "(T)(.*)";
            string filepathDir = "../../../ATLProject2";
            Console.WriteLine("Demostrating 1st COM, FileMng. This COM object should receive a string path and a regular expression, and return a string list of the matched filename/filepath.");
            Console.WriteLine("Finding regular expression '" + regforname + "' for filenames under " + filepathDir);
            FileMng fm = new FileMng();
            object result = new object();
            fm.GetFileList(filepathDir,regforname,ref result);
            Array ct = (Array)result;

            string[] content = new string[ct.Length];
            ct.CopyTo(content, 0);

            Console.WriteLine(content.Length + " files are found:");
            for (int i=0;i< content.Length;i++)
            {
                Console.WriteLine("File "+i+": "+content[i]);
            }
            Console.WriteLine("Press any key to see result of 2nd COM");

           Console.ReadLine();
            Console.WriteLine("Demostrating 2nd COM, TextSearch. This COM object should receive a string path and a regular expression, and return the line numbers that matches.");
            Console.WriteLine("Finding regular expression '" + reg + "' for lines under " + filepathDir);
            TextSearcher ts = new TextSearcher();
            foreach (string i in content) {
                string reply = "";
                ts.FindLines(i, reg, ref reply);
                if(reply!="") Console.WriteLine(reply);
            }
            Console.WriteLine("Press any key to exit");
            Console.ReadLine();
        }
    }
}
