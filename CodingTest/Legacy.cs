//using System;
//using System.Collections.Generic;
//using System.Text;

//namespace CodeTest
//{
//    internal class Program
//    {

//        static void Main(string[] args)
//        {
//            //Solution01 s1 = new Solution01();
//            //s1.Start();

//            Solution02 s2 = new Solution02();
//        }




//    }

//    class Solution02
//    {

//        public Solution02()
//        {
//            Start();
//        }

//        public void Start()
//        {
//            int count;
//            string[] arr;
//            count = int.Parse(Console.ReadLine());
//            arr = new string[count];
//            for (int i = 0; i < count; i++)
//            {
//                arr[i] = Console.ReadLine();
//            }

//            Console.WriteLine("SLURPYS OUTPUT");
//            for (int i = 0; i < count; i++)
//            {
//                Console.WriteLine("SLUR" + (CheckSlurpy(arr[i]) ? "YES" : "NO"));
//                Console.WriteLine("SLIM" + (CheckSlimp(arr[i]) == -1 ? "NO" : "YES"));
//                Console.WriteLine("SLUM" + (CheckSlump(arr[i]) == -1 ? "NO" : "YES"));
//            }
//            Console.WriteLine("END OF OUTPUT");
//        }

//        int CheckF(string str, int idx)
//        {
//            Console.WriteLine(str.Length + " / " + idx);
//            if (str.Length <= idx)
//            {
//                return -1;
//            }
//            if (!str[idx].Equals('F'))
//            {
//                return idx;
//            }

//            return CheckF(str, idx + 1);
//        }

//        int CheckSlump(string str)
//        {
//            if (str.Length <= 2)
//            {
//                return -1;
//            }
//            Console.WriteLine("slump(" + str);
//            if ((str[0].Equals('D') || str[0].Equals('E')) && str[1].Equals('F'))
//            {
//                // Console.WriteLine("slump init condition ok");
//                int nextIndex = CheckF(str, 2);
//                if (nextIndex != -1)
//                {

//                    char nextChar = str[nextIndex];
//                    if (nextChar.Equals('G'))
//                    {
//                        // Console.WriteLine("slump end");
//                        return nextIndex;
//                    }
//                    else
//                    {
//                        int sub = CheckSlump(str.Substring(nextIndex));

//                        if (sub != -1)
//                        {
//                            //  Console.WriteLine("new slump_" + sub);
//                            return sub + nextIndex;
//                        }
//                    }
//                }
//            }
//            return -1;
//        }

//        int CheckSlimp(string str)
//        {
//            if (str.Length <= 1)
//            {
//                return -1;
//            }
//            // Console.WriteLine("slimp("+str);
//            if (str[0].Equals('A'))
//            {
//                // Console.WriteLine("slimp init condition ok");
//                if (str[1].Equals('H'))
//                {
//                    // Console.WriteLine("slimp end");
//                    return 1;
//                }
//                else
//                {
//                    if (str[1].Equals('B'))
//                    {
//                        int sub = CheckSlimp(str.Substring(2));
//                        if (sub != -1)
//                        {
//                            // Console.WriteLine(sub);
//                            // Console.WriteLine("new slimp_" + str.Substring(2));
//                            if (str[2 + sub + 1].Equals('C'))
//                            {
//                                //    Console.WriteLine("slimp_ end");
//                                return sub + 3;
//                            }
//                            // Console.WriteLine("slimp fail");
//                        }
//                    }
//                    else
//                    {
//                        int sub = CheckSlump(str.Substring(1));
//                        if (sub != -1)
//                        {
//                            // Console.WriteLine(sub);
//                            //  Console.WriteLine("new slump_" + str.Substring(1));
//                            if (str[1 + sub + 1].Equals('C'))
//                            {
//                                //   Console.WriteLine("slump_ end");
//                                return sub + 2;
//                            }
//                            // Console.WriteLine("slump fail");
//                        }
//                    }
//                }
//            }
//            return -1;
//        }

//        bool CheckSlurpy(string str)
//        {
//            if (str.Length == 0)
//            {
//                return false;
//            }
//            int slimp = CheckSlimp(str);
//            if (slimp == -1) return false;
//            Console.WriteLine(str.Substring(0, slimp + 1));

//            int slump = CheckSlump(str.Substring(slimp + 1));
//            if (slump == -1) return false;
//            Console.WriteLine(str.Substring(slimp + 1));
//            return true;
//        }
//    }


//    class Solution01
//    {
//        static Dictionary<string, Node> sameStr = new Dictionary<string, Node>();
//        static string[] arr;
//        static int[] INPUT = { 1, 2, 4, 8, 16, 32, 64, 128 };

//        class Node
//        {
//            public Node[] next = new Node[4];
//            public bool isVisit = false;
//            public bool isLast;
//            public bool isSame;
//            public string data;
//            public int count = 1;
//            public int countRef = 1;
//        }

