namespace DeliveryApp
{
    public class Zakaz
    {
        public int Id { get; private set; }

        public Zakaz(int id2 = 0)
        {
            Id = id2;
            Console.WriteLine($"Delivery created #{Id}");
        }

        public void FormZakaz(int id2)
        {
            Id = id2;
            Console.WriteLine($"Delivery described #{Id}");
        }

        public override string ToString()
        {
            string status = $"Delivery #{Id}"; //+ (IsActive ? " is alive!" : "is closed");
            return $"{status}";
        }
    }
}