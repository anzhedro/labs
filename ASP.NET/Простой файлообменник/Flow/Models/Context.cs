using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Flow.Models
{
   public class Context
    {
    //    = new Person("harlachou_nv@tut.by", "000000") { get; };
    //new Person("androsik_ei@tut.by", "111111"); 
     public   List<Person> Users = new List<Person>() ;
      public  Person p1 {get; set;}
     public    Person p2 {get; set;}
     public string DefaultPath = "C:\\Users\\Горлачёв Никита\\Documents\\Visual Studio 2013\\Projects\\Flow\\Flow\\";
       public  Context()
        {  
           p1 = new Person("harlachou_nv@tut.by", "000000") ;
           p2 = new Person("androsik_ei@tut.by", "111111"); 
            this.Users.Add(p1);
           this. Users.Add(p2);
        }
        public  void AddNew(Person person)
        {
           this. Users.Add(person);
        }
        public Person CurrentUser;
        public string CurrentFileName;
    }
}