using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employees
{
    abstract partial class Employee
    {
        protected string empName;
        protected int empID;
        protected float currPay;
        protected int empAge;
        protected string empSSN;

        protected BenefitPackage empBenefits = new BenefitPackage();


        public class BenefitPackage
        {
            public enum BenefitPackageLevel
            {
                Standart, Gold, Platinum
            };
            public double ComputePayDedaction()
            {
                return 125.0;
            }
        }
        
    }
}
