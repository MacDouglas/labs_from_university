using System;
using System.Collections.Generic;
using System.Text;

namespace ObjectOverrides
{
    class Person
    {
        public string FirstName { get; set; } = "";
        public string SecondName { get; set; } = "";
        public int Age { get; set; }
        public string SSN { get; set; } = "";
        public Person(string fName,string sName,int personAge)
        {
            FirstName = fName;
            SecondName = sName;
            Age = personAge;
        }
        public Person()
        {
            
        }
        public override string ToString() => $"[First Name: {FirstName}; Second Name: {SecondName}; Age: {Age}]";
        public override bool Equals(object obj)
        {
            if (obj is Person && obj != null)
            {
                Person temp;
                temp = (Person)obj;
                if (temp.FirstName == this.FirstName && temp.SecondName == this.SecondName && temp.Age == this.Age)
                    return true;
                else
                    return false;
            }
            return false;
        }
        //public override bool Equals(object obj) => obj?.ToString() == ToString();
        public override int GetHashCode()
        {
            //return SSN.GetHashCode();
            
            // Возвратить хеш-код на основе значения, возвращаемого методом ToString()
            // для объекта Person.      
            return this.ToString().GetHashCode();
        }
    }
}
