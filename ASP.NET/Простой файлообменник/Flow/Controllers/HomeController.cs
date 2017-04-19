using Flow.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.AccessControl;
using System.Security.Principal;
using System.Web;
using System.Web.Mvc;


namespace Flow.Controllers
{   
        
     
    public class HomeController : Controller
    {
        //
        // GET: /Home/
        static Context context = new Context();
        
        public ActionResult Index()
        {
         
     //Users.Add(p1);
     //   Users.Add(p2);
            
                return View();
          
                
        }
        public ActionResult LogInWithoutParam()
        {
            
            DirectoryInfo d = new DirectoryInfo(Server.MapPath("~/Content/Reposity/" + context.CurrentUser.Login));

            IEnumerable<FileInfo> files = d.GetFiles();
            // передаем все полученный объекты в динамическое свойство Books в ViewBag
            ViewBag.Files = d.GetFiles();
            ViewBag.User = context.CurrentUser.Login;
            return View();
        }
        [HttpPost]
        public ActionResult LogIn(string login, string password)
        {
           
            Person temp = new Person(login, password);

            for (int i = 0; i < context.Users.Count; i++)
            {
                if (context.Users[i].Login.Equals(temp.Login) && context.Users[i].Password.Equals(temp.Password))
                {
                    context.CurrentUser = new Person(login, password);
                    DirectoryInfo d = new DirectoryInfo(Server.MapPath("~/Content/Reposity/" + login));
                    
                    IEnumerable<FileInfo> files = d.GetFiles();
                    // передаем все полученный объекты в динамическое свойство Books в ViewBag
                    ViewBag.Files = d.GetFiles();
                    ViewBag.User = context.CurrentUser.Login;
                    return View();
                }
            }
            
            return Redirect("Index");
        }
    
     public ActionResult FollowLinkRegistration()
     {
         return View();
     }

    
        [HttpPost]
        public ActionResult Registration(string login, string password)
     {
          
         Person New = new Person(login, password);

         for (int i = 0; i < context.Users.Count; i++)
         {
             if (context.Users[i].Login.Equals(New.Login) )
             {

                 Response.Write("<script>window.alert('!!! Sorry, but this user already exists !!! Try again :(');</script>");
                 
                // return Redirect("FollowLinkRegistration");
             }
         } 
            
         context.Users.Add(New);
         string newFolder = login;
         var folder = Server.MapPath("~/Content/Reposity/" + newFolder);
         if (!Directory.Exists(folder))
         {
             Directory.CreateDirectory(folder);
         }
         //DirectoryInfo d = new DirectoryInfo(context.DefaultPath + "\\Content\\Reposity" + "\\" + newFolder);
         //d.Create();
         //DirectoryInfo d = new DirectoryInfo("~\\Context\\Reposity");
         ////d.CreateSubdirectory("logun");
         ////Directory.CreateDirectory(Path.Combine(context.DefaultPath, newFolder));
         return View("Index");
     }
        [HttpPost]
        public ActionResult Upload(IEnumerable<HttpPostedFileBase> fileUpload)
        {
            foreach (var file in fileUpload)
            {
                if (file == null) continue;
                string path = AppDomain.CurrentDomain.BaseDirectory + "Content/Reposity/"+context.CurrentUser.Login+"/";
                string filename = Path.GetFileName(file.FileName);
                if (filename != null) file.SaveAs(Path.Combine(path, filename));
            }

             return Redirect("LogInWithoutParam");
        }
       [HttpPost]
        public ActionResult PreShareIt(FormCollection form)
        {
            if (!form.AllKeys[0].Equals("LogOff"))
            {
                context.CurrentFileName = form.AllKeys[0];
                List<Person> preShare = new List<Person>();
                int pos = 0;
                for (int i = 0; i < context.Users.Count; i++)
                {
                    if (context.Users[i].Login.Equals(context.CurrentUser.Login))
                    {
                        continue;
                    }
                    else
                    {
                        preShare.Insert(pos, context.Users[i]);
                        pos++;
                    }
                }
                ViewBag.preShare = preShare;
                return View();
            }
            else
            {
                return Redirect("Index");
            }
        }
       [HttpPost]
       public ActionResult ShareIt(FormCollection form)
       {
           if (!form.AllKeys[0].Equals("LogOff"))
           {
               string filePath = Path.Combine(Server.MapPath("~/Content/Reposity/" + context.CurrentUser.Login), context.CurrentFileName);
               System.IO.File.Copy(filePath, Server.MapPath("~/Content/Reposity/" + form.AllKeys[0] + "/" + context.CurrentFileName));
               //File.CopyTo(filePath, Server.MapPath("~/Content/Reposity/" + form.AllKeys[0]));
               return Redirect("LogInWithoutParam");
           }
           else
           {
               return View("Index");
           }
       }
    }
};
