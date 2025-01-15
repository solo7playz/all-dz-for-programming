using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Patterns
{
    class Program
    {
        static void Main(string[] args)
        {
            DeliveryFactory factory = new DeliveryFactory();

            FoodDelivery Delivery = factory.CreateDelivery(Console.ReadLine());
            Console.WriteLine($"Вы выбрали доставку: {factory.type}");
            Delivery.Deliver();

            FoodDelivery sushiDelivery = factory.CreateDelivery("Суши");
            Console.WriteLine("Вы выбрали доставку: Суши");
            sushiDelivery.Deliver();


            OrderSet baseSet = new OrderSet();
            baseSet.AddOrder("Пицца");
            baseSet.AddOrder("Суши");
            baseSet.AddOrder("Бургер");

            Console.WriteLine("Базовый набор:");
            baseSet.PrintOrders();

            OrderSet clonedSet = baseSet.Clone();
            clonedSet.RemoveOrder("Суши");

            Console.WriteLine();
            clonedSet.PrintOrders();
        }
    }
    abstract class FoodDelivery
    {
        public abstract void Deliver();
    }
    class PizzaDelivery : FoodDelivery
    {
        public override void Deliver()
        {
            Console.WriteLine("Пицца доставляется в коробке.");
        }
    }
    class SushiDelivery : FoodDelivery
    {
        public override void Deliver()
        {
            Console.WriteLine("Суши доставляются в специальном контейнере.");
        }
    }
    class BurgerDelivery : FoodDelivery
    {
        public override void Deliver()
        {
            Console.WriteLine("Бургеры доставляются в упаковке с логотипом.");
        }
    }

    class DeliveryFactory
    {
        public string type { get; set; }
        public FoodDelivery CreateDelivery(string type)
        {
            this.type = type;
            switch (this.type)
            {
                case "Пицца":
                    return new PizzaDelivery();
                    break;
                case "Суши":
                    return new SushiDelivery();
                    break;
                case "Бургер":
                    return new BurgerDelivery();
                    break;
                //case default:
                //    Console.WriteLine("Error. You are error, fu***ng user, kill yourself or print type of food again!");
                //    break;
            }
            return null;
        }
    }
    class OrderSet
    {
        private List<string> orders;

        public OrderSet()
        {
            orders = new List<string>();
        }

        public OrderSet(List<string> orders)
        {
            this.orders = orders;
        }

        public void AddOrder(string order)
        {
            orders.Add(order);
        }

        public void RemoveOrder(string order)
        {
            orders.Remove(order);
        }

        public OrderSet Clone()
        {
            return new OrderSet(new List<string>(orders));
        }
        public void PrintOrders()
        {
            foreach (string order in orders)
            {
                Console.WriteLine("- " + order);
            }
        }
    }
}
