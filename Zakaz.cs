namespace DeliveryApp
{
    public class Zakaz : IDisposable
    {
        public int Id { get; private set; }
        private bool _isAlive = false;

        public Zakaz(int id2 = 0)
        {
            _isAlive = true;
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
            string status = $"Delivery #{Id}" + (_isAlive ? " is alive!" : " is closed");
            return $"{status}";
        }

        public void Dispose()
        {
            _isAlive = false;
            Console.WriteLine($"Delivery #{Id} closed");
        }
    }
}