//        public void Start()
//        {
//            int row, col;
//            int newRow, newCol;
//            int big;

//            string[] s = Console.ReadLine().Split(' ');

//            int.TryParse(s[0], out row);
//            int.TryParse(s[1], out col);

//            big = col > row ? col : row;

//            newRow = big;
//            newCol = big;

//            for (int i = 1; i < INPUT.Length; i++)
//            {
//                if (big == INPUT[i - 1])
//                {
//                    newRow = INPUT[i - 1];
//                    newCol = INPUT[i - 1];
//                    break;
//                }

//                if (big > INPUT[i - 1] && big <= INPUT[i])
//                {
//                    newRow = INPUT[i];
//                    newCol = INPUT[i];
//                    break;
//                }
//            }
//            string[] tmp = new string[row];
//            arr = new string[newRow];

//            for (int i = 0; i < row; i++)
//            {
//                tmp[i] = Console.ReadLine();
//            }

//            for (int i = 0; i < newRow; i++)
//            {
//                StringBuilder sb = new StringBuilder();
//                if (i < tmp.Length)
//                {
//                    sb.Append(tmp[i]);
//                    sb.Append('0', (newCol - col));
//                }
//                else
//                {
//                    sb.Append('0', (newCol));
//                }
//                arr[i] = sb.ToString();
//            }

//            Console.WriteLine();
//            for (int i = 0; i < newRow; i++)
//            {
//                Console.WriteLine(arr[i]);
//            }
//            Console.WriteLine();

//            int newSize = newRow * newCol;
//            Node node = MakeNode(newRow, 0, 0, 0);

//            Console.WriteLine(node.countRef + " " + node.count);

//            Console.WriteLine("===========");
//            Console.WriteLine("===========");
//            Console.WriteLine("===========");
//            Draw(node);
//            Console.WriteLine("===========");
//            Console.WriteLine("===========");
//            Console.WriteLine("===========");
//            _DrawRef(node);
//        }

//        static void Draw(Node node)
//        {
//            if (node.isVisit)
//            {
//                Console.WriteLine(node.data);
//                return;
//            }
//            if (node.isLast)
//            {
//                Console.WriteLine("[EndNode]=" + node.data + "*");
//                return;
//            }
//            if (node.isSame)
//            {
//                Console.WriteLine("[Same]=" + node.next[0].data);
//                return;
//            }

//            Console.WriteLine(node.data + "*");
//            Draw(node.next[0]);
//            Draw(node.next[1]);
//            Draw(node.next[2]);
//            Draw(node.next[3]);
//            Console.WriteLine("===========");
//            return;

//        }

//        static void _DrawRef(Node node)
//        {
//            if (node.isVisit)
//            {
//                Console.WriteLine(node.data);
//                return;
//            }
//            if (node.isLast)
//            {
//                Console.WriteLine("[EndNode]=" + node.data + "*");
//                return;
//            }
//            if (node.isSame)
//            {
//                _DrawRef(node.next[0]);
//                return;
//            }

//            Console.WriteLine(node.data + "*");
//            _DrawRef(node.next[0]);
//            _DrawRef(node.next[1]);
//            _DrawRef(node.next[2]);
//            _DrawRef(node.next[3]);
//            Console.WriteLine("===========");
//            return;

//        }

//        static Node MakeNode(int size, int row, int col, int depth)
//        {
//            Node node = new Node();

//            //  Console.WriteLine(size + " " + (row) + " " + (col) + " " + depth);
//            string str = string.Empty;
//            int count = 0;
//            int countRef = 0;

//            if (size == 1)
//            {
//                node.next = null;
//                node.data = arr[row][col].ToString();
//                node.isLast = true;
//                node.isSame = false;

//                return node;
//            }


//            int newSize = (int)(size / 2);
//            int nexPoint = (int)(Math.Ceiling(size * 0.5));
//            // Console.WriteLine("사이즈 "+ newSize+ " 다음값 "+ nexPoint);

//            node.next[0] = MakeNode((int)newSize, row, col, depth + 1);
//            node.next[1] = MakeNode((int)newSize, row, col + nexPoint, depth + 1);
//            node.next[2] = MakeNode((int)newSize, row + nexPoint, col, depth + 1);
//            node.next[3] = MakeNode((int)newSize, row + nexPoint, col + nexPoint, depth + 1);

//            str = node.next[0].data + node.next[1].data + node.next[2].data + node.next[3].data;
//            count = node.next[0].count + node.next[1].count + node.next[2].count + node.next[3].count;
//            countRef = node.next[0].countRef + node.next[1].countRef + node.next[2].countRef + node.next[3].countRef;

