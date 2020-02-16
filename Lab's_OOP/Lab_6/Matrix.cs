using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab_6
{
    class Matrix : IFormattable, ICloneable, IEnumerable<double>
    {
        private double[] matrix;
        public int rows { get; private set; }
        public int cols { get; private set; }
        public int id { get; private set; }
        private static int сounter { get; set; }
       
        public Matrix()
        {
            this.id = ++сounter;
            Console.WriteLine($"Конструктор матрицы {id}");
        }
       
        public Matrix(int rows, int cols) : this()
        {
            if (rows > 0 && cols > 0)
            {
                this.rows = rows;
                this.cols = cols;
                this.matrix = new double[rows * cols];
            }
            else if (rows < 0 || cols < 0)
                throw new ArgumentOutOfRangeException($"Не корректный размер матрицы {id}");
        }
        public Matrix(int rows, int cols, params double[] arr) : this(rows, cols)
        {
            for (int i = 0; i < rows * cols; i++)
                this.matrix[i] = arr[i];
        }
        public Matrix(int rows, int cols, Func<int, double> fun) : this(rows, cols)
        {
            for (int i = 0; i < rows * cols; i++)
                this.matrix[i] = fun(i);
        }
        public Matrix(int size) : this(size, size) {}
        public Matrix(int size, params double[] arr) : this(size, size, arr) {}
        ~Matrix()
        {
            Console.WriteLine($"Деструктор матрицы {id}");
        }
        public IEnumerator<double> GetEnumerator()              //перечислитель, который поддерживает простой перебор элементов неуниверсальной коллекции
        {
            foreach (double i in matrix)
                yield return i;                                 //используется для возврата каждого элемента по одному.
        }
        IEnumerator IEnumerable.GetEnumerator()                 //Возвращает перечислитель, который осуществляет итерацию по коллекции.
        {
            return matrix.GetEnumerator();
        }
        public Matrix Clone()
        {
            return new Matrix(rows, cols, matrix);
        }
        object ICloneable.Clone()
        {
            return this.Clone();
        }
        public static bool sum_ans(in Matrix a, in Matrix b)
        {
            return a.rows == b.rows && a.cols == b.cols;
        }
        public static bool multip_ans(in Matrix a, in Matrix b)
        {
            return a.rows == b.cols;
        }
        public static Matrix operator +(Matrix a, Matrix b)
        {
            if (Matrix.sum_ans(a, b))
            {
                Matrix tmp = new Matrix(a.rows, a.cols);
                for (int i = 0; i < a.rows * a.cols; i++)
                    tmp.matrix[i] = a.matrix[i] + b.matrix[i];
                return a;
            }
            throw new ArgumentException($"Операция + невозможна, т.к. размеры матриц #{a.id} и #{b.id} не совпадают!");
        }
        public static Matrix operator -(Matrix a, Matrix b)
        {
            if (Matrix.sum_ans(a, b))
            {
                Matrix tmp = new Matrix(a.rows, a.cols);
                for (int i = 0; i < a.rows * a.cols; i++)
                    tmp.matrix[i] = a.matrix[i] - b.matrix[i];
                return a;
            }
            throw new ArgumentException($"Операция - невозможна, т.к. размеры матриц #{a.id} и #{b.id} не совпадают!");
        }
        public static Matrix operator *(Matrix a, Matrix b)
        {
            if (multip_ans(a, b))
            {
                Matrix tmp = new Matrix(a.rows, b.cols);
                for (int i = 0; i < a.rows; i++)
                    for (int j = 0; j < b.cols; j++)
                        for (int k = 0; k < a.cols; k++)
                            tmp.matrix[i * tmp.cols + j] += a.matrix[i * a.cols + k] * b.matrix[k * b.cols + j];
                return tmp;
            }
            throw new ArgumentException($"Операция * невозможна, т.к. размеры матриц #{a.id} и #{b.id} не совпадают!");
        }
        public static Matrix operator *(Matrix a, double num)
        {
            for (int i = 0; i < a.rows * a.cols; i++)
                a.matrix[i] *= num;
            return a;
        }
        public double this[int i, int j]
        {
            get
            {
                if (i >= 0 && j >= 0 && i < rows && j < cols)
                    return matrix[i * cols + j];
                throw new IndexOutOfRangeException($"Incorrect index for Matrix{id}");
            }
            set
            {
                if (i >= 0 && j >= 0 && i < rows && j < cols)
                    this.matrix[i * cols + j] = value;
                else
                    throw new IndexOutOfRangeException($"Incorrect index for Matrix{id}");
            }
        }
        public string ToString(string format, IFormatProvider formatProvider = null)
        {
            if (string.IsNullOrEmpty(format))
                format = "G";

            var splitted = format.Split('.');
            string numberFormat = splitted[0];
            int width;

            if (splitted.Length == 1)
                width = 6;
            else
                width = int.Parse(splitted[1]);

            string resultFormat = $"{{0,{width}:{numberFormat}}}";

            var s = new StringBuilder();

            for (int i = 0; i < this.rows; i++)
            {
                for (int j = 0; j < this.cols; j++)
                    s.AppendFormat(formatProvider, resultFormat, this.matrix[j * cols + i]);
                s.AppendLine();
            }
            return s.ToString();
        }

    }
}

