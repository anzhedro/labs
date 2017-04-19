using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Flow.Models
{
    public class Person
    {


        //public Person(string name, string login, string password)
        //{
        //    // TODO: Complete member initialization
        //    this.Name = name;
        //    this.Login = login;
        //    this.Password = password;
        //}
        public Person(string login, string password)
        {
            // TODO: Complete member initialization
            this.Login = login;
            this.Password = password;
        }
       // public string Name { get; set; }
        public string Login { get; set; }
        public string Password { get; set; }
    }
    
}
       