//            if (Check(str))
//            {
//                node.isLast = true;
//                node.next = null;
//                count = 0;
//                countRef = 0;
//            }
//            else
//            {
//                if (!sameStr.ContainsKey(str))
//                {
//                    // Console.WriteLine("Not Same(" + str + ")");
//                    sameStr.Add(str, node);
//                }
//                else
//                {
//                    // Console.WriteLine("Same(" + str + ")");
//                    node.isSame = true;
//                    node.next = new Node[1];
//                    node.next[0] = sameStr[str];
//                    count = -1;
//                }
//            }
//            node.data = str;
//            node.count += count;
//            node.countRef += countRef;

//            // Console.WriteLine();
//            return node;
//        }


//        static bool Check(string str)
//        {
//            return (str.Replace('0', ' ').Trim() == string.Empty) || (str.Replace('1', ' ').Trim() == string.Empty);
//        }
//    }
//}


using System;

namespace CodeTest
{
    internal class Program
    {

        static void Main(string[] args)
        {
            //Solution01 s1 = new Solution01();
            //s1.Start();

            Solution02 s2 = new Solution02();
        }




    }

    class Solution02
    {

        public Solution02()
        {
            Start();
        }

        public void Start()
        {
            int count;
            string[] arr;
            count = int.Parse(Console.ReadLine());
            arr = new string[count];
            for (int i = 0; i < count; i++)
            {
                arr[i] = Console.ReadLine();
            }

            Console.WriteLine("SLURPYS OUTPUT");
            for (int i = 0; i < count; i++)
            {
                Console.WriteLine((CheckSlurpy(arr[i]) ? "YES" : "NO"));
                //Console.WriteLine("SLIM" + (CheckSlimp(arr[i]) == -1 ? "NO" : "YES"));
                //Console.WriteLine("SLUM" + (CheckSlump(arr[i]) == -1 ? "NO" : "YES"));
            }
            Console.WriteLine("END OF OUTPUT");
        }

        int CheckF(string str, int idx)
        {
            //Console.WriteLine(str.Length+" / " +idx);
            if (str.Length <= idx)
            {
                return -1;
            }
            if (!str[idx].Equals('F'))
            {
                return idx;
            }

            return CheckF(str, idx + 1);
        }

        int CheckSlump(string str)
        {
            if (str.Length <= 2)
            {
                return -1;
            }
            //Console.WriteLine("slump(" + str);
            if ((str[0].Equals('D') || str[0].Equals('E')) && str[1].Equals('F'))
            {
                // Console.WriteLine("slump init condition ok");
                int nextIndex = CheckF(str, 2);
                if (nextIndex != -1 && nextIndex<str.Length)
                {

                    char nextChar = str[nextIndex];
                    if (nextChar.Equals('G'))
                    {
                        // Console.WriteLine("slump end");
                        return nextIndex;
                    }
                    else
                    {
                        int sub = CheckSlump(str.Substring(nextIndex));

                        if (sub != -1)
                        {
                            //  Console.WriteLine("new slump_" + sub);
                            return sub + nextIndex;
                        }
                    }
                }
            }
            return -1;
        }

        int CheckSlimp(string str)
        {
            if (str.Length <= 1)
            {
                return -1;
            }
            // Console.WriteLine("slimp("+str);
            if (str[0].Equals('A'))
            {
                // Console.WriteLine("slimp init condition ok");
                if (str[1].Equals('H'))
                {
                    // Console.WriteLine("slimp end");
                    return 1;
                }
                else
                {
                    if (str[1].Equals('B'))
                    {
                        if (str.Length < 3) return -1;
                        int sub = CheckSlimp(str.Substring(2));

                        if (sub != -1 && sub+3<str.Length)
                        {
                            // Console.WriteLine(sub);
                            // Console.WriteLine("new slimp_" + str.Substring(2));
                            if (str[2 + sub + 1].Equals('C'))
                            {
                                //    Console.WriteLine("slimp_ end");
                                return sub + 3;
                            }
                            // Console.WriteLine("slimp fail");
                        }
                    }
                    else
                    {
                        int sub = CheckSlump(str.Substring(1));
                        if (sub != -1 && sub + 2 < str.Length)
                        {
                            // Console.WriteLine(sub);
                            //  Console.WriteLine("new slump_" + str.Substring(1));
                            if (str[1 + sub + 1].Equals('C'))
                            {
                                //   Console.WriteLine("slump_ end");
                                return sub + 2;
                            }
                            // Console.WriteLine("slump fail");
                        }
                    }
                }
            }
            return -1;
        }

        bool CheckSlurpy(string str)
        {
            if (str.Length == 0)
            {
                return false;
            }
            int slimp = CheckSlimp(str);
            if (slimp == -1) return false;
            //Console.WriteLine(str.Substring(0, slimp+1));

            int slump = CheckSlump(str.Substring(slimp + 1));
            if (slump == -1 || slimp + 2 + slump != str.Length) return false;


            //Console.WriteLine(slimp);
            //Console.WriteLine(slimp + 1+slump);
            //Console.WriteLine(str.Length);

            return true;
        }
    }
}